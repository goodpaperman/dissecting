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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
    m_penCur.CreatePen(PS_SOLID, m_nPenWidth, RGB(0, 0, 0)); 
}

CStroke* CScribbleDoc::NewStroke()
{
    CStroke* pStrokeItem = new CStroke(m_nPenWidth); 
    m_strokeList.AddTail(pStrokeItem); 
    SetModifiedFlag(); 
    return pStrokeItem; 
}
