

#ifndef _ZDUI_THEME_MANAGER_H_
#define _ZDUI_THEME_MANAGER_H_

class CZdUiThemeMgrReactor
{
public:
    CZdUiThemeMgrReactor();
    virtual void ThemeAdded(const CString & strThemeName) = 0;
    virtual void ThemeRemoved(const CString & strThemeName) = 0;
    virtual void SystemColorChanged() = 0;
    ~CZdUiThemeMgrReactor();
};

class CZdUiThemeManager 
{
    friend class CZdUiThemeMgrReactor;

public:
    CZdUiThemeManager();
    ~CZdUiThemeManager();

    CZdUiTheme * GetTheme(const ZTCHAR *pThemeName);
    BOOL ReleaseTheme(CZdUiTheme * pTheme);

    BOOL HasTheme(const ZTCHAR *pThemeName) const;

    void SystemColorChanged();

private:
    int  RemoveTheme(const ZTCHAR *pThemeName);
    void Cleanup();
    int  GetThemeIndex(const ZTCHAR *pThemeName) const;
    int  GetThemeIndex(const CZdUiTheme *pTheme) const;
    BOOL RegisterThemeMgrReactor(CZdUiThemeMgrReactor * pReactor);
    BOOL UnregisterThemeMgrReactor(CZdUiThemeMgrReactor * pReactor);
    void NotifyThemeAddedReactors(const CString & strThemeName);
    void NotifySysColorReactors();
    CObArray        m_list;
    CTypedPtrArray<CPtrArray, CZdUiThemeMgrReactor*> m_arrayThemeMgrReactors;
};
#endif  
