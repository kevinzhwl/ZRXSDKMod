

#ifndef   _ZSOFT_H
#define   _ZSOFT_H

#pragma pack (push, 8)

struct ZSoft
{

    typedef char       Int8;
    typedef short      Int16;
    typedef long       Int32;
	typedef __int64	   Int64;

    typedef unsigned char  UInt8;
    typedef unsigned short UInt16;
    typedef unsigned long  UInt32;
	typedef unsigned __int64 UInt64;

    typedef unsigned char  uchar;
    typedef unsigned short ushort;
    typedef unsigned int   uint;
    typedef unsigned long  ulong;

#ifndef _WIN64

    typedef __w64 long          LongPtr;
    typedef __w64 unsigned long ULongPtr;
    
    typedef __w64 int           IntPtr;
    typedef __w64 unsigned int  UIntPtr;
#else   
    typedef __int64             LongPtr;
    typedef unsigned __int64    ULongPtr;
    typedef __int64             IntPtr;
    typedef unsigned __int64    UIntPtr;
#endif

    typedef LongPtr IntDbId;
    typedef IntPtr GsMarker;

#ifndef ZSoft_Boolean_is_bool
    typedef int        Boolean;
    enum           { kFalse = 0, kTrue = 1 };
#else
    typedef bool       Boolean;
    enum           { kFalse = false, kTrue = true };
#endif
};

#ifndef NULL
#define NULL 0
#endif

#pragma pack (pop)
#ifdef _UNICODE
#else
typedef          char    ZTCHAR;
#endif
typedef          char         LEGACY_CHAR;
typedef          char*        LEGACY_STRING;
typedef const    char*        LEGACY_STRING_CONST;
typedef       unsigned short  WIDE_CHAR;          
typedef       unsigned short* WIDE_STRING;        
typedef const unsigned short* WIDE_STRING_CONST;  

typedef          char*   MEMORY_POINTER;
typedef const    char*   MEMORY_POINTER_CONST;

typedef unsigned char    ZC_BYTE;

#define ZSOFT_NO_VTABLE __declspec(novtable)
#define ZSOFT_STDCALL   __stdcall
#define ZSOFT_DEPRECATED __declspec(deprecated)

#endif
