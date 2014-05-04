

#ifndef _zcutilads_h
#define _zcutilads_h 1

#ifdef __cplusplus
    extern "C" {
#endif

#include "zadsdef.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

void           zcad__assert(const ZTCHAR *, const ZTCHAR *, int);

int            zcutCvUnit (zds_real value, const ZTCHAR *oldunit,
                             const ZTCHAR *newunit, zds_real *result);
int            zcutWcMatch (const ZTCHAR *string, const ZTCHAR *pattern);

int            zcutPrintf (const ZTCHAR *format, ...);
int            zcutSPrintf (ZTCHAR *buffer, const ZTCHAR *format, ...);

struct resbuf *zcutNewRb (int v);
int            zcutRelRb (struct resbuf *rb);
struct resbuf *zcutBuildList (int rtype, ...);

zds_real       zcutAngle (const zds_point pt1, const zds_point pt2);
zds_real       zcutDistance (const zds_point pt1, const zds_point pt2);
void           zcutPolar (const zds_point pt, zds_real angle,
                            zds_real dist, zds_point ptres);

int            zcutIsAlpha (int c);
int            zcutIsUpper (int c);
int            zcutIsLower (int c);
int            zcutIsDigit (int c);
int            zcutIsXDigit (int c);
int            zcutIsSpace (int c);
int            zcutIsPunct (int c);
int            zcutIsAlNum (int c);
int            zcutIsPrint (int c);
int            zcutIsGraph (int c);
int            zcutIsCntrl (int c);
int            zcutToUpper (int c);
int            zcutToLower (int c);

#pragma pack (pop)

#ifdef __cplusplus
    }
#endif

#endif 
