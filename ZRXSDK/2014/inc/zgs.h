
#pragma once

#include "zAcArray.h"
#include "zAdAChar.h"
#include "zgept3dar.h"
#include "zdbid.h"


class ZcGiDrawable;
class ZcGeMatrix3d;
class ZcGePoint3d;
class ZcGeVector3d;
class ZcGePoint2d;

class ZcGsView;
class ZcGsModel;
class ZcGsDevice;
class ZcGsConfig;
class ZcGsReactor;
class ZcGsClassFactory;
class ZcGiVisualStyle;
class ZcGiContextualColors;
namespace Ztil
{
    class Image;
};

namespace GS 
{

    enum ErrorStatus {
        kSuccess,
        kOutOfRange,
        kInvalidInput
    };

    enum DeviceType {
        kScreenDevice =         0,
        kOffScreenDevice =      1,
        kSelectionDevice =      2
    };

    enum HighlightStyle {
        kHighlightDashed =               0,
        kHighlightThicken =              1,
        kHighlightDashedAndThicken =     2,
        kHighlightCustom =               3
    };


};

#define SCALAR_MIN     (-2147483647 - 1) 
#define SCALAR_MAX       2147483647      
#pragma pack (push, 8)

class ZcGsDCPoint 
{
public:
    enum            MaxFlag { Maximum };
    enum            MinFlag { Minimum };

                    ZcGsDCPoint (void) { }
                    ZcGsDCPoint (long xin, long yin) : x (xin), y (yin) { }

                    ZcGsDCPoint (MaxFlag) { x = SCALAR_MAX; y = SCALAR_MAX; }
                    ZcGsDCPoint (MinFlag) { x = SCALAR_MIN; y = SCALAR_MIN; }

    void            operator=   (MaxFlag) { x = SCALAR_MAX; y = SCALAR_MAX; }
    void            operator=   (MinFlag) { x = SCALAR_MIN; y = SCALAR_MIN; }

	void            operator=   (ZcGsDCPoint const & r)              { x =  r.x;   y =  r.y; }
	bool            operator==  (ZcGsDCPoint const & r) const { return x == r.x && y == r.y; }
	bool            operator!=  (ZcGsDCPoint const & r) const { return x != r.x || y != r.y; }

    long            x;
    long            y;
};

class ZcGsDCRect 
{
public:
    enum            NullFlag { Null    };

	                ZcGsDCRect (void) { }
	                ZcGsDCRect (ZcGsDCPoint const & min, ZcGsDCPoint const & max)
                        : m_min (min)
                        , m_max (max) { }
	                ZcGsDCRect (long l, long r, long b, long t)
                        : m_min (l,b)
                        , m_max (r,t) { }
	                ZcGsDCRect (NullFlag) { set_null(); }

	ZcGsDCRect &    operator= (ZcGsDCRect const & other) {
                        m_min = other.m_min;
                        m_max = other.m_max;
                        return *this;
                    }
	void            operator|= (ZcGsDCRect const & rightside) {
                        if (m_min.x > rightside.m_min.x)            
                            m_min.x = rightside.m_min.x;            
                        if (m_max.x < rightside.m_max.x)            
                            m_max.x = rightside.m_max.x;

                        if (m_min.y > rightside.m_min.y)
                            m_min.y = rightside.m_min.y;
                        if (m_max.y < rightside.m_max.y)
                            m_max.y = rightside.m_max.y;
                    }
	void            operator&= (ZcGsDCRect const & rightside) {
                        if (m_min.x < rightside.m_min.x)
                            m_min.x = rightside.m_min.x;            
                        if (m_max.x > rightside.m_max.x)            
                            m_max.x = rightside.m_max.x;

                        if (m_min.y < rightside.m_min.y)
                            m_min.y = rightside.m_min.y;
                        if (m_max.y > rightside.m_max.y)
                            m_max.y = rightside.m_max.y;

                        if (m_min.x > m_max.x || m_min.y > m_max.y)
                            *this = Null;
                    }
	bool            operator== (ZcGsDCRect const & rightside) const {
                        return m_min == rightside.m_min &&
                               m_max == rightside.m_max;    
                    }
	bool            operator!= (ZcGsDCRect const & rightside) const {
                        return !(*this == rightside);
                    }

    void            set_null (void) {                   
		                m_min = ZcGsDCPoint::Maximum;   
		                m_max = ZcGsDCPoint::Minimum;   
                    }                                   

