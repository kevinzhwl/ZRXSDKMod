

#pragma once

#include "zacdb.h"

class ZcGiLineAttrUtils
{
public:
    static char __stdcall zcgiLineWeightToIndex(ZcDb::LineWeight lw);
    static ZcDb::LineWeight __stdcall zcgiIndexToLineWeight(char index);
};
