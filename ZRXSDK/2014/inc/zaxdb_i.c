

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

MIDL_DEFINE_GUID(IID, LIBID_ZXAUTOLib,0x52A3A019,0xF33C,0x4484,0xBF,0xB0,0x29,0x34,0xC2,0x8F,0xF4,0xDE);

MIDL_DEFINE_GUID(IID, IID_IZcadObject,0x1F0BDC7C,0xA414,0x4A46,0xA4,0xD6,0xAC,0x2A,0x6F,0x8F,0xC3,0x75);

MIDL_DEFINE_GUID(IID, IID_IZcadDictionary,0xF5E44E79,0x30C3,0x484A,0x84,0xAA,0x75,0x2E,0x29,0x75,0x78,0x0A);

MIDL_DEFINE_GUID(IID, IID_IZcadEntity,0x1AF16967,0xB8B3,0x44FD,0x8C,0x3B,0x21,0x06,0x53,0x2E,0xCE,0x68);

MIDL_DEFINE_GUID(IID, IID_IZcadBlock,0xD75A9595,0x306F,0x40AD,0xA6,0xD3,0x49,0x40,0xDE,0x14,0xF9,0x41);

MIDL_DEFINE_GUID(IID, IID_IZcadDatabase,0x1384375E,0xA882,0x4028,0x9C,0x95,0xD4,0xD1,0x20,0x92,0x06,0x6D);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionTypeSettings,0x62BC10FC,0xF2E3,0x4132,0xB2,0xCA,0x75,0x3C,0x79,0x3F,0x1E,0x54);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionTypeSettings2,0xB51F3969,0xDB28,0x49AA,0x81,0x6A,0x41,0xF9,0xFF,0xCE,0x4F,0xFB);

MIDL_DEFINE_GUID(IID, IID_IZcadHyperlink,0x93052458,0xDBCC,0x4870,0xB5,0x3F,0x5D,0x82,0x33,0x32,0x33,0xBC);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHyperlink,0x0C7B7C9D,0x3C48,0x4119,0x85,0xD8,0x72,0xA5,0xAA,0xEE,0x5F,0x5D);

MIDL_DEFINE_GUID(IID, IID_IZcadDynamicBlockReferenceProperty,0x94D6A068,0xA4BD,0x40E7,0xAF,0x87,0x07,0x45,0x15,0xD8,0x14,0x07);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDynamicBlockReferenceProperty,0x1FB68AC9,0x434C,0x46C2,0x91,0x9D,0x7D,0x70,0xA4,0xFB,0x3D,0x4E);

MIDL_DEFINE_GUID(IID, IID_IZcadZcCmColor,0x1C27EDF5,0x101D,0x41AE,0xA6,0x95,0x7E,0xB1,0x50,0x25,0xCF,0xA0);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadZcCmColor,0x4D3DD97B,0xAE75,0x4A00,0xAA,0x33,0xC8,0x0A,0x09,0x25,0xB9,0x43);

MIDL_DEFINE_GUID(IID, IID_IZcadObjectEvents,0xD2B8D07F,0x0CFB,0x47CC,0xAD,0x2C,0x2A,0x1E,0x4D,0xAB,0x3A,0xC2);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadObject,0x019B1433,0xD74E,0x48D7,0xA5,0xDC,0x6F,0x65,0x64,0x0F,0xF4,0x35);

MIDL_DEFINE_GUID(IID, IID_IZcadXRecord,0x00844616,0x8148,0x4826,0x93,0x22,0xCC,0x43,0x6D,0xFD,0x0D,0xF2);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadXRecord,0xA58E766F,0x6A82,0x47EB,0x8B,0x70,0xE0,0xB3,0x5E,0xE6,0x24,0x99);

MIDL_DEFINE_GUID(IID, IID_IZcadSortentsTable,0x1D826D05,0x92DF,0x4E9B,0xB8,0xBD,0x33,0x02,0xD4,0x1E,0x1A,0x35);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSortentsTable,0x01A9A3B5,0x41CA,0x4AF3,0x88,0x13,0x66,0xFF,0xB2,0xDD,0xA0,0x75);

MIDL_DEFINE_GUID(IID, IID_IZcadDimStyle,0x885D3F3C,0x1037,0x45A7,0x85,0x48,0xA4,0xE1,0x8D,0xC3,0xDF,0x1E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimStyle,0x30FD78AB,0xDD69,0x4C55,0x96,0x4C,0x3A,0xEA,0x6E,0xD3,0xB3,0x55);

MIDL_DEFINE_GUID(IID, IID_IZcadLayer,0xB63D150F,0x6B2C,0x46D3,0xA1,0x02,0xC3,0xEA,0x2E,0x02,0x43,0x27);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayer,0xDDDA3FDC,0xBFDD,0x4273,0x81,0x6A,0xDD,0xCA,0xBD,0xD5,0x4E,0x07);

MIDL_DEFINE_GUID(IID, IID_IZcadLineType,0xF91B931B,0x98ED,0x451E,0x9F,0xA2,0x97,0xB3,0xFA,0x52,0xB0,0xE3);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLineType,0x45233A94,0xC88F,0x4F3B,0xB2,0x7B,0x4C,0x62,0x6C,0x60,0xEC,0x4F);

MIDL_DEFINE_GUID(IID, IID_IZcadMaterial,0x7FACF69E,0xA791,0x447F,0xBF,0x8A,0xAD,0x1A,0x1A,0xAD,0x43,0xFB);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMaterial,0x31FE96B1,0x13DB,0x43F8,0xB5,0x2E,0x41,0xE4,0x31,0xDC,0xEA,0x15);

