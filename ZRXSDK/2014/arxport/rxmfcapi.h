
#ifndef __RXMFCAPI_H__
#define __RXMFCAPI_H__

#include "AdAChar.h"
#include "AcStatusBar.h"

#include "..\inc\zrxmfcapi.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcApGetDatabase
#define AcApGetDatabase		ZcApGetDatabase
#endif //#ifndef AcApGetDatabase

#ifndef AcApStatusBar
#define AcApStatusBar		ZcApStatusBar
#endif //#ifndef AcApStatusBar

#ifndef AcChildFrmSettings
#define AcChildFrmSettings		ZcChildFrmSettings
#endif //#ifndef AcChildFrmSettings

#ifndef AcColorSettings
#define AcColorSettings		ZcColorSettings
#endif //#ifndef AcColorSettings

#ifndef AcColorSettingsEx
#define AcColorSettingsEx		ZcColorSettingsEx
#endif //#ifndef AcColorSettingsEx

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcPane
#define AcPane		ZcPane
#endif //#ifndef AcPane

#ifndef AcStatusBar
#define AcStatusBar		ZcStatusBar
#endif //#ifndef AcStatusBar

#ifndef AcStatusBarMenuItem
#define AcStatusBarMenuItem		ZcStatusBarMenuItem
#endif //#ifndef AcStatusBarMenuItem

#ifndef AcStatusBarType
#define AcStatusBarType		ZcStatusBarType
#endif //#ifndef AcStatusBarType

#ifndef WM_ACAD_KEEPFOCUS
#define WM_ACAD_KEEPFOCUS		WM_ZCAD_KEEPFOCUS
#endif //#ifndef WM_ACAD_KEEPFOCUS

#ifndef acedAddDropTarget
#define acedAddDropTarget		zcedAddDropTarget
#endif //#ifndef acedAddDropTarget

#ifndef acedCoordFromPixelToWorld
#define acedCoordFromPixelToWorld		zcedCoordFromPixelToWorld
#endif //#ifndef acedCoordFromPixelToWorld

#ifndef acedCoordFromWorldToPixel
#define acedCoordFromWorldToPixel		zcedCoordFromWorldToPixel
#endif //#ifndef acedCoordFromWorldToPixel

#ifndef acedDrawingStatusBarsVisible
#define acedDrawingStatusBarsVisible		zcedDrawingStatusBarsVisible
#endif //#ifndef acedDrawingStatusBarsVisible

#ifndef acedDwgPoint
#define acedDwgPoint		zcedDwgPoint
#endif //#ifndef acedDwgPoint

#ifndef acedEndOverrideDropTarget
#define acedEndOverrideDropTarget		zcedEndOverrideDropTarget
#endif //#ifndef acedEndOverrideDropTarget

#ifndef acedGetAcadDoc
#define acedGetAcadDoc		zcedGetZcadDoc
#endif //#ifndef acedGetAcadDoc

#ifndef acedGetAcadDockCmdLine
#define acedGetAcadDockCmdLine		zcedGetZcadDockCmdLine
#endif //#ifndef acedGetAcadDockCmdLine

#ifndef acedGetAcadDwgView
#define acedGetAcadDwgView		zcedGetZcadDwgView
#endif //#ifndef acedGetAcadDwgView

#ifndef acedGetAcadFrame
#define acedGetAcadFrame		zcedGetZcadFrame
#endif //#ifndef acedGetAcadFrame

#ifndef acedGetAcadResourceInstance
#define acedGetAcadResourceInstance		zcedGetZcadResourceInstance
#endif //#ifndef acedGetAcadResourceInstance

#ifndef acedGetAcadTextCmdLine
#define acedGetAcadTextCmdLine		zcedGetZcadTextCmdLine
#endif //#ifndef acedGetAcadTextCmdLine

#ifndef acedGetAcadWinApp
#define acedGetAcadWinApp		zcedGetZcadWinApp
#endif //#ifndef acedGetAcadWinApp

#ifndef acedGetApplicationStatusBar
#define acedGetApplicationStatusBar		zcedGetApplicationStatusBar
#endif //#ifndef acedGetApplicationStatusBar

#ifndef acedGetCurrentColors
#define acedGetCurrentColors		zcedGetCurrentColors
#endif //#ifndef acedGetCurrentColors

#ifndef acedGetIUnknownForCurrentCommand
#define acedGetIUnknownForCurrentCommand		zcedGetIUnknownForCurrentCommand
#endif //#ifndef acedGetIUnknownForCurrentCommand

#ifndef acedGetMenu
#define acedGetMenu		zcedGetMenu
#endif //#ifndef acedGetMenu

#ifndef acedGetRegistryCompany
#define acedGetRegistryCompany		zcedGetRegistryCompany
#endif //#ifndef acedGetRegistryCompany

#ifndef acedGetWinNum
#define acedGetWinNum		zcedGetWinNum
#endif //#ifndef acedGetWinNum

#ifndef acedIsInputPending
#define acedIsInputPending		zcedIsInputPending
#endif //#ifndef acedIsInputPending

#ifndef acedRegisterCustomDropTarget
#define acedRegisterCustomDropTarget		zcedRegisterCustomDropTarget
#endif //#ifndef acedRegisterCustomDropTarget

#ifndef acedRegisterExtendedTab
#define acedRegisterExtendedTab		zcedRegisterExtendedTab
#endif //#ifndef acedRegisterExtendedTab

