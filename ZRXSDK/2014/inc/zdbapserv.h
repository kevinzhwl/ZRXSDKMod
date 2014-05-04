

#ifndef ZcDbHostApplicationServices_INC
#define ZcDbHostApplicationServices_INC

#include "zadesk.h"
#include "zacdb.h"
#include "zacarray.h"
#include "zcodepgid.h"

#include "zinetstrc.h"
#include "zrxdlinkr.h"

#pragma pack (push, 8)

class ZcDbAuditInfo;
class ZcDbDatabase;
class ZcDbUndoController;
class ZcDbTransactionManager;
class ZcDbGlobals;
class ZcDbAppSystemVariables;
class COleClientItem;
class CArchive;
class ZcadInternalServices;
struct flagmat;

class ZcDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;

class ZcDbPlotSettingsValidator;
class ZcDbLayoutManager;
class ZcPwdCache;

struct _EXCEPTION_POINTERS;

#ifndef ZCUTIL_API
#    ifdef ZCUTIL_INTERNAL
#        define ZCUTIL_API __declspec(dllexport)
#    else
#        define ZCUTIL_API __declspec(dllimport)
#    endif
#endif

typedef unsigned long LCID;

enum  ZcSDIValues {
    kMDIEnabled = 0,
    kSDIUserEnforced,
    kSDIAppEnforced,
    kSDIUserAndAppEnforced
};

enum ProdIdCode {
    kProd_ZCAD = 1,
    kProd_LT,
    kProd_OEM,
    kProd_ZcDb
};

ZCUTIL_API extern class ZcDbHostApplicationServices * s_pServices;

int zcdbHostAppMinorVersion();

class ZcDbHostApplicationProgressMeter{
public:
    ZcDbHostApplicationProgressMeter();
    virtual ~ZcDbHostApplicationProgressMeter();

    virtual void start(const ZTCHAR * displayString = NULL);
    virtual void stop();
    
    virtual void meterProgress();

    virtual void setLimit(int max);

};

typedef Zcad::ErrorStatus (*SELECTFILEPROC )( short *userCancel, 
                                              ZTCHAR *& chosenPath,
                                             void* h, 
                                             const int nFlags,
                                             const ZTCHAR * prompt,
                                             const ZTCHAR * dir,
                                             const ZTCHAR * name,
                                             const ZTCHAR * type,
                                             int* pnChoice,
                                             bool* pbReadOnly,
                                             const ZTCHAR * pszWSTags,
                                             void* pReserved);

typedef Zcad::ErrorStatus (* REMAPPROC) ( ZTCHAR *& newName,
                                         const ZTCHAR * filename,
                                         int context,
                                         void* pReserved);

typedef void (* MAPFILENOTIFYPROC) (const ZTCHAR * filename,
                                    const ZTCHAR * newName,
                                    int context,
                                    void* pReserved);

class ZSOFT_NO_VTABLE ZcDbHostApplicationServices : public ZcRxObject
{
    friend ZcadInternalServices;
public:    
    ZCRX_DECLARE_MEMBERS(ZcDbHostApplicationServices);
    ZcDbHostApplicationServices( int createGlobals = 1 );
    virtual ~ZcDbHostApplicationServices();

    enum FindFileHint
    {
        kDefault = 0,
        kFontFile,              
        kCompiledShapeFile,     
        kTrueTypeFontFile,      
        kEmbeddedImageFile,
        kXRefDrawing,
        kPatternFile,
        kZRXApplication,
        kFontMapFile,
        kUnderlayFile
    };
    
    enum RemapFileContext
    {
        kDrawingOpen,
        kXrefResolution,
        kRasterResolution,
        kAfterXrefResolution
    };

    virtual Zcad::ErrorStatus findFile(ZTCHAR * pcFullPathOut,
                 int   nBufferLength,
                 const ZTCHAR * pcFilename,
                 ZcDbDatabase * pDb = NULL, 
                                            
                 ZcDbHostApplicationServices::FindFileHint hint = kDefault) = 0;

    virtual Zcad::ErrorStatus getRoamableRootFolder(const ZTCHAR *& folder);
    virtual Zcad::ErrorStatus getLocalRootFolder(const ZTCHAR *& folder);

