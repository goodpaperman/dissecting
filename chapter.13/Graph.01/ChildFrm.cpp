// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "Graph.h"

#include "ChildFrm.h"
#include "TextView.h"
#include "BarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
    //return m_wndSplitter.Create( this,
    //    2, 2,                 // TODO: adjust the number of rows, columns
    //    CSize( 10, 10 ),      // TODO: adjust the minimum pane size
    //    pContext );
    
    m_wndSplitter1.CreateStatic(this, 1, 2); 

    m_wndSplitter1.CreateView(0, 0, RUNTIME_CLASS(CTextView), CSize(300, 0), pContext); 

    m_wndSplitter2.CreateStatic(&m_wndSplitter1, 2, 1, WS_CHILD | WS_VISIBLE, m_wndSplitter1.IdFromRowCol(0, 1)); 

    m_wndSplitter2.CreateView(0, 0, RUNTIME_CLASS(CBarView), CSize(0, 150), pContext); 

    m_wndSplitter2.CreateView(1, 0, pContext->m_pNewViewClass, CSize(0, 0), pContext); 

    SetActiveView((CView*)m_wndSplitter1.GetPane(0, 0)); 
    return TRUE; 
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
