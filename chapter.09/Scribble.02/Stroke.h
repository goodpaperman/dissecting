// Stroke.h: interface for the CStroke class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STROKE_H__8FB6BA80_012F_4022_A098_4DB12259E36D__INCLUDED_)
#define AFX_STROKE_H__8FB6BA80_012F_4022_A098_4DB12259E36D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStroke : public CObject  
{
public:
    CStroke(); 
	CStroke(UINT nPenWidth);
	virtual ~CStroke();

protected:
    UINT m_nPenWidth; 

public:
    CList<CPoint, CPoint> m_pointList; 

public:
    BOOL DrawStroke(CDC* pDC); 
    virtual void Serialize(CArchive& ar);     

    DECLARE_SERIAL(CStroke)
};

#endif // !defined(AFX_STROKE_H__8FB6BA80_012F_4022_A098_4DB12259E36D__INCLUDED_)
