

#ifndef _zcedads_h
#define _zcedads_h 1

#ifdef __cplusplus
    extern "C" {
#endif

#include "zadsdef.h"
#include "zacmem.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

void           zcrx_abort (const ZTCHAR * format, ...);
ZTCHAR*         zcedGetAppName ();
int            zcedUpdate(int vport, zds_point p1, zds_point p2);

#if defined(_WINDEF_)

HWND           zdsw_zcadMainWnd();
#ifndef zdsw_hwndZcad
#define zdsw_hwndZcad zdsw_zcadMainWnd()
#endif

HWND           zdsw_zcadDocWnd();

#endif  

int            zcedCommand (int rtype, ...);
int            zcedCmd (const struct resbuf *rbp);

int            zcedRegFunc (int (*fhdl) (void), int fcode);

int            zcedUsrBrk (void);

int            zcedDefun (const ZTCHAR *sname, short funcno);

int            zcedSetFunHelp (const ZTCHAR* pszFunctionName,
                               const ZTCHAR* pszHelpfile,
                               const ZTCHAR* pszTopic, int iCmd);

int            zcedUndef (const ZTCHAR *sname, short funcno);

int            zcedGetFunCode (void);
struct resbuf *zcedGetArgs (void);

int            zcedRetList (const struct resbuf *rbuf);
int            zcedRetVal (const struct resbuf *rbuf);
int            zcedRetPoint (const zds_point pt);
int            zcedRetStr (const ZTCHAR *s);
int            zcedRetName (const zds_name aname, int type);
int            zcedRetInt (int ival);
int            zcedRetReal (zds_real rval);
int            zcedRetT (void);
int            zcedRetNil (void);
int            zcedRetVoid (void);

int            zcedEntSel (const ZTCHAR *str, zds_name entres,
                             zds_point ptres);
int            zcedNEntSel (const ZTCHAR *str, zds_name entres,
                              zds_point ptres, zds_point xformres[4],
                              struct resbuf **refstkres);
int            zcedNEntSelP (const ZTCHAR *str, zds_name entres,
                              zds_point ptres, int pickflag,
                              zds_matrix xformres,
                              struct resbuf **refstkres);
int            zcedSSGet (const ZTCHAR *str, const void *pt1,
                            const void *pt2, const struct resbuf *filter,
                            zds_name ss);
int            zcedSSGetFirst (struct resbuf** gset, struct resbuf** pset);
int            zcedSSSetFirst (const zds_name pset, const zds_name unused);
int            zcedSSFree (const zds_name sname);
int            zcedSSLength (const zds_name sname, long *len);
int            zcedSSAdd (const zds_name ename, const zds_name sname,
                            zds_name result);
int            zcedSSDel (const zds_name ename, const zds_name ss);
int            zcedSSMemb (const zds_name ename, const zds_name ss);
int            zcedSSName (const zds_name ss, long i, zds_name entres);
int            zcedSSNameX (struct resbuf **rbpp, const zds_name ss,
                              const long i);
int            zcedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const ZTCHAR*));
int            zcedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const ZTCHAR*));
int            zcedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const ZTCHAR*));
int            zcedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const ZTCHAR*));

int            zcedTrans (const zds_point pt, const struct resbuf *from,
                            const struct resbuf *to, int disp,
                            zds_point result);

int            zcedSetVar (const ZTCHAR *sym, const struct resbuf *val);
int            zcedInitGet (int val, const ZTCHAR *kwl);

int            zcedGetSym (const ZTCHAR *sname, struct resbuf **value);
int            zcedPutSym (const ZTCHAR *sname, struct resbuf *value);

int            zcedHelp (const ZTCHAR* szFilename, const ZTCHAR* szTopic, int iCmd);
int            zcedFNSplit (const ZTCHAR *pathToSplit, ZTCHAR *prebuf,
                            ZTCHAR *namebuf, ZTCHAR *extbuf);

#define HELP_CONTENTS     0x0003L  
#define HELP_HELPONHELP   0x0004L  
#define HELP_PARTIALKEY   0x0105L  

struct resbuf  *zcedZrxLoaded (void);
int            zcedZrxLoad (const ZTCHAR *app);
int            zcedZrxUnload (const ZTCHAR *app);

int            zcedInvoke (const struct resbuf *args,
                             struct resbuf **result);

int            zcedGetVar (const ZTCHAR *sym, struct resbuf *result);
int            zcedFindFile (const ZTCHAR *fname, ZTCHAR *result);

int            zcedGetEnv (const ZTCHAR *sym, ZTCHAR  *var);
int            zcedSetEnv (const ZTCHAR *sym, const ZTCHAR *val);

int            zcedGetCfg (const ZTCHAR *sym, ZTCHAR  *var, int len);
int            zcedSetCfg (const ZTCHAR *sym, const ZTCHAR *val);

int            zcedGetString (int cronly, const ZTCHAR *prompt, ZTCHAR *result);
int            zcedGetStringB (int cronly, const ZTCHAR *prompt,
                                    ZTCHAR *result, int bufsize);

int            zcedMenuCmd (const ZTCHAR *str);
int            zcedPrompt (const ZTCHAR *str);
int            zcedAlert (const ZTCHAR *str);

int            zcedGetAngle (const zds_point pt, const ZTCHAR *prompt,
                               zds_real *result);
