

#ifndef ZD_ZCDBABB_H
//#error "zcdbabb.h included more than once!  Is it included by a .h file?"
//#endif
#define ZD_ZCDBABB_H 1

#include "zacdb.h"

typedef Zcad::ErrorStatus       ErrorStatus;

typedef ZcDb::OpenMode          OpenMode;
typedef ZcDb::OsnapMode         OsnapMode;
typedef ZcDb::CoordAxis         CoordAxis;
typedef ZcDb::CoordSystem       CoordSystem;
typedef ZcDb::Intersect         Intersect;
typedef ZcDb::Visibility        Visibility;
typedef ZcDb::SaveType          SaveType;
typedef ZcDb::DxfCode           DxfCode;
typedef ZcDb::DwgDataType       DwgDataType;
typedef ZcDb::TextHorzMode      TextHorzMode;
typedef ZcDb::TextVertMode      TextVertMode;
typedef ZcDb::LineSpacingStyle  LineSpacingStyle;
typedef ZcDb::Planarity         Planarity;
typedef ZcDb::PointIndex        PointIndex;
typedef ZcDb::EdgeIndex         EdgeIndex;
typedef ZcDb::Poly2dType        Poly2dType;
typedef ZcDb::Poly3dType        Poly3dType;
typedef ZcDb::PolyMeshType      PolyMeshType;
typedef ZcDb::Vertex2dType      Vertex2dType;
typedef ZcDb::Vertex3dType      Vertex3dType;
typedef ZcDb::SpaceValueType    SpaceValueType;
typedef ZcDb::BoolOperType      BoolOperType;
typedef ZcDb::SubentType        SubentType;
typedef ZcDb::GeomId            GeomId;
typedef ZcDb::GeomType          GeomType;
typedef ZcDb::OrthographicView  OrthographicView;

const Zcad::ErrorStatus eOk = Zcad::eOk;
const Zcad::ErrorStatus eNotImplementedYet = Zcad::eNotImplementedYet;
const Zcad::ErrorStatus eNotApplicable = Zcad::eNotApplicable;
const Zcad::ErrorStatus eInvalidInput = Zcad::eInvalidInput;
const Zcad::ErrorStatus eAmbiguousInput = Zcad::eAmbiguousInput;
const Zcad::ErrorStatus eAmbiguousOutput = Zcad::eAmbiguousOutput;
const Zcad::ErrorStatus eOutOfMemory = Zcad::eOutOfMemory;
const Zcad::ErrorStatus eBufferTooSmall = Zcad::eBufferTooSmall;
const Zcad::ErrorStatus eInvalidOpenState = Zcad::eInvalidOpenState;
const Zcad::ErrorStatus eEntityInInactiveLayout
    = Zcad::eEntityInInactiveLayout;
const Zcad::ErrorStatus eHandleExists = Zcad::eHandleExists;
const Zcad::ErrorStatus eNullHandle = Zcad::eNullHandle;
const Zcad::ErrorStatus eBrokenHandle = Zcad::eBrokenHandle;
const Zcad::ErrorStatus eUnknownHandle = Zcad::eUnknownHandle;
const Zcad::ErrorStatus eHandleInUse = Zcad::eHandleInUse;
const Zcad::ErrorStatus eNullObjectPointer = Zcad::eNullObjectPointer;
const Zcad::ErrorStatus eNullObjectId = Zcad::eNullObjectId;
const Zcad::ErrorStatus eNullBlockName = Zcad::eNullBlockName;
const Zcad::ErrorStatus eContainerNotEmpty = Zcad::eContainerNotEmpty;
const Zcad::ErrorStatus eNullEntityPointer = Zcad::eNullEntityPointer;
const Zcad::ErrorStatus eIllegalEntityType = Zcad::eIllegalEntityType;
const Zcad::ErrorStatus eKeyNotFound = Zcad::eKeyNotFound;
const Zcad::ErrorStatus eDuplicateKey = Zcad::eDuplicateKey;
const Zcad::ErrorStatus eInvalidIndex = Zcad::eInvalidIndex;
const Zcad::ErrorStatus eDuplicateIndex = Zcad::eDuplicateIndex;
const Zcad::ErrorStatus eAlreadyInDb = Zcad::eAlreadyInDb;
const Zcad::ErrorStatus eOutOfDisk = Zcad::eOutOfDisk;
const Zcad::ErrorStatus eDeletedEntry = Zcad::eDeletedEntry;
const Zcad::ErrorStatus eNegativeValueNotAllowed 
    = Zcad::eNegativeValueNotAllowed;
const Zcad::ErrorStatus eInvalidExtents = Zcad::eInvalidExtents;
const Zcad::ErrorStatus eInvalidAdsName = Zcad::eInvalidAdsName;
const Zcad::ErrorStatus eInvalidKey = Zcad::eInvalidKey;
const Zcad::ErrorStatus eEndOfObject = Zcad::eEndOfObject;
const Zcad::ErrorStatus eEndOfFile = Zcad::eEndOfFile;
const Zcad::ErrorStatus eObjectToBeDeleted = Zcad::eObjectToBeDeleted;
const Zcad::ErrorStatus eInvalidDwgVersion = Zcad::eInvalidDwgVersion;
const Zcad::ErrorStatus eAnonymousEntry = Zcad::eAnonymousEntry;
const Zcad::ErrorStatus eIllegalReplacement = Zcad::eIllegalReplacement;
const Zcad::ErrorStatus eIsReading = Zcad::eIsReading;
const Zcad::ErrorStatus eIsWriting = Zcad::eIsWriting;
const Zcad::ErrorStatus eNotOpenForRead = Zcad::eNotOpenForRead;
const Zcad::ErrorStatus eNotOpenForWrite = Zcad::eNotOpenForWrite;
const Zcad::ErrorStatus eNotThatKindOfClass = Zcad::eNotThatKindOfClass;
const Zcad::ErrorStatus eInvalidDxfCode = Zcad::eInvalidDxfCode;
const Zcad::ErrorStatus eInvalidResBuf = Zcad::eInvalidResBuf;
const Zcad::ErrorStatus eBadDxfSequence = Zcad::eBadDxfSequence;
const Zcad::ErrorStatus eInvalidBlockName = Zcad::eInvalidBlockName;
const Zcad::ErrorStatus eMissingDxfField  = Zcad::eMissingDxfField;
const Zcad::ErrorStatus eDuplicateDxfField = Zcad::eDuplicateDxfField;
const Zcad::ErrorStatus eFilerError = Zcad::eFilerError;
const Zcad::ErrorStatus eVertexAfterFace = Zcad::eVertexAfterFace;
const Zcad::ErrorStatus eInvalidFaceVertexIndex = Zcad::eInvalidFaceVertexIndex;
const Zcad::ErrorStatus eInvalidMeshVertexIndex = Zcad::eInvalidMeshVertexIndex;
const Zcad::ErrorStatus eOtherObjectsBusy = Zcad::eOtherObjectsBusy;
const Zcad::ErrorStatus eMustFirstAddBlockToDb = Zcad::eMustFirstAddBlockToDb;
const Zcad::ErrorStatus eCannotNestBlockDefs = Zcad::eCannotNestBlockDefs;
const Zcad::ErrorStatus eDwgRecoveredOK = Zcad::eDwgRecoveredOK;
const Zcad::ErrorStatus eDwgNotRecoverable = Zcad::eDwgNotRecoverable;
const Zcad::ErrorStatus eDwgNeedsRecovery = Zcad::eDwgNeedsRecovery;
const Zcad::ErrorStatus eDeleteEntity = Zcad::eDeleteEntity;
const Zcad::ErrorStatus eInvalidFix = Zcad::eInvalidFix;
const Zcad::ErrorStatus eFSMError = Zcad::eFSMError;
const Zcad::ErrorStatus eDxfPartiallyRead = Zcad::eDxfPartiallyRead;
const Zcad::ErrorStatus eMissingSymbolTable = Zcad::eMissingSymbolTable;
const Zcad::ErrorStatus eMissingSymbolTableRec = Zcad::eMissingSymbolTableRec;
const Zcad::ErrorStatus eDwgCRCDoesNotMatch = Zcad::eDwgCRCDoesNotMatch;
const Zcad::ErrorStatus eDwgSentinelDoesNotMatch 
    = Zcad::eDwgSentinelDoesNotMatch;
