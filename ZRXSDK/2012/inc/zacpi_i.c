
#pragma warning( disable: 4049 )  


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else 

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif 

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif 

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyInspector,0xBEF8D63E,0xE73E,0x444F,0x86,0x72,0xB8,0x8E,0x0A,0xAC,0xEF,0xC4);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyEditControl,0xD8CD2EE7,0x4411,0x41FE,0xBF,0x2F,0x3B,0x93,0x06,0xD5,0x5F,0xD1);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyEditEventsSink,0xE765A043,0xC70D,0x4F1B,0x83,0xAD,0x62,0x2F,0x5A,0xBB,0x5B,0xA3);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyUnspecified,0x43806682,0xBA4A,0x4605,0xA8,0x8D,0x77,0xE9,0x53,0x83,0x36,0xFA);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyDisplay,0x2617FBDB,0x8353,0x48D8,0x9F,0x52,0x30,0x51,0x8E,0x61,0x8D,0x07);


MIDL_DEFINE_GUID(IID, IID_IZcPiCategorizeProperties,0x6CB44A48,0x5129,0x46DF,0x88,0xD0,0x8E,0x34,0x24,0xA5,0x5A,0x56);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropCommandButtons,0xEA1682CB,0x53E2,0x4AF0,0x91,0xC4,0x43,0x2D,0xA4,0x62,0xA7,0x37);


MIDL_DEFINE_GUID(IID, IID_IZcPiCommandButton,0xFB2C0DD6,0xDBD6,0x4A15,0xB4,0x97,0x34,0xA1,0x80,0x58,0xB8,0xAB);


MIDL_DEFINE_GUID(IID, IID_IZcPiCommandButton2,0x192BFC32,0x8DD2,0x4DA7,0x8A,0x3F,0x8C,0x7C,0xF9,0x35,0xEF,0xAA);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyInspectorEventsSink,0x521A516F,0xD016,0x48EE,0xA9,0x5E,0xD9,0x9E,0x89,0xDF,0xA5,0xBD);


MIDL_DEFINE_GUID(IID, IID_IZcPiPropertyInspectorInputEventSink,0x8EF61F10,0x131E,0x4590,0x9F,0x20,0xD3,0x39,0xBD,0xA8,0x48,0x19);


MIDL_DEFINE_GUID(IID, LIBID_ZCPILib,0xA5459FE9,0xEA12,0x49CB,0x96,0x97,0xE2,0x39,0xD5,0xFB,0x15,0x58);


MIDL_DEFINE_GUID(CLSID, CLSID_ZcPiPropertyInspector,0xE15C2119,0x5054,0x4DB8,0x9F,0x3D,0xCF,0x1B,0x13,0x71,0x08,0x45);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



