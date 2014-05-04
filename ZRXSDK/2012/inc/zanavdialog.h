

#ifndef _ZANavDialog_h
#define _ZANavDialog_h

#if _MSC_VER >= 1000
#pragma once
#endif 

enum OkHandlerErr
{
    NAV_OKHANDLER_SUCCESS = 0,      
    NAV_OKHANDLER_NONFILESYSTEM,    
    NAV_OKHANDLER_FAILURE           
};

enum NavToolsMenuItem
{
    NAV_TOOLS_ITEM_FIND = 0x1,
    NAV_TOOLS_ITEM_LOCATE = 0x2,
    NAV_TOOLS_ITEM_FTPMODIFY = 0x4,
    NAV_TOOLS_ITEM_SIMPLESTORAGE = 0x8,
    NAV_TOOLS_ITEM_ADDCURRENT = 0x10,
    NAV_TOOLS_ITEM_ADDFAVORITES = 0x20
};

enum NavInetTransferActions
{	
   NAV_INET_IGNORE_CACHE = 0x1,         
   NAV_INET_STOP_ON_ERROR = 0x2,        
   NAV_INET_KEEP_CACHE 	= 0x4           
};

class ANAV_PORT CNavDialog : public CZdUiDialog {
    friend class CNavDialogImp;
    DECLARE_DYNAMIC(CNavDialog)

public:

    CNavDialog(
        CNavDataArray& dataArray,
        CNavFilterArray& filterArray,
        UINT idd=0,
        CWnd *pParent=NULL,
        HINSTANCE hDialogResource=NULL
    );
    virtual ~CNavDialog();

    enum { IDD = 0 };

    CNavDataArray& GetDataArray();

    CNavFilterArray& GetFilterArray();

    LPCTSTR GetDialogCaption();
    void    SetDialogCaption(LPCTSTR caption);

    LPCTSTR GetDefaultFileExtension();
    void    SetDefaultFileExtension(LPCTSTR ext);

    int     GetFilterIndex();
    void    SetFilterIndex(int index);

    int     GetDefaultFilterIndex();
    void    SetDefaultFilterIndex(int index);

    DWORD   GetInitialFilterIndex();

    int     GetForceFilterIndex();        
    void    SetForceFilterIndex(int index);

    LPCTSTR GetForceInitialFolder();        
    void    SetForceInitialFolder(LPCTSTR folder);

    void    SetDefaultInitialFolder(LPCTSTR folder);
    LPCTSTR GetDefaultInitialFolder();

    LPCTSTR GetInitialFileName();
    void    SetInitialFileName(LPCTSTR name);

    BOOL    GetUseRegExtensionFlags();               
    void    SetUseRegExtensionFlags(BOOL bUse);

    BOOL    GetConfirmReplace();
    void    SetConfirmReplace(BOOL confirm);

    BOOL    GetAcceptAnyFileExtension();
    void    SetAcceptAnyFileExtension(BOOL any);

    BOOL    GetNoURLFileTransfer();
    void    SetNoURLFileTransfer(BOOL noTransfer);

    BOOL    GetNoURLsAllowed();
    void    SetNoURLsAllowed(BOOL noURLs);

    UINT    GetViewMode();
    void    SetViewMode(UINT viewMode);

    BOOL    GetMultiSelectAllowed();
    void    SetMultiSelectAllowed(BOOL allow);

    BOOL    GetReadOnlyAllowed();
    void    SetReadOnlyAllowed(BOOL allow);

    BOOL    GetReadOnlyHidden();
    void    SetReadOnlyHidden(BOOL hidden);

    BOOL    GetReadOnlySpecified();
    void    SetReadOnlySpecified(BOOL readOnly);

    BOOL    GetCreatingFile();
    void    SetCreatingFile(BOOL create);

    UINT    GetToolsMenuItemsPresent();
    void    SetToolsMenuItemsPresent(UINT flag);

    BOOL    GetNoFTP();
    void    SetNoFTP(BOOL noFTP);

    BOOL    GetNoExtraExtensions();
    void    SetNoExtraExtensions(BOOL noExtraExtensions);

    BOOL    GetNoExtraExtensionsInPlaces();
    void    SetNoExtraExtensionsInPlaces(BOOL noExtraExtensions);

    BOOL    GetFoldersOnly();
    void    SetFoldersOnly(BOOL foldersOnly);

    BOOL    GetNoPlacesList();

    void    SetFolderListCtrl(CNavListCtrl* folderListCtrl);

