//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#pragma once
#include <QMutex>

//  Allows an image producer and an image consumer to swap
//  buffers efficiently
class CTripleBuffer
{
public:
    CTripleBuffer(void);
    ~CTripleBuffer(void);
protected:
    QMutex              m_lock;
    unsigned char *     m_pTripleBuffer;
    bool                m_bTripleBufferDirty;
public:
    void Push(unsigned char **pBuf);
    bool Pull(unsigned char **pBuf);
    bool IsEmpty();
    unsigned char * Alloc(size_t nBufferSize);
    void Free();
};