	bool            is_null (void) const {
                        ASSERT ((m_min.x <= m_max.x && m_min.y <= m_max.y) ||
			                    (m_min == ZcGsDCPoint::Maximum && m_max == ZcGsDCPoint::Minimum));
                        return m_min.x > m_max.x;
                    }

	bool            within (ZcGsDCRect const & rightside) const {
		                ASSERT (!is_null());                        
		                return m_min.x >= rightside.m_min.x &&      
			                   m_min.y >= rightside.m_min.y &&      
                               m_max.x <= rightside.m_max.x &&
                               m_max.y <= rightside.m_max.y;
                    }

	ZcGsDCPoint     m_min;
	ZcGsDCPoint     m_max;
};

struct ZcGsColor
{
	unsigned char   m_red;
    unsigned char   m_green;
    unsigned char   m_blue;
    unsigned char   m_filler;
};

typedef void *      ZcGsWindowingSystemID;       


class ZcGsNode
{
public:
    virtual ZcGiDrawable *  drawable        (void) const = 0;
    virtual void            setDrawableNull (void)       = 0;
};


class ZcGsView
{
public:

	enum RenderMode
	{
		k2DOptimized,               
		kBoundingBox,               
		kWireframe,                 
		kHiddenLine,                
		kFlatShaded,                
		kGouraudShaded,             
		kFlatShadedWithWireframe,   
		kGouraudShadedWithWireframe,
		kCount,
		kNone = kCount
	};

    enum Projection
    {
        kParallel,
        kPerspective
    };

    enum SelectionMode
    {
        kWindow,
        kCrossing,
        kFence,
        kWPoly,
        kCPoly,
    };

    enum DefaultLightingType
    {
        kOneLight,
        kTwoLights,
        kBackLight
    };

	virtual                    ~ZcGsView            (void) { }

	virtual void                setViewport         (const ZcGePoint2d & lowerLeft,
		                                             const ZcGePoint2d & upperRight)            = 0;
	virtual void                setViewport         (const ZcGsDCRect  & screen_rect)           = 0;
	virtual void                getViewport         (      ZcGePoint2d & lowerLeft,
		                                                   ZcGePoint2d & upperRight)  const     = 0;
	virtual void                getViewport         (      ZcGsDCRect  & screen_rect) const     = 0;

	virtual void                setViewportClipRegion       (int                 contours, 
                                                             int const *         counts, 
		                                                     ZcGsDCPoint const * points)        = 0;
    virtual void                removeViewportClipRegion    (void)                              = 0;

	virtual void                setViewportBorderProperties (ZcGsColor const &   color,
                                                             int                 weight)        = 0;
	virtual void                getViewportBorderProperties (ZcGsColor &         color,
                                                             int &               weight) const  = 0;

    virtual void                setViewportBorderVisibility (bool                bVisible)      = 0;
    virtual bool                isViewportBorderVisible     (void) const                        = 0;

	virtual void                setView             (const ZcGePoint3d &  position,
		                                             const ZcGePoint3d &  target,
		                                             const ZcGeVector3d&  upVector,
                                                     double               fieldWidth,
                                                     double               fieldHeight,
                                                     Projection           projection = kParallel) = 0;

	virtual ZcGePoint3d         position            (void) const            = 0;
	virtual ZcGePoint3d         target              (void) const            = 0;
	virtual ZcGeVector3d        upVector            (void) const            = 0;
    virtual bool                isPerspective       (void) const            = 0;
    virtual double              fieldWidth          (void) const            = 0;
    virtual double              fieldHeight         (void) const            = 0;

    virtual void                setEnableFrontClip  (bool enable)           = 0;
    virtual bool                isFrontClipped      (void) const            = 0;
    virtual void                setFrontClip        (double distance)       = 0;
    virtual double              frontClip           (void) const            = 0;

    virtual void                setEnableBackClip   (bool enable)           = 0;
    virtual bool                isBackClipped       (void) const            = 0;
    virtual void                setBackClip         (double distance)       = 0;
    virtual double              backClip            (void) const            = 0;
    
	virtual ZcGeMatrix3d        viewingMatrix       (void) const            = 0;
	virtual ZcGeMatrix3d        projectionMatrix    (void) const            = 0;
	virtual ZcGeMatrix3d        screenMatrix        (void) const            = 0;
	virtual ZcGeMatrix3d        worldToDeviceMatrix (void) const            = 0;
	virtual ZcGeMatrix3d        objectToDeviceMatrix(void) const            = 0;

    virtual void                setMode             (RenderMode mode)       = 0;
    virtual RenderMode          mode                (void) const            = 0;

