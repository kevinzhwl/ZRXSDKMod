

#ifndef _ZDUI_THEME_H_
#define _ZDUI_THEME_H_

#include <afxtempl.h>
#include "zAdAChar.h"

#define PROPERTY_PALETTE_THEME  ZCRX_T("PropertyPalette")
#define TOOL_PALETTE_THEME      ZCRX_T("ToolPalette")
#define OWNDERDRAW_BUTTON_THEME ZCRX_T("OwnerDrawButton")
#define DIALOG_WORKSHEET_THEME  ZCRX_T("DialogWorksheet")
#define PALETTE_SET_THEME       ZCRX_T("PaletteSet")
#define DESIGN_CENTER_THEME     ZCRX_T("DesignCenter")
#define TOOL_PANEL_THEME        ZCRX_T("ToolPanel")

typedef enum {
    
    kUnknownElements = -1,

    kPaletteFontCaption,
    kPaletteFontTab,
    kPaletteFontToolTip,
    kPaletteFont,
    kWorksheetFont,
    kWorksheetFontCaption,
    kInspectorItemFont,
    kInspectorRootFont,

    kPaletteBackground,
    kPaletteCaptionBackground,
    kPaletteCaptionInactive,
    kPaletteCaptionText,
    kPaletteCaptionInactiveText,
    kPaletteTabText,
    kPaletteTabBackground,
    kPaletteBorder,
    kPaletteTabShadow,
    kPaletteTabHighlight,
    kPaletteTabTextHilite,
    kPaletteTabSelectHilite,
    kPaletteToolTip,
    kPaletteToolTipText,
    kPaletteButtonText,
    kPaletteButtonTextDisabled,
    kPaletteButtonBorder,
    kPaletteItemText,
    kPaletteScrollBackground,
    kPaletteScrollThumb,
    kPaletteScrollArrow,

    kWorksheetBackground,
    kWorksheetCaptionBackground,
    kWorksheetCaptionText,
    kWorksheet3DBtnShadow,
    kWorksheetButtonText,
    kWorksheetButtonTextDisabled,
    kWorksheetScrollBackground,
    kWorksheetScrollThumb,
    kWorksheetBorder,
    kWorksheetGripHighlight,

    kInspector,
    kInspectorTop,
    kInspectorCat,
    kInspectorItem,
    kInspectorBorder,
    kInspectorBorderItem,
    kInspectorTextTop,
    kInspectorTextCat,
    kInspectorTextItem,
    kInspectorFGHighlight,
    kInspectorBGHighlight,
    kInspector3dShadow,
    kInspectorControl,
    kInspectorCatChevron1,
    kInspectorCatChevron2,
    kInspectorSubChevron,
    kPanelBackground,
    kPanelSashBackground,
    kPanelBorder,
    kControlBorder,
    kControlBackground,
    kDisabledControlBorder,
    kControlSupport,

} ZdUiThemeElement;

class CZdUiThemeModifiedReactor
{
public:
    virtual void ThemeModified(const CZdUiTheme * pTheme, ZdUiThemeElement element) = 0;
};

class ZDUI_PORT CZdUiTheme
{
    friend class CZdUiThemeManager;

public:
    
    COLORREF GetColor (ZdUiThemeElement nDisplayElement) const;
    
    BOOL SetColor(ZdUiThemeElement nDisplayElement, COLORREF crColor);

    BOOL SetFont(ZdUiThemeElement nDisplayElement,LOGFONT *plf=NULL);
    BOOL GetFont(ZdUiThemeElement nDisplayElement,LOGFONT *plf) const;
    BOOL GetFont(ZdUiThemeElement nDisplayElement,CFont *& pFont) const;

    BOOL GetData(int nElement, DWORD& dwData) const;
    void SetData(int nElement, const DWORD& dwData);
    BOOL GetData(int nElement, CString& sData) const;
    void SetData(int nElement, const CString& sData);
    void* GetDataPtr(int nElement) const;
    void SetDataPtr(int nElement, void* pData);
    BOOL RegisterReactor(CZdUiThemeModifiedReactor * pReactor);
    BOOL UnregisterReactor(CZdUiThemeModifiedReactor * pReactor);

    void SuspendModifiedNotifications() { m_nModNotificationsSuspended++; }
    void ResumeModifiedNotifications();
    void SendModifiedNotification() const;

