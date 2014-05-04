

#ifndef _ZcExtensionModule_h
#define _ZcExtensionModule_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zacdocman.h"

class CZcExtensionModule {
public:
                CZcExtensionModule ();
                ~CZcExtensionModule ();

protected:
        BOOL    m_bAttached;
        HINSTANCE m_hDefaultResource;
        HINSTANCE m_hModuleResource;
        AFX_EXTENSION_MODULE m_module;

public:
        BOOL    Attached ();
        HINSTANCE DefaultResourceInstance ();
        HINSTANCE ModuleResourceInstance ();

        BOOL    AttachInstance (HINSTANCE hInst);

        void    DetachInstance ();
};

inline CZcExtensionModule::CZcExtensionModule () :
    m_bAttached(FALSE),
    m_hDefaultResource(NULL),
    m_hModuleResource(NULL)
{
    m_module.bInitialized = FALSE;
    m_module.hModule = NULL;
    m_module.hResource = NULL;
    m_module.pFirstSharedClass = NULL;
    m_module.pFirstSharedFactory = NULL;
}

inline CZcExtensionModule::~CZcExtensionModule ()
{
}

inline BOOL CZcExtensionModule::Attached ()
{
    return m_bAttached;
}

inline BOOL CZcExtensionModule::AttachInstance (HINSTANCE hInst)
{
    if (m_bAttached)
        return FALSE;
    m_bAttached = AfxInitExtensionModule(m_module, hInst);
    if (m_bAttached) {
        m_hDefaultResource = AfxGetResourceHandle();
        m_hModuleResource = hInst;
        new CDynLinkLibrary(m_module);
    }
    return m_bAttached;
}

inline HINSTANCE CZcExtensionModule::DefaultResourceInstance ()
{
    return m_hDefaultResource;
}

inline void CZcExtensionModule::DetachInstance ()
{
    if (m_bAttached) {
        AfxTermExtensionModule(m_module);
        m_bAttached = FALSE;
    }
}

inline HINSTANCE CZcExtensionModule::ModuleResourceInstance ()
{
    return m_hModuleResource;
}

class CZcModuleResourceOverride {
public:
                    CZcModuleResourceOverride ();
                    CZcModuleResourceOverride (HINSTANCE hInst);
                    ~CZcModuleResourceOverride ();

private:
static  CZcExtensionModule& m_extensionModule;
};

inline CZcModuleResourceOverride::CZcModuleResourceOverride ()
{
    zcDocManager->pushResourceHandle(m_extensionModule.ModuleResourceInstance());
}

inline CZcModuleResourceOverride::CZcModuleResourceOverride (HINSTANCE hInst)
{
    zcDocManager->pushResourceHandle(hInst ? hInst : 
                                     m_extensionModule.ModuleResourceInstance());
}

inline CZcModuleResourceOverride::~CZcModuleResourceOverride ()
{
    zcDocManager->popResourceHandle();
}

#define ZC_DECLARE_EXTENSION_MODULE(exm)        \
    extern CZcExtensionModule exm;

#define ZC_IMPLEMENT_EXTENSION_MODULE(exm)      \
    CZcExtensionModule exm;                     \
    CZcExtensionModule& CZcModuleResourceOverride::m_extensionModule = exm;

#endif
