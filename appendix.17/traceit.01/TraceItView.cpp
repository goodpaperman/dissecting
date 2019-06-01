// TraceItView.cpp : implementation of the CTraceItView class
//

#include "stdafx.h"
#include "TraceIt.h"

#include "TraceItDoc.h"
#include "TraceItView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTraceItView

IMPLEMENT_DYNCREATE(CTraceItView, CView)

BEGIN_MESSAGE_MAP(CTraceItView, CView)
	//{{AFX_MSG_MAP(CTraceItView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTraceItView construction/destruction

CTraceItView::CTraceItView()
{
	// TODO: add construction code here

}

CTraceItView::~CTraceItView()
{
}

BOOL CTraceItView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTraceItView drawing

void CTraceItView::OnDraw(CDC* pDC)
{
	CTraceItDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTraceItView printing

BOOL CTraceItView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTraceItView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTraceItView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTraceItView diagnostics

#ifdef _DEBUG
void CTraceItView::AssertValid() const
{
	CView::AssertValid();
}

void CTraceItView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTraceItDoc* CTraceItView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTraceItDoc)));
	return (CTraceItDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTraceItView message handlers