const Zcad::ErrorStatus eDwgObjectImproperlyRead 
    = Zcad::eDwgObjectImproperlyRead;
const Zcad::ErrorStatus eNoInputFiler = Zcad::eNoInputFiler;
const Zcad::ErrorStatus eDwgNeedsAFullSave = Zcad::eDwgNeedsAFullSave;
const Zcad::ErrorStatus eDxfReadAborted = Zcad::eDxfReadAborted;
const Zcad::ErrorStatus eDxbPartiallyRead = Zcad::eDxbPartiallyRead;
const Zcad::ErrorStatus eDxbReadAborted = Zcad::eDxbReadAborted;
const Zcad::ErrorStatus eFileLockedByZCAD = Zcad::eFileLockedByZCAD;
const Zcad::ErrorStatus eFileAccessErr = Zcad::eFileAccessErr;
const Zcad::ErrorStatus eFileSystemErr = Zcad::eFileSystemErr;
const Zcad::ErrorStatus eFileInternalErr = Zcad::eFileInternalErr;
const Zcad::ErrorStatus eFileNotFound = Zcad::eFileNotFound;
const Zcad::ErrorStatus eDwgShareDemandLoad = Zcad::eDwgShareDemandLoad;
const Zcad::ErrorStatus eDwgShareReadAccess = Zcad::eDwgShareReadAccess;
const Zcad::ErrorStatus eDwgShareWriteAccess = Zcad::eDwgShareWriteAccess;
const Zcad::ErrorStatus eDwkLockFileFound = Zcad::eDwkLockFileFound;
const Zcad::ErrorStatus eWasErased = Zcad::eWasErased;
const Zcad::ErrorStatus eWasNotErased = Zcad::eWasNotErased;
const Zcad::ErrorStatus ePermanentlyErased = Zcad::ePermanentlyErased;
const Zcad::ErrorStatus eWasOpenForRead = Zcad::eWasOpenForRead;
const Zcad::ErrorStatus eWasOpenForWrite = Zcad::eWasOpenForWrite;
const Zcad::ErrorStatus eWasOpenForUndo = Zcad::eWasOpenForUndo;
const Zcad::ErrorStatus eWasNotifying = Zcad::eWasNotifying;
const Zcad::ErrorStatus eWasOpenForNotify = Zcad::eWasOpenForNotify;
const Zcad::ErrorStatus eOnLockedLayer = Zcad::eOnLockedLayer;
const Zcad::ErrorStatus eMustOpenThruOwner = Zcad::eMustOpenThruOwner;
const Zcad::ErrorStatus eSubentitiesStillOpen = Zcad::eSubentitiesStillOpen;
const Zcad::ErrorStatus eAtMaxReaders = Zcad::eAtMaxReaders;
const Zcad::ErrorStatus eIsWriteProtected = Zcad::eIsWriteProtected;
const Zcad::ErrorStatus eIsXRefObject = Zcad::eIsXRefObject;
const Zcad::ErrorStatus eNotAnEntity = Zcad::eNotAnEntity;
const Zcad::ErrorStatus eHadMultipleReaders = Zcad::eHadMultipleReaders;
const Zcad::ErrorStatus eWasNotOpenForWrite = Zcad::eWasNotOpenForWrite;
const Zcad::ErrorStatus eCloseWasNotifying = Zcad::eCloseWasNotifying;
const Zcad::ErrorStatus eCloseModifyAborted = Zcad::eCloseModifyAborted;
const Zcad::ErrorStatus eClosePartialFailure = Zcad::eClosePartialFailure;
const Zcad::ErrorStatus eCannotBeErasedByCaller = Zcad::eCannotBeErasedByCaller;
const Zcad::ErrorStatus eFixedAllErrors = Zcad::eFixedAllErrors;
const Zcad::ErrorStatus eLeftErrorsUnfixed = Zcad::eLeftErrorsUnfixed;
const Zcad::ErrorStatus eUnrecoverableErrors = Zcad::eUnrecoverableErrors;
const Zcad::ErrorStatus eNoDatabase = Zcad::eNoDatabase;
const Zcad::ErrorStatus eXdataSizeExceeded = Zcad::eXdataSizeExceeded;
const Zcad::ErrorStatus eRegappIdNotFound = Zcad::eRegappIdNotFound;
const Zcad::ErrorStatus eRepeatEntity = Zcad::eRepeatEntity;
const Zcad::ErrorStatus eRecordNotInTable = Zcad::eRecordNotInTable;
const Zcad::ErrorStatus eIteratorDone = Zcad::eIteratorDone;
const Zcad::ErrorStatus eNotInBlock = Zcad::eNotInBlock;
const Zcad::ErrorStatus eGeneralModelingFailure = Zcad::eGeneralModelingFailure;
const Zcad::ErrorStatus eOutOfRange = Zcad::eOutOfRange;
const Zcad::ErrorStatus eNonCoplanarGeometry = Zcad::eNonCoplanarGeometry;
const Zcad::ErrorStatus eDegenerateGeometry  = Zcad::eDegenerateGeometry;
const Zcad::ErrorStatus eOwnerNotInDatabase = Zcad::eOwnerNotInDatabase;
const Zcad::ErrorStatus eOwnerNotOpenForRead = Zcad::eOwnerNotOpenForRead;
const Zcad::ErrorStatus eOwnerNotOpenForWrite = Zcad::eOwnerNotOpenForWrite;
const Zcad::ErrorStatus eExplodeBeforeTransform = Zcad::eExplodeBeforeTransform;
const Zcad::ErrorStatus eCannotScaleNonUniformly 
    = Zcad::eCannotScaleNonUniformly;
const Zcad::ErrorStatus eNotInDatabase = Zcad::eNotInDatabase;
const Zcad::ErrorStatus eNotCurrentDatabase = Zcad::eNotCurrentDatabase;
const Zcad::ErrorStatus eIsAnEntity = Zcad::eIsAnEntity;
const Zcad::ErrorStatus eCannotChangeActiveViewport 
    = Zcad::eCannotChangeActiveViewport;
const Zcad::ErrorStatus eNotInPaperspace = Zcad::eNotInPaperspace;
const Zcad::ErrorStatus eCommandWasInProgress = Zcad::eCommandWasInProgress;
const Zcad::ErrorStatus eInvalidAxis  = Zcad::eInvalidAxis;
const Zcad::ErrorStatus ePointNotOnEntity  = Zcad::ePointNotOnEntity;
const Zcad::ErrorStatus eSingularPoint  = Zcad::eSingularPoint;
const Zcad::ErrorStatus eInvalidOffset = Zcad::eInvalidOffset;
const Zcad::ErrorStatus eStringTooLong  = Zcad::eStringTooLong;
const Zcad::ErrorStatus eNullIterator = Zcad::eNullIterator;
const Zcad::ErrorStatus eInvalidSymbolTableName = Zcad::eInvalidSymbolTableName;
const Zcad::ErrorStatus eDuplicateRecordName = Zcad::eDuplicateRecordName;
const Zcad::ErrorStatus eXRefDependent = Zcad::eXRefDependent;
const Zcad::ErrorStatus eSelfReference = Zcad::eSelfReference;
const Zcad::ErrorStatus eWrongDatabase = Zcad::eWrongDatabase;
const Zcad::ErrorStatus eWrongObjectType = Zcad::eWrongObjectType;
const Zcad::ErrorStatus eInvalidSymTableFlag = Zcad::eInvalidSymTableFlag;
const Zcad::ErrorStatus eUndefinedLineType = Zcad::eUndefinedLineType;
const Zcad::ErrorStatus eInvalidTextStyle = Zcad::eInvalidTextStyle;
const Zcad::ErrorStatus eTooFewLineTypeElements = Zcad::eTooFewLineTypeElements;
const Zcad::ErrorStatus eTooManyLineTypeElements 
    = Zcad::eTooManyLineTypeElements;
