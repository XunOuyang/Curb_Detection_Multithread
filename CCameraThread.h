//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#ifndef CCAMERATHREAD_H
#define CCAMERATHREAD_H

#include <QThread>
#include "apbase.h"
#include "TripleBuffer.h"

class CCameraThread : public QThread
{
    Q_OBJECT

public:
    CCameraThread(AP_HANDLE        hApBase,
                  CTripleBuffer *  pTripleBuffer);
    ~CCameraThread();

    unsigned char *     m_pBuffer;
    size_t              m_nBufferSize;
    bool                m_bPlaying;
    CTripleBuffer *     m_pTripleBuffer;
    AP_HANDLE           m_hApBase;

    void                run();
    void                stop();


private:
    
};

#endif // CCAMERATHREAD_H
