
#include "zAdAChar.h"
#include "zAcStatusBar.h"

#ifndef ZD_RXMFCAPI_H
#define ZD_RXMFCAPI_H 1
#pragma pack (push, 8)

#ifndef WM_ZCAD_KEEPFOCUS
#define WM_ZCAD_KEEPFOCUS  (WM_USER+0x6D01)
#endif

class ZcDbDatabase;
class ZcApStatusBar;
class CDialogBar;
CWinApp* zcedGetZcadWinApp();

CDocument* zcedGetZcadDoc();

CView* zcedGetZcadDwgView();

CMDIFrameWnd* zcedGetZcadFrame();

CWnd* zcedGetZcadDockCmdLine();

CWnd* zcedGetZcadTextCmdLine();

HINSTANCE zcedGetZcadResourceInstance();

typedef double zcedDwgPoint[3];

void zcedCoordFromPixelToWorld(const CPoint &ptIn, zcedDwgPoint ptOut);

BOOL zcedCoordFromPixelToWorld(int windnum, CPoint ptIn, zcedDwgPoint ptOut);

BOOL zcedCoordFromWorldToPixel(int windnum, const zcedDwgPoint ptIn, CPoint& ptOut);

int zcedGetWinNum(int ptx, int pty);

int zcedSetStatusBarProgressMeter(const ZTCHAR* pszLabel, int nMinPos,
                                  int nMaxPos);

int zcedSetStatusBarProgressMeterPos(int nPos);

void zcedRestoreStatusBar();

typedef void (* ZcedWatchWinMsgFn)(const MSG*);
typedef BOOL (* ZcedFilterWinMsgFn)(MSG*);
typedef void (* ZcedOnIdleMsgFn) ();
BOOL zcedRegisterFilterWinMsg(const ZcedFilterWinMsgFn pfn);

BOOL zcedRemoveFilterWinMsg(const ZcedFilterWinMsgFn pfn); 

BOOL zcedRegisterWatchWinMsg(const ZcedWatchWinMsgFn pfn);

