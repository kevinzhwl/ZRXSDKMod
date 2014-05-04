

#ifndef _ZCEDSEL_H
#define _ZCEDSEL_H

#include "zAcArray.h"
#include "zdbid.h"
#include "zdbsubeid.h"
#pragma pack (push, 8)

class ZcEdSolidSubentitySelector
{
public:
    ZcEdSolidSubentitySelector();
    ~ZcEdSolidSubentitySelector();

    Zcad::ErrorStatus selectFaces(ZcDbObjectId& selectedSolidId, 
        ZcArray<ZcDbSubentId *>& faceSet);
};

#pragma pack (pop)
#endif 