	virtual bool                add                 (ZcGiDrawable * drawable, 
                                                     ZcGsModel    * model)    = 0;
	virtual bool                erase               (ZcGiDrawable * drawable) = 0;
    virtual void                eraseAll            (void)                    = 0;

    virtual void                invalidate          (void)                  = 0;
	virtual void                invalidate          (const ZcGsDCRect &rect)= 0;
    virtual bool                isValid             (void) const            = 0;

    virtual void                update              (void)                  = 0;
    virtual void                beginInteractivity  (double fFrameRateInHz) = 0;
    virtual void                endInteractivity    (void)                  = 0;
    virtual void                flush               (void)                  = 0;

    virtual void                setMaximumUpgrade   (int step)              = 0;
    virtual int                 maximumUpgrade      (void)                  = 0;
    virtual void                setMinimumDegrade   (int step)              = 0;
    virtual int                 minimumDegrade      (void)                  = 0;

    virtual void                hide                (void)                  = 0;
    virtual void                show                (void)                  = 0;
    virtual bool                isVisible           (void)                  = 0;

    virtual void                freezeLayer         (LONG_PTR layerID)      = 0;
    virtual void                thawLayer           (LONG_PTR layerID)      = 0;
    virtual void                clearFrozenLayers   (void)                  = 0;

    virtual void                invalidateCachedViewportGeometry (void)     = 0;


	virtual void                dolly               (const ZcGeVector3d & vector)   = 0;
    virtual void                dolly               (double x, double y, double z)  = 0;
    virtual void                roll                (double angle)                  = 0;
    virtual void                orbit               (double x, double y)            = 0;
    virtual void                zoom                (double factor)                 = 0;
	virtual void                zoomExtents         (const ZcGePoint3d& minPoint, 
                                                     const ZcGePoint3d& maxPoint)   = 0;
	virtual void                zoomWindow          (const ZcGePoint2d& lowerLeft, 
                                                     const ZcGePoint2d& upperRight) = 0;
    virtual void                pan                 (double x, double y)            = 0;

	virtual bool                pointInView         (const ZcGePoint3d& pnt)        = 0;
	virtual bool                extentsInView       (const ZcGePoint3d& minPoint, 
                                                     const ZcGePoint3d& maxPoint)   = 0;

	virtual ZcGsView *          clone               (bool bCloneViewParameters = true,
                                                     bool bCloneGeometry       = false)  = 0;

    virtual bool                exceededBounds      (void)                          = 0;

    virtual void                enableStereo        (bool bEnable)                  = 0;
    virtual bool                isStereoEnabled     (void) const                    = 0;
    virtual void                setStereoParameters (double     magnitude,
                                                     double     parallax)           = 0;
    virtual void                getStereoParameters (double &   magnitude, 
                                                     double &   parallax) const     = 0;

	virtual void                getSnapShot         (Ztil::Image       * pOutput,
                                                     ZcGsDCPoint const & offset)    = 0;

	virtual bool                RenderToImage       (Ztil::Image* pOutput,
                                                     ZcGiDrawable* pSettings,
                                                     void* pProgressMonitor,
                                                     const ZcGsDCRect & rectScreen,
                                                     bool bReuseScene = false)      = 0;


	virtual ZcGsDevice *        getDevice(void) const = 0;


	virtual void                setVisualStyle      (const ZcDbObjectId visualStyleId)      = 0;
	virtual ZcDbObjectId        visualStyle         (void) const                            = 0;
	virtual void                setVisualStyle      (const ZcGiVisualStyle &visualStyle)    = 0;
	virtual bool                visualStyle         (ZcGiVisualStyle &visualStyle) const    = 0;


	virtual void                setBackground       (const ZcDbObjectId backgroundId)       = 0;
	virtual ZcDbObjectId        background          (void) const                            = 0;


    virtual void                enableDefaultLighting (bool bEnable, 
                                                       DefaultLightingType type = kTwoLights) = 0;

	virtual void                getNumPixelsInUnitSquare(const ZcGePoint3d& givenWorldpt, 
		                                                       ZcGePoint2d& pixelArea,
                                                               bool includePerspective = true) const = 0;      
                                                                                    
};

class ZcGsModel
{
public:

	enum RenderType
	{  
		kMain,              
		kSprite,            
		kDirect,            
		kHighlight,         
		kHighlightSelection,
		kCount              
	};