MIDL_DEFINE_GUID(IID, IID_IZcadRegisteredApplication,0x38ABF5AD,0x0E51,0x4DD8,0x92,0xB7,0xA8,0xF2,0xFA,0x5F,0x25,0x05);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRegisteredApplication,0x2C001FE8,0xBDAE,0x4867,0x9B,0x9D,0x7F,0x71,0x96,0xD2,0xD5,0x2F);

MIDL_DEFINE_GUID(IID, IID_IZcadTextStyle,0x1FD1C19E,0x6D3C,0x4255,0xB3,0x3E,0xCF,0xDB,0xC2,0x0F,0x82,0x1A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTextStyle,0x0BC1192F,0x4CBD,0x47DE,0x96,0xD7,0x13,0xAE,0xAE,0x73,0xEF,0xB4);

MIDL_DEFINE_GUID(IID, IID_IZcadUCS,0x700C89D7,0xC6FE,0x4367,0xAF,0xA9,0x9F,0x8B,0x49,0x2A,0xD6,0xEF);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadUCS,0x58BD6393,0x389D,0x4475,0xBB,0x00,0xDF,0x3D,0x91,0xFA,0x91,0xD4);

MIDL_DEFINE_GUID(IID, IID_IZcadView,0xBFDE59F0,0x3C0E,0x4167,0xAE,0x7F,0x74,0x2D,0x52,0xE8,0x25,0x04);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadView,0x8F3F94DE,0xAFC7,0x4823,0x82,0xB6,0x22,0x14,0xF9,0x31,0xD0,0xDF);

MIDL_DEFINE_GUID(IID, IID_IZcadViewport,0x56EF7D8C,0xD7A2,0x40C5,0x95,0xDC,0x0D,0xF9,0x27,0xBC,0xDD,0x45);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadViewport,0x54C6D311,0x849D,0x4D33,0xA1,0x59,0x7A,0xB4,0xB1,0x18,0xC3,0x0A);

MIDL_DEFINE_GUID(IID, IID_IZcadGroup,0xCD5C2408,0x0C64,0x4E98,0xB3,0xBA,0x96,0x18,0x17,0x93,0x17,0xB1);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadGroup,0x3E62E7FC,0xFD66,0x441F,0x98,0xD7,0x58,0x8B,0xFD,0xC2,0x1B,0x5A);

MIDL_DEFINE_GUID(IID, IID_IZcadPlotConfiguration,0x8EB924BD,0x2C5E,0x452F,0xB7,0xC0,0xF7,0x54,0xCE,0x73,0x15,0x1D);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPlotConfiguration,0xCE790806,0x72B9,0x4C2A,0x81,0x0A,0xEF,0x81,0xFD,0xBC,0x91,0xD1);

MIDL_DEFINE_GUID(IID, IID_IZcadLayout,0x32F20089,0x67A4,0x4B05,0xA6,0xC3,0x50,0x3B,0x64,0x9E,0x77,0xC5);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayout,0x7746C86F,0x97BF,0x4B99,0xA8,0xEC,0xF7,0xB4,0x05,0xE2,0x8A,0x7C);

MIDL_DEFINE_GUID(IID, IID_IZcadIdPair,0x0EB1584B,0xD5A9,0x4912,0x84,0xCA,0x99,0x64,0xBD,0x9C,0x5C,0x0E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadIdPair,0x4760DED6,0x4BDE,0x4E35,0x99,0xDB,0xB9,0x60,0x91,0xD9,0x09,0xE0);

MIDL_DEFINE_GUID(IID, IID_IZcadTableStyle,0xCEDE4876,0x6875,0x4BA3,0x8A,0x2A,0x41,0xC1,0xC3,0x92,0xCB,0xA9);

MIDL_DEFINE_GUID(IID, IID_IZcadTableStyle2,0xD835588D,0xBD58,0x4F38,0x9D,0xC4,0x7E,0xB8,0xDD,0x2C,0x52,0x74);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTableStyle,0xB281ACAF,0x1D9C,0x45EF,0xBE,0x45,0xCA,0xF0,0xCB,0x18,0xC7,0x5E);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionSettings,0x704CCDB8,0x051F,0x49FC,0x98,0x46,0x19,0x4B,0x15,0xFA,0x16,0x20);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSectionSettings,0x650AB93A,0x46DC,0x437C,0xB2,0x32,0xBD,0x08,0x49,0x7F,0xFE,0x60);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSectionTypeSettings,0x3309DC7D,0x9422,0x4A90,0xAE,0x3B,0x24,0x65,0x0E,0x3D,0xDF,0xA7);

MIDL_DEFINE_GUID(IID, IID_IZcadMLeaderStyle,0x3FD3ABBD,0x4943,0x4DC1,0xBD,0x50,0x35,0xCA,0xBA,0x81,0x45,0xE5);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLeaderStyle,0x02395E4A,0x6BD7,0x4DC8,0xB1,0xC4,0xDB,0xCD,0x0F,0x23,0x8C,0xE0);

MIDL_DEFINE_GUID(IID, IID_IZcadHyperlinks,0x325172FB,0x255D,0x4B38,0x86,0x44,0xAC,0x42,0x47,0xA1,0xA6,0x30);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHyperlinks,0xA477C235,0x5264,0x43E6,0x98,0xC4,0x98,0x73,0x9D,0x5F,0x43,0x8B);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDictionary,0xF08D9FDA,0x6460,0x4FC9,0xB2,0x0A,0x82,0xB9,0x26,0x1A,0xBC,0x74);

MIDL_DEFINE_GUID(IID, IID_IZcadLayers,0x7F4F112A,0x74C2,0x43F4,0xAA,0x4B,0xDB,0xF9,0xC6,0x08,0x0B,0xA4);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayers,0x2346A7EC,0xC0BA,0x498F,0xB6,0x70,0x34,0x79,0xEC,0xE9,0x85,0x5F);

