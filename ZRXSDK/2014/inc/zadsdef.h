

#ifndef _zdsdef_h
#define _zdsdef_h 1
#include "zAdAChar.h"

#define TRUE    1
#define FALSE   0
#ifndef EOS
#define EOS     ZCRX_T('\0')
#endif

#pragma pack(push, 8)

typedef double   zds_real;
typedef zds_real zds_point[3];
#ifndef _WIN64
typedef __w64 long zds_name[2];
typedef __w64 long *zds_namep;
#else
typedef __int64 zds_name[2];
typedef __int64 *zds_namep;
#endif
typedef zds_real zds_matrix[4][4];

typedef zds_real *zds_pointp;

#ifdef X
#undef X
#endif
#ifdef Y
#undef Y
#endif
#ifdef Z
#undef Z
#endif
#ifdef T
#undef T
#endif

#ifndef _XYZT_DEFINED
#define _XYZT_DEFINED
enum { X = 0, Y = 1, Z = 2 }; 
enum { T = 3 };               
#endif 

#define PAUSE ZCRX_T("\\")

enum {
    RSG_NONULL      = 0x01,  
    RSG_NOZERO      = 0x02,  
    RSG_NONEG       = 0x04,  
    RSG_NOLIM       = 0x08,  
    RSG_GETZ        = 0x10,  
    RSG_DASH        = 0x20,  
                             
    RSG_2D          = 0x40,  
                             
    RSG_OTHER       = 0x80,  
    RSG_DDISTFIRST  = 0x100,
    RSG_TRACKUCS    = 0x200,

    RSG_NOORTHOZ    = 0x400,

    RSG_NOOSNAP     = 0x800
};

enum {
    INP_NNULL   = RSG_NONULL,
    INP_NZERO   = RSG_NOZERO,
    INP_NNEG    = RSG_NONEG,
    INP_NLIM    = RSG_NOLIM,
    INP_DASH    = RSG_DASH,
    INP_NZCOORD = RSG_2D
};

enum SelectorType {
    SELECT_TYPE_FREE = 0,
    SELECT_TYPE_PICK,
    SELECT_TYPE_WPOLY,
    SELECT_TYPE_CPOLY,
    SELECT_TYPE_FENCE,
    SELECT_TYPE_SUBENTITY,
    SELECT_TYPE_BAG,
    SELECT_TYPE_LAST,
    SELECT_TYPE_LEAF,
    SELECT_TYPE_GROUP,
    SELECT_TYPE_PASTE,
    SELECT_TYPE_HATCHASC,
    SELECT_TYPE_NRVP,
    SELECT_TYPE_OCCLASS
};

struct zds_binary {    
    short clen;        
    char *buf;         
};

union zds_u_val {
    zds_real rreal;
    zds_real rpoint[3];
    short rint;
    ZTCHAR *rstring;
#ifndef _WIN64
    __w64 long  rlname[2];
    __w64 long  mnLongPtr;
#else
    __int64     rlname[2];
    __int64     mnLongPtr;
#endif
    long rlong;
    __int64     mnInt64;
    struct zds_binary rbinary;
    unsigned char ihandle[8];
};

struct resbuf {
        struct resbuf *rbnext;
        short restype;
        union zds_u_val resval;
};

typedef struct resbuf *pResbuf;
typedef const struct resbuf *kpResbuf;  

#pragma pack(pop)

#endif