	enum InvalidationHint
	{
		kInvalidateNone,
		kInvalidateIsolines,
		kInvalidateViewportCache,
		kInvalidateAll,
		kInvalidateAllStatic,
		kInvalidateFacets,
		kInvalidateFills,
		kInvalidateLinetypes,
		kInvalidateMaterials,
		kInvalidateLayers,
	};

	virtual                    ~ZcGsModel           (void) { }

	virtual bool                addSceneGraphRoot   (ZcGiDrawable * pRoot)      = 0;
	virtual bool                eraseSceneGraphRoot (ZcGiDrawable * pRoot)      = 0;

	virtual void                onAdded             (ZcGiDrawable * pAdded,        
		                                             ZcGiDrawable * pParent)    = 0;
	virtual void                onAdded             (ZcGiDrawable * pAdded,
                                                     LONG_PTR       parentID)   = 0;
                                                    
	virtual void                onModified          (ZcGiDrawable * pModified,
		                                             ZcGiDrawable * pParent)    = 0;
	virtual void                onModified          (ZcGiDrawable * pModified, 
                                                     LONG_PTR       parentID)   = 0;
                                                    
	virtual void                onErased            (ZcGiDrawable * pErased,
		                                             ZcGiDrawable * pParent)    = 0;
	virtual void                onErased            (ZcGiDrawable * pErased, 
                                                     LONG_PTR       parentID)   = 0;

    virtual void                onPaletteModified   (void) = 0;


	virtual void                setTransform        (const ZcGeMatrix3d &)      = 0;
	virtual ZcGeMatrix3d        transform           (void) const                = 0;
	virtual void                setExtents          (const ZcGePoint3d &,
                                                     const ZcGePoint3d &)       = 0;

    virtual void                invalidate          (InvalidationHint hint)     = 0;

    virtual void                setViewClippingOverride (bool bOverride)        = 0;
	virtual void                setRenderModeOverride   (ZcGsView::RenderMode mode = 
                                                         ZcGsView::kNone)       = 0;

	virtual void                setVisualStyle      (const ZcDbObjectId visualStyleId)      = 0;
	virtual ZcDbObjectId        visualStyle         (void) const                            = 0;
	virtual void                setVisualStyle      (const ZcGiVisualStyle &visualStyle)    = 0;
	virtual bool                visualStyle         (ZcGiVisualStyle &visualStyle) const    = 0;


	virtual void                setBackground       (const ZcDbObjectId backgroundId)       = 0;
	virtual ZcDbObjectId        background          (void) const                            = 0;


    virtual void                enableLinetypes     (bool bEnable)              = 0;
    virtual bool                linetypesEnabled    (void) const                = 0;

    virtual void                setEnableSectioning      (bool enable)          = 0;
    virtual bool                isSectioningEnabled      (void) const           = 0;
	virtual bool                setSectioning            (const ZcGePoint3dArray & pts, 
                                                          const ZcGeVector3d &     upVector) = 0;
	virtual bool                setSectioning            (const ZcGePoint3dArray & pts, 
                                                          const ZcGeVector3d &     upVector, 
                                                          double                   top, 
                                                          double                   bottom)   = 0;
	virtual void                setSectioningVisualStyle (const ZcDbObjectId visualStyleId)  = 0;


    virtual RenderType          renderType               (void)                     = 0;

	virtual double              shadowPlaneLocation      (void) const               = 0;
	virtual void                setShadowPlaneLocation   (double planeLocationZ)    = 0;
};

class ZcGsDevice
{
public:

    enum RendererType
    {
        kDefault,
        kSoftware,
        kSoftwareNewViewsOnly,
        kFullRender,
        kSelectionRender
    };

	virtual                    ~ZcGsDevice          (void) { }
	virtual void                invalidate          (void)                  = 0;
	virtual void                invalidate          (const ZcGsDCRect &rect)= 0;
	virtual bool                isValid             (void) const            = 0;

	virtual void                update              (ZcGsDCRect* pUpdatedRect = NULL) = 0;

    virtual void                onSize              (int width, int height) = 0;
    virtual void                onRealizeForegroundPalette (void)           = 0;
    virtual void                onRealizeBackgroundPalette (void)           = 0;
    virtual void                onDisplayChange     (int nBitsPerPixel,     
                                                     int nXRes,             
                                                     int nYRes)             = 0;

	virtual bool                add                 (ZcGsView * view)       = 0;
	virtual bool                erase               (ZcGsView * view)       = 0;
    virtual void                eraseAll            (void)                  = 0;
                                                                            
