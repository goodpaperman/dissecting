// TraceItDoc.cpp : implementation of the CTraceItDoc class
//

#include "stdafx.h"
#include "TraceIt.h"

#include "TraceItDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTraceItDoc

IMPLEMENT_DYNCREATE(CTraceItDoc, CDocument)

BEGIN_MESSAGE_MAP(CTraceItDoc, CDocument)
	//{{AFX_MSG_MAP(CTraceItDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTraceItDoc construction/destruction

CTraceItDoc::CTraceItDoc()
{
	// TODO: add one-time construction code here

}

CTraceItDoc::~CTraceItDoc()
{
}

BOOL CTraceItDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTraceItDoc serialization

void CTraceItDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTraceItDoc diagnostics

#ifdef _DEBUG
void CTraceItDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTraceItDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTraceItDoc commands
