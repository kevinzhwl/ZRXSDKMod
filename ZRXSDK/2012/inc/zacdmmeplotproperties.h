
#ifndef ZcDMMEPlotProperties_h
#define ZcDMMEPlotProperties_h

#include "zAcDMMEPlotProperty.h"
#include "zAcDMMUtils.h"

class ZcDMMEPlotProperties
{
public:
    ZcDMMEPlotProperties()
        : m_id(NULL)
    {

    }
    ZcDMMEPlotProperties(const ZcDMMEPlotProperties &src)
        : m_id(NULL)
    {
        *this = src;
    }
    ~ZcDMMEPlotProperties()
    {
        m_properties.clear();
        m_refs.clear();
        if (NULL != m_id)
            delete m_id;
    }
    void AddProperty(const ZcDMMEPlotProperty * property)
    {
        if (NULL == property)
            return;
        m_properties.push_back(*property);
    }
    void AddProperty(wchar_t * name, wchar_t *value)
    {
        ZcDMMEPlotProperty newProp(name, value);
        m_properties.push_back(newProp);
    }
    const ZcDMMEPlotPropertyVec& GetProperties() const
    {
        return m_properties;
    }
    const ZcDMMEPlotProperty * GetProperty(unsigned long index) const
    {
        if (m_properties.size() <= index)
            return NULL;
        return &m_properties[index];
    }
    void ZcDMMEPlotProperties::SetId(const wchar_t * id)
    {
        if (NULL != m_id)
            delete m_id;
        if (NULL != id) {
            m_id = new wchar_t[::wcslen(id) + 1];
            ::wcscpy(m_id, id);
        } else
            m_id = NULL;
    }
    const wchar_t * GetId() const
    {
        return m_id;
    }
    void ZcDMMEPlotProperties::SetRefs(const ZcDMMStringVec& refs)
    {
        m_refs.clear();
        m_refs.assign(refs.begin(), refs.end());
    }
    const ZcDMMStringVec * ZcDMMEPlotProperties::GetRefs() const
    {
        return &m_refs;
    }
    ZcDMMEPlotProperties& operator= (const ZcDMMEPlotProperties &src)
    {
        if (this == &src)
            return *this;

        m_properties.assign(src.m_properties.begin(),
            src.m_properties.end());
        SetId(src.m_id);
        SetRefs(src.m_refs);
        return *this;
    }

private:

    ZcDMMEPlotPropertyVec m_properties;
    wchar_t * m_id;
    ZcDMMStringVec m_refs;
};

#endif 
