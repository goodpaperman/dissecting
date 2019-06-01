#if !defined(AFX_NEWDOC_H__DD4FA158_6BEC_4591_980A_47E04D76581C__INCLUDED_)
#define AFX_NEWDOC_H__DD4FA158_6BEC_4591_980A_47E04D76581C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewDoc document

class CNewDoc : public CDocument
{
protected:
	CNewDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CNewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CNewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWDOC_H__DD4FA158_6BEC_4591_980A_47E04D76581C__INCLUDED_)