    virtual Zcad::ErrorStatus   selectFile(short *userCancel, 
                                           ZTCHAR *& chosenPath,
                                           void* h, 
                                           const int nFlags,
                                           const ZTCHAR * prompt,
                                           const ZTCHAR * dir,
                                           const ZTCHAR * name,
                                           const ZTCHAR * type,
                                           int* pnChoice,
                                           bool* pbReadOnly,
                                           const ZTCHAR * pszWSTags,
                                           void* pReserved) ;
    virtual Zcad::ErrorStatus   registerSelectFileCallback(const ZTCHAR * appName,
                                                   SELECTFILEPROC proc, 
                                                   bool unRegister = false, 
                                                   bool asPrimary  = false);
    virtual const ZTCHAR *       primaryClientForSelectFileCallback();
    virtual Zcad::ErrorStatus   getRegisteredSelectFileClients(
                                            ZcArray<const ZTCHAR *>& clients);

    virtual Zcad::ErrorStatus   mapFile( ZTCHAR *& newName,
                                        const ZTCHAR * filename,
                                        int context,
                                        void* pReserved);
    virtual Zcad::ErrorStatus   registerMapFileCallback(const ZTCHAR * appName,
                                                REMAPPROC  proc,
                                                bool unRegister = false, 
                                                bool asPrimary  = false);
    virtual const ZTCHAR *       primaryClientForMapFileCallback();
    virtual bool                setMapFlag(bool setIt);
    virtual Zcad::ErrorStatus   getRegisteredFileMapClients(
                                            ZcArray<const ZTCHAR *>& clients);
    virtual Zcad::ErrorStatus   registerMapFileNotification(const ZTCHAR * appName,
                                                MAPFILENOTIFYPROC,
                                                bool unRegister = false);

    virtual void fatalError(const ZTCHAR *format, ...);

    virtual void reportUnhandledZrxException(const _EXCEPTION_POINTERS *pExcPtrs,
                                             const ZTCHAR *pAppName);

    virtual ZSoft::Boolean userBreak(bool updCtrlsWhenEnteringIdle = true) const;

    virtual void displayChar(ZTCHAR c) const;
    virtual void displayString(const ZTCHAR* string, int count) const;

    virtual ZSoft::Boolean readyToDisplayMessages();

    virtual void enableMessageDisplay(ZSoft::Boolean);

    virtual ZSoft::Boolean doFullCRCCheck();

    virtual unsigned int getTempPath(ZSoft::UInt32 lBufferSize, 
                                                ZTCHAR* pcBuffer);

    virtual const ZTCHAR* getEnv(const ZTCHAR * var);

    virtual ZcDbHostApplicationProgressMeter* newProgressMeter();

    void setWorkingProgressMeter(ZcDbHostApplicationProgressMeter* pNewMeter);

    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
    virtual ClipBoundaryArray* newClipBoundaryArray();

    ZcDbDatabase* workingDatabase() const;
    void setWorkingDatabase(ZcDbDatabase* pDatabase);

    virtual ZcDbUndoController* defaultUndoController();
    void setDefaultUndoController(ZcDbUndoController* pUndoCtrl);

    virtual ZcDbTransactionManager* workingTransactionManager();
    void setWorkingTransactionManager(ZcDbTransactionManager* pTM);

    virtual ZcDbGlobals * createWorkingGlobals();
    ZcDbGlobals * workingGlobals() const;
    void setWorkingGlobals(ZcDbGlobals* pGlobals);
    
