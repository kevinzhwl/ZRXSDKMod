
#pragma once

struct ZcGsRenderStatistics
{
public:
    float fRenderTime;
    size_t iMemory;
    size_t iMaterialCount;
    size_t iLightCount;
    size_t iTriangleCount;
};

class ZcGsRenderProgressMonitor
{
public:
    enum Phase
    {
        kTranslation,
        kPhotonEmission,
        kFinalGather,
        kRender
    };
    virtual bool OnProgress(Phase ePhase, float fProgress) = 0;
    virtual void OnTile(int x, int y, int w, int h, const BYTE* pPixels) = 0;
    virtual void SetStatistics(const ZcGsRenderStatistics* pStats) = 0;
    virtual bool ShouldReuseDatabase() { return false; }
};
