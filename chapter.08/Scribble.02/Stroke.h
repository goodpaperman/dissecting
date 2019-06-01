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

class CRectangle : public CObject
{
public:
    CRectangle(CRect rect); 

protected:
    CRectangle(); 
    DECLARE_SERIAL(CRectangle)

    CRect m_rect; 

public:
    virtual void Serialize(CArchive& ar); 
}; 

class CCircle : public CObject
{
public:
    CCircle(CPoint center, UINT radius); 

protected:
    CCircle(); 
    DECLARE_SERIAL(CCircle)

    CPoint m_center; 
    UINT m_radius; 

public:
    virtual void Serialize(CArchive& ar); 
}; 

#endif // !defined(AFX_STROKE_H__8FB6BA80_012F_4022_A098_4DB12259E36D__INCLUDED_)
