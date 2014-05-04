

#ifndef _ZCGI_H
#define _ZCGI_H 1

#define ZCGI_SERVICES  ZCRX_T("ZcGiServices")

typedef enum {
    eZcGiRegenTypeInvalid = 0,
    kZcGiStandardDisplay = 2,
    kZcGiHideOrShadeCommand,
    kZcGiRenderCommand,
    kZcGiShadedDisplay = kZcGiRenderCommand,
    kZcGiForExplode,
    kZcGiSaveWorldDrawForProxy
} ZcGiRegenType;

#define kZcGiSaveWorldDrawForR12 kZcGiForExplode 

typedef enum {
     kZcGiFillAlways = 1,
     kZcGiFillNever
} ZcGiFillType;

typedef enum {
    kZcGiInvisible = 0,
    kZcGiVisible,
    kZcGiSilhouette
} ZcGiVisibility;

typedef enum {
    kZcGiArcSimple = 0,                 
    kZcGiArcSector,                     
    kZcGiArcChord                       
} ZcGiArcType;

typedef enum {
    kZcGiCounterClockwise = -1,
    kZcGiNoOrientation = 0,
    kZcGiClockwise = 1
} ZcGiOrientationType;

typedef enum {
    kZcGiMaxDevForCircle = 0,
    kZcGiMaxDevForCurve,
    kZcGiMaxDevForBoundary,
    kZcGiMaxDevForIsoline,
    kZcGiMaxDevForFacet
} ZcGiDeviationType;

typedef enum {
    kZcGiBitonal,
    kZcGiPalette,
    kZcGiGray,
    kZcGiRGBA,
    kZcGiBGRA,
    kZcGiARGB,
    kZcGiABGR,
    kZcGiBGR,
    kZcGiRGB                              
} ZcGiImageOrg;

typedef enum {
    kZcGiXLeftToRightTopFirst,
    kZcGiXLeftToRightBottomFirst,
    kZcGiXRightToLeftTopFirst,
    kZcGiXRightToLeftBottomFirst,
    kZcGiYTopToBottomLeftFirst,
    kZcGiYTopToBottomRightFirst,
    kZcGiYBottomToTopLeftFirst,
    kZcGiYBottomToTopRightFirst
} ZcGiImageOrient;

typedef enum {
    kDefaultScaleFilter,
    kNearestScaleFilter,
    kBellScaleFilter,
    kMitchellScaleFilter,
    kTriangleScaleFilter,
    kCubicScaleFilter,
    kBsplineScaleFilter,
    kLanczos3ScaleFilter
} ZcGiScaleFilterType;

typedef enum {
    kDefaultRotationFilter,
    kInterpolatedRotationFilter,
    kNearestRotationFilter,
} ZcGiRotationFilterType;

typedef enum {
    kDefaultScale,
    kRelativeScale,
    kUnTransformedScale
} ZcGiScaleType;

enum ZcGiEdgeStyleMaskValues {
    kZcGiNoEdgeStyleMask = 0,
    kZcGiJitterMask      = 1,
    kZcGiOverhangMask    = 2,
    kZcGiEdgeColorMask   = 4
};

typedef unsigned int ZcGiEdgeStyleMask;

#include "zrxobject.h"
#include "zAdAChar.h"
#include "zdbpl.h"
#include "zgemat3d.h"
#include "zgemat2d.h"
#include "zgepnt2d.h"
#include "zdbcolor.h"
#include "zacdb.h"
#include "zAcGiStyleAttributes.h"
#include "assert.h"

#pragma pack (push, 8)

struct ZcGiSentScanLines 
{
    enum IsmRequestStatus {
        eOk,                           
        eInvalidInput,                 
        eInvalidColorDepth,            
        eInvalidPixelRequest,          
        eInvalidDeliveryMethod,        
        eNoValidCompressors,           
        eInsufficientMemory            
    };

    ZSoft::Int8 *    mpPixelBuffer;          
    ZSoft::UInt32    mRowBytes;              
    void *           mpImageId;              
    ZSoft::Int16     mIsCancelled;           
    ZSoft::Int16     mHasFailed;
    ZSoft::UInt32    mBytes;
    IsmRequestStatus mRequestStatus;

};

struct ZcGiRequestScanLines 
{
    enum IEDitherMethod 
    {
        kIEAnyPalette,
        kCustomDithering,
        kCustomDitheringMethod
    };

    enum IEColorSystem
    {
        kBitonal,
        kCMY,
        kCMYK,
        kRGB
    };

    enum ImagePaletteType
    {
        kFromDevice,
        kFromIeWholeImage
    };

    ZcGiRequestScanLines()
        : mPixelMinX          (0)
        , mPixelMinY          (0)
        , mPixelMaxX          (0)
        , mPixelMaxY          (0)
        , mpImageId           (0)
        , mImageOrg           (kZcGiBitonal)
        , mImageOrient        (kZcGiXLeftToRightTopFirst)
        , mWindowId           (0)
        , mColorDepth         (8)
        , mPaletteIncarnation (0)
        , mpPalette           (0)
        , mIsDisplay          (0)
        , mRasterRatio        (1.0)
        , mPaletteType        (kFromDevice)
        , mpDataBuffer        (0)
        , mRowWidth           (0)
        , mpBoundaryPoints    (0)
        , mnContours          (0)
        , mpCounts            (0)
        , mScalingType        (kDefaultScale)
        , mScaleFilterType    (kDefaultScaleFilter)
        , mRotationFilterType (kDefaultRotationFilter)
        , mnTotalChunks       (0)
        , mnThisChunk         (0)
    {
    }

