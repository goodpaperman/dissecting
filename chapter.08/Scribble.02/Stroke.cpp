// Stroke.cpp: implementation of the CStroke class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Scribble.h"
#include "Stroke.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CStroke, CObject, 1)

CStroke::CStroke()
{
    m_nPenWidth = 2; 
}

CStroke::CStroke(UINT nPenWidth)
{
    m_nPenWidth = nPenWidth; 
}

CStroke::~CStroke()
{

}

void CStroke::Serialize(CArchive& ar)
{
    if(ar.IsStoring())
    {
        ar << (WORD)m_nPenWidth; 
        m_pointList.Serialize(ar); 
    }
    else 
    {
        WORD w; 
        ar >> w;
        m_nPenWidth = w; 
        m_pointList.Serialize(ar); 
    }
}

BOOL CStroke::DrawStroke(CDC* pDC)
{
    if(m_pointList.GetCount() == 0)
        return FALSE; 

    CPen penStroke; 
    if(!penStroke.CreatePen(PS_SOLID, m_nPenWidth, RGB(0, 0, 0)))
        return FALSE; 

    CPen* pOldPen = pDC->SelectObject(&penStroke); 
    
    POSITION pos = m_pointList.GetHeadPosition(); 
    pDC->MoveTo(m_pointList.GetNext(pos)); 
    while(pos != NULL)
    {
        CPoint point = m_pointList.GetNext(pos); 
        pDC->LineTo(point); 
    }

    pDC->SelectObject(pOldPen); 
    return TRUE; 
}



IMPLEMENT_SERIAL(CRectangle, CObject, 1)

CRectangle::CRectangle()
{
}

CRectangle::CRectangle(CRect rect)
{
    m_rect = rect; 
}

void CRectangle::Serialize(CArchive& ar)
{
    if(ar.IsStoring())
        ar << m_rect; 
    else 
        ar >> m_rect; 
}



IMPLEMENT_SERIAL(CCircle, CObject, 1)

CCircle::CCircle()
{
}

CCircle::CCircle(CPoint center, UINT radius)
{
    m_radius = radius; 
    m_center = center; 
}

void CCircle::Serialize(CArchive& ar)
{
    if(ar.IsStoring())
    {
        ar << m_center; 
        ar << m_radius; 
    }
    else 
    {
         ar >> m_center; 
         ar >> m_radius; 
    }
}
