//header.h
#ifndef CRTC_SEC_H
#define CRTC_SEC_H

#include "windows.h"

class RAII_CrtcSec
{
private:
    CRITICAL_SECTION crtc_sec;
public:
    RAII_CrtcSec() { ::InitializeCriticalSection(&crtc_sec); }
    ~RAII_CrtcSec() { ::DeleteCriticalSection(&crtc_sec); }
    RAII_CrtcSec(const RAII_CrtcSec &) = delete;
    RAII_CrtcSec & operator=(const RAII_CrtcSec &) = delete;
    //
    void Lock() { ::EnterCriticalSection(&crtc_sec); }
    void Unlock() { ::LeaveCriticalSection(&crtc_sec); }
};

#endif