    CNavListCtrl* GetFolderListCtrl();

    UINT    GetIDD();

    void    SetOkButtonText(LPCTSTR text);
    void    GetOkButtonText(CString& strOk, BOOL bIncludeAccel = TRUE);

    void    SetOkButtonMenuExists(BOOL bExists);

    void    AddDataToHistory();

    CNavFilter* GetCurrentFileExtension(CString& strExt);

    void SetFolderComboCurSel(int i);

    int GetToolsMenuItemPosition(NavToolsMenuItem itemFlag);

    BOOL GetPersonalFolderPath(CString& strPersonal);

    BOOL NavigateToFolder(LPCTSTR sFolder);

    void GetCurrentFolderForPersistence(CString& strFolder);

    void GetSingleDataFullPath(CString& strFullPath);

    void TrimWhiteSpace(CString& strName, BOOL bAll);

    void BrowseCurrentObject();

    int InsertUserItemInPlaces(int index, LPCTSTR sFullPath, LPCTSTR sText);

    void* GetImpObject() const;

    virtual BOOL SetAllDialogsData(const CString& cValueName, CString& cValue);
    virtual BOOL SetAllDialogsData(const CString& cValueName, DWORD dwValue);
    virtual BOOL GetAllDialogsData(const CString& cValueName, CString& cValue);
    virtual BOOL GetAllDialogsData(const CString& cValueName, DWORD& data);

    virtual void LocateFile();

    virtual BOOL GetProductName(CString& strProduct);

    virtual BOOL BeginDownloadFiles(CStringArray& strURLs, CDWordArray& dwActionCodes);

    virtual DWORD GetDownloadActionCodes(CString& strURL);

    virtual void OnDialogHelp();
    virtual void OnDialogHelp(LPCTSTR pHelpTag);    

protected:

    virtual BOOL OnInitDialog();

    virtual BOOL PreTranslateMessage(MSG* pMsg);

    virtual void DoDataExchange(CDataExchange* pDX);

    virtual void PrepareOkMenu(CMenu* pMenu);

    virtual void PrepareToolsMenu(CMenu* pMenu);

    virtual void PrepareViewsMenu(CMenu* pMenu);

    virtual void OnCancel();

    virtual void OnOK();

    virtual OkHandlerErr PreprocessData(CNavDataArray& array);

    virtual OkHandlerErr CombineDataTextWithFolderName(CNavData* data, CString& strResult);

    virtual BOOL UpdateFileExtension(CString& strName, BOOL bCanUseCurrentExtension);

    virtual BOOL OnFileNameOK();

    virtual BOOL    VerifyURLSave();

    virtual BOOL OnUrlOK();

    virtual BOOL ReportURLTransferStatus(CDWordArray& dwErrorArray, CStringArray& strURLs, CStringArray& strLocals);

    virtual BOOL GetRecentDirectory(CString& strRecent);

    virtual BOOL FindInSearchPath(LPCTSTR sBase, CString* pFullPath);

    virtual void DisplaySearchError(LPCTSTR sBase);

    virtual void GetDefaultBrowserStartURL(CString& strStartPage);

    virtual BOOL LaunchBrowserDialog(CString& strSelectedURL, LPCTSTR strDialogCaption,
                                     LPCTSTR strOk, LPCTSTR strStartPage);

    virtual void OnURLDownloadSuccess(CString& strURL);

    virtual void OnDoLocate();

    virtual void OnDoFind();

    virtual void OnDoAddToFavorites(BOOL bOneItem);

    virtual void Refresh();

    virtual void OnFileNameChange();

    virtual void OnFileNameSelectionChange();

    virtual void OnFilterChange();

    virtual void OnFolderItemChange();

    virtual void OnFolderChange();

    virtual void UpdateUIState();

    virtual ZDUI_REPLY OnNotifyControlChange(UINT controlId, LPARAM lParam);
    virtual ZDUI_REPLY OnNotifyGeneric(UINT controlId, LPARAM lParam);

    virtual BOOL OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo );

    afx_msg void OnDestroy();
    afx_msg void OnContextMenu(CWnd*, CPoint);
    afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
    afx_msg void OnKickIdle();
    afx_msg void OnSysColorChange();    

private:
    afx_msg LRESULT OnWmGetIShellBrowser (WPARAM wp, LPARAM lp);
    afx_msg LRESULT OnWmDeviceChange     (WPARAM wp, LPARAM lp);

    DECLARE_MESSAGE_MAP()

    void* m_navImp;            
};
#endif