MIDL_DEFINE_GUID(IID, IID_IZcadDimStyles,0xA5C91436,0xF3AF,0x47C4,0xBE,0x87,0xD7,0xD0,0x13,0xF4,0x4F,0x08);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimStyles,0x5C294D7E,0xF77D,0x4934,0x8B,0xED,0x9B,0x90,0xDC,0x17,0x90,0x84);

MIDL_DEFINE_GUID(IID, IID_IZcadDictionaries,0x022C20F1,0xE3B8,0x48ED,0x87,0x7C,0x95,0xF0,0x27,0x48,0x0B,0x21);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDictionaries,0xA70C867F,0xF8B5,0x4340,0x87,0x30,0x01,0xE2,0x21,0x15,0x8D,0x78);

MIDL_DEFINE_GUID(IID, IID_IZcadLineTypes,0xAD879ADD,0x48CF,0x4A13,0xB3,0x00,0x94,0x18,0x62,0xD7,0xE4,0xA7);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLineTypes,0x4903D5C5,0x2493,0x41D2,0xAB,0x50,0x45,0xFC,0x06,0x5D,0x16,0xF1);

MIDL_DEFINE_GUID(IID, IID_IZcadMaterials,0x6F5B1927,0xE25E,0x450B,0xBB,0x24,0xBA,0xC5,0xA8,0x9C,0xAB,0x7E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMaterials,0x4692BDE3,0x3F55,0x447D,0x83,0x2A,0xE0,0x78,0xFA,0xF6,0x2D,0x2D);

MIDL_DEFINE_GUID(IID, IID_IZcadTextStyles,0xDBB7994D,0xEC95,0x4A2B,0xB9,0x1E,0x2A,0x57,0x7E,0x13,0x9B,0xF8);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTextStyles,0x2AA59DF9,0xEF68,0x4488,0x94,0x1B,0xC4,0x94,0x92,0xAE,0xB0,0x80);

MIDL_DEFINE_GUID(IID, IID_IZcadUCSs,0x24251251,0xC740,0x4DEF,0xB4,0x8A,0x23,0x57,0xB2,0x67,0x49,0xCC);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadUCSs,0x71BE9911,0x2BBD,0x4C1F,0xA2,0xE8,0x44,0xE9,0x68,0x76,0xAA,0xB6);

MIDL_DEFINE_GUID(IID, IID_IZcadRegisteredApplications,0x6CA614E9,0x858D,0x42BA,0x95,0x33,0x97,0xCE,0x15,0x9F,0x96,0x49);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRegisteredApplications,0xB9BA9F06,0x67DA,0x44D6,0x96,0x28,0xCE,0xA0,0x25,0x69,0x4D,0x6B);

MIDL_DEFINE_GUID(IID, IID_IZcadViews,0xEBE6FA11,0x0D18,0x49F2,0xB1,0xD6,0xB2,0xD9,0xCB,0xCF,0x8B,0x04);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadViews,0xE50FC86F,0x690A,0x4D04,0xA3,0xFD,0x0A,0x40,0xB3,0x74,0xF4,0x8C);

MIDL_DEFINE_GUID(IID, IID_IZcadViewports,0xBABFCAB8,0x0033,0x494B,0xA6,0x1F,0x6D,0x77,0xB1,0x9E,0x03,0x8D);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadViewports,0xF733F8AF,0x8BAF,0x4F73,0x9C,0xB4,0x16,0x4A,0x90,0x7A,0x0C,0xE4);

MIDL_DEFINE_GUID(IID, IID_IZcadGroups,0x37CD755D,0x833A,0x4136,0x86,0xD3,0x89,0x22,0x9A,0x78,0x9C,0xB9);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadGroups,0xD584C96C,0x45F6,0x438B,0x9D,0xC6,0xEC,0xE4,0x92,0x72,0xF2,0x44);

MIDL_DEFINE_GUID(IID, IID_IZcadBlocks,0x710175D8,0xBD69,0x4DE3,0x83,0xC5,0x8E,0x4C,0xA3,0xE5,0x1D,0x36);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadBlocks,0xC0B897D8,0x9957,0x4A0E,0x97,0x96,0x34,0xFC,0x2C,0x17,0x7C,0x96);

MIDL_DEFINE_GUID(IID, IID_IZcadLayouts,0x67593343,0x7A76,0x4635,0xBA,0x8A,0x96,0x61,0xB2,0xCE,0x04,0x22);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayouts,0x05C91E01,0xA381,0x416F,0x90,0xC0,0x9E,0x40,0x75,0x01,0x43,0x04);

MIDL_DEFINE_GUID(IID, IID_IZcadPlotConfigurations,0x8FEF7E33,0x9902,0x4C2D,0xAC,0xD9,0xAF,0x94,0x2E,0xF9,0x92,0xDD);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPlotConfigurations,0x6B018147,0x8034,0x44AC,0x82,0xC2,0xF3,0xAF,0xF4,0xB6,0xBA,0x6F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadEntity,0x06EC41B8,0x12A9,0x42E0,0x80,0x9D,0xBF,0x0B,0x18,0xFC,0xD2,0xEF);

MIDL_DEFINE_GUID(IID, IID_IZcadShadowDisplay,0x93397123,0x5E07,0x47EB,0xA6,0xBB,0x62,0xA0,0x31,0xBC,0x44,0x37);

MIDL_DEFINE_GUID(IID, IID_IZcadRasterImage,0xF0E7CD0B,0x25BD,0x43F7,0x85,0x95,0xB8,0x45,0x79,0x7E,0x76,0x0A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRasterImage,0x3637803A,0x8DDF,0x488D,0xAB,0x63,0xD2,0x7F,0xB7,0x63,0xE3,0xB4);

