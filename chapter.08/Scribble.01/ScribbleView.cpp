// ScribbleView.cpp : implementation of the CScribbleView class
//

#include "stdafx.h"
#include "Scribble.h"

#include "ScribbleDoc.h"
#include "ScribbleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScribbleView

IMPLEMENT_DYNCREATE(CScribbleView, CView)

BEGIN_MESSAGE_MAP(CScribbleView, CView)
	//{{AFX_MSG_MAP(CScribbleView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScribbleView construction/destruction

CScribbleView::CScribbleView()
{
	// TODO: add construction code here

}

CScribbleView::~CScribbleView()
{
}

BOOL CScribbleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CScribbleView drawing

void CScribbleView::OnDraw(CDC* pDC)
{
	CScribbleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
    CTypedPtrList<CObList, CStroke*>& strokeList = pDoc->m_strokeList; 
    POSITION pos = strokeList.GetHeadPosition(); 
    while(pos != NULL)
    {
        CStroke* pStroke = strokeList.GetNext(pos); 
        pStroke->DrawStroke(pDC); 
    }
}

void CScribbleView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pSender != this)
        Invalidate(); 	
}


/////////////////////////////////////////////////////////////////////////////
// CScribbleView printing

BOOL CScribbleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CView preparation
	return CView::OnPreparePrinting(pInfo);
}

void CScribbleView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CView begin printing.
	CView::OnBeginPrinting(pDC, pInfo);
}

void CScribbleView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CView end printing
	CView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CScribbleView diagnostics

#ifdef _DEBUG
void CScribbleView::AssertValid() const
{
	CView::AssertValid();
}

void CScribbleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CScribbleDoc* CScribbleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScribbleDoc)));
	return (CScribbleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScribbleView message handlers

void CScribbleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_pStrokeCur = GetDocument()->NewStroke(); 
    m_pStrokeCur->m_pointList.AddTail(point); 
    m_ptPrev = point; 
    SetCapture(); 

	CView::OnLButtonDown(nFlags, point);
}

void CScribbleView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(GetCapture() != this)
        return; 

    CScribbleDoc* pDoc = GetDocument(); 
    CClientDC dc(this); 
    CPen* pOldPen = dc.SelectObject(pDoc->GetCurrentPen()); 
    dc.MoveTo(m_ptPrev); 
    dc.LineTo(point); 
    m_ptPrev = point; 
    dc.SelectObject(pOldPen); 
    m_pStrokeCur->m_pointList.AddTail(point); 

	CView::OnMouseMove(nFlags, point);
}

void CScribbleView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(GetCapture() != this)
        return; 

    CScribbleDoc* pDoc = GetDocument(); 
    CClientDC dc(this); 
    CPen* pOldPen = dc.SelectObject(pDoc->GetCurrentPen()); 
    dc.MoveTo(m_ptPrev); 
    dc.LineTo(point); 
    m_ptPrev = point; 
    dc.SelectObject(pOldPen); 
    m_pStrokeCur->m_pointList.AddTail(point); 
    ReleaseCapture(); 

    pDoc->UpdateAllViews(this); 
	CView::OnLButtonUp(nFlags, point);
}