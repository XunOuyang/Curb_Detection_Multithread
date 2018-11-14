#include "CRecordThread.h" 

CRecordThread::CRecordThread(AP_HANDLE            hApBase,
	CTripleBuffer *      pTripleBuffer)
	: QThread(),
	m_pBuffer(NULL),
	m_nBufferSize(0),
	m_bPlaying(false),
	m_pTripleBuffer(pTripleBuffer),
	m_hApBase(hApBase),
	m_bRecording(false)
{

}

CRecordThread::~CRecordThread()
{
	delete[] m_pBuffer;
}

void CRecordThread::stop()
{
	m_bRecording = false;
	m_bPlaying = false;
}

void CRecordThread::run()
{
	VideoWriter video;
	if (m_pBuffer == NULL)
	{
		m_nBufferSize = ap_GrabFrame(m_hApBase, NULL, 0);
		m_pBuffer = new unsigned char[m_nBufferSize];
		String timeStr = currentTimeString();
		createFileFolder();
		String videoName = "./Data/" + timeStr + "cam" + std::to_string(index) + ".avi";
		int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
		
		video.open(videoName, codec, 30, Size(FRAME_WIDTH, FRAME_HEIGHT));
	}

	m_bRecording = true;
	m_bPlaying = true;
	
	while (m_bPlaying && m_bRecording)
	{
		//  Get the latest available sensor image data buffer
		if (!m_pTripleBuffer->Pull(&m_pBuffer))
		{
			//  There is no new image available so we release a little bit of processing time
			msleep(1);
			continue;
		}

		//  Convert the image data from the camera to RGB
		ap_u32  rgbWidth, rgbHeight, rgbBitDepth;
		unsigned char *rgb;
		rgb = ap_ColorPipe(m_hApBase, m_pBuffer, m_nBufferSize,
			&rgbWidth, &rgbHeight, &rgbBitDepth);
		if (rgb == NULL)
		{
			msleep(30);
			continue;
		}
		
		QImage *image = new QImage(rgb, rgbWidth, rgbHeight, QImage::Format_RGB32);
		emit drawPix(image, index);

		cv::Mat cvImage = cv::Mat(FRAME_HEIGHT, FRAME_WIDTH, CV_8UC4, (unsigned *)rgb);
		cv::cvtColor(cvImage, cvImage,  COLOR_BGRA2BGR);
		video.write(cvImage);
	}
	video.release();
}


String CRecordThread::currentTimeString()
{
	time_t t = time(0);
	std::tm* now = std::localtime(&t);
	return std::to_string(now->tm_year + 1900) + "_" + std::to_string(now->tm_mon + 1)
		+ "_" + std::to_string(now->tm_mday) + "_" + std::to_string(now->tm_hour)
		+ "_" + std::to_string(now->tm_min) + "_" + std::to_string(now->tm_sec);
}

void CRecordThread::createFileFolder()
{
	String dir = "./data";
	_mkdir(dir.c_str());
}