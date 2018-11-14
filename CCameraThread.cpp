//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include "CCameraThread.h"

CCameraThread::CCameraThread(AP_HANDLE        hApBase,
                             CTripleBuffer *  pTripleBuffer)
    : QThread(),
    m_pBuffer(NULL),
    m_nBufferSize(0),
    m_bPlaying(false),
    m_pTripleBuffer(pTripleBuffer),
    m_hApBase(hApBase)
{

}

CCameraThread::~CCameraThread()
{
    delete [] m_pBuffer;
}

void CCameraThread::stop()
{
    m_bPlaying = false;
}

void CCameraThread::run()
{
    if (m_pBuffer == NULL)
    {
        m_nBufferSize = ap_GrabFrame(m_hApBase, NULL, 0);
        m_pBuffer = new unsigned char [m_nBufferSize];
    }

    m_bPlaying = true;
    while (m_bPlaying)
    {
        //  Grab a frame (ignore bad frames)
        ap_u32 bytesReturned;
        bytesReturned = ap_GrabFrame(m_hApBase, m_pBuffer, m_nBufferSize);
        ap_s32 retVal = ap_GetLastError();
        if (retVal != AP_CAMERA_ERROR)
        {
            //  Store the new camera image into the triple buffer for processing
            m_pTripleBuffer->Push(&m_pBuffer);
            //m_cameraFrameCount++;
        }
    }
}
