

#ifndef   _ZCPLPLOTENGINE_H
#define   _ZCPLPLOTENGINE_H

#include "zAdAChar.h"
#include "zAcPl.h"
#include "zAcPlObject.h"

class ZcViewport;
class PlotEnvironment;
class ZcPlPlotProgress;
class ZcPlPlotInfo;
class ZcDbPlotSettings;
class ZcPlPlotConfig;

enum PreviewStatus {
    kNormal = 0,
    kPlot,
    kCancel,
    kNext,
    kPrevious
};

struct ZCPL_PREVIEWENDPLOT {
    PreviewStatus nStatus;
};

class ZcPlPlotPageInfo : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlPlotPageInfo);

public:
    ZCPL_PORT ZcPlPlotPageInfo();
    ZCPL_PORT virtual ~ZcPlPlotPageInfo();

    ZCPL_PORT long entityCount() const;
    ZCPL_PORT long rasterCount() const;
    ZCPL_PORT long oleObjectCount() const;
    ZCPL_PORT long gradientCount() const;
    ZCPL_PORT long shadedViewportType() const;
};

class ZSOFT_NO_VTABLE ZcPlPlotEngine {
public:
    virtual Zcad::ErrorStatus beginPlot(ZcPlPlotProgress* pPlotProgress, void* pParams = NULL);
    virtual Zcad::ErrorStatus endPlot(void* pParams = NULL);

    virtual Zcad::ErrorStatus beginDocument(ZcPlPlotInfo& plotInfo, 
                                            const ZTCHAR * pDocname,
                                            void *pParams = NULL,
                                            long nCopies = 1, 
                                            bool bPlotToFile = false, 
                                            const ZTCHAR * pFileName = NULL);
    virtual Zcad::ErrorStatus endDocument(void* pParams = NULL);

    virtual Zcad::ErrorStatus beginPage(ZcPlPlotPageInfo& pageInfo, 
                                        ZcPlPlotInfo& plotInfo, 
                                        bool bLastPage, 
                                        void* pParams = NULL);
    virtual Zcad::ErrorStatus endPage(void* pParams = NULL);
    
    virtual Zcad::ErrorStatus beginGenerateGraphics(void* pParams = NULL);
    virtual Zcad::ErrorStatus beginGenerateGraphics(ZcViewport*& pViewport, void* pParams = NULL);
    virtual Zcad::ErrorStatus endGenerateGraphics(void* pParams = NULL);
    
    virtual void destroy();
    virtual bool isBackgroundPackaging() const;
};

#endif 
