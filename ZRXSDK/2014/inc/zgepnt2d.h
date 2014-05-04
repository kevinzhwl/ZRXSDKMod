

#ifndef ZC_GEPNT2D_H
#define ZC_GEPNT2D_H

#include "zgevec2d.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;
class ZcGeVector2d;
class ZcGeLinearEnt2d;
class ZcGeLine2d;

class
GE_DLLEXPIMPORT
ZcGePoint2d
{
public:
    ZcGePoint2d();
    ZcGePoint2d(const ZcGePoint2d& pnt);
    ZcGePoint2d(double x, double y);

    static const   ZcGePoint2d kOrigin;

    friend
    GE_DLLEXPIMPORT
    ZcGePoint2d    operator *  (const ZcGeMatrix2d& mat, const ZcGePoint2d& pnt);
    ZcGePoint2d&   setToProduct(const ZcGeMatrix2d& mat, const ZcGePoint2d& pnt);
    ZcGePoint2d&   transformBy (const ZcGeMatrix2d& leftSide);
    ZcGePoint2d&   rotateBy    (double angle, const ZcGePoint2d& wrtPoint
                                = ZcGePoint2d::kOrigin);
    ZcGePoint2d&   mirror      (const ZcGeLine2d& line);
    ZcGePoint2d&   scaleBy     (double scaleFactor, const ZcGePoint2d& wrtPoint
                                = ZcGePoint2d::kOrigin);

    ZcGePoint2d    operator *  (double) const;
    friend
    ZcGePoint2d    operator *  (double, const ZcGePoint2d& scl);
    ZcGePoint2d&   operator *= (double scl);
    ZcGePoint2d    operator /  (double scl) const;
    ZcGePoint2d&   operator /= (double scl);

    ZcGePoint2d    operator +  (const ZcGeVector2d& vec) const;
    ZcGePoint2d&   operator += (const ZcGeVector2d& vec);
    ZcGePoint2d    operator -  (const ZcGeVector2d& vec) const;
    ZcGePoint2d&   operator -= (const ZcGeVector2d& vec);
    ZcGePoint2d&   setToSum    (const ZcGePoint2d& pnt, const ZcGeVector2d& vec);

    ZcGeVector2d   operator -  (const ZcGePoint2d& pnt) const;
    ZcGeVector2d   asVector    () const;

    double         distanceTo  (const ZcGePoint2d& pnt) const;

    bool operator == (const ZcGePoint2d& pnt) const;
    bool operator != (const ZcGePoint2d& pnt) const;
    bool isEqualTo   (const ZcGePoint2d& pnt,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int idx);
    ZcGePoint2d&   set         (double x, double y);

    double         x, y;
};

__forceinline
ZcGePoint2d::ZcGePoint2d() : x(0.0), y(0.0)
{
}

__forceinline
ZcGePoint2d::ZcGePoint2d(const ZcGePoint2d& src) : x(src.x), y(src.y)
{
}

__forceinline
ZcGePoint2d::ZcGePoint2d(double xx, double yy) : x(xx), y(yy)
{
}

__forceinline bool
ZcGePoint2d::operator == (const ZcGePoint2d& p) const
{
    return this->isEqualTo(p);
}

__forceinline bool
ZcGePoint2d::operator != (const ZcGePoint2d& p) const
{
    return !this->isEqualTo(p);
}

__forceinline ZcGePoint2d
ZcGePoint2d::operator * (double val) const
{
    return ZcGePoint2d(x*val, y*val);
}

__forceinline ZcGePoint2d
operator * (double val, const ZcGePoint2d& p)
{
    return ZcGePoint2d(p.x*val, p.y*val);
}

__forceinline ZcGePoint2d&
ZcGePoint2d::operator *= (double val)
{
    x *= val;
    y *= val;
    return *this;
}

__forceinline ZcGePoint2d
ZcGePoint2d::operator / (double val) const
{
    return ZcGePoint2d (x/val, y/val);
}

__forceinline ZcGePoint2d&
ZcGePoint2d::operator /= (double val)
{
    x /= val;
    y /= val;
    return *this;
}

__forceinline ZcGePoint2d
ZcGePoint2d::operator + (const ZcGeVector2d& v) const
{
    return ZcGePoint2d(x + v.x, y + v.y);
}

__forceinline ZcGePoint2d&
ZcGePoint2d::operator += (const ZcGeVector2d& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

__forceinline ZcGePoint2d
ZcGePoint2d::operator - (const ZcGeVector2d& v) const
{
    return ZcGePoint2d(x - v.x, y - v.y);
}

__forceinline ZcGePoint2d&
ZcGePoint2d::operator -= (const ZcGeVector2d& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

__forceinline ZcGeVector2d
ZcGePoint2d::operator - (const ZcGePoint2d& p) const
{
    return ZcGeVector2d(x - p.x, y - p.y);
}

__forceinline ZcGeVector2d
ZcGePoint2d::asVector() const
{
    return ZcGeVector2d(x, y);
}

__forceinline ZcGePoint2d&
ZcGePoint2d::set(double xx, double yy)
{
    x = xx;
    y = yy;
    return *this;
}

__forceinline double
ZcGePoint2d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

__forceinline double&
ZcGePoint2d::operator [] (unsigned int i)
{
    return *(&x+i);
}

#pragma pack (pop)
#endif
