

#ifndef ZC_GEDLL_H
#define ZC_GEDLL_H

#pragma warning(disable:4251)
#pragma warning(disable:4273)
#pragma warning(disable:4275)
#ifdef  ZCGE_INTERNAL
#define GE_DLLEXPIMPORT __declspec(dllexport)
#else
#define GE_DLLEXPIMPORT __declspec(dllimport)
#endif

#ifdef  ZCGX_INTERNAL
#define GX_DLLEXPIMPORT __declspec(dllexport)
#else
#define GX_DLLEXPIMPORT __declspec(dllimport)
#endif

#ifdef ZCGE_INTERNAL
#ifndef GELIB_REGRESS
#include "zcmemdebug.h"
#endif
#endif

#endif 