const Zcad::ErrorStatus eExcessiveItemCount = Zcad::eExcessiveItemCount;
const Zcad::ErrorStatus eIgnoredLinetypeRedef = Zcad::eIgnoredLinetypeRedef;
const Zcad::ErrorStatus eBadUCS = Zcad::eBadUCS;
const Zcad::ErrorStatus eBadPaperspaceView = Zcad::eBadPaperspaceView;
const Zcad::ErrorStatus eSomeInputDataLeftUnread=Zcad::eSomeInputDataLeftUnread;
const Zcad::ErrorStatus eNoInternalSpace=Zcad::eNoInternalSpace;
const Zcad::ErrorStatus eInvalidDimStyle = Zcad::eInvalidDimStyle;
const Zcad::ErrorStatus eInvalidLayer = Zcad::eInvalidLayer;
const Zcad::ErrorStatus eUserBreak = Zcad::eUserBreak;
const Zcad::ErrorStatus eBadLayerName = Zcad::eBadLayerName;
const Zcad::ErrorStatus eLayerGroupCodeMissing = Zcad::eLayerGroupCodeMissing;
const Zcad::ErrorStatus eBadColorIndex = Zcad::eBadColorIndex;
const Zcad::ErrorStatus eBadColor = Zcad::eBadColor;
const Zcad::ErrorStatus eBadLinetypeName = Zcad::eBadLinetypeName;
const Zcad::ErrorStatus eBadLinetypeScale = Zcad::eBadLinetypeScale;
const Zcad::ErrorStatus eBadVisibilityValue = Zcad::eBadVisibilityValue;
const Zcad::ErrorStatus eProperClassSeparatorExpected 
    = Zcad::eProperClassSeparatorExpected;
const Zcad::ErrorStatus eBadMaterialName = Zcad::eBadMaterialName;
const Zcad::ErrorStatus ePagerError = Zcad::ePagerError;
const Zcad::ErrorStatus eOutOfPagerMemory = Zcad::eOutOfPagerMemory;
const Zcad::ErrorStatus ePagerWriteError = Zcad::ePagerWriteError;
const Zcad::ErrorStatus eWasNotForwarding = Zcad::eWasNotForwarding;
const Zcad::ErrorStatus eInvalidIdMap = Zcad::eInvalidIdMap;
const Zcad::ErrorStatus eInvalidOwnerObject = Zcad::eInvalidOwnerObject;
const Zcad::ErrorStatus eOwnerNotSet = Zcad::eOwnerNotSet;
const Zcad::ErrorStatus eNoActiveTransactions = Zcad::eNoActiveTransactions; 
const Zcad::ErrorStatus eNotTopTransaction = Zcad::eNotTopTransaction; 
const Zcad::ErrorStatus eTransactionOpenWhileCommandEnded 
    = Zcad::eTransactionOpenWhileCommandEnded;
const Zcad::ErrorStatus eInProcessOfCommitting 
    = Zcad::eInProcessOfCommitting;
const Zcad::ErrorStatus eNotNewlyCreated = Zcad::eNotNewlyCreated;
const Zcad::ErrorStatus eLongTransReferenceError 
    = Zcad::eLongTransReferenceError;
const Zcad::ErrorStatus eNoWorkSet = Zcad::eNoWorkSet;
const Zcad::ErrorStatus eAlreadyInGroup = Zcad::eAlreadyInGroup;
const Zcad::ErrorStatus eNotInGroup = Zcad::eNotInGroup;
const Zcad::ErrorStatus eWrongSubentityType = Zcad::eWrongSubentityType;
const Zcad::ErrorStatus eInvalidStyle = Zcad::eInvalidStyle;
const Zcad::ErrorStatus eCannotRestoreFromAcisFile 
    = Zcad::eCannotRestoreFromAcisFile;
const Zcad::ErrorStatus eNonPlanarEntity = Zcad::eNonPlanarEntity;
const Zcad::ErrorStatus eCannotExplodeEntity = Zcad::eCannotExplodeEntity;
const Zcad::ErrorStatus ePolyWidthLost = Zcad::ePolyWidthLost;
const Zcad::ErrorStatus eNullExtents = Zcad::eNullExtents;

const Zcad::ErrorStatus eLockViolation = Zcad::eLockViolation;
const Zcad::ErrorStatus eLockConflict = Zcad::eLockConflict;
const Zcad::ErrorStatus eDatabaseObjectsOpen = Zcad::eDatabaseObjectsOpen;
const Zcad::ErrorStatus eLockChangeInProgress = Zcad::eLockChangeInProgress;

const Zcad::ErrorStatus eVetoed = Zcad::eVetoed;
const Zcad::ErrorStatus eXrefReloaded = Zcad::eXrefReloaded;

const Zcad::ErrorStatus eNoDocument = Zcad::eNoDocument;
const Zcad::ErrorStatus eNotFromThisDocument = Zcad::eNotFromThisDocument;
const Zcad::ErrorStatus eLISPActive = Zcad::eLISPActive;
const Zcad::ErrorStatus eTargetDocNotQuiescent = Zcad::eTargetDocNotQuiescent;
const Zcad::ErrorStatus eDocumentSwitchDisabled = Zcad::eDocumentSwitchDisabled;
const Zcad::ErrorStatus eInvalidContext = Zcad::eInvalidContext;

const Zcad::ErrorStatus eProfileDoesNotExist = Zcad::eProfileDoesNotExist;
const Zcad::ErrorStatus eInvalidFileExtension= Zcad::eInvalidFileExtension;
const Zcad::ErrorStatus eInvalidProfileName  = Zcad::eInvalidProfileName;
const Zcad::ErrorStatus eFileExists          = Zcad::eFileExists;     
const Zcad::ErrorStatus eProfileIsInUse      = Zcad::eProfileIsInUse;
const Zcad::ErrorStatus eCantOpenFile        = Zcad::eCantOpenFile;
const Zcad::ErrorStatus eNoFileName          = Zcad::eNoFileName;
const Zcad::ErrorStatus eRegistryAccessError = Zcad::eRegistryAccessError;
const Zcad::ErrorStatus eRegistryCreateError = Zcad::eRegistryCreateError;