    ZSoft::UInt32       mPixelMinX;             
    ZSoft::UInt32       mPixelMinY;
    ZSoft::UInt32       mPixelMaxX;
    ZSoft::UInt32       mPixelMaxY;
    ZcGePoint2d         mLowerLeft;             
    ZcGePoint2d         mUpperRight;            
    void *              mpImageId;              
    ZcGiImageOrg        mImageOrg;              
    ZcGiImageOrient     mImageOrient;           
    ZSoft::Int16        mWindowId;              
    ZSoft::Int16        mColorDepth;            
    union {
        ZSoft::Int16 mBackgroundIndex;
        ZSoft::Int8 mBackgroundRGB[3];
    }                   mBackgroundColor;       
    union {
        ZSoft::Int16 mTransparentIndex;
        ZSoft::Int8 mTransparentRGB[3];
    } mTransparentColor;                        
    union {
        ZSoft::Int16 mEntityIndex;
        ZSoft::Int8 mEntityRGB[3];
    }                   mEntityColor;           
    ZSoft::Int32        mPaletteIncarnation;    
    ZSoft::Int8 *       mpPalette;              
    ZSoft::Int16        mIsDisplay;             
    double              mRasterRatio;           
    ZcGeMatrix2d        mPixelToDc;             
    ImagePaletteType    mPaletteType;
    void *              mpDataBuffer;
    ZSoft::Int32        mRowWidth;
    ZSoft::Int32        mNumRows;
    ZSoft::Int32 const *mpBoundaryPoints;        
    ZSoft::UInt32       mnContours;              
    ZSoft::Int32 const *mpCounts;                
    ZcGiScaleType          mScalingType;
    ZcGiScaleFilterType    mScaleFilterType;
    ZcGiRotationFilterType mRotationFilterType;
    short                  mnTotalChunks;
    short                  mnThisChunk;
	ZSoft::Int32		mOrigin[2];
	ZSoft::Int32		mLowerRightPt[2];
	ZSoft::Int32		mUpperLeftPt[2];
};

struct ZcGiClipBoundary
{
    ZcGeVector3d        m_vNormal;
    ZcGePoint3d         m_ptPoint;
    ZcGePoint2dArray    m_aptPoints;    

    ZcGeMatrix3d        m_xToClipSpace;
    ZcGeMatrix3d        m_xInverseBlockRefXForm; 

    ZSoft::Boolean      m_bClippingFront;
    ZSoft::Boolean      m_bClippingBack;
    double              m_dFrontClipZ;
    double              m_dBackClipZ;

    ZSoft::Boolean      m_bDrawBoundary;
};

class OwnerDraw3d
{
public:
    virtual ~OwnerDraw3d(void) {};
};

typedef enum ZcGiColorIntensity 
{
    kZcGiMinColorIntensity = 0x0,
    kZcGiColorIntensity1   = 0x1,
    kZcGiColorIntensity2   = 0x2,
    kZcGiColorIntensity3   = 0x3,
    kZcGiColorIntensity4   = 0x4,
    kZcGiColorIntensity5   = 0x5,
    kZcGiColorIntensity6   = 0x6,
    kZcGiMaxColorIntensity = 0x7 
};

class ZcGiColorRGB
{
public:
    ZcGiColorRGB (void)
        : red   (0.0)
        , green (0.0)
        , blue  (0.0)
    { }

    ZcGiColorRGB (double r, double g, double b)
        : red   (r)
        , green (g)
        , blue  (b)
    { }

    double red;
    double green;
    double blue;
};

inline ZcGiColorRGB operator* (const ZcGiColorRGB& c1, const ZcGiColorRGB& c2)
{
    return ZcGiColorRGB(c1.red   * c2.red,
                        c1.green * c2.green,
                        c1.blue  * c2.blue);
}

inline ZcGiColorRGB operator* (const ZcGiColorRGB& c, double s)
{
    return ZcGiColorRGB(s * c.red,
                        s * c.green,
                        s * c.blue);
}

inline ZcGiColorRGB operator* (double s, const ZcGiColorRGB& c)
{
    return c * s;
}

inline ZcGiColorRGB operator+ (const ZcGiColorRGB& c1, const ZcGiColorRGB& c2)
{
    return ZcGiColorRGB(c1.red   + c2.red,
                        c1.green + c2.green,
                        c1.blue  + c2.blue);
}

class ZcGiColorRGBA
{
public:
    ZcGiColorRGBA (void)
        : red   (0.0)
        , green (0.0)
        , blue  (0.0)
        , alpha (1.0)
    { }

    ZcGiColorRGBA (double r, double g, double b, double a)
        : red   (r)
        , green (g)
        , blue  (b)
        , alpha (a)
    { }

    double red;
    double green;
    double blue;
    double alpha;
};

inline ZcGiColorRGBA operator* (const ZcGiColorRGBA& c1, const ZcGiColorRGBA& c2)
{
    return ZcGiColorRGBA(c1.red   * c2.red,
                         c1.green * c2.green,
                         c1.blue  * c2.blue,
                         c1.alpha * c2.alpha);
}

inline ZcGiColorRGBA operator*(const ZcGiColorRGBA& c, double s)
{
    return ZcGiColorRGBA(s * c.red,
                         s * c.green,
                         s * c.blue,
                         s * c.alpha);
}

inline ZcGiColorRGBA operator* (double s, const ZcGiColorRGBA& c)
{
    return c * s;
}

inline ZcGiColorRGBA operator+ (const ZcGiColorRGBA& c1, const ZcGiColorRGBA& c2)
{
    return ZcGiColorRGBA(c1.red   + c2.red,
                         c1.green + c2.green,
                         c1.blue  + c2.blue,
                         c1.alpha + c2.alpha);
}

class ZcGiSubEntityTraits;
class ZcGiDrawableTraits;
class ZcGiSubEntityTraitsImp;
class ZcGiWorldGeometry;
class ZcGiViewport;
class ZcGiViewportGeometry;
class ZcGiImpEdgeData;
class ZcGiImpFaceData;
class ZcGiImpVertexData;
class ZcGiImpTextStyle;
class ZcGiTextStyle;
class ZcGiEdgeData;
class ZcGiFaceData;
class ZcGiVertexData;
class OwnerDraw;
class ZcGiImpVariant;
class ZcGiVariant;
class ZcGiContextImp;
class ZcGiContext;
class ZcGiCommonDraw;
class ZcGiGeometry;
class ZcCmEntityColor;
struct TextParams;
struct FontInfo;
class ZcGiMapper;
class ZcGiViewportTraits;
class ZcGiVisualStyleTraits;
class ZcGiEdgeStyle;
class ZcGiContextualColors;

