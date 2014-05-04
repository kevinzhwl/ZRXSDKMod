
#pragma once

#include "zacdocman.h"
#include <map>

template <class T> 
class ZcApDataManager : public ZcApDocManagerReactor {

public:
	ZcApDataManager () {
		zcDocManager->addReactor (this) ;
	}
	~ZcApDataManager () {
		if ( zcDocManager != NULL )
			zcDocManager->removeReactor (this) ;
	}
	virtual void documentToBeDestroyed (ZcApDocument *pDoc) {
		m_dataMap.erase (pDoc) ;
	}

	T &docData (ZcApDocument *pDoc) {
		std::map<ZcApDocument *, T>::iterator i =m_dataMap.find (pDoc) ;
		if ( i == m_dataMap.end () )
			return (m_dataMap [pDoc]) ;
		return ((*i).second) ;
	}
	T &docData () {
		return (docData (zcDocManager->curDocument ())) ;
	}

private:
	std::map<ZcApDocument *, T> m_dataMap ;
} ;
