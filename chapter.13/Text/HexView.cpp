// HexView.cpp : implementation file
//

#include "stdafx.h"
#include "Text.h"
#include "HexView.h"
#include "TextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHexView

IMPLEMENT_DYNCREATE(CHexView, CView)

CHexView::CHexView()
{
}

CHexView::~CHexView()
{
}


BEGIN_MESSAGE_MAP(CHexView, CView)
	//{{AFX_MSG_MAP(CHexView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHexView drawing

void CHexView::OnDraw(CDC* pDC)
{
	CTextDoc* pDoc = (CTextDoc*)GetDocument();
	// TODO: add draw code here

    int i, j, k, l, nHeight; 
    long n; 
    char temp[10]; 
    CString Line; 
    TEXTMETRIC tm; 
    pDC->GetTextMetrics(&tm); 
    nHeight = tm.tmHeight + tm.tmExternalLeading; 
    j = pDoc->m_strArray.GetSize(); 
    for(i =0; i<j; i++)
    {
        wsprintf(temp, "%02x     ", i); 
        Line = temp; 
        l = pDoc->m_strArray[i].GetLength(); 
        for(k=0; k<l; k++)
        {
            n = pDoc->m_strArray[i][k] & 0x00FF; 
            wsprintf(temp, "%02lx", n); 
            Line += temp; 
        }

        pDC->TextOut(10, i * nHeight, Line); 
    }
}

BOOL CHexView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHexView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHexView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


/////////////////////////////////////////////////////////////////////////////
// CHexView diagnostics

#ifdef _DEBUG
void CHexView::AssertValid() const
{
	CView::AssertValid();
}

void CHexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHexView message handlers