typedef void (*ZcGiWorldSegmentCallback)(const ZcGePoint3d *);

bool zcgiIsValidClipBoundary(const ZcGePoint2dArray& pts);

class ZcGiVariant : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiVariant);

    ZcGiVariant(void);
    virtual ~ZcGiVariant(void);

    ZcGiVariant             (const ZcGiVariant & value);
    ZcGiVariant & operator= (const ZcGiVariant & value);
    virtual bool  operator==(const ZcGiVariant & value) const;

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

    enum VariantType
    {
        kUndefined = 0,
        kBoolean,
        kInt,
        kDouble,
        kColor,
        kString,
        kTable,
    };

    class EnumType
    {
    public:
        explicit EnumType (int value) : m_value(value) { }
        
        template <typename T>
        operator T () { return static_cast<T>(m_value); }

        template <typename T>
        bool operator== (T right) const { return static_cast<int>(right) == m_value; }

        template <typename T>
        bool operator!= (T right) const { return !(*this == right); }

    protected:    
        int m_value;
    };

    ZcGiVariant(bool);
    ZcGiVariant(long);
    ZcGiVariant(double);
    ZcGiVariant(const ZcCmColor&); 
    ZcGiVariant(const ZTCHAR *); 

    VariantType type() const;

    void                set(bool);
    void                set(long);
    void                set(double);
    void                set(const ZcCmColor&); 
    void                set(const ZTCHAR *); 

    bool                asBoolean() const;
    int                 asInt() const;
    double              asDouble() const;
    ZcCmColor           asColor() const;
    ZcString            asString() const;
    ZCDB_PORT float               asFloat() const;
    ZCDB_PORT char                asChar() const;
    ZCDB_PORT unsigned char       asUchar() const;
    ZCDB_PORT short               asShort() const;
    ZCDB_PORT unsigned short      asUshort() const;
    ZCDB_PORT unsigned int        asUint() const;
    ZCDB_PORT long                asLong() const;
    ZCDB_PORT unsigned long       asUlong() const;
    ZCDB_PORT EnumType            asEnum() const;
    Zcad::ErrorStatus   getElem(ZTCHAR *const, ZcGiVariant & value) const;
    const ZcGiVariant*  getElem(ZTCHAR *const) const;
    void                setElem(ZTCHAR *const, const ZcGiVariant&);
    void                deleteElem(ZTCHAR *const);

    int                 getElemCount() const;
    Zcad::ErrorStatus   getElemAt(const int, ZTCHAR*&, ZcGiVariant &) const; 
    ZcGiVariant*        getElemAt(const int, ZTCHAR*&) const;                

    static bool         isEquivalent(ZcGiVariant*, ZcGiVariant*);

private:
    ZcGiImpVariant * mpZcGiImpVariant;
};

class ZcGiContext : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiContext);

    virtual ZSoft::Boolean          isPsOut() const = 0;
    virtual ZSoft::Boolean          isPlotGeneration() const = 0;
    virtual ZcDbDatabase *          database() const = 0;
    virtual bool             isBoundaryClipping() const = 0;

    virtual void          disableFastMoveDrag() const{};

    virtual bool isNesting() const { return false; }

    virtual ZcCmEntityColor   effectiveColor() const { return ZcCmEntityColor(); }
    virtual ZcDb::LineWeight  byBlockLineWeight() const { return ZcDb::kLnWt000; }
    virtual ZcDbObjectId      byBlockPlotStyleNameId() const { return NULL; }
    virtual ZcDbObjectId      byBlockMaterialId() const { return ZcDbObjectId::kNull; }

    virtual bool supportsTrueTypeText() { return false; }
    virtual bool supportsOwnerDraw() {return false;}

    virtual ZcGiContextImp * getImpPtr() { return NULL; }
    virtual const ZcGiContextImp * getConstImpPtr() const { return NULL; }

protected:

    friend class ZcGiTextHook;
    friend class CShFont;
    friend class ZcDbImpText;

    virtual ZcGiWorldSegmentCallback wSegTaker() const { return NULL; }
    virtual int getTrueTypeBoundingBox(ZcGePoint3d const & location,
                                       const wchar_t * text,
                                       int length, TextParams const * tp,
                                       ZcGePoint3d * bbox, float * char_widths)
                                        { return 0; }
    
    virtual int getTrueTypeTextExtents(ZTCHAR const *,unsigned int,double,
                                       int,int,
                                       int,short,short,double,double,
                                       ZcGePoint2d &,ZcGePoint2d &) 
                                       { return -1; }

    virtual int setTrueTypeTransform(const ZcGePoint3d &,const ZcGeVector3d &,
                                     double,double,double,bool,bool) 
                                     { return 0; }

    virtual int drawTrueTypeText(const ZTCHAR *,double,int,bool,
                                 const TextParams &,unsigned int){ return 0; }
    virtual int restoreTrueTypeTransform() { return 0; }
    virtual void bypassHiddenLineRemoval() { return; }
    virtual int setTextStyle(int);
    virtual ZSoft::LongPtr loadTrueTypeFont(const ZTCHAR *,
                                            bool,bool,int,int,FontInfo &)
                                  { return 0; }

};

class ZcGiCommonDraw : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiCommonDraw);
    virtual ZcGiRegenType           regenType() const = 0;
    virtual ZSoft::Boolean          regenAbort() const = 0;
    virtual ZcGiSubEntityTraits&    subEntityTraits() const = 0;
    virtual ZcGiGeometry *   rawGeometry() const = 0;
    virtual ZSoft::Boolean          isDragging() const = 0;

    virtual double                deviation(const ZcGiDeviationType, 
                                            const ZcGePoint3d&) const = 0;
    virtual ZSoft::UInt32           numberOfIsolines() const = 0;
    
    virtual ZcGiContext *      context() = 0;
    virtual bool               secondaryCall() const { return false; }
};