const Zcad::ErrorStatus eBadDxfFile = Zcad::eBadDxfFile;
const Zcad::ErrorStatus eUnknownDxfFileFormat = Zcad::eUnknownDxfFileFormat;
const Zcad::ErrorStatus eMissingDxfSection = Zcad::eMissingDxfSection;
const Zcad::ErrorStatus eInvalidDxfSectionName = Zcad::eInvalidDxfSectionName;
const Zcad::ErrorStatus eNotDxfHeaderGroupCode = Zcad::eNotDxfHeaderGroupCode;
const Zcad::ErrorStatus eUndefinedDxfGroupCode = Zcad::eUndefinedDxfGroupCode;
const Zcad::ErrorStatus eNotInitializedYet = Zcad::eNotInitializedYet;
const Zcad::ErrorStatus eInvalidDxf2dPoint = Zcad::eInvalidDxf2dPoint;
const Zcad::ErrorStatus eInvalidDxf3dPoint = Zcad::eInvalidDxf3dPoint;
const Zcad::ErrorStatus eBadlyNestedAppData  = Zcad::eBadlyNestedAppData;
const Zcad::ErrorStatus eIncompleteBlockDefinition = Zcad::eIncompleteBlockDefinition;
const Zcad::ErrorStatus eIncompleteComplexObject = Zcad::eIncompleteComplexObject;
const Zcad::ErrorStatus eBlockDefInEntitySection = Zcad::eBlockDefInEntitySection;
const Zcad::ErrorStatus eNoBlockBegin = Zcad::eNoBlockBegin;
const Zcad::ErrorStatus eDuplicateLayerName = Zcad::eDuplicateLayerName;
const Zcad::ErrorStatus eDuplicateBlockName = Zcad::eDuplicateBlockName;
const Zcad::ErrorStatus eBadPlotStyleName = Zcad::eBadPlotStyleName;
const Zcad::ErrorStatus eBadPlotStyleType = Zcad::eBadPlotStyleType;
const Zcad::ErrorStatus eBadPlotStyleNameHandle = Zcad::eBadPlotStyleNameHandle;
const Zcad::ErrorStatus eUndefineShapeName = Zcad::eUndefineShapeName;
const Zcad::ErrorStatus eDuplicateBlockDefinition = Zcad::eDuplicateBlockDefinition;
const Zcad::ErrorStatus eMissingBlockName = Zcad::eMissingBlockName;
const Zcad::ErrorStatus eBinaryDataSizeExceeded = Zcad::eBinaryDataSizeExceeded;
const Zcad::ErrorStatus eHatchTooDense = Zcad::eHatchTooDense;

const Zcad::ErrorStatus eUndoOperationNotAvailable = Zcad::eUndoOperationNotAvailable;
const Zcad::ErrorStatus eUndoNoGroupBegin = Zcad::eUndoNoGroupBegin;

const Zcad::ErrorStatus eObjectIsReferenced = Zcad::eObjectIsReferenced;
const Zcad::ErrorStatus eNoThumbnailBitmap = Zcad::eNoThumbnailBitmap;
const Zcad::ErrorStatus eGuidNoAddress = Zcad::eGuidNoAddress;
const Zcad::ErrorStatus eNoPlotStyleTranslationTable = Zcad::eNoPlotStyleTranslationTable;

const Zcad::ErrorStatus ePlotStyleInColorDependentMode = Zcad::ePlotStyleInColorDependentMode;
const Zcad::ErrorStatus eNoClassId = Zcad::eNoClassId;
const Zcad::ErrorStatus eMaxLayouts = Zcad::eMaxLayouts;

const Zcad::ErrorStatus eWrongCellType = Zcad::eWrongCellType;
const Zcad::ErrorStatus eCannotChangeColumnType = Zcad::eCannotChangeColumnType;
const Zcad::ErrorStatus eRowsMustMatchColumns = Zcad::eRowsMustMatchColumns;

const Zcad::ErrorStatus eNullNodeId = Zcad::eNullNodeId;
const Zcad::ErrorStatus eNoNodeActive = Zcad::eNoNodeActive;
const Zcad::ErrorStatus eGraphContainsProxies = Zcad::eGraphContainsProxies;

const Zcad::ErrorStatus eLoadFailed = Zcad::eLoadFailed;
const Zcad::ErrorStatus eDeviceNotFound = Zcad::eDeviceNotFound;
const Zcad::ErrorStatus eNoCurrentConfig = Zcad::eNoCurrentConfig;
const Zcad::ErrorStatus eNullPtr = Zcad::eNullPtr;
const Zcad::ErrorStatus eNoLayout = Zcad::eNoLayout;
const Zcad::ErrorStatus eIncompatiblePlotSettings = Zcad::eIncompatiblePlotSettings;
const Zcad::ErrorStatus eNonePlotDevice = Zcad::eNonePlotDevice;
const Zcad::ErrorStatus eNoMatchingMedia = Zcad::eNoMatchingMedia;
const Zcad::ErrorStatus eInvalidView = Zcad::eInvalidView;
const Zcad::ErrorStatus eInvalidWindowArea = Zcad::eInvalidWindowArea;
const Zcad::ErrorStatus eInvalidPlotArea = Zcad::eInvalidPlotArea;
const Zcad::ErrorStatus eCustomSizeNotPossible = Zcad::eCustomSizeNotPossible;

const Zcad::ErrorStatus ePageCancelled = Zcad::ePageCancelled;
const Zcad::ErrorStatus ePlotCancelled = Zcad::ePlotCancelled;
const Zcad::ErrorStatus eInvalidEngineState = Zcad::eInvalidEngineState;
const Zcad::ErrorStatus ePlotAlreadyStarted = Zcad::ePlotAlreadyStarted;
const Zcad::ErrorStatus eNoErrorHandler = Zcad::eNoErrorHandler;
const Zcad::ErrorStatus eInvalidPlotInfo = Zcad::eInvalidPlotInfo;
const Zcad::ErrorStatus eNumberOfCopiesNotSupported = Zcad::eNumberOfCopiesNotSupported;
const Zcad::ErrorStatus eLayoutNotCurrent = Zcad::eLayoutNotCurrent;
const Zcad::ErrorStatus eGraphicsNotGenerated = Zcad::eGraphicsNotGenerated;
const Zcad::ErrorStatus eCannotPlotToFile = Zcad::eCannotPlotToFile;
const Zcad::ErrorStatus eMustPlotToFile = Zcad::eMustPlotToFile;
const Zcad::ErrorStatus eBackgroundPlotInProgress = Zcad::eBackgroundPlotInProgress;

const Zcad::ErrorStatus eInvalidObjectId = Zcad::eInvalidObjectId;
const Zcad::ErrorStatus eInvalidXrefObjectId = Zcad::eInvalidXrefObjectId;
const Zcad::ErrorStatus eNoViewAssociation = Zcad::eNoViewAssociation;
const Zcad::ErrorStatus eNoLabelBlock = Zcad::eNoLabelBlock;
const Zcad::ErrorStatus eUnableToSetViewAssociation = Zcad::eUnableToSetViewAssociation;
const Zcad::ErrorStatus eUnableToGetViewAssociation = Zcad::eUnableToGetViewAssociation;
const Zcad::ErrorStatus eUnableToSetLabelBlock = Zcad::eUnableToSetLabelBlock;
const Zcad::ErrorStatus eUnableToGetLabelBlock = Zcad::eUnableToGetLabelBlock;
const Zcad::ErrorStatus eUnableToRemoveAssociation = Zcad::eUnableToRemoveAssociation;
const Zcad::ErrorStatus eUnableToSyncModelView = Zcad::eUnableToSyncModelView;

const Zcad::ErrorStatus eSubSelectionSetEmpty = Zcad::eSubSelectionSetEmpty;
const Zcad::ErrorStatus eGraphEdgeNotFound = Zcad::eGraphEdgeNotFound;
const Zcad::ErrorStatus eGraphNodeNotFound = Zcad::eGraphNodeNotFound;
const Zcad::ErrorStatus eGraphNodeAlreadyExists = Zcad::eGraphNodeAlreadyExists;
const Zcad::ErrorStatus eGraphEdgeAlreadyExists = Zcad::eGraphEdgeAlreadyExists;
const Zcad::ErrorStatus eGraphCyclesFound = Zcad::eGraphCyclesFound;

const Zcad::ErrorStatus eAlreadyHasRepresentation =
                                        Zcad::eAlreadyHasRepresentation;