MIDL_DEFINE_GUID(IID, IID_IZcad3DFace,0x938537D7,0x8CF8,0x4992,0xB7,0xDA,0x8C,0x2C,0x0A,0x1B,0xAF,0x22);

MIDL_DEFINE_GUID(CLSID, CLSID_Zcad3DFace,0x1762C266,0x86B0,0x4C70,0xBF,0x07,0x14,0x33,0xD7,0x8A,0x7F,0x26);

MIDL_DEFINE_GUID(IID, IID_IZcad3DPolyline,0x6A6B6D10,0xE788,0x4745,0x90,0x54,0xDC,0x0E,0xEC,0x87,0x93,0xFA);

MIDL_DEFINE_GUID(CLSID, CLSID_Zcad3DPolyline,0x94EA8CE5,0xCAC5,0x40DE,0xAD,0xD3,0xD9,0xCD,0xAA,0x97,0x2E,0xCB);

MIDL_DEFINE_GUID(IID, IID_IZcadRegion,0x273F17C2,0x9089,0x4043,0x8B,0xF8,0xD1,0xCE,0x79,0xC9,0xCC,0x5F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRegion,0xE354A46F,0x4B1A,0x44D6,0x93,0x86,0xB5,0xCE,0x6F,0xF4,0xFD,0x22);

MIDL_DEFINE_GUID(IID, IID_IZcad3DSolid,0xAFBDE899,0x0342,0x4CDB,0xB4,0x2B,0x76,0xAA,0xD9,0xDA,0xE8,0xFE);

MIDL_DEFINE_GUID(CLSID, CLSID_Zcad3DSolid,0xB4B9E142,0x213F,0x4E06,0xB3,0xC1,0x72,0x73,0xC0,0xAC,0x28,0xF9);

MIDL_DEFINE_GUID(IID, IID_IZcadArc,0xD3D6DEA3,0xCE1A,0x46E9,0x8C,0x99,0xFD,0xE1,0x27,0x25,0x24,0x6D);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadArc,0xA1792D80,0xB292,0x4E5E,0x8E,0xCF,0xE8,0x08,0x4D,0xD8,0x9D,0x20);

MIDL_DEFINE_GUID(IID, IID_IZcadAttribute,0xC66BC8E3,0x29FE,0x4484,0xA6,0xDB,0x12,0xB6,0x0D,0x88,0x60,0x0D);

MIDL_DEFINE_GUID(IID, IID_IZcadAttribute2,0xD4CA6CE8,0x1824,0x4CF5,0xAF,0x57,0xC1,0xB5,0x74,0x7A,0x39,0x4C);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadAttribute,0xB032008F,0xAD8F,0x494A,0xB5,0x43,0x08,0xC1,0x4D,0x23,0xDD,0xA5);

MIDL_DEFINE_GUID(IID, IID_IZcadAttributeReference,0x19EE1722,0xF0BE,0x4A6A,0xB6,0x87,0x2C,0xB5,0xA5,0x1E,0xBE,0xEF);

MIDL_DEFINE_GUID(IID, IID_IZcadAttributeReference2,0xBCF188D4,0xD472,0x4F40,0x97,0xF3,0xF1,0xFD,0xEA,0x23,0xD4,0x80);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadAttributeReference,0x8271884B,0xE37E,0x423D,0xB7,0x74,0x31,0x66,0x58,0xA2,0xBC,0x71);

MIDL_DEFINE_GUID(IID, IID_IZcadBlockReference,0xFA31CB90,0x9168,0x4CB5,0xBF,0x3E,0x24,0x41,0xD0,0x0D,0xED,0x2A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadBlockReference,0x5B7F702B,0x8E26,0x4A26,0xB6,0xF3,0xC6,0xDA,0xBB,0xA3,0x35,0x89);

MIDL_DEFINE_GUID(IID, IID_IZcadCircle,0x88FCE675,0x8B2F,0x46FB,0xA6,0xA0,0xD9,0xB2,0xE8,0x8C,0xE5,0xC2);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadCircle,0x346940D6,0x0DEE,0x409B,0x89,0xB9,0xC3,0xFA,0x03,0x91,0x86,0xC8);

MIDL_DEFINE_GUID(IID, IID_IZcadEllipse,0xE589D236,0x9A22,0x49EF,0xAA,0x8B,0xFB,0xF2,0x67,0xB3,0xD9,0x85);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadEllipse,0x1D5FA1D3,0xB16D,0x4D28,0x97,0x58,0x55,0xC6,0xEC,0x55,0xDD,0x4D);

MIDL_DEFINE_GUID(IID, IID_IZcadHatch,0x36B7DF9F,0x5FF3,0x40C4,0xB4,0x1F,0x4F,0xD5,0xF2,0xE1,0x20,0x6D);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHatch,0xB99387A7,0x858A,0x4FD1,0x86,0x58,0x0F,0xD5,0x2B,0x45,0xC6,0x25);

MIDL_DEFINE_GUID(IID, IID_IZcadLeader,0x711287E4,0x45DE,0x475A,0xAF,0x78,0x23,0xA9,0xD0,0xB9,0x52,0x12);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLeader,0xC325C425,0xEF5C,0x4D4A,0xAE,0xB7,0xC8,0x38,0x4B,0x9D,0xE8,0x66);

MIDL_DEFINE_GUID(IID, IID_IZcadMLeader,0x2127696C,0x90E2,0x41EB,0xA8,0xC7,0xBE,0x9C,0x23,0x45,0x82,0x61);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLeader,0xBD98518B,0xF013,0x425A,0xA0,0x63,0xA4,0xF2,0x81,0x23,0xF7,0xE4);

