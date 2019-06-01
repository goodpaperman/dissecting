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

IMPLEMENT_DYNCREATE(CScribbleView, CEditView)

BEGIN_MESSAGE_MAP(CScribbleView, CEditView)
	//{{AFX_MSG_MAP(CScribbleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
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

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
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
}

/////////////////////////////////////////////////////////////////////////////
// CScribbleView printing

BOOL CScribbleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CScribbleView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CScribbleView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CScribbleView diagnostics

#ifdef _DEBUG
void CScribbleView::AssertValid() const
{
	CEditView::AssertValid();
}

void CScribbleView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CScribbleDoc* CScribbleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScribbleDoc)));
	return (CScribbleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScribbleView message handlers