const Zcad::ErrorStatus eNoRepresentation = Zcad::eNoRepresentation;
const Zcad::ErrorStatus eNoIntersections = Zcad::eNoIntersections;
const Zcad::ErrorStatus eEmbeddedIntersections = Zcad::eEmbeddedIntersections;

const Zcad::ErrorStatus eFailedToSetEdgeChamfers = Zcad::eFailedToSetEdgeChamfers;
const Zcad::ErrorStatus eNoCoectedBlendSet = Zcad::eNoConnectedBlendSet;
const Zcad::ErrorStatus eFailedToBlend = Zcad::eFailedToBlend;
const Zcad::ErrorStatus eFailedToSetEdgeRounds = Zcad::eFailedToSetEdgeRounds;

const Zcad::ErrorStatus eFailedToSetVertexRounds = Zcad::eFailedToSetVertexRounds;

const ZcDb::OpenMode kForRead = ZcDb::kForRead;
const ZcDb::OpenMode kForWrite = ZcDb::kForWrite;
const ZcDb::OpenMode kForNotify = ZcDb::kForNotify;

const ZcDb::ShowImagesMode kNeverShow      = ZcDb::kNeverShow;
const ZcDb::ShowImagesMode kAlwaysShow     = ZcDb::kAlwaysShow;
const ZcDb::ShowImagesMode kBoundingBoxShow     = ZcDb::kBoundingBoxShow;

const ZcDb::SaveImagesMode kNeverSave      = ZcDb::kNeverSave;
const ZcDb::SaveImagesMode kAlwaysSave     = ZcDb::kAlwaysSave;

const ZcDb::CoordAxis kX = ZcDb::kX;
const ZcDb::CoordAxis kY = ZcDb::kY;
const ZcDb::CoordAxis kZ = ZcDb::kZ;

const ZcDb::CoordSystem kWorldCS = ZcDb::kWorldCS;
const ZcDb::CoordSystem kUserCS = ZcDb::kUserCS;
const ZcDb::CoordSystem kCurDisplayCS = ZcDb::kCurDisplayCS;
const ZcDb::CoordSystem kPaperDisplayCS = ZcDb::kPaperDisplayCS;
const ZcDb::CoordSystem kEntityCS = ZcDb::kEntityCS;

const ZcDb::Intersect kOnBothOperands = ZcDb::kOnBothOperands;
const ZcDb::Intersect kExtendThis = ZcDb::kExtendThis;
const ZcDb::Intersect kExtendArg = ZcDb::kExtendArg;
const ZcDb::Intersect kExtendBoth = ZcDb::kExtendBoth;

const ZcDb::Visibility kInvisible = ZcDb::kInvisible;
const ZcDb::Visibility kVisible = ZcDb::kVisible;

