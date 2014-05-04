

#ifndef ZDBDIMVAR_H
#define ZDBDIMVAR_H

    virtual int              dimadec  () const;  
    virtual bool             dimalt   () const;
    virtual int              dimaltd  () const;
    virtual double           dimaltf  () const;
    virtual double           dimaltrnd() const;  
    virtual int              dimalttd () const;
    virtual int              dimalttz () const;
    virtual int              dimaltu  () const;
    virtual int              dimaltz  () const;
    virtual const ZTCHAR *    dimapost () const;
    virtual int              dimarcsym() const;  
    virtual double           dimasz   () const;
    virtual int              dimatfit () const;  
    virtual int              dimaunit () const;
    virtual int              dimazin  () const;  
    virtual ZcDbObjectId     dimblk   () const;
    virtual ZcDbObjectId     dimblk1  () const;
    virtual ZcDbObjectId     dimblk2  () const;
    virtual double           dimcen   () const;
    virtual ZcCmColor        dimclrd  () const;
    virtual ZcCmColor        dimclre  () const;
    virtual ZcCmColor        dimclrt  () const;
    virtual int              dimdec   () const;
    virtual double           dimdle   () const;
    virtual double           dimdli   () const;
    virtual ZTCHAR            dimdsep  () const;  
    virtual double           dimexe   () const;
    virtual double           dimexo   () const;
    virtual int              dimfrac  () const;  
    virtual double           dimgap   () const;
    virtual double           dimjogang() const;  
    virtual int              dimjust  () const;
    virtual ZcDbObjectId     dimldrblk() const;  
    virtual double           dimlfac  () const;
    virtual bool             dimlim   () const;
    virtual ZcDbObjectId     dimltex1 () const;  
    virtual ZcDbObjectId     dimltex2 () const;  
    virtual ZcDbObjectId     dimltype () const;  
    virtual int              dimlunit () const;  
    virtual ZcDb::LineWeight dimlwd   () const;  
    virtual ZcDb::LineWeight dimlwe   () const;  
    virtual const ZTCHAR *    dimpost  () const;
    virtual double           dimrnd   () const;
    virtual bool             dimsah   () const;
    virtual double           dimscale () const;
    virtual bool             dimsd1   () const;
    virtual bool             dimsd2   () const;
    virtual bool             dimse1   () const;
    virtual bool             dimse2   () const;
    virtual bool             dimsoxd  () const;
    virtual int              dimtad   () const;
    virtual int              dimtdec  () const;
    virtual double           dimtfac  () const;
    virtual int              dimtfill () const;   
    virtual ZcCmColor        dimtfillclr() const; 
    virtual bool             dimtih   () const;
    virtual bool             dimtix   () const;
    virtual double           dimtm    () const;
    virtual int              dimtmove () const;  
    virtual bool             dimtofl  () const;
    virtual bool             dimtoh   () const;
    virtual bool             dimtol   () const;
    virtual int              dimtolj  () const;
    virtual double           dimtp    () const;
    virtual double           dimtsz   () const;
    virtual double           dimtvp   () const;
    virtual ZcDbObjectId     dimtxsty () const;
    virtual double           dimtxt   () const;
    virtual int              dimtzin  () const;
    virtual bool             dimupt   () const;
    virtual int              dimzin   () const;

    virtual bool             dimfxlenOn  () const;  
    virtual double           dimfxlen    () const;  
    virtual bool             dimtxtdirection() const;  
    virtual double           dimmzf   () const;        
    virtual const ZTCHAR *   dimmzs   () const;        
    virtual double           dimaltmzf() const;        
    virtual const ZTCHAR *    dimaltmzs() const;
    virtual Zcad::ErrorStatus setDimadec  (int              v);  
    virtual Zcad::ErrorStatus setDimalt   (bool             v);
    virtual Zcad::ErrorStatus setDimaltd  (int              v);
    virtual Zcad::ErrorStatus setDimaltf  (double           v);
    virtual Zcad::ErrorStatus setDimaltmzf(double           v);  
    virtual Zcad::ErrorStatus setDimaltmzs(const ZTCHAR *    v); 
    virtual Zcad::ErrorStatus setDimaltrnd(double           v);  
    virtual Zcad::ErrorStatus setDimalttd (int              v);
    virtual Zcad::ErrorStatus setDimalttz (int              v);
    virtual Zcad::ErrorStatus setDimaltu  (int              v);
    virtual Zcad::ErrorStatus setDimaltz  (int              v);
    virtual Zcad::ErrorStatus setDimapost (const ZTCHAR *    v);
    virtual Zcad::ErrorStatus setDimarcsym(int              v);  
    virtual Zcad::ErrorStatus setDimasz   (double           v);
    virtual Zcad::ErrorStatus setDimatfit (int              v);  
    virtual Zcad::ErrorStatus setDimaunit (int              v);
    virtual Zcad::ErrorStatus setDimazin  (int              v);  
    virtual Zcad::ErrorStatus setDimblk   (ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimblk1  (ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimblk2  (ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimcen   (double           v);
    virtual Zcad::ErrorStatus setDimclrd  (const ZcCmColor& v);
    virtual Zcad::ErrorStatus setDimclre  (const ZcCmColor& v);
    virtual Zcad::ErrorStatus setDimclrt  (const ZcCmColor& v);
    virtual Zcad::ErrorStatus setDimdec   (int              v);
    virtual Zcad::ErrorStatus setDimdle   (double           v);
    virtual Zcad::ErrorStatus setDimdli   (double           v);
    virtual Zcad::ErrorStatus setDimdsep  (ZTCHAR            v);  
    virtual Zcad::ErrorStatus setDimexe   (double           v);
    virtual Zcad::ErrorStatus setDimexo   (double           v);
    virtual Zcad::ErrorStatus setDimfrac  (int              v);  
    virtual Zcad::ErrorStatus setDimgap   (double           v);
    virtual Zcad::ErrorStatus setDimjogang(double           v);  
    virtual Zcad::ErrorStatus setDimjust  (int              v);
    virtual Zcad::ErrorStatus setDimldrblk(ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimlfac  (double           v);
    virtual Zcad::ErrorStatus setDimlim   (bool             v);
    virtual Zcad::ErrorStatus setDimltex1 (ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimltex2 (ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimltype (ZcDbObjectId     v);  
    virtual Zcad::ErrorStatus setDimlunit (int              v);  
    virtual Zcad::ErrorStatus setDimlwd   (ZcDb::LineWeight v);  
    virtual Zcad::ErrorStatus setDimlwe   (ZcDb::LineWeight v); 
    virtual Zcad::ErrorStatus setDimmzf   (double           v);  
    virtual Zcad::ErrorStatus setDimmzs   (const ZTCHAR *    v);
    virtual Zcad::ErrorStatus setDimpost  (const ZTCHAR *    v);
    virtual Zcad::ErrorStatus setDimrnd   (double           v);
    virtual Zcad::ErrorStatus setDimsah   (bool             v);
    virtual Zcad::ErrorStatus setDimscale (double           v);
    virtual Zcad::ErrorStatus setDimsd1   (bool             v);
    virtual Zcad::ErrorStatus setDimsd2   (bool             v);
    virtual Zcad::ErrorStatus setDimse1   (bool             v);
    virtual Zcad::ErrorStatus setDimse2   (bool             v);
    virtual Zcad::ErrorStatus setDimsoxd  (bool             v);
    virtual Zcad::ErrorStatus setDimtad   (int              v);
    virtual Zcad::ErrorStatus setDimtdec  (int              v);
    virtual Zcad::ErrorStatus setDimtfac  (double           v);
    virtual Zcad::ErrorStatus setDimtfill (int              v);   
    virtual Zcad::ErrorStatus setDimtfillclr(const ZcCmColor& v); 
    virtual Zcad::ErrorStatus setDimtih   (bool             v);
    virtual Zcad::ErrorStatus setDimtix   (bool             v);
    virtual Zcad::ErrorStatus setDimtm    (double           v);
    virtual Zcad::ErrorStatus setDimtmove (int              v);  
    virtual Zcad::ErrorStatus setDimtofl  (bool             v);
    virtual Zcad::ErrorStatus setDimtoh   (bool             v);
    virtual Zcad::ErrorStatus setDimtol   (bool             v);
    virtual Zcad::ErrorStatus setDimtolj  (int              v);
    virtual Zcad::ErrorStatus setDimtp    (double           v);
    virtual Zcad::ErrorStatus setDimtsz   (double           v);
    virtual Zcad::ErrorStatus setDimtvp   (double           v);
    virtual Zcad::ErrorStatus setDimtxsty (ZcDbObjectId     v);
    virtual Zcad::ErrorStatus setDimtxt   (double           v);
    virtual Zcad::ErrorStatus setDimtxtdirection (bool      v);
    virtual Zcad::ErrorStatus setDimtzin  (int              v);
    virtual Zcad::ErrorStatus setDimupt   (bool             v);
    virtual Zcad::ErrorStatus setDimzin   (int              v);

    virtual Zcad::ErrorStatus setDimblk   (const ZTCHAR *    v);
    virtual Zcad::ErrorStatus setDimblk1  (const ZTCHAR *    v);
    virtual Zcad::ErrorStatus setDimblk2  (const ZTCHAR *    v);
    virtual Zcad::ErrorStatus setDimldrblk(const ZTCHAR *    v);  

    virtual Zcad::ErrorStatus setDimfxlenOn (bool           v);  
    virtual Zcad::ErrorStatus setDimfxlen (double           v);  

#endif

