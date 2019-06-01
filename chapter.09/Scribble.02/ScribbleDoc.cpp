// ScribbleDoc.cpp : implementation of the CScribbleDoc class
//

#include "stdafx.h"
#include "Scribble.h"

#include "ScribbleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScribbleDoc

IMPLEMENT_DYNCREATE(CScribbleDoc, CDocument)

BEGIN_MESSAGE_MAP(CScribbleDoc, CDocument)
	//{{AFX_MSG_MAP(CScribbleDoc)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, OnEditClearAll)
	ON_COMMAND(ID_PEN_THICK_OR_THIN, OnPenThickOrThin)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR_ALL, OnUpdateEditClearAll)
	ON_UPDATE_COMMAND_UI(ID_PEN_THICK_OR_THIN, OnUpdatePenThickOrThin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScribbleDoc construction/destruction

CScribbleDoc::CScribbleDoc()
{
	// TODO: add one-time construction code here

}

CScribbleDoc::~CScribbleDoc()
{
}

BOOL CScribbleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    InitDocument(); 
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CScribbleDoc serialization

void CScribbleDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	//((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
    if(ar.IsStoring())
    {
    }
    else 
    {
    }
    m_strokeList.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CScribbleDoc diagnostics

#ifdef _DEBUG
void CScribbleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScribbleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScribbleDoc commands

BOOL CScribbleDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	InitDocument(); 
	return TRUE;
}

void CScribbleDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	while(!m_strokeList.IsEmpty())
        delete m_strokeList.RemoveHead(); 

	CDocument::DeleteContents();
}

void CScribbleDoc::InitDocument()
{
    m_nPenWidth = 2; 
    m_bThickPen = FALSE; 
    m_nThinWidth = 2; 
    m_nThickWidth = 5; 
    ReplacePen(); 
}

CStroke* CScribbleDoc::NewStroke()
{
    CStroke* pStrokeItem = new CStroke(m_nPenWidth); 
    m_strokeList.AddTail(pStrokeItem); 
    SetModifiedFlag(); 
    return pStrokeItem; 
}

void CScribbleDoc::OnEditClearAll() 
{
	// TODO: Add your command handler code here
    DeleteContents(); 
    SetModifiedFlag(); 
    UpdateAllViews(NULL); 	
}

void CScribbleDoc::OnPenThickOrThin() 
{
	// TODO: Add your command handler code here
    m_bThickPen = !m_bThickPen; 
    ReplacePen(); 
}

void CScribbleDoc::ReplacePen()
{
    m_nPenWidth = m_bThickPen ? m_nThickWidth : m_nThinWidth; 
    m_penCur.DeleteObject(); 
    m_penCur.CreatePen(PS_SOLID, m_nPenWidth, RGB(0, 0, 0)); 
}

void CScribbleDoc::OnUpdateEditClearAll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_strokeList.IsEmpty()); 
}

void CScribbleDoc::OnUpdatePenThickOrThin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bThickPen); 
}