const ZcDb::DxfCode kDxfInvalid = ZcDb::kDxfInvalid;
const ZcDb::DxfCode kDxfXDictionary = ZcDb::kDxfXDictionary;
const ZcDb::DxfCode kDxfPReactors = ZcDb::kDxfPReactors;
const ZcDb::DxfCode kDxfOperator = ZcDb::kDxfOperator;
const ZcDb::DxfCode kDxfXDataStart = ZcDb::kDxfXDataStart;
const ZcDb::DxfCode kDxfHeaderId = ZcDb::kDxfHeaderId;
const ZcDb::DxfCode kDxfEnd = ZcDb::kDxfEnd;
const ZcDb::DxfCode kDxfStart = ZcDb::kDxfStart;
const ZcDb::DxfCode kDxfText = ZcDb::kDxfText;
const ZcDb::DxfCode kDxfShapeName = ZcDb::kDxfShapeName;
const ZcDb::DxfCode kDxfSymbolTableName = ZcDb::kDxfSymbolTableName;
const ZcDb::DxfCode kDxfBlockName = ZcDb::kDxfBlockName;
const ZcDb::DxfCode kDxfAttributeTag = ZcDb::kDxfAttributeTag;
const ZcDb::DxfCode kDxfAttributePrompt = ZcDb::kDxfAttributePrompt;
const ZcDb::DxfCode kDxfDimStyleName = ZcDb::kDxfDimStyleName;
const ZcDb::DxfCode kDxfXRefPath = ZcDb::kDxfXRefPath;
const ZcDb::DxfCode kDxfHandle = ZcDb::kDxfHandle;
const ZcDb::DxfCode kDxfLinetypeName = ZcDb::kDxfLinetypeName;
const ZcDb::DxfCode kDxfTextStyleName = ZcDb::kDxfTextStyleName;
const ZcDb::DxfCode kDxfCLShapeText = ZcDb::kDxfCLShapeText;
const ZcDb::DxfCode kDxfCLShapeName = ZcDb::kDxfCLShapeName;
const ZcDb::DxfCode kDxfLayerName = ZcDb::kDxfLayerName;
const ZcDb::DxfCode kDxfLayoutName = ZcDb::kDxfLayoutName;
const ZcDb::DxfCode kDxfXCoord = ZcDb::kDxfXCoord;
const ZcDb::DxfCode kDxfYCoord = ZcDb::kDxfYCoord;
const ZcDb::DxfCode kDxfZCoord = ZcDb::kDxfZCoord;
const ZcDb::DxfCode kDxfElevation = ZcDb::kDxfElevation;
const ZcDb::DxfCode kDxfThickness = ZcDb::kDxfThickness;
const ZcDb::DxfCode kDxfReal = ZcDb::kDxfReal;
const ZcDb::DxfCode kDxfXReal = ZcDb::kDxfXReal;
const ZcDb::DxfCode kDxfInt8 = ZcDb::kDxfInt8;
const ZcDb::DxfCode kDxfBool = ZcDb::kDxfBool;
const ZcDb::DxfCode kDxfLinetypeScale = ZcDb::kDxfLinetypeScale;
const ZcDb::DxfCode kDxfLinetypeElement = ZcDb::kDxfLinetypeElement;
const ZcDb::DxfCode kDxfAngle = ZcDb::kDxfAngle;
const ZcDb::DxfCode kDxfVisibility = ZcDb::kDxfVisibility;
const ZcDb::DxfCode kDxfLayerLinetype = ZcDb::kDxfLayerLinetype;
const ZcDb::DxfCode kDxfColor = ZcDb::kDxfColor;
const ZcDb::DxfCode kDxfHasSubentities = ZcDb::kDxfHasSubentities;
const ZcDb::DxfCode kDxfViewportVisibility = ZcDb::kDxfViewportVisibility;
const ZcDb::DxfCode kDxfViewportActive = ZcDb::kDxfViewportActive;
const ZcDb::DxfCode kDxfViewportNumber = ZcDb::kDxfViewportNumber;
const ZcDb::DxfCode kDxfInt16 = ZcDb::kDxfInt16;
const ZcDb::DxfCode kDxfXInt16 = ZcDb::kDxfXInt16;
const ZcDb::DxfCode kDxfXXInt16 = ZcDb::kDxfXXInt16;
const ZcDb::DxfCode kDxfInt32 = ZcDb::kDxfInt32;
const ZcDb::DxfCode kDxfInt64 = ZcDb::kDxfInt64;
const ZcDb::DxfCode kDxfControlString = ZcDb::kDxfControlString;
const ZcDb::DxfCode kDxfSymTableRecComments = ZcDb::kDxfSymTableRecComments;
const ZcDb::DxfCode kDxfDimVarHandle = ZcDb::kDxfDimVarHandle;
const ZcDb::DxfCode kDxfUCSOrg = ZcDb::kDxfUCSOrg;
const ZcDb::DxfCode kDxfUCSOriX = ZcDb::kDxfUCSOriX;
const ZcDb::DxfCode kDxfUCSOriY = ZcDb::kDxfUCSOriY;
const ZcDb::DxfCode kDxfSubclass = ZcDb::kDxfSubclass;
const ZcDb::DxfCode kDxfEmbeddedObjectStart = ZcDb::kDxfEmbeddedObjectStart;
const ZcDb::DxfCode kDxfNormalX = ZcDb::kDxfNormalX;
const ZcDb::DxfCode kDxfNormalY = ZcDb::kDxfNormalY;
const ZcDb::DxfCode kDxfNormalZ = ZcDb::kDxfNormalZ;
const ZcDb::DxfCode kDxfXTextString = ZcDb::kDxfXTextString;
const ZcDb::DxfCode kDxfBinaryChunk = ZcDb::kDxfBinaryChunk;
const ZcDb::DxfCode kDxfArbHandle   = ZcDb::kDxfArbHandle;
const ZcDb::DxfCode kDxfSoftPointerId = ZcDb::kDxfSoftPointerId;
const ZcDb::DxfCode kDxfHardPointerId = ZcDb::kDxfHardPointerId;
const ZcDb::DxfCode kDxfSoftOwnershipId = ZcDb::kDxfSoftOwnershipId;
const ZcDb::DxfCode kDxfHardOwnershipId = ZcDb::kDxfHardOwnershipId;
const ZcDb::DxfCode kDxfLineWeight = ZcDb::kDxfLineWeight;
const ZcDb::DxfCode kDxfPlotStyleNameType = ZcDb::kDxfPlotStyleNameType;
const ZcDb::DxfCode kDxfPlotStyleNameId = ZcDb::kDxfPlotStyleNameId;
const ZcDb::DxfCode kDxfXXXInt16 = ZcDb::kDxfXXXInt16;
const ZcDb::DxfCode kDxfComment = ZcDb::kDxfComment;
const ZcDb::DxfCode kDxfXdAsciiString = ZcDb::kDxfXdAsciiString;
const ZcDb::DxfCode kDxfRegAppName = ZcDb::kDxfRegAppName;
const ZcDb::DxfCode kDxfXdControlString = ZcDb::kDxfXdControlString;
const ZcDb::DxfCode kDxfXdLayerName = ZcDb::kDxfXdLayerName;
const ZcDb::DxfCode kDxfXdBinaryChunk = ZcDb::kDxfXdBinaryChunk;
const ZcDb::DxfCode kDxfXdHandle = ZcDb::kDxfXdHandle;
const ZcDb::DxfCode kDxfXdXCoord = ZcDb::kDxfXdXCoord;
const ZcDb::DxfCode kDxfXdYCoord = ZcDb::kDxfXdYCoord;
const ZcDb::DxfCode kDxfXdZCoord = ZcDb::kDxfXdZCoord;
const ZcDb::DxfCode kDxfXdWorldXCoord = ZcDb::kDxfXdWorldXCoord;
const ZcDb::DxfCode kDxfXdWorldYCoord = ZcDb::kDxfXdWorldYCoord;
const ZcDb::DxfCode kDxfXdWorldZCoord = ZcDb::kDxfXdWorldZCoord;
const ZcDb::DxfCode kDxfXdWorldXDisp = ZcDb::kDxfXdWorldXDisp;
const ZcDb::DxfCode kDxfXdWorldYDisp = ZcDb::kDxfXdWorldYDisp;
const ZcDb::DxfCode kDxfXdWorldZDisp = ZcDb::kDxfXdWorldZDisp;
const ZcDb::DxfCode kDxfXdWorldXDir = ZcDb::kDxfXdWorldXDir;
const ZcDb::DxfCode kDxfXdWorldYDir = ZcDb::kDxfXdWorldYDir;
const ZcDb::DxfCode kDxfXdWorldZDir = ZcDb::kDxfXdWorldZDir;
const ZcDb::DxfCode kDxfXdReal = ZcDb::kDxfXdReal;
const ZcDb::DxfCode kDxfXdDist = ZcDb::kDxfXdDist;
const ZcDb::DxfCode kDxfXdScale = ZcDb::kDxfXdScale;
const ZcDb::DxfCode kDxfXdInteger16 = ZcDb::kDxfXdInteger16;
const ZcDb::DxfCode kDxfXdInteger32 = ZcDb::kDxfXdInteger32;
const ZcDb::DxfCode kDxfColorRGB =  ZcDb::kDxfColorRGB; 
const ZcDb::DxfCode kDxfColorName =  ZcDb::kDxfColorName;
const ZcDb::DxfCode kDxfAlpha =  ZcDb::kDxfAlpha;    
const ZcDb::DxfCode kDxfMaterialId =  ZcDb::kDxfMaterialId;
const ZcDb::DxfCode kDxfViewportGridDisplay = ZcDb::kDxfViewportGridDisplay;
const ZcDb::DxfCode kDxfObjVisualStyleId = ZcDb::kDxfObjVisualStyleId;
const ZcDb::DxfCode kDxfVpVisualStyleId = ZcDb::kDxfVpVisualStyleId;
const ZcDb::DxfCode kDxfDragVisualStyleId = ZcDb::kDxfDragVisualStyleId;
const ZcDb::DxfCode kDxfShadowFlags = ZcDb::kDxfShadowFlags;
const ZcDb::DxfCode kDxfFaceStyleId = ZcDb::kDxfFaceStyleId;
const ZcDb::DxfCode kDxfEdgeStyleId = ZcDb::kDxfEdgeStyleId;
const ZcDb::DxfCode kDxfVisualStyleId = ZcDb::kDxfVisualStyleId;

const ZcDb::DxfCode kDxfGradientObjType  = ZcDb::kDxfGradientObjType;
const ZcDb::DxfCode kDxfGradientPatType  = ZcDb::kDxfGradientPatType;
const ZcDb::DxfCode kDxfGradientTintType = ZcDb::kDxfGradientTintType;
const ZcDb::DxfCode kDxfGradientColCount = ZcDb::kDxfGradientColCount;
const ZcDb::DxfCode kDxfGradientAngle    = ZcDb::kDxfGradientAngle;
const ZcDb::DxfCode kDxfGradientShift    = ZcDb::kDxfGradientShift;
const ZcDb::DxfCode kDxfGradientTintVal  = ZcDb::kDxfGradientTintVal;
const ZcDb::DxfCode kDxfGradientColVal   = ZcDb::kDxfGradientColVal;
const ZcDb::DxfCode kDxfGradientName     = ZcDb::kDxfGradientName;

const ZcDb::DwgDataType kDwgNull = ZcDb::kDwgNull;
const ZcDb::DwgDataType kDwgReal = ZcDb::kDwgReal;
const ZcDb::DwgDataType kDwgInt64 = ZcDb::kDwgInt64;
const ZcDb::DwgDataType kDwgInt32 = ZcDb::kDwgInt32;
const ZcDb::DwgDataType kDwgInt16 = ZcDb::kDwgInt16;
const ZcDb::DwgDataType kDwgInt8 = ZcDb::kDwgInt8;
const ZcDb::DwgDataType kDwgText = ZcDb::kDwgText;
const ZcDb::DwgDataType kDwgBChunk = ZcDb::kDwgBChunk;
const ZcDb::DwgDataType kDwgHandle = ZcDb::kDwgHandle;
const ZcDb::DwgDataType kDwgHardOwnershipId = ZcDb::kDwgHardOwnershipId;
const ZcDb::DwgDataType kDwgSoftOwnershipId = ZcDb::kDwgSoftOwnershipId;
const ZcDb::DwgDataType kDwgHardPointerId   = ZcDb::kDwgHardPointerId;
const ZcDb::DwgDataType kDwgSoftPointerId   = ZcDb::kDwgSoftPointerId;
const ZcDb::DwgDataType kDwg3Real = ZcDb::kDwg3Real;
const ZcDb::DwgDataType kDwgNotRecognized = ZcDb::kDwgNotRecognized;