BOOL zcedRemoveWatchWinMsg(const ZcedWatchWinMsgFn pfn); 
BOOL zcedRegisterOnIdleWinMsg(const ZcedOnIdleMsgFn pfn);
BOOL zcedRemoveOnIdleWinMsg(const ZcedOnIdleMsgFn pfn);
struct ZcColorSettings {
    DWORD dwGfxModelBkColor;
    DWORD dwGfxLayoutBkColor;
    DWORD dwParallelBkColor;
    DWORD dwBEditBkColor;
    DWORD dwCmdLineBkColor;
    DWORD dwPlotPrevBkColor;
    DWORD dwSkyGradientZenithColor;
    DWORD dwSkyGradientHorizonColor;
    DWORD dwGroundGradientOriginColor;
    DWORD dwGroundGradientHorizonColor;
    DWORD dwEarthGradientAzimuthColor;
    DWORD dwEarthGradientHorizonColor;
    DWORD dwModelCrossHairColor;
    DWORD dwLayoutCrossHairColor;
    DWORD dwParallelCrossHairColor;
    DWORD dwPerspectiveCrossHairColor;
    DWORD dwBEditCrossHairColor;
    DWORD dwParallelGridMajorLines;
    DWORD dwPerspectiveGridMajorLines;
    DWORD dwParallelGridMinorLines;
    DWORD dwPerspectiveGridMinorLines;
    DWORD dwParallelGridAxisLines;
    DWORD dwPerspectiveGridAxisLines;
    DWORD dwTextForeColor, dwTextBkColor;
    DWORD dwCmdLineForeColor;
    DWORD dwAutoTrackingVecColor;
    DWORD dwLayoutATrackVecColor;
    DWORD dwParallelATrackVecColor;
    DWORD dwPerspectiveATrackVecColor;
    DWORD dwBEditATrackVecColor;
    DWORD dwModelASnapMarkerColor;
    DWORD dwLayoutASnapMarkerColor;
    DWORD dwParallelASnapMarkerColor;
    DWORD dwPerspectiveASnapMarkerColor;
    DWORD dwBEditASnapMarkerColor;
    DWORD dwModelDftingTooltipColor;
    DWORD dwLayoutDftingTooltipColor;
    DWORD dwParallelDftingTooltipColor;
    DWORD dwPerspectiveDftingTooltipColor;
    DWORD dwBEditDftingTooltipColor;
    DWORD dwModelDftingTooltipBkColor;
    DWORD dwLayoutDftingTooltipBkColor;
    DWORD dwParallelDftingTooltipBkColor;
    DWORD dwPerspectiveDftingTooltipBkColor;
    DWORD dwBEditDftingTooltipBkColor;
    DWORD dwModelLightGlyphs;
    DWORD dwLayoutLightGlyphs;
    DWORD dwParallelLightGlyphs;
    DWORD dwPerspectiveLightGlyphs;
    DWORD dwBEditLightGlyphs;
    DWORD dwModelLightHotspot;
    DWORD dwLayoutLightHotspot;
    DWORD dwParallelLightHotspot;
    DWORD dwPerspectiveLightHotspot;
    DWORD dwBEditLightHotspot;
    DWORD dwModelLightFalloff;
    DWORD dwLayoutLightFalloff;
    DWORD dwParallelLightFalloff;
    DWORD dwPerspectiveLightFalloff;
    DWORD dwBEditLightFalloff;
    DWORD dwModelLightStartLimit;
    DWORD dwLayoutLightStartLimit;
    DWORD dwParallelLightStartLimit;
    DWORD dwPerspectiveLightStartLimit;
    DWORD dwBEditLightStartLimit;
    DWORD dwModelLightEndLimit;
    DWORD dwLayoutLightEndLimit;
    DWORD dwParallelLightEndLimit;
    DWORD dwPerspectiveLightEndLimit;
    DWORD dwBEditLightEndLimit;
    DWORD dwModelCameraGlyphs;
    DWORD dwLayoutCameraGlyphs;
    DWORD dwParallelCameraGlyphs;
    DWORD dwPerspectiveCameraGlyphs;
    DWORD dwModelCameraFrustrum;
    DWORD dwLayoutCameraFrustrum;
    DWORD dwParallelCameraFrustrum;
    DWORD dwPerspectiveCameraFrustrum;
    DWORD dwModelCameraClipping;
    DWORD dwLayoutCameraClipping;
    DWORD dwParallelCameraClipping;
    DWORD dwPerspectiveCameraClipping;
    int nModelCrosshairUseTintXYZ;
    int nLayoutCrosshairUseTintXYZ;
    int nParallelCrosshairUseTintXYZ;
    int nPerspectiveCrosshairUseTintXYZ;
    int nBEditCrossHairUseTintXYZ;
    int nModelATrackVecUseTintXYZ;
    int nLayoutATrackVecUseTintXYZ;
    int nParallelATrackVecUseTintXYZ;
    int nPerspectiveATrackVecUseTintXYZ;
    int nBEditATrackVecUseTintXYZ;
    int nModelDftingTooltipBkUseTintXYZ;
    int nLayoutDftingTooltipBkUseTintXYZ;
    int nParallelDftingTooltipBkUseTintXYZ;
    int nPerspectiveDftingTooltipBkUseTintXYZ;
    int nBEditDftingTooltipBkUseTintXYZ;
    int nParallelGridMajorLineTintXYZ;
    int nPerspectiveGridMajorLineTintXYZ;
    int nParallelGridMinorLineTintXYZ;
    int nPerspectiveGridMinorLineTintXYZ;
    int nParallelGridAxisLineTintXYZ;
    int nPerspectiveGridAxisLineTintXYZ;
};

BOOL zcedGetCurrentColors(ZcColorSettings* pColorSettings);
BOOL zcedSetCurrentColors(ZcColorSettings* pColorSettings);
BOOL zcedGetSystemColors(ZcColorSettings* pColorSettings);