MIDL_DEFINE_GUID(IID, IID_IZcadLWPolyline,0x5A5EB2D8,0x347F,0x4067,0x9F,0x57,0x88,0xFA,0x34,0xED,0xDC,0x71);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLWPolyline,0x912B9D59,0x8DF1,0x4003,0xA5,0x74,0xE2,0x81,0x74,0xF2,0xFC,0xE3);

MIDL_DEFINE_GUID(IID, IID_IZcadLine,0x42984412,0x2F29,0x4966,0xAE,0xFB,0x26,0x0E,0x0A,0x1E,0xAB,0xE8);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLine,0x75E8A37D,0x2A48,0x470C,0x9F,0x22,0xEF,0xC3,0xE6,0xFD,0x18,0x44);

MIDL_DEFINE_GUID(IID, IID_IZcadMText,0xC8CCAF2D,0x9958,0x4C8E,0x97,0x9A,0x62,0xEA,0xB2,0x9F,0x81,0x73);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMText,0xA527D88D,0xE955,0x42CC,0x8D,0x7D,0x9A,0x05,0xC4,0xE8,0x4A,0x02);

MIDL_DEFINE_GUID(IID, IID_IZcadPoint,0x20C6B40D,0x02FF,0x4886,0xA1,0xDD,0xBD,0x57,0x97,0xA5,0xF3,0x88);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPoint,0x5F3CDDE8,0x6E6D,0x4985,0x86,0x35,0x12,0x61,0xA5,0x8C,0x5B,0x1E);

MIDL_DEFINE_GUID(IID, IID_IZcadPolyline,0x2B7D3C97,0x464C,0x46A7,0x8A,0x4A,0x9A,0x59,0x47,0x1D,0x2C,0xAE);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPolyline,0x7A2BE793,0x9360,0x48F6,0x80,0x14,0x82,0xAF,0x3C,0x84,0x18,0xC7);

MIDL_DEFINE_GUID(IID, IID_IZcadPolygonMesh,0xA1148365,0xC9CF,0x46DD,0xA3,0xCC,0x81,0xC7,0xDC,0xF0,0x4E,0xD0);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPolygonMesh,0xFC563955,0x413A,0x4E1C,0x89,0xA4,0xA4,0xCE,0x0A,0x3F,0xDD,0xEB);

MIDL_DEFINE_GUID(IID, IID_IZcadRay,0x7EC24848,0xB3C8,0x480E,0x96,0xB1,0x30,0x63,0xDF,0xE3,0x78,0x14);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRay,0x1E4DA279,0xD75A,0x4083,0x93,0xE1,0x0B,0xA9,0x18,0x1F,0x55,0x37);

MIDL_DEFINE_GUID(IID, IID_IZcadShape,0x39DC9A61,0x363C,0x43A7,0xB0,0xAA,0xA6,0x8C,0x3F,0x86,0x8D,0x37);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadShape,0x44BBE389,0xEE17,0x4B1D,0xB3,0x4F,0xE9,0x49,0xF6,0xE4,0x75,0xE6);

MIDL_DEFINE_GUID(IID, IID_IZcadSolid,0xD39AA5FC,0x47B2,0x4E19,0xB1,0x06,0x04,0x6F,0xA5,0x36,0x95,0xC1);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSolid,0x8F18735A,0x50CF,0x4D66,0xA2,0x56,0x3E,0xE2,0xB7,0x3D,0xF7,0x84);

MIDL_DEFINE_GUID(IID, IID_IZcadSpline,0xC0596926,0xEF09,0x4E26,0xAC,0x67,0xB0,0x47,0x8F,0x9F,0x25,0x06);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSpline,0xA65E518E,0x2FE7,0x49E6,0xB5,0x18,0x53,0xB3,0x4F,0xCF,0x70,0x84);

MIDL_DEFINE_GUID(IID, IID_IZcadText,0x3EC099A1,0xBEFE,0x42FF,0xBC,0xDF,0x02,0xFE,0xDF,0x55,0xE8,0x6C);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadText,0xDAB9566B,0x7E6D,0x4B68,0xA0,0x63,0x34,0xEA,0x83,0xA2,0x5D,0xD7);

MIDL_DEFINE_GUID(IID, IID_IZcadTolerance,0xB8430914,0xDE6B,0x4123,0x82,0x25,0x5D,0x3E,0x89,0x5A,0x3D,0xB0);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTolerance,0x38FE9A03,0x9697,0x4ADA,0xAC,0x43,0x5A,0xE4,0x58,0x2A,0xEB,0xCE);

MIDL_DEFINE_GUID(IID, IID_IZcadTrace,0xD92E8C74,0x2599,0x4342,0x94,0xDA,0x5A,0xCB,0xD5,0x8A,0xEF,0xBE);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTrace,0x9D726F7D,0x0FBB,0x4E65,0xB5,0xFB,0x98,0x4A,0x07,0x2C,0x4D,0xED);

MIDL_DEFINE_GUID(IID, IID_IZcadXline,0x6E45F9E5,0xB527,0x4C7B,0xBE,0xC6,0xF3,0x7C,0x9E,0xA9,0xF7,0xE3);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadXline,0xB26B6C84,0x112B,0x49B6,0xBC,0x78,0xED,0x26,0x91,0x75,0x81,0x62);

MIDL_DEFINE_GUID(IID, IID_IZcadPViewport,0x771B7A67,0x3D1C,0x431D,0xBE,0x61,0xD0,0xBC,0x22,0xFF,0x56,0x3A);

