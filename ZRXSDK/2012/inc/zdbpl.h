

#ifndef ZD_DBPL_H
#define ZD_DBPL_H 1

#include "zdbmain.h"
#include "zdbcurve.h"

#include "zgelnsg2d.h"
#include "zgelnsg3d.h"
#include "zgearc2d.h"
#include "zgearc3d.h"
#include "zgept2dar.h"
#include "zdbboiler.h"

#pragma pack(push, 8)

class ZcDb2dPolyline;

class ZcDbPolyline : public ZcDbCurve
{

public:
                      ZcDbPolyline();
                      ZcDbPolyline(unsigned int num_verts);
    virtual          ~ZcDbPolyline();

    ZCDB_DECLARE_MEMBERS(ZcDbPolyline);

    Zcad::ErrorStatus convertFrom(ZcDbEntity*& pPline, 
                                  ZSoft::Boolean transferId = ZSoft::kTrue);
    Zcad::ErrorStatus convertTo(ZcDb2dPolyline*&  pPline,
                                ZSoft::Boolean transferId = ZSoft::kTrue) const;

    Zcad::ErrorStatus getPointAt(unsigned int, ZcGePoint3d& pt) const;

    enum SegType {
        kLine,
        kArc,
        kCoincident,
        kPoint,
        kEmpty
    };

    SegType           segType           (unsigned int index) const;

    Zcad::ErrorStatus getLineSegAt      (unsigned int index,
                                         ZcGeLineSeg2d& ln) const;
    Zcad::ErrorStatus getLineSegAt      (unsigned int index,
                                         ZcGeLineSeg3d& ln) const;
    Zcad::ErrorStatus getArcSegAt       (unsigned int index,
                                         ZcGeCircArc2d& arc) const;
    Zcad::ErrorStatus getArcSegAt       (unsigned int index,
                                         ZcGeCircArc3d& arc) const;
    virtual ZSoft::Boolean onSegAt      (unsigned int index, const ZcGePoint2d& pt2d,
                                         double& param) const;

    void              setClosed       (ZSoft::Boolean);
    void              setPlinegen     (ZSoft::Boolean);
    void              setElevation    (double);
    Zcad::ErrorStatus setThickness    (double);
    Zcad::ErrorStatus setConstantWidth(double);
    Zcad::ErrorStatus setNormal       (const ZcGeVector3d&);

    ZSoft::Boolean    isClosed        ()                        const;      
    ZSoft::Boolean    isOnlyLines     ()                        const;
    ZSoft::Boolean    hasPlinegen     ()                        const;
    double            elevation       ()                        const;
    double            thickness       ()                        const;
    Zcad::ErrorStatus getConstantWidth(double&)                 const;
    ZcGeVector3d      normal          ()                        const;

    Zcad::ErrorStatus addVertexAt     (unsigned int index,
                                       const ZcGePoint2d& pt,
                                       double bulge = 0.,
                                       double startWidth = -1.,
                                       double endWidth = -1);

    Zcad::ErrorStatus removeVertexAt  (unsigned int index);

    unsigned int      numVerts        ()                        const;

    Zcad::ErrorStatus getPointAt        (unsigned int index,
                                       ZcGePoint2d& pt)         const;
    Zcad::ErrorStatus getBulgeAt      (unsigned int index,
                                       double&      bulge)      const;
    Zcad::ErrorStatus getWidthsAt     (unsigned int index,
                                       double&      startWidth,
                                       double&      endWidth)   const;

    Zcad::ErrorStatus setPointAt      (unsigned int index,
                                       const ZcGePoint2d& pt);
    Zcad::ErrorStatus setBulgeAt      (unsigned int index,
                                       double       bulge);
    Zcad::ErrorStatus setWidthsAt     (unsigned int index,
                                       double       startWidth,
                                       double       endWidth);

    Zcad::ErrorStatus minimizeMemory  ();
    Zcad::ErrorStatus maximizeMemory  ();

    void              reset           (ZSoft::Boolean reuse,
                                       unsigned int numVerts);

    ZSoft::Boolean     hasBulges       ()        const;
    ZSoft::Boolean     hasWidth        ()        const;

    virtual ZSoft::Boolean    isPeriodic   () const;      
    virtual ZSoft::Boolean    isPlanar     () const;

    virtual Zcad::ErrorStatus getPlane       (ZcGePlane&         plane, 
                                              ZcDb::Planarity&   type) const; 

    virtual Zcad::ErrorStatus getStartParam  (double&      startParam) const;
    virtual Zcad::ErrorStatus getEndParam    (double&      endParam)   const;
    virtual Zcad::ErrorStatus getStartPoint  (ZcGePoint3d& startPoint) const;
    virtual Zcad::ErrorStatus getEndPoint    (ZcGePoint3d& endPoint)   const; 

    virtual Zcad::ErrorStatus getPointAtParam(double             param, 
                                              ZcGePoint3d&       point) const;
    virtual Zcad::ErrorStatus getParamAtPoint(const ZcGePoint3d& point,
                                              double&            param) const;
    virtual Zcad::ErrorStatus getDistAtParam (double             param,
                                              double&            dist)  const;
    virtual Zcad::ErrorStatus getParamAtDist (double             dist,
                                              double&            param) const; 
    virtual Zcad::ErrorStatus getDistAtPoint (const ZcGePoint3d& point,
                                              double&            dist)  const;
    virtual Zcad::ErrorStatus getPointAtDist (double             dist,
                                              ZcGePoint3d&       point) const;