const ZcDb::OsnapMask kOsMaskEnd = ZcDb::kOsMaskEnd;
const ZcDb::OsnapMask kOsMaskMid = ZcDb::kOsMaskMid;
const ZcDb::OsnapMask kOsMaskCen = ZcDb::kOsMaskCen;
const ZcDb::OsnapMask kOsMaskNode = ZcDb::kOsMaskNode;
const ZcDb::OsnapMask kOsMaskQuad = ZcDb::kOsMaskQuad;
const ZcDb::OsnapMask kOsMaskInt = ZcDb::kOsMaskInt;
const ZcDb::OsnapMask kOsMaskIns = ZcDb::kOsMaskIns;
const ZcDb::OsnapMask kOsMaskPerp = ZcDb::kOsMaskPerp;
const ZcDb::OsnapMask kOsMaskTan = ZcDb::kOsMaskTan;
const ZcDb::OsnapMask kOsMaskNear = ZcDb::kOsMaskNear;
const ZcDb::OsnapMask kOsMaskQuick = ZcDb::kOsMaskQuick;
const ZcDb::OsnapMask kOsMaskImmediate = ZcDb::kOsMaskImmediate;
const ZcDb::OsnapMask kOsMaskAllowTan = ZcDb::kOsMaskAllowTan;
const ZcDb::OsnapMask kOsMaskDisablePerp = ZcDb::kOsMaskDisablePerp;
const ZcDb::OsnapMask kOsMaskRelCartesian = ZcDb::kOsMaskRelCartesian;
const ZcDb::OsnapMask kOsMaskRelPolar = ZcDb::kOsMaskRelPolar;
const ZcDb::OsnapMask kOsMaskNoneOverride = ZcDb::kOsMaskNoneOverride;

const ZcDb::OsnapMode kOsModeEnd = ZcDb::kOsModeEnd;
const ZcDb::OsnapMode kOsModeMid = ZcDb::kOsModeMid;
const ZcDb::OsnapMode kOsModeCen = ZcDb::kOsModeCen;
const ZcDb::OsnapMode kOsModeNode = ZcDb::kOsModeNode;
const ZcDb::OsnapMode kOsModeQuad = ZcDb::kOsModeQuad;
const ZcDb::OsnapMode kOsModeIns = ZcDb::kOsModeIns;
const ZcDb::OsnapMode kOsModePerp = ZcDb::kOsModePerp;
const ZcDb::OsnapMode kOsModeTan = ZcDb::kOsModeTan;
const ZcDb::OsnapMode kOsModeNear = ZcDb::kOsModeNear;

const ZcDb::TextHorzMode kTextLeft = ZcDb::kTextLeft;
const ZcDb::TextHorzMode kTextCenter = ZcDb::kTextCenter;
const ZcDb::TextHorzMode kTextRight = ZcDb::kTextRight;
const ZcDb::TextHorzMode kTextAlign = ZcDb::kTextAlign;
const ZcDb::TextHorzMode kTextMid = ZcDb::kTextMid;
const ZcDb::TextHorzMode kTextFit = ZcDb::kTextFit;

const ZcDb::TextVertMode kTextBase = ZcDb::kTextBase;
const ZcDb::TextVertMode kTextBottom = ZcDb::kTextBottom;
const ZcDb::TextVertMode kTextVertMid = ZcDb::kTextVertMid;
const ZcDb::TextVertMode kTextTop = ZcDb::kTextTop;

const ZcDb::LineSpacingStyle kAtLeast = ZcDb::kAtLeast;
const ZcDb::LineSpacingStyle kExactly = ZcDb::kExactly;

const ZcDb::Planarity kNonPlanar = ZcDb::kNonPlanar;
const ZcDb::Planarity kPlanar = ZcDb::kPlanar;
const ZcDb::Planarity kLinear = ZcDb::kLinear;

const ZcDb::PointIndex kMPoint1 = ZcDb::kMPoint1;
const ZcDb::PointIndex kMPoint2 = ZcDb::kMPoint2;
const ZcDb::PointIndex kMPoint3 = ZcDb::kMPoint3;
const ZcDb::PointIndex kMPoint4 = ZcDb::kMPoint4;

const ZcDb::EdgeIndex kMEdge1 = ZcDb::kMEdge1;
const ZcDb::EdgeIndex kMEdge2 = ZcDb::kMEdge2;
const ZcDb::EdgeIndex kMEdge3 = ZcDb::kMEdge3;
const ZcDb::EdgeIndex kMEdge4 = ZcDb::kMEdge4;

const ZcDb::Poly2dType k2dSimplePoly = ZcDb::k2dSimplePoly;
const ZcDb::Poly2dType k2dFitCurvePoly = ZcDb::k2dFitCurvePoly;
const ZcDb::Poly2dType k2dQuadSplinePoly = ZcDb::k2dQuadSplinePoly;
const ZcDb::Poly2dType k2dCubicSplinePoly = ZcDb::k2dCubicSplinePoly;

const ZcDb::Poly3dType k3dSimplePoly = ZcDb::k3dSimplePoly;
const ZcDb::Poly3dType k3dQuadSplinePoly = ZcDb::k3dQuadSplinePoly;
const ZcDb::Poly3dType k3dCubicSplinePoly = ZcDb::k3dCubicSplinePoly;

const ZcDb::PolyMeshType kSimpleMesh = ZcDb::kSimpleMesh;
const ZcDb::PolyMeshType kQuadSurfaceMesh = ZcDb::kQuadSurfaceMesh;
const ZcDb::PolyMeshType kCubicSurfaceMesh = ZcDb::kCubicSurfaceMesh;
const ZcDb::PolyMeshType kBezierSurfaceMesh = ZcDb::kBezierSurfaceMesh;

const ZcDb::Vertex2dType k2dVertex = ZcDb::k2dVertex;
const ZcDb::Vertex2dType k2dSplineCtlVertex = ZcDb::k2dSplineCtlVertex;
const ZcDb::Vertex2dType k2dSplineFitVertex = ZcDb::k2dSplineFitVertex;
const ZcDb::Vertex2dType k2dCurveFitVertex = ZcDb::k2dCurveFitVertex;

const ZcDb::Vertex3dType k3dSimpleVertex = ZcDb::k3dSimpleVertex;
const ZcDb::Vertex3dType k3dControlVertex = ZcDb::k3dControlVertex;
const ZcDb::Vertex3dType k3dFitVertex = ZcDb::k3dFitVertex;

const ZcDb::SpaceValueType kUndefined = ZcDb::kUndefined;
const ZcDb::SpaceValueType kStubPtr = ZcDb::kStubPtr;
const ZcDb::SpaceValueType kEndOfFile = ZcDb::kEndOfFile;
const ZcDb::SpaceValueType kBackwardBranch = ZcDb::kBackwardBranch;
const ZcDb::SpaceValueType kForwardBranch = ZcDb::kForwardBranch;
const ZcDb::SpaceValueType kDetour = ZcDb::kDetour;

const ZcDb::BoolOperType kBoolUnite = ZcDb::kBoolUnite;
const ZcDb::BoolOperType kBoolIntersect = ZcDb::kBoolIntersect;
const ZcDb::BoolOperType kBoolSubtract = ZcDb::kBoolSubtract;