    void IncrementRefCount() { m_nRefCount++; }

    CZdUiTheme& operator=(const CZdUiTheme *pTheme);
    
private:
    CZdUiTheme();
    virtual ~CZdUiTheme();

    void SendThemeModifiedNotifications(ZdUiThemeElement nElement) const;

    void CheckXP();

    BOOL UsesXP() { return m_bUsesXPThemes; };

    void DecrementRefCount() { m_nRefCount--; }
    int RefCount() { return m_nRefCount; }

    int    m_nRefCount;
    CTypedPtrArray<CPtrArray, CZdUiThemeModifiedReactor*> m_arrayModReactors;
    int m_nModNotificationsSuspended;
    CMap<int, int, DWORD, DWORD> m_mapDwordValues;
    CMap<int, int, CString, CString> m_mapStringValues;
    CMap<int, int, void*, void*> m_mapPointerValues;

    LOGFONT             m_lfWorksheet;
    LOGFONT             m_lfWorksheetCaption;
    LOGFONT             m_lfPaletteCaption;
    LOGFONT             m_lfInspectorItem;
    LOGFONT             m_lfInspectorRoot;
    LOGFONT             m_lfPaletteTab;
    LOGFONT             m_lfPalette;
    LOGFONT             m_lfPaletteToolTip;

    COLORREF            m_crPaletteBkgnd;
    COLORREF            m_crPaletteCaptionBkgnd;
    COLORREF            m_crPaletteCaptionInactive;
    COLORREF            m_crPaletteCaptionText;
    COLORREF            m_crPaletteCaptionInactiveText;
    COLORREF            m_crPaletteItemText;
    COLORREF            m_crPaletteTabText;
    COLORREF            m_crPaletteTabBackground;
    COLORREF            m_crPaletteBorder;
    COLORREF            m_crPaletteTabShadow;
    COLORREF            m_crPaletteTabHighlight;
    COLORREF            m_crPaletteTabSelectHilite;
    COLORREF            m_crPaletteTabTextHilite;
    COLORREF            m_crPaletteScrollBackground;
    COLORREF            m_crPaletteScrollThumb;
    COLORREF            m_crPaletteScrollArrow;
    COLORREF            m_crPaletteButtonBorder;
    COLORREF            m_crPaletteButtonText;
    COLORREF            m_crPaletteButtonTextDisabled;
    COLORREF            m_crPaletteToolTip;
    COLORREF            m_crPaletteToolTipText;

    COLORREF            m_crWorksheetBkgnd;
    COLORREF            m_crWorksheetCaptionBkgnd;
    COLORREF            m_crWorksheetCaptionText;
    COLORREF            m_crWorksheetBtnShadow;
    COLORREF            m_crWorksheetBtnText;
    COLORREF            m_crWorksheetBtnTextDisabled;
    COLORREF            m_crWorksheetScroll;
    COLORREF            m_crWorksheetScrollThumb;
    COLORREF            m_crWorksheetBorder;
    COLORREF            m_crWorksheetGripHighlight;

    COLORREF            m_crInspector;
    COLORREF            m_crInspectorTop;
    COLORREF            m_crInspectorCat;
    COLORREF            m_crInspectorItem;
    COLORREF            m_crInspectorBorder;
    COLORREF            m_crInspectorBorderItem;
    COLORREF            m_crInspectorTextTop;
    COLORREF            m_crInspectorTextCat;
    COLORREF            m_crInspectorTextItem;
    COLORREF            m_crInspectorFGHighlight;
    COLORREF            m_crInspectorBGHighlight;
    COLORREF            m_crInspector3dShadow;    
    COLORREF            m_crInspectorControl;
    COLORREF            m_crInspectorCatChevron1;
    COLORREF            m_crInspectorCatChevron2;
    COLORREF            m_crInspectorSubChevron;
    COLORREF            m_crPanelBackground;
    COLORREF            m_crPanelSashBackground;
    COLORREF            m_crPanelBorder;
    COLORREF            m_crControlBorder;
    COLORREF            m_crControlBackground;
    COLORREF            m_crDisabledControlBorder;
    COLORREF            m_crControlSupport;
    BOOL                m_bUsesXPThemes;    
    
};

#endif 