typedef struct tagChildFrmSettings {

    ZcColorSettings m_ColorSettings;
    bool m_bShowLayoutBar;
    bool m_bShowScrollBar;
    CDialogBar *m_pDialogBar;
    bool m_bIsBedit;
} ZcChildFrmSettings;

BOOL zcedGetChildFrameSettings(ZcChildFrmSettings* pChildFrmSettings,
    CMDIChildWnd *pWnd);
BOOL zcedSetChildFrameSettings(ZcChildFrmSettings* pChildFrmSettings,
    CMDIChildWnd *pWnd);

#ifdef _ZRX_CUSTOM_DRAG_N_DROP_

BOOL zcedRegisterCustomDropTarget(IDropTarget* pItarget);
BOOL zcedStartOverrideDropTarget(COleDropTarget* pTarget);

BOOL zcedRevokeCustomDropTarget();
BOOL zcedEndOverrideDropTarget(COleDropTarget* pTarget);

BOOL zcedAddDropTarget(COleDropTarget* pTarget);

BOOL zcedRemoveDropTarget(COleDropTarget* pTarget);

#endif 

ZcDbDatabase* ZcApGetDatabase(CView *pView);

const CString& zcedGetRegistryCompany();

BOOL zcedRegisterExtendedTab(LPCTSTR szAppName, LPCTSTR szDialogName);

HMENU zcedGetMenu(LPCTSTR pszAlias);

BOOL zcedIsInputPending ();

BOOL zcedSetIUnknownForCurrentCommand(const LPUNKNOWN);
BOOL zcedGetIUnknownForCurrentCommand(LPUNKNOWN &pUnk);

ZcApStatusBar* zcedGetApplicationStatusBar();

BOOL zcedShowDrawingStatusBars(BOOL bShow = TRUE);

BOOL zcedDrawingStatusBarsVisible();
BOOL zcedRegisterStatusBarMenuItem(ZcStatusBarMenuItem* pItem,
                                   ZcStatusBarMenuItem::ZcStatusBarType nType);
BOOL zcedUnregisterStatusBarMenuItem(ZcStatusBarMenuItem* pItem,
                                     ZcStatusBarMenuItem::ZcStatusBarType nType);
BOOL zcedSetStatusBarPaneID(ZcPane* pPane,
                            ZcStatusBarMenuItem::ZcStatusBarType nType,
                            int nID);

struct ZcColorSettingsEx
{

    DWORD dwModelLightWeb;
    DWORD dwLayoutLightWeb;
    DWORD dwParallelLightWeb;
    DWORD dwPerspectiveLightWeb;
    DWORD dwBEditLightWeb;
    DWORD dwModelLightWebMissingFile;
    DWORD dwLayoutLightWebMissingFile;
    DWORD dwParallelLightWebMissingFile;
    DWORD dwPerspectiveLightWebMissingFile;
    DWORD dwBEditLightWebMissingFile;
    DWORD dwModelLightWebShape;
    DWORD dwLayoutLightWebShape;
    DWORD dwParallelLightWebShape;
    DWORD dwPerspectiveLightWebShape;
    DWORD dwBEditLightWebShape;
    DWORD dwModelLightWebLuxAtDist;
    DWORD dwLayoutLightWebLuxAtDist;
    DWORD dwParallelLightWebLuxAtDist;
    DWORD dwPerspectiveLightWebLuxAtDist;
    DWORD dwBEditLightWebLuxAtDist;
};

BOOL zcedGetCurrentColorsEx(ZcColorSettings* pColorSettings,
                           ZcColorSettingsEx* pColorSettingsEx);

BOOL zcedSetCurrentColorsEx(ZcColorSettings* pColorSettings,
                           ZcColorSettingsEx* pColorSettingsEx);

BOOL zcedGetSystemColorsEx(ZcColorSettings* pColorSettings,
                          ZcColorSettingsEx* pColorSettingsEx);

#pragma pack (pop)
#endif 
