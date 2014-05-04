

#ifndef ZC_GETOL_H
#define ZC_GETOL_H

#ifndef unix
#include <stdlib.h>
#endif
#include "zgedll.h"
#include "zgedblar.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeTol {
public:
    ZcGeTol();

    double  equalPoint          () const;
    double  equalVector         () const;

    void    setEqualPoint       ( double val );
    void    setEqualVector      ( double val );

private:
    double				mTolArr[5];
    int                 mAbs;

    friend class ZcGeTolA;
};

__forceinline void ZcGeTol::setEqualVector( double val )
    { mTolArr[1] = val; }

__forceinline double ZcGeTol::equalVector() const
    { return mTolArr[1]; }

__forceinline void ZcGeTol::setEqualPoint( double val )
    { mTolArr[0] = val; }

__forceinline double ZcGeTol::equalPoint() const
    { return mTolArr[0]; }

#pragma pack (pop)
#endif