MIDL_DEFINE_GUID(IID, IID_IZcadPViewport2,0xBCD0F547,0x839B,0x4684,0xA0,0x01,0xD1,0x45,0x77,0xBC,0xB5,0x28);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPViewport,0xBDCC2112,0xFCF4,0x4D41,0x89,0x0D,0x91,0xEA,0xAA,0xA0,0x4F,0xD7);

MIDL_DEFINE_GUID(IID, IID_IZcadMInsertBlock,0xF2776CD1,0xD55B,0x4B6D,0xB2,0x6A,0xB5,0x1C,0xD9,0xAC,0xD9,0x24);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMInsertBlock,0xFE9E099C,0xAECE,0x45C2,0x80,0x90,0x00,0x10,0x83,0x16,0xFD,0x71);

MIDL_DEFINE_GUID(IID, IID_IZcadPolyfaceMesh,0x7E33D3A5,0x98E1,0x42EF,0x87,0x81,0x34,0x16,0x18,0xC9,0x21,0x54);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPolyfaceMesh,0xF362DF64,0xE27B,0x4CDE,0x98,0xF7,0x3A,0x86,0x6D,0x8D,0xB9,0x91);

MIDL_DEFINE_GUID(IID, IID_IZcadMLine,0xB940FBCC,0xAD44,0x4A75,0xBC,0xB6,0x2C,0x99,0xAF,0x3E,0x89,0x5C);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLine,0xA7C41B75,0xF95C,0x44DF,0xAF,0xCC,0x32,0x25,0x27,0xEC,0xE4,0x71);

MIDL_DEFINE_GUID(IID, IID_IZcadExternalReference,0xD8A874BD,0xEB61,0x44B1,0x8A,0x96,0x58,0xED,0x03,0xE2,0x69,0x3A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadExternalReference,0xA6AE9066,0x6934,0x4902,0xB1,0x3A,0x7B,0xFF,0x12,0x92,0x92,0x10);

MIDL_DEFINE_GUID(IID, IID_IZcadTable,0x98D0740D,0xFF8E,0x410E,0x98,0x97,0xA0,0xA8,0xBA,0xBC,0xC0,0xD9);

MIDL_DEFINE_GUID(IID, IID_IZcadTable2,0x20012BE2,0x43D0,0x433F,0xB5,0x04,0xB2,0x3A,0xBD,0x16,0x5A,0xB5);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTable,0x80A83D27,0x6160,0x48A5,0xBC,0x37,0xE5,0xE2,0x20,0x43,0xF7,0x23);

MIDL_DEFINE_GUID(IID, IID_IZcadOle,0x1965EED0,0xC199,0x4AC6,0xB1,0x9C,0x02,0x0E,0x68,0xE5,0x75,0xA2);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadOle,0xBF9915A1,0x6482,0x4FF9,0xA0,0xE6,0x30,0xEB,0x30,0x1C,0x2C,0x34);

MIDL_DEFINE_GUID(IID, IID_IZcadHelix,0x56F42749,0xA82E,0x4F6A,0xA4,0xF3,0x39,0x7B,0x88,0x60,0xA2,0x9E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHelix,0x195B2396,0x9589,0x46A2,0xA5,0xF3,0xA4,0x62,0x85,0x35,0x75,0xED);

MIDL_DEFINE_GUID(IID, IID_IZcadSurface,0xF08D4A0E,0x2D64,0x4C04,0xAC,0x09,0x87,0x7D,0x82,0xB7,0xDB,0x88);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSurface,0x4BDCE115,0x3118,0x445B,0x89,0x50,0x10,0xFB,0x91,0x5D,0xA7,0xEA);

MIDL_DEFINE_GUID(IID, IID_IZcadPlaneSurface,0x6CB8ABB6,0x9329,0x4F15,0xAF,0x58,0xE9,0x20,0xA2,0xD3,0x83,0x9A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPlaneSurface,0x3B2B1199,0xA29D,0x4E56,0xB1,0x2B,0x83,0x9B,0x0E,0x6D,0xA0,0x70);

MIDL_DEFINE_GUID(IID, IID_IZcadExtrudedSurface,0xCCB941E8,0x69E3,0x4926,0xAE,0xE5,0x43,0xB3,0x0D,0x35,0xE1,0xAD);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadExtrudedSurface,0x4D064CC7,0x2027,0x4307,0x84,0xE4,0xE0,0x6A,0xEA,0x5B,0xC8,0x66);

MIDL_DEFINE_GUID(IID, IID_IZcadRevolvedSurface,0xDDB92F5D,0x3D4A,0x4F80,0xBB,0xAA,0xE5,0xBD,0x72,0x06,0xF0,0x0E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRevolvedSurface,0x1264D1BD,0xAFA7,0x43A5,0x8B,0x18,0xA6,0x7A,0xBC,0x84,0xAF,0x78);

MIDL_DEFINE_GUID(IID, IID_IZcadSweptSurface,0x43949A55,0xD6BD,0x4D05,0x92,0xE8,0x10,0x82,0x0D,0x91,0x70,0x57);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSweptSurface,0x4EDF8FCF,0xB67D,0x4B7E,0xAB,0x57,0x39,0x38,0xD0,0x4F,0x27,0xA1);

MIDL_DEFINE_GUID(IID, IID_IZcadLoftedSurface,0x6AF68CD2,0x4810,0x4795,0x9B,0xA7,0x52,0x7E,0x74,0x2D,0xB9,0xA6);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLoftedSurface,0x12973215,0xFD58,0x4538,0xB5,0x0E,0xA2,0x83,0x58,0xC3,0x17,0x38);

