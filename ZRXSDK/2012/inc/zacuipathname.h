

#pragma once

#pragma pack (push, 8)

class AFILE;

class ZCUI_PORT CZcUiPathname : public CZdUiPathname {

public:
        CZcUiPathname(void);
        CZcUiPathname(const CZcUiPathname&);
        ~CZcUiPathname(void);

virtual PathErr Parse( LPCTSTR, const BOOL wildcard_ok = FALSE );
        int Status(void);
        BOOL Open(AFILE** fdp, const TCHAR *openmode);

        const CZcUiPathname& CZcUiPathname::operator=(const CZcUiPathname& pathSrc);
        const CZcUiPathname& CZcUiPathname::operator=(const CZcUiPathname* pathSrc);

protected:

virtual void AssignCopy( const CZcUiPathname& );

};

inline const CZcUiPathname& CZcUiPathname::operator=(const CZcUiPathname& pathSrc)
{
    AssignCopy( pathSrc);

    return *this;
}

inline const CZcUiPathname& CZcUiPathname::operator=(const CZcUiPathname* pathSrc)
{
    AssignCopy( *pathSrc);

    return *this;
}

#pragma pack (pop)

