// BarView.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "BarView.h"
#include "GraphDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBarView

IMPLEMENT_DYNCREATE(CBarView, CView)

CBarView::CBarView()
{
}

CBarView::~CBarView()
{
}


BEGIN_MESSAGE_MAP(CBarView, CView)
	//{{AFX_MSG_MAP(CBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBarView drawing

void CBarView::OnDraw(CDC* pDC)
{
	CGraphDoc* pDoc = (CGraphDoc*)GetDocument();
	// TODO: add draw code here
    
    int cxBar, cxBarSpacing, cxGraph, cyGraph, x, y, i; 
    RECT rc; 

    CPen pen(PS_SOLID, 1, RGB(0, 255, 0)); 
    CBrush brush(RGB(0, 255, 0)); 
    CBrush* pOldBrush = pDC->SelectObject(&brush); 
    CPen* pOldPen = pDC->SelectObject(&pen); 

    cxGraph = 100; 
    cyGraph = DATAMAX; 

    GetClientRect(&rc); 
    pDC->SetMapMode(MM_ANISOTROPIC); 
    pDC->SetWindowOrg(0, 0); 
    pDC->SetViewportOrg(10, rc.bottom - 10); 
    pDC->SetWindowExt(cxGraph, cyGraph); 
    pDC->SetViewportExt(rc.right-20, -(rc.bottom - 20)); 

    cxBar = (3 * cxGraph) / (4 * DATANUM); 
    cxBarSpacing = cxBar / 3; 
    if(cxBar < 3)
        cxBar = 3; 

    pDC->MoveTo(0, 0); 
    pDC->LineTo(0, cyGraph); 
    pDC->MoveTo(0, 0); 
    pDC->LineTo(cxGraph, 0); 

    for(x=cxBarSpacing, y=0, i=0; i<DATANUM; i++, x+= cxBar + cxBarSpacing)
    {
        pDC->Rectangle(x, y, x+cxBar, y+pDoc->m_intArray[i]); 
    }

    pDC->SelectObject(pOldBrush); 
    pDC->SelectObject(pOldPen); 
}

BOOL CBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBarView diagnostics

#ifdef _DEBUG
void CBarView::AssertValid() const
{
	CView::AssertValid();
}

void CBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBarView message handlers