class ZcGiWorldDraw: public ZcGiCommonDraw
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiWorldDraw);
    virtual ZcGiWorldGeometry&      geometry() const = 0;
};

class ZcGiViewportDraw: public ZcGiCommonDraw 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewportDraw);
    virtual ZcGiViewport&        viewport() const = 0;
    virtual ZcGiViewportGeometry& geometry() const = 0;
    virtual ZSoft::UInt32        sequenceNumber() const = 0;
    virtual ZSoft::Boolean       isValidId(const ZSoft::ULongPtr zcgiId) const =0;
    virtual ZcDbObjectId         viewportObjectId() const = 0;
};

class ZcGiViewport: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewport);

    virtual void getModelToEyeTransform(ZcGeMatrix3d&) const = 0;
    virtual void getEyeToModelTransform(ZcGeMatrix3d&) const = 0;
    virtual void getWorldToEyeTransform(ZcGeMatrix3d&) const = 0;
    virtual void getEyeToWorldTransform(ZcGeMatrix3d&) const = 0;

    virtual ZSoft::Boolean isPerspective() const = 0;
    virtual ZSoft::Boolean doPerspective(ZcGePoint3d&) const = 0;
    virtual ZSoft::Boolean doInversePerspective(ZcGePoint3d&) const = 0;

    virtual void getNumPixelsInUnitSquare(const ZcGePoint3d& givenWorldpt,
                                  ZcGePoint2d& pixelArea,
                                  bool includePerspective = true) const = 0;
    virtual void getCameraLocation(ZcGePoint3d& location) const = 0;
    virtual void getCameraTarget(ZcGePoint3d& target) const = 0;
    virtual void getCameraUpVector(ZcGeVector3d& upVector) const = 0;

    virtual ZSoft::ULongPtr viewportId() const = 0;
    virtual ZSoft::Int16  zcadWindowId() const = 0;
    virtual void getViewportDcCorners(ZcGePoint2d& lower_left,
                                      ZcGePoint2d& upper_right) const = 0;

    virtual ZSoft::Boolean getFrontAndBackClipValues(ZSoft::Boolean& clip_front,
                                         ZSoft::Boolean& clip_back,
                                         double& front,
                                         double& back) const = 0;

    virtual double linetypeScaleMultiplier() const = 0;

    virtual double linetypeGenerationCriteria() const = 0;

    virtual ZSoft::Boolean layerVisible(const ZcDbObjectId & idLayer) const { return ZSoft::kTrue; }

    virtual ZcGeVector3d viewDir() const { return ZcGeVector3d::kZAxis; }
    virtual const ZcGiContextualColors* contextualColors() const { return NULL; }
};

class ZcGiContextualColors : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiContextualColors);
    virtual ZSoft::UInt32 gridMajorLines() const = 0;
    virtual ZSoft::UInt32 gridMinorLines() const = 0;
    virtual ZSoft::UInt32 gridAxisLines() const = 0;
    virtual int gridMajorLineTintXYZ() const = 0;
    virtual int gridMinorLineTintXYZ() const = 0;
    virtual int gridAxisLineTintXYZ() const = 0;

    virtual ZSoft::UInt32 lightGlyphs() const = 0;
    virtual ZSoft::UInt32 lightHotspot() const = 0;
    virtual ZSoft::UInt32 lightFalloff() const = 0;
    virtual ZSoft::UInt32 lightStartLimit() const = 0;
    virtual ZSoft::UInt32 lightEndLimit() const = 0;

    virtual ZSoft::UInt32 cameraGlyphs() const = 0;
    virtual ZSoft::UInt32 cameraFrustrum() const = 0;
    virtual ZSoft::UInt32 cameraClipping() const = 0;
    virtual void setContextFlags(ZSoft::UInt32 flg, bool set = true) = 0;
    virtual bool flagsSet(ZSoft::UInt32 flg) const = 0;
};

class ZcGiContextualColors2 : public ZcGiContextualColors
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiContextualColors2);

    virtual ZcCmColor     webMeshColor        (void) const = 0;
    virtual ZcCmColor     webMeshMissingColor (void) const = 0;
    virtual ZcCmColor     lightShapeColor     (void) const = 0;
    virtual ZcCmColor     lightDistanceColor  (void) const = 0;
};

#define ZcGiSelectionMarkerZCADReserveStart         (-2147483647 - 1)
#define ZcGiSelectionMarkerZCADReserveEnd           (ZcGiSelectionMarkerZCADReserveStart + 65535)

#define ZcGiSelectionMarkerZCADSelectionPreviewOff  (ZcGiSelectionMarkerZCADReserveStart + 1)
#define ZcGiSelectionMarkerZCADSelectionPreviewOn   (ZcGiSelectionMarkerZCADReserveStart + 2)

