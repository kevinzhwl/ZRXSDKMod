
#ifndef _ZCPUBLISHUIREACTORS_H
#define _ZCPUBLISHUIREACTORS_H

#include "zAdAChar.h"
#include "zAcPublishReactors.h"
#include "zrxobject.h"
#include "zacarray.h"
#include "zAcPlDSDData.h"
#include "zAcPublishReactors.h"

class ZcPublishUIReactorInfo
{
public:
    ZcPublishUIReactorInfo() {};
    virtual ~ZcPublishUIReactorInfo() {};
    virtual const ZcPlDSDData * GetDSDData() = 0;
    virtual const ZcNameValuePairVec
        GetPrivateData(const ZTCHAR * sectionName) = 0;
    virtual bool WritePrivateSection(const ZTCHAR * sectionName,
        const ZcNameValuePairVec nameValuePairVec) = 0;
    virtual bool JobWillPublishInBackground() = 0;
};

class ZcPublishUIReactor : public ZcRxObject
{
public:
    virtual void OnInitPublishOptionsDialog(IUnknown **pUnk,
                                            ZcPublishUIReactorInfo *pInfo);
    virtual ~ZcPublishUIReactor() {};

protected:
    ZcPublishUIReactor() {};
};

inline void
ZcPublishUIReactor::OnInitPublishOptionsDialog(IUnknown **pUnk,
                                               ZcPublishUIReactorInfo *pInfo)
{
};

void ZcGlobAddPublishUIReactor(ZcPublishUIReactor *pReactor);

void ZcGlobRemovePublishUIReactor(ZcPublishUIReactor *pReactor);

typedef void (__cdecl * ZCGLOBADDPUBLISHUIREACTOR)(ZcPublishUIReactor * pReactor);
typedef void (__cdecl * ZCGLOBREMOVEPUBLISHUIREACTOR)(ZcPublishUIReactor * pReactor);
#endif