const ZcDb::SubentType kNullSubentType   = ZcDb::kNullSubentType;
const ZcDb::SubentType kVertexSubentType = ZcDb::kVertexSubentType;
const ZcDb::SubentType kEdgeSubentType   = ZcDb::kEdgeSubentType;
const ZcDb::SubentType kFaceSubentType   = ZcDb::kFaceSubentType;
const ZcDb::SubentType kMlineSubentCache = ZcDb::kMlineSubentCache;
const ZcDb::SubentType kClassSubentType  = ZcDb::kClassSubentType;
const ZcDb::GeomId kNoGeom = ZcDb::kNoGeom;

const ZcDb::GeomType kInvalidGeom = ZcDb::kInvalidGeom;
const ZcDb::GeomType kPointGeom = ZcDb::kPointGeom;
const ZcDb::GeomType kLineGeom = ZcDb::kLineGeom;
const ZcDb::GeomType kCircleGeom = ZcDb::kCircleGeom;
const ZcDb::GeomType kPlaneGeom = ZcDb::kPlaneGeom;

const ZcDb::UnitsValue kUnitsUndefined      = ZcDb::kUnitsUndefined;
const ZcDb::UnitsValue kUnitsInches         = ZcDb::kUnitsInches;
const ZcDb::UnitsValue kUnitsFeet           = ZcDb::kUnitsFeet;
const ZcDb::UnitsValue kUnitsMillimeters    = ZcDb::kUnitsMillimeters;
const ZcDb::UnitsValue kUnitsMeters         = ZcDb::kUnitsMeters;
const ZcDb::UnitsValue kUnitsMicroinches    = ZcDb::kUnitsMicroinches;
const ZcDb::UnitsValue kUnitsMils           = ZcDb::kUnitsMils;
const ZcDb::UnitsValue kUnitsYards          = ZcDb::kUnitsYards;
const ZcDb::UnitsValue kUnitsMiles          = ZcDb::kUnitsMiles;
const ZcDb::UnitsValue kUnitsAngstroms      = ZcDb::kUnitsAngstroms;
const ZcDb::UnitsValue kUnitsNanometers     = ZcDb::kUnitsNanometers;
const ZcDb::UnitsValue kUnitsMicrons        = ZcDb::kUnitsMicrons;
const ZcDb::UnitsValue kUnitsDecimeters     = ZcDb::kUnitsDecimeters;
const ZcDb::UnitsValue kUnitsCentimeters    = ZcDb::kUnitsCentimeters;
const ZcDb::UnitsValue kUnitsDekameters     = ZcDb::kUnitsDekameters;
const ZcDb::UnitsValue kUnitsHectometers    = ZcDb::kUnitsHectometers;
const ZcDb::UnitsValue kUnitsKilometers     = ZcDb::kUnitsKilometers;
const ZcDb::UnitsValue kUnitsGigameters     = ZcDb::kUnitsGigameters;
const ZcDb::UnitsValue kUnitsAstronomical   = ZcDb::kUnitsAstronomical;
const ZcDb::UnitsValue kUnitsLightYears     = ZcDb::kUnitsLightYears;
const ZcDb::UnitsValue kUnitsParsecs        = ZcDb::kUnitsParsecs;
const ZcDb::UnitsValue kUnitsMax            = ZcDb::kUnitsMax;

const ZcDb::OrthographicView kTopView      = ZcDb::kTopView;
const ZcDb::OrthographicView kBottomView   = ZcDb::kBottomView;
const ZcDb::OrthographicView kFrontView    = ZcDb::kFrontView;
const ZcDb::OrthographicView kBackView     = ZcDb::kBackView;
const ZcDb::OrthographicView kLeftView     = ZcDb::kLeftView;
const ZcDb::OrthographicView kRightView    = ZcDb::kRightView;
const ZcDb::OrthographicView kNonOrthoView = ZcDb::kNonOrthoView;

const ZcDb::CellType kUnknownCell          =  ZcDb::kUnknownCell;	
const ZcDb::CellType kTextCell             =  ZcDb::kTextCell;	
const ZcDb::CellType kBlockCell            =  ZcDb::kBlockCell;

const ZcDb::CellEdgeMask kTopMask          =  ZcDb::kTopMask;	
const ZcDb::CellEdgeMask kRightMask        =  ZcDb::kRightMask;	
const ZcDb::CellEdgeMask kBottomMask       =  ZcDb::kBottomMask;	
const ZcDb::CellEdgeMask kLeftMask         =  ZcDb::kLeftMask;

const ZcDb::FlowDirection kTtoB            =  ZcDb::kTtoB;	
const ZcDb::FlowDirection kBtoT            =  ZcDb::kBtoT;

const ZcDb::RotationAngle kDegrees000      =  ZcDb::kDegrees000;	
const ZcDb::RotationAngle kDegrees090      =  ZcDb::kDegrees090;	
const ZcDb::RotationAngle kDegrees180      =  ZcDb::kDegrees180;	
const ZcDb::RotationAngle kDegrees270      =  ZcDb::kDegrees270;	
const ZcDb::RotationAngle kDegreesUnknown  =  ZcDb::kDegreesUnknown;	

const ZcDb::CellAlignment kTopLeft		   =  ZcDb::kTopLeft;
const ZcDb::CellAlignment kTopCenter	   =  ZcDb::kTopCenter;	
const ZcDb::CellAlignment kTopRight		   =  ZcDb::kTopRight;	
const ZcDb::CellAlignment kMiddleLeft	   =  ZcDb::kMiddleLeft;	
const ZcDb::CellAlignment kMiddleCenter	   =  ZcDb::kMiddleCenter;	
const ZcDb::CellAlignment kMiddleRight	   =  ZcDb::kMiddleRight;	
const ZcDb::CellAlignment kBottomLeft	   =  ZcDb::kBottomLeft;	
const ZcDb::CellAlignment kBottomCenter	   =  ZcDb::kBottomCenter;	
const ZcDb::CellAlignment kBottomRight	   =  ZcDb::kBottomRight;	

const ZcDb::GridLineType kInvalidGridLine  =  ZcDb::kInvalidGridLine;	  
const ZcDb::GridLineType kHorzTop		   =  ZcDb::kHorzTop;	
const ZcDb::GridLineType kHorzInside	   =  ZcDb::kHorzInside;	
const ZcDb::GridLineType kHorzBottom	   =  ZcDb::kHorzBottom;	
const ZcDb::GridLineType kVertLeft		   =  ZcDb::kVertLeft;	
const ZcDb::GridLineType kVertInside	   =  ZcDb::kVertInside;	
const ZcDb::GridLineType kVertRight		   =  ZcDb::kVertRight;	

const ZcDb::GridLineTypes kAllGridLines	=  ZcDb::kAllGridLines;	

const ZcDb::RowType kUnknownRow			   =  ZcDb::kUnknownRow;	
const ZcDb::RowType kDataRow			   =  ZcDb::kDataRow;	
const ZcDb::RowType kTitleRow			   =  ZcDb::kTitleRow;	
const ZcDb::RowType kHeaderRow			   =  ZcDb::kHeaderRow;	

const ZcDb::RowTypes kAllRows               =  ZcDb::kAllRows;	

const ZcDb::TableStyleFlags kHorzInsideLineFirst =  ZcDb::kHorzInsideLineFirst;
const ZcDb::TableStyleFlags kHorzInsideLineSecond =  ZcDb::kHorzInsideLineSecond;
const ZcDb::TableStyleFlags kHorzInsideLineThird =  ZcDb::kHorzInsideLineThird;
const ZcDb::TableStyleFlags kTableStyleModified =  ZcDb::kTableStyleModified;

const ZcDb::SliceModelType kKeepBothSides    =  ZcDb::kKeepBothSides;
const ZcDb::SliceModelType kUseCurrentColor  =  ZcDb::kUseCurrentColor;

#endif