class ZcGiSubEntityTraits: public ZcRxObject 
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSubEntityTraits);

    enum DrawFlags
    {
        kNoDrawFlags        =   0,
        kDrawBackfaces      =   1,
        kDrawHatchGroup     =   2,
    };

    enum ShadowFlags
    {
        kShadowsCastAndReceive  = 0x00,
        kShadowsDoesNotCast     = 0x01,
        kShadowsDoesNotReceive  = 0x02,
        kShadowsIgnore          = kShadowsDoesNotCast | kShadowsDoesNotReceive,
    };

    virtual void              setColor              (const ZSoft::UInt16 color) = 0;
    virtual void              setTrueColor          (const ZcCmEntityColor& color) = 0;
    virtual void              setLayer              (const ZcDbObjectId layerId) = 0;
    virtual void              setLineType           (const ZcDbObjectId linetypeId) = 0;
    virtual void              setSelectionMarker    (const ZSoft::LongPtr markerId) = 0;
    virtual void              setFillType           (const ZcGiFillType) = 0;
    virtual void              setLineWeight         (const ZcDb::LineWeight lw) = 0;
    virtual void              setLineTypeScale      (double dScale = 1.0) = 0;
    virtual void              setThickness          (double dThickness) = 0;
    virtual void              setVisualStyle        (const ZcDbObjectId visualStyleId);
    virtual Zcad::ErrorStatus setEdgeStyleOverride  (ZcGiEdgeStyleMask mask, const ZcGiEdgeStyle& edgeStyle);
    virtual void              setPlotStyleName      (ZcDb::PlotStyleNameType type, const ZcDbObjectId & id = ZcDbObjectId::kNull) {}
    virtual void              setMaterial           (const ZcDbObjectId materialId);
    virtual void              setMapper             (const ZcGiMapper * mapper);
    virtual void              setSectionable        (bool bSectionable);
    virtual Zcad::ErrorStatus setDrawFlags          (ZSoft::UInt32 flags);
    virtual Zcad::ErrorStatus setShadowFlags        (ShadowFlags flags);
    virtual void              setSelectionGeom      (bool bSelectionflag);
    virtual ZSoft::UInt16           color               (void) const = 0;
    virtual ZcCmEntityColor         trueColor           (void) const = 0;
    virtual ZcDbObjectId            layerId             (void) const = 0;
    virtual ZcDbObjectId            lineTypeId          (void) const = 0;
    virtual ZcGiFillType            fillType            (void) const = 0;
    virtual ZcDb::LineWeight        lineWeight          (void) const = 0;
    virtual double                  lineTypeScale       (void) const = 0;
    virtual double                  thickness           (void) const = 0;
    virtual ZcDbObjectId            visualStyle         (void) const;
    virtual Zcad::ErrorStatus       edgeStyleOverride   (ZcGiEdgeStyleMask& mask, ZcGiEdgeStyle& edgeStyle) const;
    virtual ZcDb::PlotStyleNameType getPlotStyleNameId  (ZcDbObjectId& idResult) const { return ZcDb::kPlotStyleNameByLayer ; }
    virtual ZcDbObjectId            materialId          (void) const;
    virtual const ZcGiMapper *      mapper              (void) const;
    virtual bool                    sectionable         (void) const;
    virtual ZSoft::UInt32           drawFlags           (void) const;
    virtual ShadowFlags             shadowFlags         (void) const;
    virtual bool                    selectionGeom       (void) const;
};

inline void
ZcGiSubEntityTraits::setMaterial(const ZcDbObjectId materialId)
{
}

inline ZcDbObjectId
ZcGiSubEntityTraits::materialId(void) const
{
    return ZcDbObjectId::kNull;
}

inline
void ZcGiSubEntityTraits::setMapper (const ZcGiMapper * mapper)
{
}

inline const ZcGiMapper *
ZcGiSubEntityTraits::mapper (void) const
{
    return NULL;
}

inline void
ZcGiSubEntityTraits::setVisualStyle(ZcDbObjectId visualStyleId)
{
}

inline ZcDbObjectId
ZcGiSubEntityTraits::visualStyle(void) const
{
    return ZcDbObjectId::kNull;
}

inline Zcad::ErrorStatus
ZcGiSubEntityTraits::setEdgeStyleOverride (ZcGiEdgeStyleMask mask, const ZcGiEdgeStyle& edgeStyle)
{
    return Zcad::eNotImplementedYet;
}

inline Zcad::ErrorStatus
ZcGiSubEntityTraits::edgeStyleOverride (ZcGiEdgeStyleMask& mask, ZcGiEdgeStyle& edgeStyle) const
{
    return Zcad::eNotImplementedYet;
}

inline void
ZcGiSubEntityTraits::setSectionable(bool bSectionable)
{
}

inline bool
ZcGiSubEntityTraits::sectionable(void) const
{
    return false;
}

inline Zcad::ErrorStatus
ZcGiSubEntityTraits::setDrawFlags (ZSoft::UInt32 flags)
{
    return Zcad::eNotImplementedYet;
}

inline ZSoft::UInt32
ZcGiSubEntityTraits::drawFlags (void) const
{
    return 0;
}

inline Zcad::ErrorStatus
ZcGiSubEntityTraits::setShadowFlags (ShadowFlags flags)
{
    return Zcad::eNotImplementedYet;
}

inline ZcGiSubEntityTraits::ShadowFlags
ZcGiSubEntityTraits::shadowFlags (void) const
{
    return kShadowsCastAndReceive;
}

inline void
ZcGiSubEntityTraits::setSelectionGeom ( bool )
{
}

inline bool
ZcGiSubEntityTraits::selectionGeom ( void ) const
{
    return false;
}

class ZcGiDrawableTraits: public ZcGiSubEntityTraits 
{ 
public:

    friend class            ZcDbLayerTableRecord;

    ZCRX_DECLARE_MEMBERS(ZcGiDrawableTraits);

    virtual void setupForEntity(ZcDbEntity * pEntity);
    virtual void addLight(const ZcDbObjectId& lightId);

protected:

    enum LayerFlags {
        kNone       = 0x00,
        kOff        = 0x01,
        kFrozen     = 0x02,
        kZero       = 0x04
    };

    virtual void    setLayerFlags       (ZSoft::UInt8 flags)        { };
};

inline void
ZcGiDrawableTraits::addLight(const ZcDbObjectId& lightId)
{
}

