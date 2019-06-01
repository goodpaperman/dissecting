// TextView.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "TextView.h"
#include "GraphDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

CTextView::CTextView()
{
}

CTextView::~CTextView()
{
}


BEGIN_MESSAGE_MAP(CTextView, CView)
	//{{AFX_MSG_MAP(CTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CGraphDoc* pDoc = (CGraphDoc*)GetDocument();
	// TODO: add draw code here

    TEXTMETRIC tm; 
    pDC->GetTextMetrics(&tm); 

    int x, y, cy, i; 
    char sz[20]; 
    cy = tm.tmHeight; 
    pDC->SetTextColor(RGB(0, 0, 255)); 
    for(x=5, y=5, i=0; i<DATANUM; i++, y+=cy)
    {
        wsprintf(sz, "%d", pDoc->m_intArray[i]); 
        pDC->TextOut(x, y, sz); 
    }
}

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers
