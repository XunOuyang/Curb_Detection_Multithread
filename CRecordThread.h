#ifndef CRECORDTHREAD_H
#define CRECORDTHREAD_H

#include <QThread>
#include <QGraphicsPixmapItem>
#include "apbase.h"
#include "TripleBuffer.h"


#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <direct.h>
#include <fstream>

#define RESOLUTION 1

#if RESOLUTION > 1
#define FRAME_WIDTH 1928
#define FRAME_HEIGHT 1208
#else
#define FRAME_WIDTH 1344
#define FRAME_HEIGHT 968
#endif

using namespace cv;


class CRecordThread : public QThread
{
	Q_OBJECT

public:
	CRecordThread(AP_HANDLE            hApBase,
		CTripleBuffer *      pTripleBuffer);
	~CRecordThread();

	unsigned char *         m_pBuffer;
	size_t                  m_nBufferSize;
	bool                    m_bPlaying;
	CTripleBuffer *         m_pTripleBuffer;
	AP_HANDLE               m_hApBase;
	int						index;


	bool					m_bRecording;

	void                run();
	void                stop();
	String				currentTimeString();
	void				createFileFolder();


signals:
	void                drawPix(QImage *image, int index);
};


#endif // CRECORDTHREAD_H
