

#include "malloc.h"
#include "zAdAChar.h"
#include "zAdCharFmt.h"

#ifdef ASSERT
#define ZcFStream_Assert ASSERT
#elif defined assert
#define ZcFStream_Assert assert
#else
#define ZcFStream_Assert(T)
#endif

#ifdef UNICODE
inline int ZcFStream_wideToMulti(const wchar_t *pSrc, int nSrcSize,
                                 char *pDest, int nDestSize);
inline std::locale ZcFStream_curLocale();
#endif

class ZcIfstream : public
#ifndef UNICODE
                        std::ifstream {
#else
                        std::wifstream {
#endif
  public:
    class ZcIfstream() {};
    class ZcIfstream(const ZTCHAR *pName);
#ifdef UNICODE
    void open(const wchar_t *pName);
    void open(const wchar_t *pName, ios_base::openmode nMode);
#endif
};

class ZcOfstream : public
#ifndef UNICODE
                        std::ofstream {
#else
                        std::wofstream {
#endif
  public:
    class ZcOfstream() {};
    class ZcOfstream(const ZTCHAR *pName);
#ifdef UNICODE
    void open(const wchar_t *pName);
    void open(const wchar_t *pName, ios_base::openmode nMode);
#endif

};

#ifndef UNICODE
inline ZcIfstream::ZcIfstream(const ZTCHAR *pName) : std::ifstream(pName)
{
}
inline ZcOfstream::ZcOfstream(const ZTCHAR *pName) : std::ofstream(pName)
{
}
#else
inline ZcIfstream::ZcIfstream(const ZTCHAR *pName)
{
    this->open(pName);
}

inline ZcOfstream::ZcOfstream(const ZTCHAR *pName)
{
    this->open(pName);
}

inline std::locale ZcFStream_curLocale()
{
    char buf[100];
    sprintf(buf, ".%d", GetACP());
    return std::locale(buf, LC_CTYPE);
}

inline int ZcFStream_wideToMulti(const wchar_t *pSrc, int nSrcSize,
                                 char *pDest, int nDestSize)
{
    return ::WideCharToMultiByte(
                        CP_ACP,
#if defined(WINVER) && (WINVER >= 0x0500)
                        WC_NO_BEST_FIT_CHARS,
#else
                        0,
#endif
                        pSrc,
                        nSrcSize,
                        pDest,
                        nDestSize,
                        NULL,
                        NULL);
}

inline void ZcIfstream::open(const wchar_t *pName)
{
    this->std::wifstream::open(pName);
    this->imbue(ZcFStream_curLocale());
}

inline void ZcIfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
    this->std::wifstream::open(pName, nMode);
    this->imbue(ZcFStream_curLocale());
}

inline void ZcOfstream::open(const wchar_t *pName)
{
    this->std::wofstream::open(pName);
    this->imbue(ZcFStream_curLocale());
}

inline void ZcOfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
    this->std::wofstream::open(pName, nMode);
    this->imbue(ZcFStream_curLocale());
}

#endif

