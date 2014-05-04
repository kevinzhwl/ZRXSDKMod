

#ifndef _ZCARRAY_H
#define _ZCARRAY_H

#pragma warning (disable: 4786)

#include <memory.h>     
#include <stdlib.h>
#include "zadesk.h"
#include "assert.h"

#ifdef ASSERT
#define ZC_ARRAY_ASSERT ASSERT
#elif defined assert
#define ZC_ARRAY_ASSERT assert
#elif defined _ASSERTE
#define ZC_ARRAY_ASSERT _ASSERTE
#else
#define ZC_ARRAY_ASSERT(T)
#endif

#pragma pack (push, 8)

#define ZCARRAY_GROWTH_THRESHOLD 0x10000

template <class T> class ZcArrayMemCopyReallocator
{
public:
    static void reallocateArray(T* pCopy, const T * pSource, int nCount)
    {
        ZC_ARRAY_ASSERT(nCount >= 0);
        ZC_ARRAY_ASSERT(nCount < 0x40000000);
        if (nCount > 0) 
        {
            memcpy(pCopy, pSource, nCount * sizeof(T));
        }
    }
};

template <class T> class ZcArrayObjectCopyReallocator
{
public:
    static void reallocateArray(T* pCopy, const T * pSource, int nCount)
    {
        ZC_ARRAY_ASSERT(nCount >= 0);
        ZC_ARRAY_ASSERT(nCount < 0x40000000);
        while(nCount--)
        {
            pCopy->operator=(*pSource);
            pCopy++;
            pSource++;
        }
    }
};

template <class T, class R = ZcArrayMemCopyReallocator<T> > class ZcArray
{
public:
    ZcArray(int initPhysicalLength = 0, int initGrowLength = 8);
    ZcArray(const ZcArray<T,R>&);
    ~ZcArray();

    ZcArray<T,R>&         operator =  (const ZcArray<T,R>&);
    bool                operator == (const ZcArray<T,R>&) const;

    T&                  operator [] (int);
    const T &           operator [] (int) const;
    const T &             at          (int index) const;
          T &             at          (int index);
    ZcArray<T,R>&         setAt       (int index, const T& value);
    ZcArray<T,R>&         setAll      (const T& value);
    T&                  first       ();
    const T &           first       () const;
    T&                  last        ();
    const T &           last        () const;

    int                 append      (const T& value);
    ZcArray<T,R>&         append      (const ZcArray<T,R>& array);
    ZcArray<T,R>&         insertAt    (int index, const T& value);

    ZcArray<T,R>&         removeAt    (int index);
    bool                  remove      (const T& value, int start = 0);
    ZcArray<T,R>&         removeFirst ();
    ZcArray<T,R>&         removeLast  ();
    ZcArray<T,R>&         removeAll   ();
    ZcArray<T,R>&         removeSubArray (int startIndex, int endIndex);

    bool                contains    (const T& value, int start = 0) const;
    bool                find        (const T& value, int& foundAt,
                                     int start = 0) const;
	int                 find        (const T& value) const;
	int                 findFrom    (const T& value, int start) const;

    int                 length      () const; 
    bool                isEmpty     () const;
    int                 logicalLength() const;
    ZcArray<T,R>&         setLogicalLength(int);
    int                 physicalLength() const;
    ZcArray<T,R>&         setPhysicalLength(int);

    int                 growLength  () const;
    ZcArray<T,R>&         setGrowLength(int);

    ZcArray<T,R>&         reverse     ();
    ZcArray<T,R>&         swap        (int i1, int i2);

    const T*            asArrayPtr  () const;
    T*                  asArrayPtr  ();

protected:
    T*                  mpArray;
    int                 mPhysicalLen;
    int                 mLogicalLen;
    int                 mGrowLen;   

    bool                isValid     (int) const;
};

#pragma pack (pop)

#ifdef GE_LOCATED_NEW
#include "zgegblnew.h"
#endif

#pragma pack (push, 8)

template <class T, class R> inline bool
ZcArray<T,R>::contains(const T& value, int start) const
{ return this->findFrom(value, start) != -1; }

template <class T, class R> inline int
ZcArray<T,R>::length() const
{ return mLogicalLen; }

template <class T, class R> inline bool
ZcArray<T,R>::isEmpty() const
{ return mLogicalLen == 0; }

template <class T, class R> inline int
ZcArray<T,R>::logicalLength() const
{ return mLogicalLen; }

template <class T, class R> inline int
ZcArray<T,R>::physicalLength() const
{ return mPhysicalLen; }

template <class T, class R> inline int
ZcArray<T,R>::growLength() const
{ return mGrowLen; }

template <class T, class R> inline const T*
ZcArray<T,R>::asArrayPtr() const
{ return mpArray; }