	virtual bool                setBackgroundColor  (ZcGsColor color)       = 0;
	virtual ZcGsColor           getBackgroundColor  (void)                  = 0;
                                                    
	virtual void                setLogicalPalette   (const ZcGsColor * palette, 
                                                     int nCount)            = 0;
	virtual void                setPhysicalPalette  (const ZcGsColor * palette, 
                                                     int nCount)            = 0;

	virtual void                getSnapShot         (Ztil::Image             * pOutput,
                                                     ZcGsDCPoint const & offset) = 0;

	virtual void                setDeviceRenderer   (RendererType type)     = 0;
	virtual RendererType        getDeviceRenderer   (void)                  = 0;
};

class ZcGsConfig
{
public:

    enum Handedness
    {
        kLeft,
        kRight
    };    

	enum Quality
	{
		kLowQuality,
		kMediumQuality,
		kHighQuality
	};

	enum DegradationChannel
	{
		kViewportDraw,
		kLineAntialias,
		kLighting,
		kTransparencyQuality,
		kShadowsFull,
		kTransparency,
		kDiscardBackfaces,
		kShadowsGround,
		kEdgeStyles,
		kFacetEdges,
		kFastSilhouette,
		kTextures,
		kMaterials,
		kLightingQuality,
		kBackgrounds,
		kIntersectEdges,
		kFaceted,
		kWireframe,
		kDegradationChannels
	};

    enum HardwareFeature { 
        kHwAcceleration,
        kHwGeometryAccel,
        kHwAntiAliasing,
        kHwGooch,
        kHwShadows,
        kHwTextureCompression,
        kHwFeatures  
    };

	virtual                    ~ZcGsConfig                      (void) { }
                                            
	virtual bool                configure                       (const ZTCHAR * pszConfigInfo, 
                                                                 bool bShowDialog)              = 0;
    virtual bool                saveSettings                    (void)                          = 0;

	virtual void                driverName                      (ZTCHAR * pszPath, 
                                                                 int nStrLen) const             = 0;
    virtual int                 driverVersion                   (void) const                    = 0;
    virtual int                 driverRevision                  (void) const                    = 0;
	virtual void                driverPath                      (ZTCHAR *        pszPath, 
                                                                 int            nStrLen) const  = 0;
	virtual void                setDriverPath                   (const ZTCHAR *  pszPath)        = 0;

	virtual void                currentDisplayDriver            (ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR *        pszDriver,
                                                                 int            nDriverStrLen,
                                                                 bool &         bHardwareAccelerated)  = 0;

	virtual void                hardwareAcceleratedDriver       (ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR *        pszDriver,
                                                                 int            nDriverStrLen)  = 0;
	virtual void                setHardwareAcceleratedDriver    (const ZTCHAR *  pszPath,
		                                                         const ZTCHAR *  pszDriver)      = 0;

	virtual void                defaultHardwareAcceleratedDriver(ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR *        pszDriver,
                                                                 int            nDriverStrLen)  = 0;
	virtual void                hardwareAcceleratedDrivers      (ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR **       pszDrivers,
                                                                 int            nDrivers)       = 0;
    virtual int                 numHardwareAcceleratedDrivers   (void)                          = 0;

    virtual void                setDynamicTessellation          (bool bDynamicTessellation)     = 0;
    virtual bool                dynamicTessellation             (void)                          = 0;

    virtual GS::ErrorStatus     setMaxLODs                      (int nLevels)                   = 0;
    virtual int                 maxLODs                         (void)                          = 0;

    virtual GS::ErrorStatus     setSurfaceTessellationTol       (int surfaceTessellationTol)    = 0;
    virtual int                 surfaceTessellationTol          (void)                          = 0;

    virtual GS::ErrorStatus     setCurveTessellationTol         (int curveTessellationTol)      = 0;
    virtual int                 curveTessellationTol            (void)                          = 0;

    virtual void                setUseHalfPixelDeviation        (bool bUseHalfPixelDeviation)   = 0;
    virtual bool                useHalfPixelDeviation           (void)                          = 0;

    virtual int                 frameRate                       (void)                          = 0;
    virtual GS::ErrorStatus     setFrameRate                    (int nFramesPerSecond)          = 0;

    virtual void                setAdaptiveDegradation          (bool bAdaptiveDegradation)     = 0;
    virtual bool                adaptiveDegradation             (void)                          = 0;