    ZcDbAppSystemVariables * workingAppSysvars() const;
    void setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars);

    virtual const ZTCHAR * program ();
    virtual const ZTCHAR * product ();
    virtual const ZTCHAR * companyName();
    virtual const ProdIdCode prodcode();
    virtual const ZTCHAR * releaseMajorMinorString();
    virtual int   releaseMajorVersion();
    virtual int   releaseMinorVersion();
    virtual const ZTCHAR * versionString();
    virtual const ZTCHAR * getRegistryProductRootKey ();
    virtual LCID  getRegistryProductLCID() ;
    virtual bool  supportsMultiRedo() const { return false; }
    enum ModelerFlavor {kModelerFull=0, kModelerRegionsOnly=1, kModelerObjectsOnly=2};
    virtual ModelerFlavor  getModelerFlavor() const { return ZcDbHostApplicationServices::kModelerFull; }

    code_page_id getSystemCodePage() const;

    void setSystemCodePage(code_page_id);

    virtual ZcadInternalServices* zcadInternalServices();

    void * zcadInternalGetvar (const ZTCHAR *name);

    virtual ZSoft::Boolean isURL(const ZTCHAR * pszURL) const;

    virtual ZSoft::Boolean isRemoteFile(const ZTCHAR * pszLocalFile,
                                          ZTCHAR * pszURL) const;

    virtual Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL,
     ZTCHAR * pszLocalFile, ZSoft::Boolean bIgnoreCache = ZSoft::kFalse) const;

    virtual Zcad::ErrorStatus putRemoteFile(const ZTCHAR * pszURL,
        const ZTCHAR * pszLocalFile) const;

    virtual ZSoft::Boolean launchBrowserDialog(
                 ZTCHAR *          pszSelectedURL,
                 const ZTCHAR *    pszDialogTitle,
                 const ZTCHAR *    pszOpenButtonCaption,
                 const ZTCHAR *    pszStartURL,
                 const ZTCHAR *    pszRegistryRootKey = 0,
                 ZSoft::Boolean bOpenButtonAlwaysEnabled = ZSoft::kFalse) const;

    virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
                                      ZSoft::LongPtr hdc,
        long left, long top, long right, long bottom);

    virtual Zcad::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);

    virtual Zcad::ErrorStatus serializeOleItem(COleClientItem* pItem,
        CArchive*);

    virtual ZSoft::Boolean _entToWorldTransform(double normal[3], 
                                                flagmat *tran);

    virtual void terminateScript();
    virtual ZSoft::Boolean getSubstituteFont(ZTCHAR **pFileName,
                                             ZTCHAR *prompt,
                                                        int type, int fontAlt); 
    virtual void alert(const ZTCHAR * string) const;

    virtual void auditPrintReport(ZcDbAuditInfo * pAuditInfo,
                                             const ZTCHAR *    line,
                                             int             both) const;

    virtual ZTCHAR * getAlternateFontName() const { return ZCRX_T(""); }

    virtual ZTCHAR * getFontMapFileName() const { return ZCRX_T(""); }

    virtual bool cacheSymbolIndices() const { return false; }

    virtual ZcDbPlotSettingsValidator* plotSettingsValidator() const; 
    virtual ZcDbLayoutManager* layoutManager() const;
    virtual bool loadApp(const ZTCHAR * appName,
                         ZcadApp::LoadReasons why, 
                         bool printit, 
                         bool asCmd);
    virtual void getDefaultPlotCfgInfo(ZTCHAR * plotDeviceName,
                                       ZTCHAR * plotStyleName);
    virtual Zcad::ErrorStatus signingComplete(Zcad::ErrorStatus es,
                                              const ZTCHAR * msg,
                                              bool* result);

	enum PasswordOptions {kPasswordOptionDefault = 0, kPasswordOptionUpperCase =1, kPasswordOptionIsExternalReference = 2};
#ifdef _UNICODE
	virtual bool getPassword(const ZTCHAR* dwgName,
                             PasswordOptions options,
                             wchar_t *password, 
                             const size_t bufSize);
#else
	virtual bool getPassword(const ZTCHAR* dwgName,
                             bool isXref,
                             wchar_t *password, 
                             const size_t bufSize);
#endif

    virtual void usedPasswordFromCacheMsg(const ZTCHAR *dwgName);
    virtual void missingCryptoProviderMsg();

    virtual const ZTCHAR * getColorBookLocation() const { return NULL; }

    ZcPwdCache * getPasswordCache() const;

protected:

    Zcad::ErrorStatus mapInetStatusToZcadStatus(
        const ZcadInet::Status status) const;

protected:

    void * mp_sessionVars;

    void zcadInternalSetvar (const ZTCHAR *name, void * var);

private:

    ZcDbDatabase* mpWorkingDatabase;
    ZcDbUndoController* mpDefaultUndoController;
    ZcDbTransactionManager* mpWorkingTransactionManager;
    ZcDbGlobals * mpWorkingGlobals;
    ZcDbAppSystemVariables * mpWorkingAppSysvars;

    code_page_id m_eSystemCodePage;

    ZSoft::Boolean mbDisplayMessages;

    ZcPwdCache * mpPasswordCache;
};

Zcad::ErrorStatus zcdbSetHostApplicationServices(ZcDbHostApplicationServices * pServices);

inline ZcDbHostApplicationServices *
zcdbHostApplicationServices()
{
    return s_pServices;
}

Zcad::ErrorStatus zcdbSendInitialDwgFileOpenComplete(ZcDbDatabase* pDb);