int            zcedGetCorner (const zds_point pt, const ZTCHAR *prompt,
                                zds_point result);
int            zcedGetDist (const zds_point pt, const ZTCHAR *prompt,
                              zds_real *result);
int            zcedGetOrient (const zds_point pt, const ZTCHAR *prompt,
                                zds_real *result);
int            zcedGetPoint (const zds_point pt, const ZTCHAR *prompt,
                               zds_point result);
int            zcedGetInt (const ZTCHAR *prompt, int *result);
int            zcedGetKword (const ZTCHAR *prompt, ZTCHAR *result);
int            zcedGetReal (const ZTCHAR *prompt, zds_real *result);
int            zcedGetInput (ZTCHAR *str);
int            zcedVports (struct resbuf **vlist);

int            zcedTextScr (void);
int            zcedGraphScr (void);
int            zcedTextPage (void);

int            zcedRedraw (const zds_name ent, int mode);
int            zcedOsnap (const zds_point pt, const ZTCHAR *mode,
                            zds_point result);
int            zcedGrRead (int track, int *type, struct resbuf *result);
int            zcedGrText (int box, const ZTCHAR *text, int hl);
int            zcedGrDraw (const zds_point from, const zds_point to,
                             int color, int hl);
int            zcedGrVecs (const struct resbuf *vlist, zds_matrix mat);
int            zcedXformSS (const zds_name ssname,
                              zds_matrix genmat);
int            zcedDragGen (const zds_name ss, const ZTCHAR *pmt, int cursor,
                              int (*scnf) (zds_point pt, zds_matrix mt),
                              zds_point p);
int            zcedSetView (const struct resbuf *view, int vport);

int            zcedGetFileD (const ZTCHAR *title, const ZTCHAR *defawlt,
                               const ZTCHAR *ext, int flags,
                               struct resbuf *result);
int            zcedGetFileNavDialog (const ZTCHAR *title, const ZTCHAR *defawlt,
                             const ZTCHAR *ext, const ZTCHAR *dlgname, int flags,
                             struct resbuf **result);

int            zcedTextBox (const struct resbuf *args,
                              zds_point pt1, zds_point pt2);

int            zcedTablet  (const struct resbuf *args,
                              struct resbuf **result);

int            zcedGetCName (const ZTCHAR *cmd, ZTCHAR **result);

int           zcedEatCommandThroat(void);
int            zcdbEntDel (const zds_name ent);
struct resbuf *zcdbEntGetX (const zds_name ent, const struct resbuf *args);
struct resbuf *zcdbEntGet (const zds_name ent);
int            zcdbEntLast (zds_name result);
int            zcdbEntNext (const zds_name ent, zds_name result);
int            zcdbEntUpd (const zds_name ent);
int            zcdbEntMod (const struct resbuf *ent);
int            zcdbEntMake (const struct resbuf *ent);
int            zcdbEntMakeX (const struct resbuf *entm, zds_name result);
int            zcdbRegApp (const ZTCHAR *appname);
struct resbuf *zcdbTblNext (const ZTCHAR *tblname, int rewind);
struct resbuf *zcdbTblSearch (const ZTCHAR *tblname, const ZTCHAR *sym,
                              int setnext);
int	           zcdbNamedObjDict (zds_name result);
struct resbuf *zcdbDictSearch (const zds_name dict, const ZTCHAR* sym,
                               int setnext);
struct resbuf *zcdbDictNext (const zds_name dict, int rewind);
int            zcdbDictRename (const zds_name dictname, const ZTCHAR* oldsym,
                               const ZTCHAR* newsym);
int            zcdbDictRemove (const zds_name dictname, const ZTCHAR* symname);
int            zcdbDictAdd (const zds_name dictname, const ZTCHAR* symname,
                            const zds_name newobj);

int            zcdbTblObjName (const ZTCHAR *tblname, const ZTCHAR *sym,
                               zds_name result);

int            zcdbAngToS (zds_real v, int unit, int prec, ZTCHAR *str);
int            zcdbRawAngToS (zds_real v, int unit, int prec, ZTCHAR *str);
int            zcdbRToS (zds_real val, int unit, int prec, ZTCHAR *str);
int            zcdbAngToF (const ZTCHAR *str, int unit, zds_real *v);
int            zcdbRawAngToF (const ZTCHAR *str, int unit, zds_real *v);
int            zcdbDisToF (const ZTCHAR *str, int unit, zds_real *v);
int            zcdbInters (const zds_point from1, const zds_point to1,
                             const zds_point from2, const zds_point to2,
                             int teston, zds_point result);
int            zcdbSNValid (const ZTCHAR *tbstr, int pipetest);

#pragma pack (pop)

#ifdef __cplusplus
    }
#endif  

#pragma pack (push, 8)
#ifdef __cplusplus
extern "C++" {

int            zcedGetFullInput(ZTCHAR *&pStr);
int            zcedGetFullKword(const ZTCHAR * pString, ZTCHAR *&pStr);
int            zcedGetFullString(int cronly, const ZTCHAR *pString,
                                 ZTCHAR *&pResult);
int            zcedSSNameXEx (struct resbuf **rbpp, const zds_name ss,
                              const long i, unsigned int flags = 0);
}

#endif  

#pragma pack (pop)

#endif  
