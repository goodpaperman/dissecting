// GraphView.cpp : implementation of the CGraphView class
//

#include "stdafx.h"
#include "Graph.h"

#include "GraphDoc.h"
#include "GraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphView

IMPLEMENT_DYNCREATE(CGraphView, CView)

BEGIN_MESSAGE_MAP(CGraphView, CView)
	//{{AFX_MSG_MAP(CGraphView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphView construction/destruction

CGraphView::CGraphView()
{
	// TODO: add construction code here

}

CGraphView::~CGraphView()
{
}

BOOL CGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView drawing

void CGraphView::OnDraw(CDC* pDC)
{
	CGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    int cxDot, cxDotSpacing, cyDot, cxGraph, cyGraph, x, y, i; 
    RECT rc; 

    CPen pen(PS_SOLID, 1, RGB(255, 0, 0)); 
    CBrush brush(RGB(255, 0, 0)); 
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

    cxDotSpacing = (2 * cxGraph) / (3 * DATANUM); 
    cxDot = cxDotSpacing / 2; 
    if(cxDot < 3)
        cxDot = 3; 
    cyDot = cxDot; 

    pDC->MoveTo(0, 0); 
    pDC->LineTo(0, cyGraph); 
    pDC->MoveTo(0, 0); 
    pDC->LineTo(cxGraph, 0); 

    //pDC->SelectObject(::GetStockObject(NULL_PEN)); 
    pDC->SelectStockObject(NULL_PEN); 
    for(x=cxDotSpacing, y=0, i=0; i<DATANUM; i++, x+= cxDot + cxDotSpacing)
    {
        pDC->Rectangle(x, y+pDoc->m_intArray[i], x+cxDot, y+pDoc->m_intArray[i]-cyDot); 
    }

    pDC->SelectObject(pOldBrush); 
    pDC->SelectObject(pOldPen); 
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView printing

BOOL CGraphView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView diagnostics

#ifdef _DEBUG
void CGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphDoc* CGraphView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphDoc)));
	return (CGraphDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphView message handlers
