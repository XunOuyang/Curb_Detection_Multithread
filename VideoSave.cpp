#include "VideoSave.h"
#include <direct.h>
#include <ctime>

#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480

VideoSave::VideoSave()
{
	isRecording = 0;
}


VideoSave::~VideoSave()
{
}

String VideoSave::currentTimeString()
{
	time_t t = time(0);
	std::tm* now = std::localtime(&t);
	return std::to_string(now->tm_year + 1900) + "_" + std::to_string(now->tm_mon + 1)
		+ "_" + std::to_string(now->tm_mday) + "_" + std::to_string(now->tm_hour)
		+ "_" + std::to_string(now->tm_min) + "_" + std::to_string(now->tm_sec);
}

//void VideoSave::Save(Mat frame, int number, float prob)
void VideoSave::Save(Mat _frame)
{
	time_t sec;
	String timeStr = currentTimeString();
	createFileFolder();
	String videoName = "./Data/" + timeStr + ".avi";
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	VideoWriter video(videoName, codec, 30, Size(FRAME_WIDTH, FRAME_HEIGHT));


	/*
	std::ofstream csvFile("./Data/" + timeStr + ".csv");
	csvFile << "Region Of Interest X/Y" << "," << roiX << "," << roiY << "\n";
	csvFile << "Region Of Interest Width/Height" << "," << roiWidth << "," << roiHeight << "\n";
	csvFile << "Frame ID" << "," << "Probability" << '\n';
	*/

	while (isRecording)
	{
		cv::Mat frame = currentFrame;
		video.write(currentFrame);
	}

	/*
	csvFile.close();
	*/
}

void VideoSave::Save(Mat _frame1, Mat _frame2)
{
	time_t sec;
	String timeStr = currentTimeString();
	createFileFolder();
	String videoName1 = "./Data/" + timeStr + "1" + ".avi";
	String videoName2 = "./Data/" + timeStr + "1" + ".avi";
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	VideoWriter video1(videoName1, codec, 30, Size(FRAME_WIDTH, FRAME_HEIGHT));
	VideoWriter video2(videoName2, codec, 30, Size(FRAME_WIDTH, FRAME_HEIGHT));


	/*
	std::ofstream csvFile("./Data/" + timeStr + ".csv");
	csvFile << "Region Of Interest X/Y" << "," << roiX << "," << roiY << "\n";
	csvFile << "Region Of Interest Width/Height" << "," << roiWidth << "," << roiHeight << "\n";
	csvFile << "Frame ID" << "," << "Probability" << '\n';
	*/

	while (isRecording)
	{
		cv::Mat frame1 = _frame1;
		cv::Mat frame2 = _frame2;
		video1.write(frame1);
		video1.write(frame2);
	}

	/*
	csvFile.close();
	*/
}

void VideoSave::createFileFolder()
{
	String dir = "./data";
	_mkdir(dir.c_str());
}