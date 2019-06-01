// TextDoc.cpp : implementation of the CTextDoc class
//

#include "stdafx.h"
#include "Text.h"

#include "TextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextDoc

IMPLEMENT_DYNCREATE(CTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextDoc, CDocument)
	//{{AFX_MSG_MAP(CTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextDoc construction/destruction

CTextDoc::CTextDoc()
{
	// TODO: add one-time construction code here

}

CTextDoc::~CTextDoc()
{
}

BOOL CTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    
    m_strArray.SetSize(10); 
    m_strArray[0] = "If you love me let me know, "; 
    m_strArray[1] = "if you don't then let me go, "; 
    m_strArray[2] = "I can take another minute   "; 
    m_strArray[3] = "  of day without you in it. "; 
    m_strArray[4] = "                            "; 
    m_strArray[5] = "If you love me le it be, "; 
    m_strArray[6] = "if you don't then set me free"; 
    m_strArray[7] = "...                         "; 
    m_strArray[8] = "SORRY, I FORGET IT!         "; 
    m_strArray[9] = "     J.J.Hou 1995.03.22 19:26"; 
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTextDoc serialization

void CTextDoc::Serialize(CArchive& ar)
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
// CTextDoc diagnostics

#ifdef _DEBUG
void CTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextDoc commands
