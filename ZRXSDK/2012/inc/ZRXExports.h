
#ifndef _ZRXEXPORTS_H_
#define _ZRXEXPORTS_H_


#define ZRX_EXPORT	__declspec(dllexport)
#define ZRX_IMPORT	__declspec(dllimport)


#ifdef ZRX_OSBASE_EXPORTS
	#define ZRX_OSBASE_EXPORT			ZRX_EXPORT
#else
	#define ZRX_OSBASE_EXPORT			ZRX_IMPORT
#endif

#ifdef ZRX_OSBASE_STATIC_EXPORTS
	#define ZRX_OSBASE_EXPORT_STATIC		ZRX_EXPORT
	#define ZRX_OSBASE_STATIC_EXPORT	
#else
	#define ZRX_OSBASE_EXPORT_STATIC
	#define ZRX_OSBASE_STATIC_EXPORT		ZRX_IMPORT
#endif


#ifdef ZRX_UT_EXPORTS
	#define ZRX_UT_EXPORT				ZRX_EXPORT
#else
	#define ZRX_UT_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_UT_STATIC_EXPORTS
	#define ZRX_UT_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_UT_STATIC_EXPORT
#else
	#define ZRX_UT_EXPORT_STATIC
	#define ZRX_UT_STATIC_EXPORT			ZRX_IMPORT
#endif


#ifdef ZRX_RX_EXPORTS
	#define ZRX_RX_EXPORT				ZRX_EXPORT
#else
	#define ZRX_RX_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_RX_STATIC_EXPORTS
	#define ZRX_RX_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_RX_STATIC_EXPORT
#else
	#define ZRX_RX_EXPORT_STATIC
	#define ZRX_RX_STATIC_EXPORT			ZRX_IMPORT
#endif


#ifdef ZRX_GE_EXPORTS
	#define ZRX_GE_EXPORT				ZRX_EXPORT
#else
	#define ZRX_GE_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_GE_STATIC_EXPORTS
	#define ZRX_GE_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_GE_STATIC_EXPORT
#else
	#define ZRX_GE_EXPORT_STATIC
	#define ZRX_GE_STATIC_EXPORT			ZRX_IMPORT
#endif

#ifdef ZRX_GI_EXPORTS
	#define ZRX_GI_EXPORT				ZRX_EXPORT
#else
	#define ZRX_GI_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_GI_STATIC_EXPORTS
	#define ZRX_GI_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_GI_STATIC_EXPORT			
#else
	#define ZRX_GI_EXPORT_STATIC
	#define ZRX_GI_STATIC_EXPORT			ZRX_IMPORT
#endif

#ifdef ZRX_GS_EXPORTS
	#define ZRX_GS_EXPORT				ZRX_EXPORT
#else
	#define ZRX_GS_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_GS_STATIC_EXPORTS
	#define ZRX_GS_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_GS_STATIC_EXPORT			
#else
	#define ZRX_GS_EXPORT_STATIC
	#define ZRX_GS_STATIC_EXPORT			ZRX_IMPORT
#endif

#ifdef ZRX_GR_EXPORTS
	#define ZRX_GR_EXPORT				ZRX_EXPORT
#else
	#define ZRX_GR_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_GR_STATIC_EXPORTS
	#define ZRX_GR_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_GR_STATIC_EXPORT			
#else
	#define ZRX_GR_EXPORT_STATIC
	#define ZRX_GR_STATIC_EXPORT			ZRX_IMPORT
#endif


#ifdef ZRX_DBROOT_EXPORTS
	#define ZRX_DBROOT_EXPORT			ZRX_EXPORT
#else
	#define ZRX_DBROOT_EXPORT			ZRX_IMPORT
#endif

#ifdef ZRX_DBROOT_STATIC_EXPORTS
	#define ZRX_DBROOT_EXPORT_STATIC		ZRX_EXPORT
	#define ZRX_DBROOT_STATIC_EXPORT
#else
	#define ZRX_DBROOT_EXPORT_STATIC
	#define ZRX_DBROOT_STATIC_EXPORT		ZRX_IMPORT
#endif


#ifdef ZRX_DB_EXPORTS
	#define ZRX_DB_EXPORT				ZRX_EXPORT
#else
	#define ZRX_DB_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_DB_STATIC_EXPORTS
	#define ZRX_DB_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_DB_STATIC_EXPORT
	#define ZRX_DB_EXPORT_GLOBAL			ZRX_EXPORT
#else
	#define ZRX_DB_EXPORT_STATIC
	#define ZRX_DB_STATIC_EXPORT			ZRX_IMPORT
	#define ZRX_DB_EXPORT_GLOBAL			ZRX_IMPORT
#endif


#ifdef ZRX_ED_EXPORTS
	#define ZRX_ED_EXPORT				ZRX_EXPORT
#else
	#define ZRX_ED_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_ED_STATIC_EXPORTS
	#define ZRX_ED_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_ED_STATIC_EXPORT
#else
	#define ZRX_ED_EXPORT_STATIC
	#define ZRX_ED_STATIC_EXPORT			ZRX_IMPORT
#endif


#ifdef ZRX_AP_EXPORTS
	#define ZRX_AP_EXPORT				ZRX_EXPORT
#else
	#define ZRX_AP_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_AP_STATIC_EXPORTS
	#define ZRX_AP_EXPORT_STATIC			ZRX_EXPORT
	#define ZRX_AP_STATIC_EXPORT
#else
	#define ZRX_AP_EXPORT_STATIC
	#define ZRX_AP_STATIC_EXPORT			ZRX_IMPORT
#endif


#ifdef ZRX_APP_EXPORTS
	#define ZRX_APP_EXPORT				ZRX_EXPORT
#else
	#define ZRX_APP_EXPORT				ZRX_IMPORT
#endif

#ifdef ZRX_APP_STATIC_EXPORTS
	#define ZRX_APP_EXPORT_STATIC		ZRX_EXPORT
	#define ZRX_APP_STATIC_EXPORT
#else
	#define ZRX_APP_EXPORT_STATIC
	#define ZRX_APP_STATIC_EXPORT		ZRX_IMPORT
#endif


#endif	//_ZRXEXPORTS_H_
