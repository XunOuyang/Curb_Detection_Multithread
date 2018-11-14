//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#ifndef CDISPLAYTHREAD_H
#define CDISPLAYTHREAD_H

#include <QThread>
#include <QGraphicsPixmapItem>
#include "apbase.h"
#include "TripleBuffer.h"

/*
// the following include files are added by Xun Ouyang
#include <core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
using namespace cv;
*/

class CDisplayThread : public QThread
{
    Q_OBJECT

public:
    CDisplayThread(AP_HANDLE            hApBase,
                   CTripleBuffer *      pTripleBuffer);
    ~CDisplayThread();

    unsigned char *         m_pBuffer;
    size_t                  m_nBufferSize;
    bool                    m_bPlaying;
    CTripleBuffer *         m_pTripleBuffer;
    AP_HANDLE               m_hApBase;

	int					index;

    void                run();
    void                stop();

signals:
    void                drawPix(QImage *image, int index);
};

#endif // CDISPLAYTHREAD_H