MIDL_DEFINE_GUID(IID, IID_IZcadSection,0xEB54FA9E,0x8DF7,0x4903,0x91,0x6D,0x56,0xB3,0x53,0x65,0x2E,0x8C);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSection,0x3525AEA2,0xE6A3,0x4EF7,0xB7,0x65,0x61,0x8B,0xFE,0x11,0x8F,0x6E);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionManager,0x9A1F7185,0x9C01,0x4F9D,0xB6,0x8E,0xE0,0x02,0x63,0xE6,0xF6,0x92);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSectionManager,0x1F9B13E2,0x2E3C,0x4B99,0xAF,0x18,0x67,0xF7,0xDD,0x8B,0x23,0xAC);

MIDL_DEFINE_GUID(IID, IID_IZcadUnderlay,0x8A36ABEA,0xF8C2,0x4A39,0x99,0xD4,0x17,0x42,0x38,0x41,0x74,0x0C);

MIDL_DEFINE_GUID(IID, IID_IZcadUnderlay2,0xA9BFA946,0x5053,0x4B82,0xBA,0xD5,0x52,0xF0,0x81,0xCA,0x75,0x65);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDwfUnderlay,0xA249F921,0xA8F8,0x4D94,0xBA,0x24,0x29,0xE7,0xD6,0xB1,0xA9,0x1F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDgnUnderlay,0xF779D165,0x9A0A,0x4482,0xB1,0x8D,0xF9,0x40,0x59,0xE3,0xCB,0x4A);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntity,0x494C600F,0xEFDA,0x4379,0x91,0x40,0xFA,0x43,0xE5,0xF7,0x2E,0xAA);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntity,0xD8F80288,0x9908,0x4A85,0xBF,0xFD,0x7C,0xE9,0x28,0x6D,0x98,0x51);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidFace,0xB2B924B8,0xC431,0x4BD7,0x88,0x51,0x4C,0xB5,0x61,0x5A,0xD5,0x7F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidFace,0x605545E6,0x33F8,0x47E0,0x8B,0xEA,0x89,0x40,0x8A,0x7C,0x58,0xF5);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidEdge,0xA6EAD337,0x2B4F,0x47EC,0x88,0xCE,0xBF,0x97,0xB6,0xF1,0x62,0x6A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidEdge,0xCF87BFC2,0x79B4,0x42FA,0xAF,0x13,0x13,0x99,0x6F,0xA6,0xB4,0xCC);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidVertex,0x16E13F14,0x6C3D,0x493E,0x97,0x22,0x40,0xAE,0xFA,0x0A,0xD2,0xC0);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidVertex,0x8181103F,0x3C4F,0x4516,0x81,0x0F,0x57,0x44,0x4B,0x68,0x0F,0x3F);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidNode,0x8153157B,0xC750,0x4788,0xA3,0x3D,0x96,0xAD,0xE0,0x37,0xF8,0x7F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidNode,0xC87E3A37,0xF999,0x432D,0xA7,0x1A,0x31,0xE5,0x01,0xFE,0xD5,0x2B);

MIDL_DEFINE_GUID(IID, IID_IZcadDimension,0x219A88E0,0x9E35,0x4028,0xB0,0xFD,0x0F,0xA1,0x86,0x97,0x44,0x44);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimension,0x7B8D17B4,0xE162,0x41DE,0xBC,0x28,0xDE,0x86,0x9E,0x94,0xBC,0xD9);

MIDL_DEFINE_GUID(IID, IID_IZcadDimAligned,0x6D60F482,0x17A8,0x4E16,0x8C,0x8E,0x5D,0x3F,0x00,0x09,0x54,0xAF);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimAligned,0x0D1E01F4,0x3EB8,0x4B7C,0xB6,0x44,0x42,0x59,0x03,0x3F,0x33,0x85);

MIDL_DEFINE_GUID(IID, IID_IZcadDimAngular,0x91926943,0x548D,0x43D5,0xBC,0xC0,0x85,0xA8,0x39,0xE0,0x0D,0xF0);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimAngular,0x6531379F,0x4732,0x49D3,0x88,0x3B,0x45,0x55,0x1A,0xAD,0x50,0xF0);

MIDL_DEFINE_GUID(IID, IID_IZcadDimDiametric,0x8F6E2C0B,0xBCC9,0x46E9,0xB5,0xEE,0xAD,0x76,0xAD,0xEB,0xBE,0x75);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimDiametric,0xA43D66F7,0x776B,0x4AB0,0xB3,0xFB,0xE5,0x53,0xC2,0xD0,0x43,0x22);

MIDL_DEFINE_GUID(IID, IID_IZcadDimOrdinate,0xA0CE5F79,0x1B2D,0x4B91,0xA6,0xA0,0xE2,0x96,0x14,0x33,0xC5,0x76);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimOrdinate,0x533E0400,0x5EC4,0x4249,0x8D,0xF9,0x06,0xCE,0x67,0x3F,0x7D,0x34);

MIDL_DEFINE_GUID(IID, IID_IZcadDimRadial,0xC09975E0,0x7D17,0x4440,0x83,0xC3,0x63,0xA7,0x22,0x6F,0x8C,0x76);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimRadial,0x3FC6B4CB,0x92C8,0x4488,0xA0,0x2D,0x3C,0x3E,0x98,0xE6,0xD6,0x9E);

MIDL_DEFINE_GUID(IID, IID_IZcadDimRotated,0x6E5CABA9,0x64D1,0x424A,0x88,0x8C,0xF7,0x4B,0xB2,0xF4,0x2F,0x4F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimRotated,0x0C78C87C,0x5100,0x4181,0xB4,0x77,0xFF,0x5B,0xC5,0xA7,0x0C,0x27);

MIDL_DEFINE_GUID(IID, IID_IZcadDim3PointAngular,0xB86E9D3D,0x9F39,0x47C8,0x95,0xF6,0x2A,0x5D,0x6A,0x63,0x3F,0x15);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDim3PointAngular,0x55B44F8A,0x7A3D,0x4CE2,0xB3,0x15,0xC0,0xA7,0x24,0x1D,0xF9,0x25);

