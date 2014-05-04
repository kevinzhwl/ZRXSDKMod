

#ifndef ZD_DRAWABLE_H
#define ZD_DRAWABLE_H

#include "zrxobject.h"
#include "zdbid.h"
#pragma pack (push, 8)

class ZcGiDrawableTraits;
class ZcGiWorldDraw;
class ZcGiViewportDraw;
class ZcGsNode;
class ZcDbSubentId;

class ZSOFT_NO_VTABLE ZcGiDrawable : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcGiDrawable);

    enum SetAttributesFlags
    {
        kDrawableNone                           =  0,
        kDrawableIsAnEntity                     =  1,
        kDrawableUsesNesting                    =  2,
        kDrawableIsCompoundObject               =  4,
        kDrawableViewIndependentViewportDraw    =  8,
        kDrawableIsInvisible                    =  16,
        kDrawableHasAttributes                  =  32,
        kDrawableRegenTypeDependantGeometry     =  64,
        kDrawableIsDimension = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128),
        kDrawableRegenDraw                      = 256,
        kDrawableStandardDisplaySingleLOD       = 512,
        kDrawableShadedDisplaySingleLOD         = 1024,
        kDrawableViewDependentViewportDraw      =  2048,
        kDrawableBlockDependentViewportDraw     =  4096
    };

    enum DrawableType
    {
        kGeometry              = 0,
        kDistantLight,
        kPointLight,
        kSpotLight,
        kAmbientLight,
        kSolidBackground,
        kGradientBackground,
        kImageBackground,
        kGroundPlaneBackground,
        kViewport,
        kWebLight,
        kSkyBackground
    };

    virtual ZSoft::UInt32   setAttributes   (ZcGiDrawableTraits * traits)   = 0;

    virtual ZSoft::Boolean  worldDraw       (ZcGiWorldDraw * wd)            = 0;

    virtual void            viewportDraw    (ZcGiViewportDraw * vd)         = 0;

    virtual ZSoft::Boolean  isPersistent    (void) const                    = 0;
    virtual ZcDbObjectId    id              (void) const                    = 0;
    virtual DrawableType    drawableType() const { return kGeometry; }
    virtual void            setGsNode       (ZcGsNode * gsnode)             = 0;
    virtual ZcGsNode*       gsNode          (void) const                    = 0;

    virtual ZSoft::UInt32   viewportDrawLogicalFlags (ZcGiViewportDraw * vd) { return 0; }
    virtual  ZSoft::Boolean RolloverHit(ZSoft::ULongPtr nSubentId,
                                        ZSoft::ULongPtr nMouseFlags,
                                        ZSoft::Boolean bReset ) {
                        return ZSoft::kFalse; }
};

#pragma pack (pop)
#endif 