class ZcGiNonEntityTraits : public ZcGiDrawableTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiNonEntityTraits);
    virtual void                setupForEntity      (ZcDbEntity* pEntity);
    virtual void                addLight(const ZcDbObjectId& id);
    virtual void                setColor            (const ZSoft::UInt16 color);
    virtual ZSoft::UInt16       color               (void) const;
    virtual void                setTrueColor        (const ZcCmEntityColor& color);
    virtual ZcCmEntityColor     trueColor           (void) const;
    virtual void                setLayer            (const ZcDbObjectId layerId);
    virtual ZcDbObjectId        layerId             (void) const;
    virtual void                setLineType         (const ZcDbObjectId linetypeId);
    virtual ZcDbObjectId        lineTypeId          (void) const;
    virtual void                setSelectionMarker  (const ZSoft::LongPtr markerId);
    virtual void                setFillType         (const ZcGiFillType fillType);
    virtual ZcGiFillType        fillType            (void) const;
    virtual void                setLineWeight       (const ZcDb::LineWeight lw);
    virtual ZcDb::LineWeight    lineWeight          (void) const;
    virtual void                setThickness        (double thickness);
    virtual double              thickness           (void) const;
    virtual void                setLineTypeScale    (double dScale);
    virtual double              lineTypeScale       (void) const;
    virtual void                setMaterial         (const ZcDbObjectId matId);
    virtual ZcDbObjectId        materialId          (void) const;
    virtual void                setSelectionGeom    (bool bSelectionflag);
    virtual bool                selectionGeom       ( void ) const;
};

inline void
ZcGiNonEntityTraits::setupForEntity (ZcDbEntity* pEntity)
{
    assert(false);
}

inline void
ZcGiNonEntityTraits::addLight(const ZcDbObjectId& id)
{
    assert(false);
}

inline void
ZcGiNonEntityTraits::setColor (const ZSoft::UInt16 color)
{
    assert(false);
}

inline ZSoft::UInt16
ZcGiNonEntityTraits::color (void) const
{
    assert(false);
    return 0;
}

inline void
ZcGiNonEntityTraits::setTrueColor (const ZcCmEntityColor& color)
{
    assert(false);
}

inline ZcCmEntityColor
ZcGiNonEntityTraits::trueColor (void) const
{
    assert(false);
    return ZcCmEntityColor();
}

inline void
ZcGiNonEntityTraits::setLayer (const ZcDbObjectId layerId)
{
    assert(false);
}

inline ZcDbObjectId
ZcGiNonEntityTraits::layerId (void) const
{
    assert(false);
    return ZcDbObjectId::kNull;
}

inline void
ZcGiNonEntityTraits::setLineType (const ZcDbObjectId linetypeId)
{
    assert(false);
}

inline ZcDbObjectId ZcGiNonEntityTraits::lineTypeId (void) const
{
    assert(false);
    return  ZcDbObjectId::kNull;
}

inline void
ZcGiNonEntityTraits::setMaterial(const ZcDbObjectId matId)
{
    assert(false);
}

inline ZcDbObjectId ZcGiNonEntityTraits::materialId (void) const
{
    assert(false);
    return  ZcDbObjectId::kNull;
}

inline void
ZcGiNonEntityTraits::setSelectionMarker (const ZSoft::LongPtr markerId)
{
    assert(false);
}

inline void
ZcGiNonEntityTraits::setFillType (const ZcGiFillType fillType)
{
    assert(false);
}

inline ZcGiFillType
ZcGiNonEntityTraits::fillType (void) const
{
    assert(false);
    return kZcGiFillAlways;
}

inline void
ZcGiNonEntityTraits::setLineWeight (const ZcDb::LineWeight lw)
{
    assert(false);
}

inline ZcDb::LineWeight
ZcGiNonEntityTraits::lineWeight (void) const
{
    assert(false);
    return ZcDb::kLnWt000;
}

inline void
ZcGiNonEntityTraits::setThickness (double thickness)
{
    assert(false);
}

inline double
ZcGiNonEntityTraits::thickness (void) const
{
    assert(false);
    return 0.0;
}

inline void
ZcGiNonEntityTraits::setLineTypeScale (double dScale)
{
    assert(false);
}

inline double
ZcGiNonEntityTraits::lineTypeScale (void) const
{
    assert(false);
    return 0.0;
}

inline void
ZcGiNonEntityTraits::setSelectionGeom ( bool )
{
    assert(false);
}

inline bool
ZcGiNonEntityTraits::selectionGeom ( void ) const
{
    assert(false);
    return false;
}

