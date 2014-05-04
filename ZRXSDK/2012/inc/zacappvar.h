

#ifndef ZCAPPVAR_H
#define ZCAPPVAR_H

#include "zacdb.h"
#pragma pack (push, 8)

enum {
    kGroupsOn     = 0x01,
    kHatchAssocOn = 0x02
};

class ZcDbAppSystemVariables {
public:
    inline ZcDbAppSystemVariables();
    inline ~ZcDbAppSystemVariables() {};
    Zcad::ErrorStatus setAttdia(bool value, bool bUndo = false);
    inline bool attdia() const;
    Zcad::ErrorStatus setAttreq(bool, bool bUndo = false);
    inline bool attreq() const;
    Zcad::ErrorStatus setBlipmode(bool, bool bUndo = false);
    inline bool blipmode() const;
    Zcad::ErrorStatus setCoords(ZSoft::Int16 value, bool bUndo = false);
    inline ZSoft::Int16 coords() const;
    Zcad::ErrorStatus setDelUsedObj(ZSoft::Int16, bool bUndo = false);
    inline ZSoft::Int16 delUsedObj() const;
    Zcad::ErrorStatus setDragmode(ZSoft::Int16, bool bUndo = false);
    inline ZSoft::Int16 dragmode() const;
    Zcad::ErrorStatus setOsmode(ZSoft::Int16 value, bool bUndo = false);
    inline ZSoft::Int16 osmode() const;
    Zcad::ErrorStatus setPickstyle(ZSoft::Int16 value, bool bUndo = false);
    inline ZSoft::Int16 pickstyle() const;
    Zcad::ErrorStatus setLwdefault(ZcDb::LineWeight value, bool bUndo = false);
    inline ZcDb::LineWeight lwdefault() const;
    Zcad::ErrorStatus setHpassoc(bool value, bool bUndo = false);
    inline bool hpassoc() const;

private:
    bool m_attdia;
    bool m_attreq;
    bool  m_blipmode;
    short m_delobj;
    short m_coords;
    short m_dragmode;
    short m_osmode;
    short m_pkstyle;
    ZcDb::LineWeight  m_lwdefault;
    bool  m_hpassoc;
};

inline
ZcDbAppSystemVariables::ZcDbAppSystemVariables()
: m_attdia(false),
  m_attreq(true),
  m_blipmode(false),
  m_delobj(-1),
  m_coords(0),
  m_dragmode(2),
  m_osmode(0),
  m_pkstyle(kGroupsOn),
  m_lwdefault(ZcDb::kLnWt025),
  m_hpassoc(1)
{
}

inline bool ZcDbAppSystemVariables::attdia() const
{
    return m_attdia;
}

inline bool ZcDbAppSystemVariables::attreq() const
{
    return m_attreq;
}

inline bool ZcDbAppSystemVariables::blipmode() const
{
    return m_blipmode;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::coords() const
{
    return m_coords;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::delUsedObj() const
{
    return m_delobj;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::dragmode() const
{
    return m_dragmode;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::osmode() const
{
    return m_osmode;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::pickstyle() const
{
    return m_pkstyle;
}

inline ZcDb::LineWeight ZcDbAppSystemVariables::lwdefault() const
{
    return m_lwdefault;
}

inline bool ZcDbAppSystemVariables::hpassoc() const
{
    return m_hpassoc;
}

#pragma pack (pop)
#endif 
