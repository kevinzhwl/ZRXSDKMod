
#pragma once

#ifndef ZDBSURF_H
#define ZDBSURF_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zdbbody.h"
#include "zdbRevolveOptions.h"
#include "zdbSweepOptions.h"
#include "zdbLoftOptions.h"

#pragma pack(push, 8)

class ZcDbSurface: public ZcDbEntity
{
public:
    ZcDbSurface();
    virtual ~ZcDbSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbSurface);
    static Zcad::ErrorStatus createFrom ( const ZcDbEntity* pFromEntity,
                                          ZcDbSurface*& pNewSurface );
    virtual Zcad::ErrorStatus convertToRegion ( ZcArray<ZcDbEntity*>& regions );
    virtual Zcad::ErrorStatus thicken(double thickness,
        bool bBothSides, ZcDb3dSolid*& pSolid) const;

    virtual Zcad::ErrorStatus getArea(double& area) const;

    virtual void* body() const;
    virtual Zcad::ErrorStatus setBody(const void* modelerBody);
    virtual ZcDbSubentId internalSubentId(void* ent) const;
    virtual void* internalSubentPtr(const ZcDbSubentId& id) const;
    virtual void list() const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
	virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual ZSoft::UInt16       uIsolineDensity() const;
    virtual Zcad::ErrorStatus   setUIsolineDensity(ZSoft::UInt16 numIsolines);

    virtual ZSoft::UInt16       vIsolineDensity() const;
    virtual Zcad::ErrorStatus   setVIsolineDensity(ZSoft::UInt16 numIsolines);
};

#pragma pack(pop)

#endif 