MIDL_DEFINE_GUID(IID, IID_IZcadDimArcLength,0x9EC93416,0x53E6,0x40F3,0xB8,0xDD,0xF0,0x0C,0x31,0xF6,0xAB,0xDA);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimArcLength,0xE1F41283,0xF7FE,0x4FEC,0x83,0xDA,0x95,0x58,0x29,0x1B,0x11,0x1C);

MIDL_DEFINE_GUID(IID, IID_IZcadDimRadialLarge,0x9542AD17,0xAC36,0x4429,0xB5,0x32,0x64,0x00,0x65,0x18,0x4D,0xBF);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimRadialLarge,0x8F29C0B8,0x23AC,0x41B1,0x84,0x73,0x70,0x95,0x46,0xB7,0x8C,0xF6);

MIDL_DEFINE_GUID(IID, IID_IZcadBlock2,0x4E0A782B,0xB09D,0x499B,0xA3,0x3F,0xFB,0x8B,0x5A,0x56,0x37,0xB0);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadBlock,0x7FE71A14,0x6892,0x4335,0x81,0x39,0xCA,0x7D,0x98,0xFC,0xB9,0xB7);

MIDL_DEFINE_GUID(IID, IID_IZcadModelSpace,0x3436A940,0xA81D,0x489A,0x87,0xDF,0xCE,0xB6,0x7B,0x58,0x24,0x61);

MIDL_DEFINE_GUID(IID, IID_IZcadModelSpace2,0x16433508,0x562D,0x4F2B,0xB6,0x87,0x26,0x94,0x22,0x22,0x92,0x7F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadModelSpace,0xA70660E3,0xC38D,0x4BFB,0xAE,0x29,0xAC,0x52,0x70,0xB4,0x50,0x5E);

MIDL_DEFINE_GUID(IID, IID_IZcadPaperSpace,0x5B43C7B6,0xD462,0x41FD,0x8B,0xCF,0x60,0xCC,0x14,0x46,0x2A,0x85);

MIDL_DEFINE_GUID(IID, IID_IZcadPaperSpace2,0x60C4242E,0x387C,0x4DCD,0x81,0x30,0x44,0x8D,0xE8,0x90,0xB8,0x05);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPaperSpace,0x35D011C7,0xB1F0,0x48F6,0xAC,0xAF,0xBF,0xA8,0xFC,0xBF,0x56,0xE9);

MIDL_DEFINE_GUID(IID, IID_IZcadFileDependency,0xDE5DB094,0xB713,0x44C8,0x96,0xC8,0x1D,0x86,0x85,0xF3,0x37,0x5E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadFileDependency,0x9494DA01,0x220B,0x4062,0x8F,0x67,0xAB,0xB6,0xA1,0xE2,0xC6,0x8A);

MIDL_DEFINE_GUID(IID, IID_IZcadFileDependencies,0x439CFCED,0x9548,0x4C0B,0x88,0x55,0x28,0x96,0x97,0x6D,0xDB,0xFD);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadFileDependencies,0x7C523094,0xC5C3,0x4545,0x8A,0x8D,0x8D,0xA7,0x73,0x60,0xA6,0x8F);

MIDL_DEFINE_GUID(IID, IID_IZcadSummaryInfo,0x2507893E,0xF4D0,0x418B,0xA3,0x2F,0xAB,0x2A,0x2D,0x94,0x34,0x7E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSummaryInfo,0x0AE8D6DF,0x6A9C,0x4DFB,0xBB,0x8A,0xA2,0xE0,0x4D,0xC7,0x67,0x0A);

MIDL_DEFINE_GUID(IID, IID_IZcadDatabasePreferences,0xF1479B77,0x601F,0x4CAC,0x87,0xBD,0xFA,0x9F,0xF8,0xE8,0xA0,0x1D);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDatabasePreferences,0x2C90F3D1,0xC43D,0x4155,0xA9,0x69,0x17,0x6E,0xD1,0xA4,0xAD,0xAE);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDatabase,0x4BCE0A18,0x2864,0x4349,0xB8,0x3C,0xF5,0x4D,0xC1,0x76,0xDF,0xA0);

MIDL_DEFINE_GUID(IID, IID_IZcadSecurityParams,0x23556A56,0x99A7,0x49FB,0x92,0x93,0x33,0xF1,0x7A,0xFA,0x16,0x60);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSecurityParams,0x2E50B35D,0x3372,0x45E1,0xA2,0xA4,0x6C,0x09,0x5F,0x03,0x51,0x45);

MIDL_DEFINE_GUID(IID, IID_IZcadLayerStateManager,0x5FD6A5CA,0xC4C7,0x4860,0x8C,0x99,0x8E,0x2D,0xA9,0x6E,0xD3,0xF1);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayerStateManager,0x0E22CD9D,0x61E9,0x4BBA,0x84,0x80,0xA3,0xD3,0x30,0xAE,0xEC,0x41);

MIDL_DEFINE_GUID(IID, IID_IZxDbDocumentEvents,0x49C74794,0x57FD,0x4CAF,0xB7,0xC6,0xCC,0x4F,0x33,0x34,0xC7,0x21);

MIDL_DEFINE_GUID(IID, IID_IZxDbDocument,0x5504A533,0x4C4C,0x476D,0x83,0xE6,0x32,0x09,0xC0,0x6F,0x0F,0xFA);

MIDL_DEFINE_GUID(CLSID, CLSID_ZxDbDocument,0x975D92D6,0xA4F9,0x438A,0x85,0x18,0x6E,0xE3,0x8C,0xE2,0x76,0xDA);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif


