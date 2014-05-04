

#ifndef _ZDUI_PALETTE_H_
#define _ZDUI_PALETTE_H_

#include "zaduiDropTarget.h"

class CZdUiPaletteSet;

#define PS_EDIT_NAME           0x00000001 

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiPalette : public CWnd
{
    DECLARE_DYNAMIC(CZdUiPalette)

public:
    CZdUiPalette();
    virtual ~CZdUiPalette();

    BOOL Create(DWORD dwStyle, LPCTSTR pszName, CZdUiPaletteSet* pParent,
                DWORD dwPaletteStyle = 0);

    virtual BOOL Create(CZdUiPaletteSet* pParent);

    DWORD GetPaletteStyle();
    
    void SetPaletteStyle(DWORD dwStyle);

    BOOL EditNameStyle()
        { return m_dwStyle & PS_EDIT_NAME; }

    virtual BOOL Load(IUnknown* pUnk);
    
    virtual BOOL Save(IUnknown* pUnk);

    CZdUiPaletteSet* GetPaletteSet() { return m_pPaletteSet; };
    
    void SetPaletteSet(CZdUiPaletteSet* pSet);

    virtual void OnSetActive();

    virtual BOOL OnKillActive();

    virtual CString GetClassName();

    CString GetName();

    void SetName(CString strName);

    virtual BOOL GetMinimumSize(CSize& size);
    
    virtual BOOL GetMaximumSize(CSize& size);

    virtual bool CanFrameworkTakeFocus();

    virtual void EditName(CPoint & ptLoc);

    virtual void EditName();

    virtual BOOL NameEditValidation(CEdit* pEdit);

    static bool PaletteNameEditInProgress() { return m_bPaletteNameEditInProgress; }  

protected:
    
    afx_msg BOOL    OnEraseBkgnd(CDC *pdc);

    afx_msg BOOL    OnSetCursor(CWnd *pwnd, UINT nHitTest, UINT msg);

    afx_msg void    OnLButtonDown(UINT nFlags, CPoint pt);

    afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);  
    afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);  

    DECLARE_MESSAGE_MAP()

private:
    CString                 m_sName;
    CZdUiPaletteSet *       m_pPaletteSet;
    CObArray                m_arrayColors;
    DWORD                   m_dwStyle;
    static UINT             m_nNextPaletteId;
    CEdit *                 m_pLabelEdit;
    static bool             m_bPaletteNameEditInProgress;
};
#pragma warning(pop)
#endif 
