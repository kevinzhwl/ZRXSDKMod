

#pragma once

#pragma pack (push, 8)

#include "zaduivolumedescriptor.h"

class ZDUI_PORT CZdUiPathname {

public:

        CZdUiPathname(void);
        CZdUiPathname(const CZdUiPathname&);

        ~CZdUiPathname(void);

        void Empty(void);

virtual PathErr Parse( LPCTSTR, const BOOL wildcard_ok = FALSE );

        PathErr ParseRelative( LPCTSTR name,
                               const CZdUiPathname* relpath,
                               const BOOL wildcard_ok = FALSE );

        BOOL ParseAndOSFind( LPCTSTR );

        const CZdUiPathname& CZdUiPathname::operator=(const CZdUiPathname& pathSrc);
        const CZdUiPathname& CZdUiPathname::operator=(const CZdUiPathname* pathSrc);

        BOOL CZdUiPathname::GetUniqueName(
                               CZdUiPathname&, 
                               BOOL alwaysMangle = FALSE ) const;

        void GetFilename(CString&) const;

        void GetExtension(CString&) const;

        void GetBasename(CString&) const;

        void GetParent(CZdUiPathname& ) const;

        PathErr Trim(void);

        PathErr TrimSlash(void);

        PathErr TrimComponent(void);

        PathErr Append( LPCTSTR );

        PathErr AppendSlash(void);

        PathErr AppendComponent( LPCTSTR );

        PathErr AddExtensionAlways( LPCTSTR );

        PathErr AddExtensionIfNoMatch( LPCTSTR );

        PathErr ReplaceExtensionAlways( LPCTSTR );

        PathErr ReplaceExtensionIfNoMatch( LPCTSTR );

        void RemoveExtensionAlways(void);

        void RemoveExtensionIfMatch( LPCTSTR );

        void BaseToLower( void );
        void BaseToUpper( void );

        void RemoveSpaces( void );

        void GetDisplayName( CString& strResult, int maxchars ) const;

        LPCTSTR GetPathString(void) const;

        BOOL GetFullPath( CString& ) const;
        BOOL GetFullPath( LPTSTR ) const;

        void GetFullUNCPath(CString&) const;

        BOOL IsPath(void) const;

        BOOL IsEmpty(void) const;

        path_type GetPathType(void) const;

        const CZdUiVolumeDescriptor* GetVolumeDescriptor(void) const;

        BOOL PathMatch( const CZdUiPathname* ) const;
        BOOL PathMatch( LPCTSTR ) const;

        BOOL Exists(void);

        BOOL VerifyExtension( LPCTSTR extlist ) const;

        BOOL HadPrefix(void) const;

        BOOL WasAbsolute(void) const;

        BOOL WasRoot(void) const;

        BOOL Open(FILE** fdp, const ZTCHAR *openmode);
        BOOL Open(CFile& fp, UINT openflags);

        BOOL OpenReadOnly(HANDLE &rFileHandle);
        BOOL OpenWriteOnly(HANDLE &rFileHandle);

        BOOL Rename(const ZTCHAR *newname);

        BOOL Remove(void);

protected:

        path_type                       m_this_type;

        const CZdUiVolumeDescriptor*        m_pvolume;

        CString*                        m_pathbuffer;

        CString*                        m_relpath;

        path_category                   m_path_cat;

        ZTCHAR                           m_separator;

        BOOL                            m_had_prefix;

        const CZdUiVolumeDescriptor* FindVolumeDescriptor(const CString& vol_name) const;

        const CZdUiVolumeDescriptor* NewVolDescriptor( const CString& vol_name) const;

        FS_TYPE GetFileSystem(CString& vol_name) const;

       inline BOOL IsDeviceName(const CString& str) const;

        static void Unquote( CString& );

        ZTCHAR GetSeparator(void) const;

virtual void AssignCopy( const CZdUiPathname& );

        static ZTCHAR GetLastCharacter( const CString& );
        
private:

        void GetFirstExtInList( LPCTSTR, CString&) const;

        void lstrncpy_x( LPTSTR dest, LPCTSTR src, int nchars) const;
        void StripSpaces(CString& work);
        void GetAttributes(const CString* path,
                const CString* relpath,
                path_type* this_type);
};

inline CZdUiPathname::CZdUiPathname(const CZdUiPathname& pathSrc)
{
        m_pathbuffer = NULL;
        m_relpath = NULL;

        AssignCopy( pathSrc );
}

inline path_type CZdUiPathname::GetPathType(void) const
{
        return m_this_type;
}

inline BOOL CZdUiPathname::IsPath(void) const
{
        return ((m_this_type == FILE_PATH)
                || (m_this_type == DIR_PATH)
                || (m_this_type == NEW_PATH) 
                || (m_this_type == WC_PATH) );
        
}        

inline BOOL CZdUiPathname::IsEmpty(void) const
{
        return (m_this_type == NO_PATH);
}        

inline const CZdUiVolumeDescriptor* CZdUiPathname::GetVolumeDescriptor(void) const
{
        return m_pvolume;
}

inline BOOL CZdUiPathname::HadPrefix(void) const
{
        return m_had_prefix;
}

inline const CZdUiPathname& CZdUiPathname::operator=(const CZdUiPathname& pathSrc)
{
        AssignCopy( pathSrc);

        return *this;
}

inline const CZdUiPathname& CZdUiPathname::operator=(const CZdUiPathname* pathSrc)
{
        AssignCopy( *pathSrc);

        return *this;
}

inline BOOL CZdUiPathname::WasAbsolute(void) const
{
    return ( (m_path_cat == DRIVE_TYPE) ||
            (m_path_cat == UNC_TYPE) );
}

inline BOOL CZdUiPathname::WasRoot(void) const
{
    return (m_path_cat == ROOT_TYPE);
}

#pragma pack (pop)

