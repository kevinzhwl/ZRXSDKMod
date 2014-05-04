

#ifndef _ZCFILEDEPMGR_H
#define _ZCFILEDEPMGR_H

#pragma pack(push, 8)

class ZcFileDependencyInfo {
    public:
        const ZTCHAR *mpFullFileName;
        const ZTCHAR *mpFileName;
        const ZTCHAR *mpFoundPath;
        const ZTCHAR *mpFingerprintGuid;
        const ZTCHAR *mpVersionGuid;
        const ZTCHAR *mpFeature;
        bool        mIsModified;
        bool        mAffectsGraphics;
        long        mIndex;
        long        mTimeStamp;
        long        mFileSize;
        long        mReferenceCount;
};

class ZSOFT_NO_VTABLE ZcFileDependencyManager {
    public:
        virtual ~ZcFileDependencyManager() {};

        virtual long createEntry(const ZTCHAR *feature,
                                 const ZTCHAR *fullFileName,
                                 const bool affectsGraphics = false,
                                 const bool noIncrement = false) = 0;

        virtual Zcad::ErrorStatus getEntry(const ZTCHAR *feature,
                                           const ZTCHAR *fullFileName,
                                           ZcFileDependencyInfo *&fileInfo, 
                                           const bool useCachedInfo = false) = 0;

        virtual Zcad::ErrorStatus getEntry(const long index,
                                           ZcFileDependencyInfo *&fileInfo, 
                                           const bool useCachedInfo = false) = 0;

        virtual Zcad::ErrorStatus updateEntry(const ZTCHAR *feature,
                                              const ZTCHAR *fullFileName) = 0;
                                      
        virtual Zcad::ErrorStatus updateEntry(const long index) = 0;

        virtual Zcad::ErrorStatus eraseEntry(const ZTCHAR *feature,
                                             const ZTCHAR *fullFileName,
                                             const bool forceRemove=false) = 0;
                                      
        virtual Zcad::ErrorStatus eraseEntry(const long index,
                                             const bool forceRemove=false) = 0;

        virtual long countEntries() = 0;

        virtual void iteratorInitialize(const ZTCHAR *feature = NULL,
                                        const bool modifiedOnly = false,
                                        const bool affectsGraphicsOnly = false,
                                        const bool walkXRefTree = false) = 0;

        virtual long iteratorNext() = 0;
};

#pragma pack(pop)

#endif