template <class T, class R> inline T*
ZcArray<T,R>::asArrayPtr()
{ return mpArray; }

template <class T, class R> inline bool
ZcArray<T,R>::isValid(int i) const
{ return i >= 0 && i < mLogicalLen; }

template <class T, class R> inline T&
ZcArray<T,R>::operator [] (int i)
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline const T&
ZcArray<T,R>::operator [] (int i) const
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline T&
ZcArray<T,R>::at(int i)
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline const T&
ZcArray<T,R>::at(int i) const
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::setAt(int i, const T& value)
{ ZC_ARRAY_ASSERT(this->isValid(i)); mpArray[i] = value; return *this; }

template <class T, class R> inline T&
ZcArray<T,R>::first()
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0]; }

template <class T, class R> inline const T&
ZcArray<T,R>::first() const
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0]; }

template <class T, class R> inline T&
ZcArray<T,R>::last()
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen-1]; }

template <class T, class R> inline const T&
ZcArray<T,R>::last() const
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen-1]; }

template <class T, class R> inline int
ZcArray<T,R>::append(const T& value)
{ insertAt(mLogicalLen, value); return mLogicalLen-1; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeFirst()
{ ZC_ARRAY_ASSERT(!isEmpty()); return removeAt(0); }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeLast()
{
    ZC_ARRAY_ASSERT(!isEmpty());
    if (!isEmpty())
        mLogicalLen--;
    return *this;
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeAll()
{ this->setLogicalLength(0); return *this; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::setGrowLength(int glen)
{ ZC_ARRAY_ASSERT(glen > 0); mGrowLen = glen; return *this; }
#define lowMemBail() ZC_ARRAY_ASSERT(false)

template < class T, class R >
ZcArray< T, R > ::ZcArray(int physicalLength, int growLength)
: mpArray(NULL),
  mPhysicalLen(physicalLength),
  mLogicalLen(0),
  mGrowLen(growLength)
{
    ZC_ARRAY_ASSERT(mGrowLen > 0);
    ZC_ARRAY_ASSERT(mPhysicalLen >= 0);
    if (mPhysicalLen > 0) {
#ifdef GE_LOCATED_NEW
        mpArray = GENEWLOCVEC(T, mPhysicalLen, this) ();
#else
        mpArray = new T[mPhysicalLen];
#endif
        if (mpArray == NULL) {
            mPhysicalLen = 0;
            lowMemBail();
        }
    }
}

template <class T, class R>
ZcArray<T,R>::ZcArray(const ZcArray<T,R>& src)
: mpArray(NULL),
  mPhysicalLen(src.mPhysicalLen),
  mLogicalLen(src.mLogicalLen),
  mGrowLen(src.mGrowLen)
{
    if (mPhysicalLen > 0) {
#ifdef GE_LOCATED_NEW
        mpArray = GENEWLOCVEC(T, mPhysicalLen, this) ();
#else
        mpArray = new T[mPhysicalLen];
#endif
        if (mpArray == NULL) {
            lowMemBail();
            mPhysicalLen = 0;
            mLogicalLen = 0;
        }
    }

    R::reallocateArray(mpArray, src.mpArray, mLogicalLen);
}

template <class T, class R>
ZcArray<T,R>::~ZcArray()
{
    if (mpArray != NULL)
        delete[] mpArray;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::operator = (const ZcArray<T,R>& src)
{
    if (this != &src) {
        if (mPhysicalLen < src.mLogicalLen) {
            if (mpArray != NULL)
                delete[] mpArray;
            mPhysicalLen = src.mLogicalLen;
            
#ifdef GE_LOCATED_NEW
        mpArray = GENEWLOCVEC(T, mPhysicalLen, this) ();
#else
            mpArray = new T[mPhysicalLen];
#endif
            if (mpArray == NULL) { 
                lowMemBail();
                mPhysicalLen = 0;
                mLogicalLen = 0;
                return *this;
            }
        }
        mLogicalLen = src.mLogicalLen;
        R::reallocateArray(mpArray, src.mpArray, mLogicalLen);
    }
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::operator == (const ZcArray<T,R>& cpr) const
{
    if (mLogicalLen == cpr.mLogicalLen) {
        for (int i = 0; i < mLogicalLen; i++)
            if (mpArray[i] != cpr.mpArray[i])
                return false;
        return true;
    }
    return false;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setAll(const T& value)
{
    for (int i = 0; i < mLogicalLen; i++) {
        mpArray[i] = value;
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::append(const ZcArray<T,R>& otherArray)
{
    int otherLen = otherArray.length();
    if (otherLen == 0) {
        return *this;
    }
    int newLen = mLogicalLen + otherLen;
    if (newLen > mPhysicalLen) {
        setPhysicalLength(newLen);
    }

    R::reallocateArray(mpArray + mLogicalLen, otherArray.mpArray, otherLen);
    
    mLogicalLen = newLen;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::insertAt(int index, const T& value)
{
    T  tmp(value);
    ZC_ARRAY_ASSERT(index >= 0 && index <= mLogicalLen);

    if (mLogicalLen >= mPhysicalLen) {
        int growth = (mLogicalLen * sizeof(T)) < ZCARRAY_GROWTH_THRESHOLD ?
            mLogicalLen : ZCARRAY_GROWTH_THRESHOLD / sizeof(T);
        setPhysicalLength(mLogicalLen + __max(growth, mGrowLen));
    }

    if (index != mLogicalLen) {
        ZC_ARRAY_ASSERT(mLogicalLen >= 0);
        T* p = mpArray + mLogicalLen;
        T* pStop = mpArray + index;
        do {
            *p = *(p-1);
        } while (--p != pStop);
    }
    mpArray[index] = tmp;
    mLogicalLen++;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::removeAt(int index)
{
    ZC_ARRAY_ASSERT(isValid(index));

    if (index < mLogicalLen - 1) {
        T* p = mpArray + index;
        T* pStop = mpArray + mLogicalLen - 1;
        do {
            *p = *(p+1);
        } while (++p != pStop);
    }

    ZC_ARRAY_ASSERT(!isEmpty());
    if (!isEmpty())
        mLogicalLen--;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::removeSubArray(int startIndex, int endIndex)
{
    ZC_ARRAY_ASSERT(isValid(startIndex));
    ZC_ARRAY_ASSERT(startIndex <= endIndex);

    if ( endIndex >= mLogicalLen - 1) {
        mLogicalLen = startIndex;
        return *this;
    }

    if (startIndex < mLogicalLen - 1) {
        T* p = mpArray + startIndex;
        T* q = mpArray + endIndex + 1;
        T* pStop = mpArray + mLogicalLen;
        for (; q < pStop; p++, q++ ) {
            *p = *q;
        }
    }
    mLogicalLen -= endIndex - startIndex + 1;
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::find(const T& value, int& index, int start) const
{
    const int nFoundAt = this->findFrom(value, start);
    if (nFoundAt == -1)
        return false;
    index = nFoundAt;
    return true;
}

template <class T, class R> int
ZcArray<T,R>::find(const T& value) const
{
	return this->findFrom(value, 0);   
}

template <class T, class R> int
ZcArray<T,R>::findFrom(const T& value, int start) const
{
	for (int i = start; i < this->mLogicalLen; i++) {
		if (mpArray[i] == value)
			return i;
	}
	return -1;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setLogicalLength(int n)
{
    ZC_ARRAY_ASSERT(n >= 0);
    if (n > mPhysicalLen) {

        int growth = (mPhysicalLen * sizeof(T)) < ZCARRAY_GROWTH_THRESHOLD ?
            mPhysicalLen : ZCARRAY_GROWTH_THRESHOLD / sizeof(T);

        int minSize = mPhysicalLen + __max(growth, mGrowLen);
        if ( n > minSize)
            minSize = n;
        setPhysicalLength(minSize);
    }
    mLogicalLen = (n >= 0) ? n : 0;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setPhysicalLength(int n)
{
    ZC_ARRAY_ASSERT(n >= 0);
    if (n == mPhysicalLen) return *this;
    T* pOldArray = mpArray;

    if (n == 0) { 
        mpArray = NULL;
        mPhysicalLen = 0;
    } else {
#ifdef GE_LOCATED_NEW
        mpArray = GENEWLOCVEC(T, n, this) ();
#else
        mpArray = new T[n];
#endif
        if (mpArray == NULL) {
            lowMemBail();
            mPhysicalLen = 0;
        } else {

            R::reallocateArray(mpArray, pOldArray, ((n < mLogicalLen) ? n : mLogicalLen));
            mPhysicalLen = n;
        }
    }

    if (pOldArray != NULL) { 
        delete[] pOldArray;
    }
    if (mPhysicalLen < mLogicalLen) {
        mLogicalLen = mPhysicalLen;
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::reverse()
{
    for (int i = 0; i < mLogicalLen/2; i++) {
        T tmp = mpArray[i];
        mpArray[i] = mpArray[mLogicalLen - 1 - i];
        mpArray[mLogicalLen - 1 - i] = tmp;
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::swap(int i1, int i2)
{
    ZC_ARRAY_ASSERT(isValid(i1));
    ZC_ARRAY_ASSERT(isValid(i2));

    if (i1 == i2) return *this;

    T tmp = mpArray[i1];
    mpArray[i1] = mpArray[i2];
    mpArray[i2] = tmp;
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::remove(const T& value, int start)
{
    const int i = this->findFrom(value, start);
    if (i == -1)
        return false;
    this->removeAt(i);
    return true;
}
#pragma pack (pop)
#endif