class ZcGiGeometry: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiGeometry);
    virtual void getModelToWorldTransform(ZcGeMatrix3d&) const = 0;
    virtual void getWorldToModelTransform(ZcGeMatrix3d&) const = 0;

    virtual ZSoft::Boolean pushModelTransform(const ZcGeVector3d & vNormal) = 0;
    virtual ZSoft::Boolean pushModelTransform(const ZcGeMatrix3d & xMat) = 0;
    virtual ZSoft::Boolean popModelTransform() = 0;

    virtual ZSoft::Boolean  circle(const ZcGePoint3d& center,
                                   const double radius,
                                   const ZcGeVector3d& normal) const = 0;

    virtual ZSoft::Boolean  circle(const ZcGePoint3d&, const ZcGePoint3d&,
                                   const ZcGePoint3d&) const = 0;

    virtual ZSoft::Boolean  circularArc(const ZcGePoint3d& center,
                                   const double radius,
                                   const ZcGeVector3d& normal,
                                   const ZcGeVector3d& startVector,
                                   const double sweepAngle,
                                   const ZcGiArcType arcType = kZcGiArcSimple) const = 0;

    virtual ZSoft::Boolean  circularArc(const ZcGePoint3d& start,
                                   const ZcGePoint3d& point,
                                   const ZcGePoint3d& end,
                                   const ZcGiArcType arcType = kZcGiArcSimple) const = 0;

    virtual ZSoft::Boolean  polyline(const ZSoft::UInt32 nbPoints,
                                   const ZcGePoint3d* pVertexList,
                                   const ZcGeVector3d* pNormal = NULL,
                                   ZSoft::LongPtr lBaseSubEntMarker = -1) const = 0;

    virtual ZSoft::Boolean  polygon(const ZSoft::UInt32 nbPoints,
                                   const ZcGePoint3d* pVertexList) const = 0;

    virtual ZSoft::Boolean  mesh(const ZSoft::UInt32 rows,
                                 const ZSoft::UInt32 columns,
                                 const ZcGePoint3d* pVertexList,
                                 const ZcGiEdgeData* pEdgeData = NULL,
                                 const ZcGiFaceData* pFaceData = NULL,
                                 const ZcGiVertexData* pVertexData = NULL,
                                 const bool bAutoGenerateNormals = true
                                 ) const = 0;

    virtual ZSoft::Boolean  shell(const ZSoft::UInt32 nbVertex,
                                 const ZcGePoint3d* pVertexList,
                                 const ZSoft::UInt32 faceListSize,
                                 const ZSoft::Int32* pFaceList,
                                 const ZcGiEdgeData* pEdgeData = NULL,
                                 const ZcGiFaceData* pFaceData = NULL,
                                 const ZcGiVertexData* pVertexData = NULL,
                                 const struct resbuf* pResBuf = NULL,
                                 const bool bAutoGenerateNormals = true
                                 ) const = 0;

    virtual ZSoft::Boolean  text(const ZcGePoint3d& position,
                                 const ZcGeVector3d& normal,
                                 const ZcGeVector3d& direction,
                                 const double height,
                                 const double width,
                                 const double oblique,
                                 const ZTCHAR* pMsg) const = 0;

    virtual ZSoft::Boolean  text(const ZcGePoint3d& position,
                                 const ZcGeVector3d& normal,
                                 const ZcGeVector3d& direction,
                                 const ZTCHAR* pMsg,
                                 const ZSoft::Int32 length,
                                 const ZSoft::Boolean raw,
                                 const ZcGiTextStyle &pTextStyle
                                 ) const = 0;

    virtual ZSoft::Boolean  xline(const ZcGePoint3d&,
                                  const ZcGePoint3d&) const = 0;

    virtual ZSoft::Boolean  ray(const ZcGePoint3d&,
                                const ZcGePoint3d&) const = 0;

    virtual ZSoft::Boolean  pline(const ZcDbPolyline& lwBuf,
                                  ZSoft::UInt32 fromIndex = 0,
                                  ZSoft::UInt32 numSegs = 0
                                  ) const = 0;

    virtual ZSoft::Boolean  draw(ZcGiDrawable*) const = 0;

    virtual ZSoft::Boolean          pushClipBoundary(ZcGiClipBoundary * pBoundary) = 0;
    virtual void                    popClipBoundary() = 0;
    virtual ZSoft::Boolean   worldLine(const ZcGePoint3d pnts[2]) {
                                        ZcGePoint3d polyPnts[2];
                                        ZcGeMatrix3d mat;
                                        getWorldToModelTransform(mat);
                                        polyPnts[0] = mat * pnts[0];
                                        polyPnts[1] = mat * pnts[1];
                                        return polyline(2, polyPnts);
                                    };

    virtual ZSoft::Boolean  polypoint( const ZSoft::UInt32 nbPoints,
                                       const ZcGePoint3d* pVertexList,
                                       const ZcGeVector3d* pNormal = NULL,
                                       const ZSoft::LongPtr *pSubEntMarkers = NULL ) const {
                                           ZcGePoint3d pline[2];
                                           ZSoft::Boolean retval = ZSoft::kFalse;
                                           for (ZSoft::UInt32 i = 0; i < nbPoints; i++) {
                                               pline[1] = pline[0] = pVertexList[i];
                                               retval = polyline(2, pline, pNormal ? &pNormal[i] : NULL, pSubEntMarkers ? pSubEntMarkers[i] : -1);
                                               if (retval)
                                                   return retval;
                                           }
                                           return retval;
                                    };

};

class ZcGiWorldGeometry: public ZcGiGeometry 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiWorldGeometry);

    virtual void setExtents(ZcGePoint3d *pNewExtents) const = 0;

    virtual void startAttributesSegment() {};
};

class ZcGiViewportGeometry: public ZcGiGeometry 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewportGeometry);

    virtual ZSoft::Boolean  polylineEye(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;
    virtual ZSoft::Boolean  polygonEye(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;

    virtual ZSoft::Boolean  polylineDc(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;
    virtual ZSoft::Boolean  polygonDc(const ZSoft::UInt32 nbPoints,
                                const ZcGePoint3d* pPoints) const = 0;

    enum ImageSource {
        kFromDwg,
        kFromOleObject,
        kFromRender
    };

    virtual ZSoft::Boolean  rasterImageDc(
                const ZcGePoint3d& origin,
                const ZcGeVector3d& u,
                const ZcGeVector3d& v,
                const ZcGeMatrix2d& pixelToDc,
                ZcDbObjectId entityId,
                ZcGiImageOrg imageOrg,
                ZSoft::UInt32 imageWidth,
                ZSoft::UInt32 imageHeight,
                ZSoft::Int16 imageColorDepth,
                ZSoft::Boolean transparency,
                ImageSource source,
                const ZcGeVector3d& unrotatedU,
                const ZcGiImageOrg origionalImageOrg,
                const ZcGeMatrix2d& unrotatedPixelToDc,
                const ZSoft::UInt32 unrotatedImageWidth,
                const ZSoft::UInt32 unrotatedImageHeight
                ) const = 0;

    virtual ZSoft::Boolean  ownerDrawDc(
                long                       vpnumber, 
                long                       left, 
                long                       top, 
                long                       right, 
                long                       bottom, 
                const OwnerDraw*           pOwnerDraw
                ) const = 0;

    virtual ZSoft::Boolean  ownerDraw3d(
                ZcGePoint3d&               minBounds,
                ZcGePoint3d&               maxBounds,
                OwnerDraw3d*               pOwnerDraw
                ) const  { return ZSoft::kFalse; };
};

class ZcGiEdgeData: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiEdgeData);

    ~ZcGiEdgeData();
    ZcGiEdgeData();

    virtual void            setColors(const short *colors);
    virtual void            setTrueColors(const ZcCmEntityColor *colors);
    virtual void            setLayers(const ZcDbObjectId *layers);
    virtual void            setLineTypes(const ZcDbObjectId *linetypes);
    virtual void            setSelectionMarkers(const ZSoft::LongPtr* pSelectionMarkers);
    virtual void            setVisibility(const ZSoft::UInt8* pVisibility);

    virtual short*          colors() const;
    virtual ZcCmEntityColor* trueColors() const;
    virtual ZcDbObjectId*   layerIds() const;
    virtual ZcDbObjectId*   linetypeIds() const;
    virtual ZSoft::LongPtr* selectionMarkers() const;
    virtual ZSoft::UInt8*   visibility() const;

private:
    ZcGiImpEdgeData *mpZcGiImpEdgeData;
};

