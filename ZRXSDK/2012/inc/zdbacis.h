

#ifndef ZDB_API_DBACIS_H
#define ZDB_API_DBACIS_H

#include "zacdb.h"
#pragma pack (push, 8)

class ZcDbDwgFiler;
class ZcDbDxfFiler;
class ENTITY;

extern "C"
{
	void zcdbModelerStart();
	void zcdbModelerEnd();
	ZSoft::Boolean zcdbIsModelerStarted();

    Zcad::ErrorStatus zcdbAcisSaveEntityToDwgFiler     (ZcDbDwgFiler* filer, 
							ENTITY*       ent);
    Zcad::ErrorStatus zcdbAcisRestoreEntityFromDwgFiler(ZcDbDwgFiler* filer, 
							ENTITY*&      ent);
    Zcad::ErrorStatus zcdbAcisSaveEntityToDxfFiler     (ZcDbDxfFiler* filer, 
                            ENTITY*       ent); 
    Zcad::ErrorStatus zcdbAcisRestoreEntityFromDxfFiler(ZcDbDxfFiler* filer, 
                            ENTITY*&      ent);

    void           zcdbAcisSetDeleteBulletins(ZSoft::Boolean onOff);
    ZSoft::Boolean zcdbAcisGetDeleteBulletins();

	ZSoft::Boolean zcdbSetAcisDwgVer(int version);

    void           zcdbAcisDeleteModelerBulletins(void);
}

#define zcdbSaveAcisEntityToDwgFiler      zcdbAcisSaveEntityToDwgFiler
#define zcdbRestoreAcisEntityFromDwgFiler zcdbAcisRestoreEntityFromDwgFiler

#pragma pack (pop)
#endif
