
#ifndef _zduiGroupCtrl_h
#define _zduiGroupCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif

#include <vector>

typedef void (*ZdUiBmpBtnFcnPtr)(CWnd*);

typedef struct ZdUiGroupCtrlData
{
    ZdUiGroupCtrlData() : nWndIndex(0), title(""), pWnd(NULL), dwBtnCookie(-1) {};
    int nWndIndex;
    CString title;
    CWnd* pWnd;
    DWORD dwBtnCookie;
} groupData;
typedef std::vector<groupData> ZDUIGROUPCTRLDATALIST;

typedef struct ZdUiBmpBtnData
{
    ZdUiBmpBtnData() : pBmp(NULL), fcnPtr(NULL),
        tooltip(""), dwCookie(0) {};
    CBitmap* pBmp;
    ZdUiBmpBtnFcnPtr fcnPtr;
    CString tooltip;
    DWORD dwCookie;
} bmpBtnData;
typedef std::vector<bmpBtnData> ZDUIHEADERBTNLIST;

#define ZDUI_NCHT_BASE      (HTHELP + 200)
#define ZDUI_NCHT_TITLE     ZDUI_NCHT_BASE
#define ZDUI_NCHT_CHEVRON   (ZDUI_NCHT_BASE + 1)
#define ZDUI_NCHT_BUTTON    (ZDUI_NCHT_BASE + 2)

#define ZDUI_GROUP_BORDER_SIZE              1
#define ZDUI_GROUP_TITLE_HEIGHT             18
#define ZDUI_GROUP_TITLE_BEVELSIZE          5
#define ZDUI_GROUP_TITLE_TEXTLEFT           10
#define ZDUI_GROUP_TITLE_TEXTTOP            1
#define ZDUI_GROUP_BUTTON_SIZE              14
#define ZDUI_GROUP_BUTTONS_RIGHT            25
#define ZDUI_GROUP_BUTTON_TOPPADDING        2
#define ZDUI_GROUP_BUTTON_BOTTOMPADDING     2
#define ZDUI_GROUP_BUTTON_SPACE             3
#define ZDUI_GROUP_CHEVRON_RIGHT            6
#define ZDUI_GROUP_CHILD_VERT_SPACE         12

#define ZDUI_GROUP_STYLE_CHEVRON        0x00000001
#define ZDUI_GROUP_STYLE_SHOWBTNFORCE   0x00000002
#define ZDUI_GROUP_STYLE_NONACTIVE      0x00000004

const DWORD WM_ZDUI_VISIBILITY_CHANGING = WM_USER + 1936;

#pragma warning(push)
#pragma warning(disable : 4275)

class ZDUI_PORT CZdUiGroupCtrl : public CStatic {
    DECLARE_DYNAMIC(CZdUiGroupCtrl);

public:
    CZdUiGroupCtrl( );
    virtual ~CZdUiGroupCtrl();
    virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, CBitmap* pBMP = NULL);
    virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszResName);
    virtual bool ShowWnd(CWnd* pWnd);
    virtual bool AddBmpBtnToHeader(LPCTSTR pszResName,
                                   ZdUiBmpBtnFcnPtr fcnPtr,
                                   DWORD& dwCookie,
                                   LPCTSTR pszToolTip);
    virtual bool AddBmpBtnToHeader(CBitmap* pBmp,
                                   ZdUiBmpBtnFcnPtr fcnPtr,
                                   DWORD& dwCookie,
                                   LPCTSTR pszToolTip);
    virtual bool RemoveBmpBtnFromHeader(DWORD dwCookie);
    virtual void ModGroupStyle(DWORD styleRemove, DWORD styleAdd);
    virtual void SetTheme(CZdUiTheme* pTheme);
    virtual void SetFont(CFont* pFont);
    virtual void SetFont(CFont* pFont, BOOL bRedraw);
    virtual void SetMinimized(bool bMinimized);
    bool GetMinimized() const;
    void SetTitle(LPCTSTR pszTitle) { m_csTitle = pszTitle; }
    void SetHeaderHeight(int nHeight) { m_nHeaderHeight = nHeight; }
    int GetHeaderHeight() { return m_nHeaderHeight; }
    void SetStyle(DWORD nStyle) { m_nStyle = nStyle; }
    DWORD GetStyle() { return m_nStyle; }
    void SetSelIndex(int nSelIndex);
    int GetSelIndex();
    void SetHideGroupHeader(bool bHide) {
        m_bHideGroupHeader = bHide;
    }
    bool GetHideGroupHeader() {
        return m_bHideGroupHeader;
    }
    void SetActive(bool bActive);
    bool GetActive() { return m_bActive; }

protected:

    virtual void DrawGroupContent(CDC* pDC);

    virtual void DrawGroupHeader(CDC* pDC);
    virtual void DeselectGroupHeader() {
        CDC* pDC = GetWindowDC();
        DrawGroupHeader(pDC);
        ReleaseDC(pDC);
    }
    void OnChevronClicked();
    virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:

    afx_msg void OnNcPaint();
    afx_msg void OnPaint();
    afx_msg void OnNcCalcSize( BOOL bCalcValidRects, NCCALCSIZE_PARAMS * );
    afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
    afx_msg void OnSize( UINT nType, int cx, int cy );
    afx_msg void OnNcLButtonDown( UINT nHitTest, CPoint );
    afx_msg void OnNcLButtonDblClk( UINT nHitTest, CPoint );
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
    afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
    afx_msg void OnSetFocus( CWnd * pOldWnd );
    afx_msg void OnKillFocus( CWnd * pNewWnd );
    afx_msg BOOL OnEraseBkgnd(CDC*) { return TRUE;};
    afx_msg HBRUSH OnCtlColor(CDC*, CWnd*, UINT);

    DECLARE_MESSAGE_MAP()

protected:
    COLORREF m_crNCBackground;
    COLORREF m_crGroupBorder;
    COLORREF m_crHeaderActive;
    COLORREF m_crHeaderInactive;
    COLORREF m_crTitleText;
    COLORREF m_crButtonBorderNormal;
    COLORREF m_crButtonFillNormal;
    COLORREF m_crButtonFillSelected;
    COLORREF m_crButtonBorderSelected1;
    COLORREF m_crButtonBorderSelected2;
    CBrush   m_bgBrush;
protected:
    CString         m_csTitle;
    bool            m_bMinimized;
    bool            m_bActive;
    bool            m_bHideGroupHeader;
    int             m_nHeaderHeight;
    int             m_nRestoreHeight;
    int             m_nSelIndex;
    DWORD           m_nStyle;
    DWORD           m_dwBtnId;
    static LOGFONT          m_lf;
    ZDUIHEADERBTNLIST       m_bmpBtnList;
    ZDUIGROUPCTRLDATALIST   m_groupList;
    CToolTipCtrl            m_ToolTip;
};

inline bool CZdUiGroupCtrl::GetMinimized() const
{
    return m_bMinimized;
}

inline void CZdUiGroupCtrl::SetMinimized( bool bMinimized )
{
    m_bMinimized = bMinimized;
}

#pragma warning(pop)

#pragma pack (pop)
#endif