extern ZcDbGlobals* getDefaultGlobals();

inline ZcDbGlobals *
ZcDbHostApplicationServices::workingGlobals() const
{
    return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
}

inline code_page_id
ZcDbHostApplicationServices::getSystemCodePage() const
{
    return this->m_eSystemCodePage;
}

inline ZcDbUndoController *
ZcDbHostApplicationServices::defaultUndoController()
{
    return mpDefaultUndoController;
}

inline ZcDbTransactionManager *
ZcDbHostApplicationServices::workingTransactionManager()
{
    return mpWorkingTransactionManager;
}

inline ZcDbDatabase *
ZcDbHostApplicationServices::workingDatabase() const
{
    return mpWorkingDatabase;
}

inline ZcDbAppSystemVariables * 
ZcDbHostApplicationServices::workingAppSysvars() const
{
    return mpWorkingAppSysvars;
}

inline void 
ZcDbHostApplicationServices::setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars)
{
    mpWorkingAppSysvars = pSysvars;
}

inline void 
ZcDbHostApplicationServices::terminateScript()
{
    return;
}

inline void 
ZcDbHostApplicationServices::reportUnhandledZrxException(
                    const _EXCEPTION_POINTERS *pExcPtrs,
                    const ZTCHAR *pAppName)
{
    return;
}

inline Zcad::ErrorStatus
ZcDbHostApplicationServices::selectFile( short *userCancel,
                                         ZTCHAR *& chosenPath,
                                        void* h, 
                                        const int nFlags,
                                        const ZTCHAR * prompt,
                                        const ZTCHAR * dir,
                                        const ZTCHAR * name,
                                        const ZTCHAR * type,
                                        int* pnChoice,
                                        bool* pbReadOnly,
                                        const ZTCHAR * pszWSTags,
                                        void* pReserved) 
{ 
    return Zcad::eNotHandled;
}

inline Zcad::ErrorStatus   
ZcDbHostApplicationServices::registerSelectFileCallback(const ZTCHAR * appName,
                                                        SELECTFILEPROC proc, 
                                                        bool unRegister, 
                                                        bool asPrimary)
{
    return Zcad::eNotImplemented;
}
inline const ZTCHAR *
ZcDbHostApplicationServices::primaryClientForSelectFileCallback() 
{
    return NULL;
}

inline Zcad::ErrorStatus 
ZcDbHostApplicationServices::mapFile(ZTCHAR *& newName,
                                     const ZTCHAR * filename,
                                     int context,
                                     void* pReserved) 
{
    return Zcad::eNotHandled;
}
    
inline Zcad::ErrorStatus
ZcDbHostApplicationServices::registerMapFileCallback(const ZTCHAR *, REMAPPROC,
                                                     bool unRegister,
                                                     bool asPrimary)
{
    return Zcad::eNotImplemented;
}
    
inline const ZTCHAR *
ZcDbHostApplicationServices::primaryClientForMapFileCallback() 
{
    return NULL;
}

inline
Zcad::ErrorStatus
ZcDbHostApplicationServices::getRegisteredSelectFileClients(
                                            ZcArray<const ZTCHAR *>& clients)
{
    return Zcad::eNotImplemented;
}

inline
Zcad::ErrorStatus
ZcDbHostApplicationServices::getRegisteredFileMapClients(
                                            ZcArray<const ZTCHAR *>& clients)
{
    return Zcad::eNotImplemented;
}

inline Zcad::ErrorStatus
ZcDbHostApplicationServices::registerMapFileNotification(const ZTCHAR * appName,
                                                         MAPFILENOTIFYPROC,
                                                         bool unRegister)
{
    return Zcad::eNotImplemented;
}

inline bool
ZcDbHostApplicationServices::setMapFlag(bool setIt)
{
    return false;
}

inline ZcPwdCache * 
ZcDbHostApplicationServices::getPasswordCache() const
{
    return mpPasswordCache;
}

void zcdbTriggerZcadOctTreeReclassification();

Zcad::ErrorStatus zcdbSetBreak3dQueueForRegen(bool);

class ZSOFT_NO_VTABLE ZcDbPasswordedFile
{
protected:
    virtual Zcad::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;
    virtual const ZTCHAR* getFullPath() = 0;
public:
    Zcad::ErrorStatus open(const wchar_t* wszPassword, ZcDbHostApplicationServices::PasswordOptions options);
};

#pragma pack (pop)

#endif


