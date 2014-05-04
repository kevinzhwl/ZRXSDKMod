

#ifndef ZD_DBDATE_H
#define ZD_DBDATE_H

#include "zacdb.h"

#pragma pack(push, 8)

class ZcDbDwgFiler;

class ZcDbDate
{
public:
    enum InitialValue {
        kInitZero          = 1,
        kInitLocalTime     = 2,
        kInitUniversalTime = 3
    };
    ZcDbDate();
    ZcDbDate(InitialValue i);
    ZcDbDate(const ZcDbDate&);
    virtual ~ZcDbDate();

    const ZcDbDate& operator= (const ZcDbDate&);

    void  getDate (short& month, short& day, short& year) const;
    void  setDate (short month, short day, short year);
    short month   () const;
    void  setMonth(short);
    short day     () const;
    void  setDay  (short);
    short year    () const;
    void  setYear (short);

#ifdef _WINBASE_

    void  getTime (SYSTEMTIME &st) const;
    void  setTime (const SYSTEMTIME &st);
#endif

    void  getTime  (short& hour, short& min, short& sec, short& msec) const;
    void  setTime  (short hour, short min, short sec, short msec);
    short hour     () const;
    void  setHour  (short);
    short minute   () const;
    void  setMinute(short);
    short second   () const;
    void  setSecond(short);
    short millisecond() const;
    void  setMillisecond(short);
    void  setToZero();

    void  getLocalTime();
    void  getUniversalTime();

    void localToUniversal();
    void universalToLocal();

    long   julianDay           () const;
    long   msecsPastMidnight   () const;
    void   setJulianDay        (long julianDay);
    void   setMsecsPastMidnight(long msec);
    void   setJulianDate       (long julianDay, long msec);
    double julianFraction      () const;
    void   setJulianFraction   (double);

    bool operator== (const ZcDbDate&) const;
    bool operator > (const ZcDbDate&) const;
    bool operator >= (const ZcDbDate&) const;
    bool operator < (const ZcDbDate&) const;
    bool operator <= (const ZcDbDate&) const;

    const ZcDbDate operator + (const ZcDbDate &date) const;
    const ZcDbDate operator - (const ZcDbDate &date) const;
    const ZcDbDate & operator += (const ZcDbDate &date);
    const ZcDbDate & operator -= (const ZcDbDate &date);

    const ZcDbDate& add      (const ZcDbDate &date);
    const ZcDbDate& subtract (const ZcDbDate &date);

    Zcad::ErrorStatus dwgOut(ZcDbDwgFiler *outFiler) const;
    Zcad::ErrorStatus dwgIn (ZcDbDwgFiler *inFiler);

private:
    friend class ZcDbImpDate;
    ZcDbImpDate *mpImpDate;
};

inline const ZcDbDate ZcDbDate::operator + (const ZcDbDate & d) const
{
    return ZcDbDate(*this) += d;
}

inline const ZcDbDate ZcDbDate::operator - (const ZcDbDate & d) const
{
    return ZcDbDate(*this) -= d;
}

inline bool ZcDbDate::operator < (const ZcDbDate & d) const
{
    return ! operator >= (d);
}

inline bool ZcDbDate::operator <= (const ZcDbDate & d) const
{
    return ! operator > (d);
}

inline const ZcDbDate & ZcDbDate::add(const ZcDbDate &date)
{
    return operator += (date);
}

inline const ZcDbDate & ZcDbDate::subtract(const ZcDbDate &date)
{
    return operator -= (date);
}

#pragma pack(pop)

#endif

