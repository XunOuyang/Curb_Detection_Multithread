//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include "TripleBuffer.h"


/////////////////////////////////////////////////////////////////////////////
// CTripleBuffer
//
// Triple buffer functionality. The optimal version of buffer sharing.
CTripleBuffer::CTripleBuffer()
{
    m_bTripleBufferDirty = false;
    m_pTripleBuffer      = NULL;
}

CTripleBuffer::~CTripleBuffer()
{
    Free();
}

unsigned char *CTripleBuffer::Alloc(size_t nBufferSize)
{
    Free();
    m_pTripleBuffer = new unsigned char [nBufferSize];
    return m_pTripleBuffer;
}

void CTripleBuffer::Free()
{
    delete [] m_pTripleBuffer;
    m_pTripleBuffer = NULL;
    m_bTripleBufferDirty = false;
}

void CTripleBuffer::Push(unsigned char **pBuf)
{
    QMutexLocker locker(&m_lock);

    unsigned char *pTmp = *pBuf;
    *pBuf = m_pTripleBuffer;
    m_pTripleBuffer = pTmp;

    m_bTripleBufferDirty = true;
}

bool CTripleBuffer::Pull(unsigned char **pBuf)
{
    QMutexLocker locker(&m_lock);

    if (!m_bTripleBufferDirty)
        return false;

    unsigned char *pTmp = *pBuf;
    *pBuf = m_pTripleBuffer;
    m_pTripleBuffer = pTmp;

    m_bTripleBufferDirty = false;

    return true;
}

bool CTripleBuffer::IsEmpty()
{
    QMutexLocker locker(&m_lock);

    return !m_bTripleBufferDirty;
}