class ZcGiFaceData: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiFaceData);

    ~ZcGiFaceData();
    ZcGiFaceData();
    virtual void            setColors(const short *colors);
    virtual void            setTrueColors(const ZcCmEntityColor *colors);
    virtual void            setLayers(const ZcDbObjectId *layers);
    virtual void            setSelectionMarkers(const ZSoft::LongPtr* pSelectionMarkers);
    virtual void            setNormals(const ZcGeVector3d* pNormals);
    virtual void            setVisibility(const ZSoft::UInt8* vis);
    virtual void            setMaterials(const ZcDbObjectId * materials);
    virtual void            setMappers(const ZcGiMapper * mappers);

    virtual short*          colors() const;
    virtual ZcCmEntityColor* trueColors() const;
    virtual ZcDbObjectId*   layerIds() const;
    virtual ZSoft::LongPtr* selectionMarkers() const;
    virtual ZcGeVector3d*   normals() const;
    virtual ZSoft::UInt8*   visibility() const;
    virtual ZcDbObjectId*   materials() const;
    virtual ZcGiMapper*     mappers() const;

private:
    ZcGiImpFaceData *mpZcGiImpFaceData;
};

class ZcGiVertexData: public ZcRxObject 
{ 
public:
    enum MapChael
    {
        kAllChaels,
        kMapChaels
    };

    ZCRX_DECLARE_MEMBERS(ZcGiVertexData);
    ~ZcGiVertexData();
    ZcGiVertexData();
    virtual void setNormals(const ZcGeVector3d* pNormals);
    virtual ZcGeVector3d* normals() const;
    virtual void setOrientationFlag(const ZcGiOrientationType oflag); 
    virtual ZcGiOrientationType orientationFlag() const;
    virtual void setTrueColors(const ZcCmEntityColor *colors);
    virtual ZcCmEntityColor* trueColors() const;

    void setMappingCoords (MapChael mapChael, const ZcGePoint3d* pCoords);
    ZcGePoint3d* mappingCoords (MapChael mapChael) const;

private:
    ZcGiImpVertexData *mpZcGiImpVertexData;
};

class ZcGiTextStyle: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcGiTextStyle);
    ~ZcGiTextStyle();
    ZcGiTextStyle();

    ZcGiTextStyle(
        const ZTCHAR*  fontName,
        const ZTCHAR*  bigFontName,
        const double textSize,
        const double xScale,
        const double obliqueAngle,
        const double trPercent,

        const ZSoft::Boolean isBackward,
        const ZSoft::Boolean isUpsideDown,
        const ZSoft::Boolean isVertical,

        const ZSoft::Boolean isOverlined,
        const ZSoft::Boolean isUnderlined,

        const ZTCHAR*          styleName = NULL);

    virtual int loadStyleRec() const;
    virtual void setTextSize(const double size);
    virtual void setXScale(const double xScale);
    virtual void setObliquingAngle(const double obliquingAngle);

    virtual void setTrackingPercent(const double trPercent);

    virtual void setBackward(const ZSoft::Boolean isBackward);
    virtual void setUpsideDown(const ZSoft::Boolean isUpsideDown);
    virtual void setVertical(const ZSoft::Boolean isVertical);

    virtual void setUnderlined(const ZSoft::Boolean isUnderlined);
    virtual void setOverlined(const ZSoft::Boolean isOverlined);

    virtual void setFileName(const ZTCHAR * fontName);
    virtual void setBigFontFileName(const ZTCHAR * bigFontFileName);

    virtual double textSize() const;
    virtual double xScale() const;
    virtual double obliquingAngle() const;

    virtual double trackingPercent() const;

    virtual ZSoft::Boolean isBackward() const;
    virtual ZSoft::Boolean isUpsideDown() const;
    virtual ZSoft::Boolean isVertical() const;

    virtual ZSoft::Boolean isUnderlined() const;
    virtual ZSoft::Boolean isOverlined() const;

    virtual const ZTCHAR * fileName() const;
    virtual const ZTCHAR * bigFontFileName() const;

    virtual ZcGePoint2d extents(const ZTCHAR * pStr,
                const ZSoft::Boolean penups,
                const int len,
                const ZSoft::Boolean raw,
                ZcGiWorldDraw *ctxt = NULL) const;

    virtual const ZTCHAR * styleName() const;
    virtual Zcad::ErrorStatus setStyleName(const ZTCHAR *);

    virtual Zcad::ErrorStatus setFont(const ZTCHAR * pTypeface,
                                      ZSoft::Boolean bold,
                                      ZSoft::Boolean italic,
                                      int charset, int pitchAndFamily);

    virtual Zcad::ErrorStatus font(ZTCHAR *& pTypeface, ZSoft::Boolean& bold,
                ZSoft::Boolean& italic, int& charset, int& pitchAndFamily) const;

    virtual Zcad::ErrorStatus  extentsBox(  const ZTCHAR * pStr,
                                            const ZSoft::Boolean penups,
                                            const int len,
                                            const ZSoft::Boolean raw,
                                            ZcGePoint2d &extMin,
                                            ZcGePoint2d &extMax,
                                            ZcGiWorldDraw *ctxt = NULL) const;

    virtual void setTrackKerning(double trackPercent) const;

    virtual bool preLoaded() const;
    virtual void setPreLoaded(bool);

private:
    ZcGiImpTextStyle *mpZcGiImpTextStyle;
};

#pragma pack (pop)

#endif