#ifndef acedRegisterFilterWinMsg
#define acedRegisterFilterWinMsg		zcedRegisterFilterWinMsg
#endif //#ifndef acedRegisterFilterWinMsg

#ifndef acedRegisterWatchWinMsg
#define acedRegisterWatchWinMsg		zcedRegisterWatchWinMsg
#endif //#ifndef acedRegisterWatchWinMsg

#ifndef acedRemoveDropTarget
#define acedRemoveDropTarget		zcedRemoveDropTarget
#endif //#ifndef acedRemoveDropTarget

#ifndef acedRemoveFilterWinMsg
#define acedRemoveFilterWinMsg		zcedRemoveFilterWinMsg
#endif //#ifndef acedRemoveFilterWinMsg

#ifndef acedRemoveWatchWinMsg
#define acedRemoveWatchWinMsg		zcedRemoveWatchWinMsg
#endif //#ifndef acedRemoveWatchWinMsg

#ifndef acedRestoreStatusBar
#define acedRestoreStatusBar		zcedRestoreStatusBar
#endif //#ifndef acedRestoreStatusBar

#ifndef acedRevokeCustomDropTarget
#define acedRevokeCustomDropTarget		zcedRevokeCustomDropTarget
#endif //#ifndef acedRevokeCustomDropTarget

#ifndef acedSetCurrentColors
#define acedSetCurrentColors		zcedSetCurrentColors
#endif //#ifndef acedSetCurrentColors

#ifndef acedSetIUnknownForCurrentCommand
#define acedSetIUnknownForCurrentCommand		zcedSetIUnknownForCurrentCommand
#endif //#ifndef acedSetIUnknownForCurrentCommand

#ifndef acedSetStatusBarProgressMeter
#define acedSetStatusBarProgressMeter		zcedSetStatusBarProgressMeter
#endif //#ifndef acedSetStatusBarProgressMeter

#ifndef acedSetStatusBarProgressMeterPos
#define acedSetStatusBarProgressMeterPos		zcedSetStatusBarProgressMeterPos
#endif //#ifndef acedSetStatusBarProgressMeterPos

#ifndef acedShowDrawingStatusBars
#define acedShowDrawingStatusBars		zcedShowDrawingStatusBars
#endif //#ifndef acedShowDrawingStatusBars

#ifndef acedStartOverrideDropTarget
#define acedStartOverrideDropTarget		zcedStartOverrideDropTarget
#endif //#ifndef acedStartOverrideDropTarget

#ifndef acedUnregisterStatusBarMenuItem
#define acedUnregisterStatusBarMenuItem		zcedUnregisterStatusBarMenuItem
#endif //#ifndef acedUnregisterStatusBarMenuItem

#ifndef acedSetChildFrameSettings
#define acedSetChildFrameSettings		zcedSetChildFrameSettings
#endif //#ifndef acedSetChildFrameSettings

#ifndef acedSetStatusBarPaneID
#define acedSetStatusBarPaneID		zcedSetStatusBarPaneID
#endif //#ifndef acedSetStatusBarPaneID

#ifndef acedSetCurrentColorsEx
#define acedSetCurrentColorsEx		zcedSetCurrentColorsEx
#endif //#ifndef acedSetCurrentColorsEx

#ifndef acedRemoveOnIdleWinMsg
#define acedRemoveOnIdleWinMsg		zcedRemoveOnIdleWinMsg
#endif //#ifndef acedRemoveOnIdleWinMsg

#ifndef acedRegisterOnIdleWinMsg
#define acedRegisterOnIdleWinMsg		zcedRegisterOnIdleWinMsg
#endif //#ifndef acedRegisterOnIdleWinMsg

#ifndef acedRegisterStatusBarMenuItem
#define acedRegisterStatusBarMenuItem		zcedRegisterStatusBarMenuItem
#endif //#ifndef acedRegisterStatusBarMenuItem

#ifndef acedGetSystemColors
#define acedGetSystemColors		zcedGetSystemColors
#endif //#ifndef acedGetSystemColors

#ifndef acedGetSystemColorsEx
#define acedGetSystemColorsEx		zcedGetSystemColorsEx
#endif //#ifndef acedGetSystemColorsEx

#ifndef acedGetChildFrameSettings
#define acedGetChildFrameSettings		zcedGetChildFrameSettings
#endif //#ifndef acedGetChildFrameSettings

#ifndef acedGetCurrentColorsEx
#define acedGetCurrentColorsEx		zcedGetCurrentColorsEx
#endif //#ifndef acedGetCurrentColorsEx

#ifndef AcedWatchWinMsgFn
#define AcedWatchWinMsgFn		ZcedWatchWinMsgFn
#endif //#ifndef AcedWatchWinMsgFn

#ifndef AcedFilterWinMsgFn
#define AcedFilterWinMsgFn		ZcedFilterWinMsgFn
#endif //#ifndef AcedFilterWinMsgFn

#ifndef AcedOnIdleMsgFn
#define AcedOnIdleMsgFn		ZcedOnIdleMsgFn
#endif //#ifndef AcedOnIdleMsgFn

#ifndef _ARX_CUSTOM_DRAG_N_DROP_
#define _ARX_CUSTOM_DRAG_N_DROP_		_ZRX_CUSTOM_DRAG_N_DROP_
#endif //#ifndef _ARX_CUSTOM_DRAG_N_DROP_

#endif //#ifndef __RXMFCAPI_H__
