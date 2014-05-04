
#ifndef _zcedsubsel_h
#define _zcedsubsel_h 1

#pragma once

class ZcDbFullSubentPath;

#include "zacarray.h"
#include "zacdb.h"
#include "zadsdef.h"

#pragma pack (push, 8)

int            zcedSSSubentLength (const zds_name sname, long index, long* len);

int            zcedSSSubentAdd    (const ZcDbFullSubentPath& subentity,
                                   const zds_name sname,
                                   zds_name result);

int            zcedSSSubentDel    (const ZcDbFullSubentPath& subentity,
                                   const zds_name ss);

int            zcedSSSubentMemb   (const ZcDbFullSubentPath& subentity,
                                   const zds_name ss);

int            zcedSSSubentName   (const zds_name ss,
                                   long entIndex,
                                   long subentIndex,
                                   ZcDbFullSubentPath& subentity);

int            zcedSSSubentNameX  (struct resbuf** rbpp,
                                   const zds_name ss,
                                   const long entIndex,
                                   const long subentIndex,
                                   unsigned int flags);

int            zcedSSSetSubentTypes(const ZcArray<ZcDb::SubentType>& types);

#pragma pack (pop)
#endif  
