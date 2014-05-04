

#ifndef ZCUINAVDIALOG_H_
#define ZCUINAVDIALOG_H_
#include "zanav.h"

class CZcUiNavPreviewButton;

typedef enum
{
	
	zcUiOpenNoTemplateNone      =   0x0000,
	zcUiOpenNoTemplateImperail  =   0x0001,
	zcUiOpenNoTemplateMetric    =   0x0002
} ZcUiOpenNoTemplateFlag;

class ZCUI_PORT CZcUiNavDialog : public CNavDialog {
    DECLARE_DYNAMIC(CZcUiNavDialog)

    public:

        CZcUiNavDialog (
            CNavDataArray& dataArray,           
            CNavFilterArray& filterArray,       
            UINT idd=0,                         
            CWnd *pParent=NULL,                 
            HINSTANCE hDialogResource=NULL      
        );
        virtual ~CZcUiNavDialog ();

        virtual BOOL OnInitDialog ();

        virtual BOOL GetRecentDirectory(CString& strRecent);

        virtual BOOL FindInSearchPath(LPCTSTR sBase, CString* pFullPath);

        virtual void GetDefaultBrowserStartURL(CString& strStartPage);

        virtual BOOL LaunchBrowserDialog(CString& strSelectedURL, LPCTSTR strDialogCaption,
            LPCTSTR strOk, LPCTSTR strStartPage);

        virtual void DisplaySearchError(LPCTSTR sBase);

        virtual void OnDoLocate();

        virtual BOOL GetProductName(CString& strProduct);

        virtual BOOL BeginDownloadFiles(CStringArray& strURLs, CDWordArray& dwActionCodes);

        virtual DWORD GetDownloadActionCodes(CString& strURL);

        virtual void OnPaintPreview(LPCTSTR strFullPath, CWnd* previewWnd);

        virtual void OnDialogHelp();
        virtual void OnDialogHelp(LPCTSTR pTag);

        BOOL GetPreviewPresent();              
        void SetPreviewPresent(BOOL preview);  
        BOOL GetPreviewVisible();              
        void SetPreviewVisible(BOOL visible);  
        BOOL GetInitialViewButtonChecked();    
        void ConvertFlagsToState(int nFlags);  

		ZcUiOpenNoTemplateFlag GetOpenNoTemplateSelection();

        short GetUpdateThumbnailOverride();      

    protected:
        virtual void OnFolderItemChange();     
        virtual void OnFilterChange();         
        virtual BOOL OnFileNameOK ();          
        virtual void OnFileNameChange ();      
        virtual void PrepareOkMenu(CMenu* pMenu);
        virtual void PrepareViewsMenu(CMenu* pMenu);
        virtual void PrepareToolsMenu(CMenu* pMenu);
        virtual void OnURLDownloadSuccess(CString& strURL);
        virtual BOOL GetOptionsState();        
        virtual void OnCancel();

        void Do3DDwfOptionsDialog();             
        void InitPreviewState();               
        
    protected:
    
        afx_msg void OnOpenNoTemplateImperial();  
        afx_msg void OnOpenNoTemplateMetric();  
        afx_msg void OnOpenMenuPartialOpen();  
        afx_msg void OnOpenMenuPartialOpenReadOnly();
        afx_msg void OnViewsMenuPreview();     
        afx_msg void OnToolsMenuOptions();     
        afx_msg void OnToolsMenuSecurity();
        afx_msg void OnDestroy();        
        afx_msg void OnUpdateThumbnailCheck();  
    
        DECLARE_MESSAGE_MAP()

    private:

        short m_CmdInProgress;
        short m_nUpdateThumbnailOverride;      
        BOOL m_bIsOpen;                        
        BOOL m_bIsSaveAs;                      
        BOOL m_bIsRecover;                     
        BOOL m_bPartialOpenAlwaysDisabled;     
        BOOL m_bInitialViewButtonPresent;      
        BOOL m_bInitialViewButtonChecked;      
        BOOL m_bPartialOpenPresent;            
        BOOL m_bOptionsPresent;                
        BOOL m_bPreviewPresent;                
        BOOL m_bPreviewVisible;                
		BOOL m_bOpenNoTemplate;        
		ZcUiOpenNoTemplateFlag m_nOpenNoTemplateSelection;
        CZcUiNavPreviewButton* m_previewButton;
        BOOL m_bIsExport;

        BOOL CanPartiallyOpen(LPCTSTR szfullPath);
};
#endif 