    virtual int                 degradationChainPosition        (DegradationChannel channel)    = 0;
    virtual DegradationChannel  degradationChannelAt            (int position)                  = 0;
    virtual void                shiftDegradationChainPosition   (DegradationChannel channel,
                                                                 bool bShiftDown)               = 0;
    virtual bool                canDegradeChannel               (DegradationChannel channel)    = 0;
    virtual void                setCanDegradeChannel            (DegradationChannel channel,
                                                                 bool bDegrade)                 = 0;

    virtual void                setCacheViewportDrawGeometry    (bool bCacheViewportGeometry)   = 0;
    virtual bool                cacheViewportDrawGeometry       () const                        = 0;

    virtual void                setUseDisplayLists              (bool bUseDisplayLists)         = 0;
    virtual bool                useDisplayLists                 (void)                          = 0;

    virtual void                setRedrawOnWindowExpose         (bool bRedrawWindowExpose)      = 0;
    virtual bool                redrawOnWindowExpose            (void)                          = 0;

    virtual Handedness          handedness                      (void) const                    = 0;
    virtual void                setHandedness                   (Handedness)                    = 0;

    virtual bool                discardBackFaces                (void)                          = 0;
    virtual void                setDiscardBackFaces             (bool bDiscardBackFaces)        = 0;

    virtual Quality             transparency                    (void)                          = 0;
    virtual void                setTransparency                 (Quality quality)               = 0;

    virtual bool                isFeatureEnabled                (HardwareFeature feature)       = 0;
    virtual void                setFeatureEnabled               (HardwareFeature feature,
                                                                 bool bEnable = true)           = 0;
    virtual bool                isFeatureAvailable              (HardwareFeature feature)       = 0;
    virtual bool                isFeatureRecommended            (HardwareFeature feature)       = 0;
};

typedef ZcGiDrawable*    (* ZcGsGetInterfaceFunc)            (LONG_PTR objectId,
                                                              bool bNeedsValidation);   // does id need validation?
typedef void             (* ZcGsReleaseInterfaceFunc)        (ZcGiDrawable*);

class ZcGsReactor
{
public:
	                            ZcGsReactor                 (void)  { }
	virtual                    ~ZcGsReactor                 (void)  { } 
	virtual void                viewWasCreated              (ZcGsView * pView)  { }
	virtual void                viewToBeDestroyed           (ZcGsView * pView)  { }
	virtual void                gsToBeUnloaded              (ZcGsClassFactory * pClassFactory) { }
    virtual void                configWasModified           (void) { }
};

struct ZcGsClientViewInfo
{
	ZcGsClientViewInfo()
        : viewportId(0)
		, zcadWindowId(0)
        , viewportObjectId(0)
        , contextColors(NULL) { }

	LONG_PTR viewportId;
	LONG_PTR zcadWindowId;
	LONG_PTR viewportObjectId;
	ZcGiContextualColors* contextColors;
};


class ZcGsClassFactory
{
public:

	virtual                    ~ZcGsClassFactory(void) { }

	virtual ZcGsModel *         createModel     (ZcGsModel::RenderType,
                                                 LONG_PTR databaseId,
                                                 ZcGsGetInterfaceFunc, 
                                                 ZcGsReleaseInterfaceFunc)  = 0;
	virtual void                deleteModel     (ZcGsModel * model)         = 0;

	virtual ZcGsView *          createView      (const ZcGsClientViewInfo * pInfo   = NULL,
                                                 bool bEnableLayerVisibilityPerView = false) = 0;
	virtual void                deleteView      (ZcGsView * view)           = 0;

	virtual ZcGsDevice *        createDevice    (ZcGsWindowingSystemID id,
                                                 GS::DeviceType deviceType = GS::kScreenDevice)  = 0;
	virtual ZcGsDevice *        createOffScreenDevice(void)                 = 0;
	virtual void                deleteDevice    (ZcGsDevice * device)       = 0;

	virtual ZcGsConfig *        getConfig       (void)                      = 0;
	virtual void                releaseConfig   (ZcGsConfig * config)       = 0;

	virtual void                addReactor      (ZcGsReactor * pReactor)    = 0;
	virtual void                removeReactor   (ZcGsReactor * pReactor)    = 0;
};

typedef ZcGsClassFactory *    (* ZcGsCreateClassFactoryFunc)(void);
typedef void                  (* ZcGsDeleteClassFactoryFunc)(ZcGsClassFactory *);

#define ZCGS_CREATE_CLASS_FACTORY "CreateClassFactory"
#define ZCGS_DELETE_CLASS_FACTORY "DeleteClassFactory"

#pragma pack (pop)
