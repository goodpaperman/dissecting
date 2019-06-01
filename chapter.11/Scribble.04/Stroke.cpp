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

IMPLEMENT_SERIAL(CStroke, CObject, 2)

CStroke::CStroke()
{
    m_nPenWidth = 2; 
    m_rectBounding.SetRectEmpty(); 
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
        ar << m_rectBounding; 
        m_pointList.Serialize(ar); 
    }
    else 
    {
        WORD w; 
        ar >> w;
        m_nPenWidth = w; 
        ar >> m_rectBounding; 
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

void CStroke::FinishStroke()
{
    CPoint pt; 
    m_rectBounding.SetRectEmpty(); 
    POSITION pos = m_pointList.GetHeadPosition(); 
    if(pos != NULL)
    {
        pt = m_pointList.GetNext(pos); 
        m_rectBounding.SetRect(pt.x, pt.y, pt.x, pt.y); 
    }
    else 
        return ;

    while(pos != NULL)
    {
        pt = m_pointList.GetNext(pos); 
        m_rectBounding.left = min(m_rectBounding.left, pt.x); 
        m_rectBounding.right = max(m_rectBounding.right, pt.x); 
        m_rectBounding.top = min(m_rectBounding.top, pt.y); 
        m_rectBounding.bottom = max(m_rectBounding.bottom, pt.y); 
    }

    m_rectBounding.InflateRect(m_nPenWidth, m_nPenWidth); 
}