    virtual Zcad::ErrorStatus getFirstDeriv (double             param, 
                                          ZcGeVector3d&      firstDeriv) const;
    virtual Zcad::ErrorStatus getFirstDeriv (const ZcGePoint3d& point, 
                                          ZcGeVector3d&      firstDeriv) const;
    virtual Zcad::ErrorStatus getSecondDeriv(double             param, 
                                          ZcGeVector3d&      secondDeriv)const;
    virtual Zcad::ErrorStatus getSecondDeriv(const ZcGePoint3d& point, 
                                          ZcGeVector3d&      secondDeriv)const;

    virtual Zcad::ErrorStatus getClosestPointTo(const ZcGePoint3d& givenPoint,
                                          ZcGePoint3d&       pointOnCurve,
                                          ZSoft::Boolean     extend = 
                                                               ZSoft::kFalse) 
                                                               const;

    virtual Zcad::ErrorStatus getClosestPointTo(const ZcGePoint3d&  givenPoint,
                                          const ZcGeVector3d& normal,
                                          ZcGePoint3d&        pointOnCurve,
                                          ZSoft::Boolean      extend = 
                                                                ZSoft::kFalse) 
                                                                      const;

    virtual Zcad::ErrorStatus getOrthoProjectedCurve(const ZcGePlane&  plane,
                                          ZcDbCurve*&       projectedCurve) 
                                                                      const;

    virtual Zcad::ErrorStatus getProjectedCurve(const ZcGePlane&    plane,
                                  const ZcGeVector3d& projDir,
                                  ZcDbCurve*&       projectedCurve) const;

    virtual Zcad::ErrorStatus getOffsetCurves(double offsetDist,
                                  ZcDbVoidPtrArray&  offsetCurves)  const;

    virtual Zcad::ErrorStatus getSpline(ZcDbSpline*& spline) const; 

    virtual Zcad::ErrorStatus getSplitCurves(
                                  const ZcGeDoubleArray& parameters,
                                  ZcDbVoidPtrArray&  curveSegments) const;

    virtual Zcad::ErrorStatus getSplitCurves(
                                  const ZcGePoint3dArray& points,
                                  ZcDbVoidPtrArray&       curveSegments) const;

    virtual Zcad::ErrorStatus extend(double          newParam);

    virtual Zcad::ErrorStatus extend(ZSoft::Boolean     extendStart,
                                     const ZcGePoint3d& toPoint);

    virtual Zcad::ErrorStatus getArea(double& area) const;

    virtual Zcad::ErrorStatus getOsnapPoints(ZcDb::OsnapMode osnapMode,
                                             ZSoft::GsMarker gsSelectionMark,
                                             const ZcGePoint3d&  pickPoint,
                                             const ZcGePoint3d&  lastPoint,
                                             const ZcGeMatrix3d& viewXform,
                                             ZcGePoint3dArray&      snapPoints,
                                             ZcDbIntArray&   geomIds)
                                             const;

    virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray& geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                            ZcDb::Intersect intType,
                                            ZcGePoint3dArray& points,
                                            ZSoft::GsMarker thisGsMarker  = 0,
                                            ZSoft::GsMarker otherGsMarker = 0)
                                            const;

    virtual Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                             ZcDb::Intersect intType,
                                             const ZcGePlane& projPlane,
                                             ZcGePoint3dArray& points,
                                             ZSoft::GsMarker thisGsMarker  = 0,
                                             ZSoft::GsMarker otherGsMarker = 0)
                                             const;

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus getTransformedCopy(const ZcGeMatrix3d& xform,
                                                 ZcDbEntity*& ent) const;

    virtual void              getEcs(ZcGeMatrix3d& retVal) const;

    virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
    virtual Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                 ZcDb::SubentType     type, 
                                 ZSoft::GsMarker      gsMark,
                                 const ZcGePoint3d&   pickPoint,
                                 const ZcGeMatrix3d&  viewXform,
                                 int&                 numIds, 
                                 ZcDbFullSubentPath*& subentIds,
                                 int                  numInserts,
                                 ZcDbObjectId*        entAndInsertStack)
                                                                     const;

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;

    virtual ZSoft::Boolean    worldDraw   (ZcGiWorldDraw* mode);
    virtual void              viewportDraw(ZcGiViewportDraw* mode);

    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* filer,
                                               ZcRxClass*    classobj);

    virtual bool              castShadows() const;
    virtual bool              receiveShadows() const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual void              saveAs(ZcGiWorldDraw* mode,
                                     ZcDb::SaveType st);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags) const;
};

inline ZSoft::Boolean ZcDbPolyline::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbPolyline::getStartParam(double& startParam) const
{
    startParam = 0.;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbPolyline::getSpline(ZcDbSpline*& spline) const
{
    return Zcad::eNotApplicable;
}

#pragma pack(pop)

#endif 
