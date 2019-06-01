// TextDoc.h : interface of the CTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTDOC_H__00E6B0F1_67BB_43DD_A0CF_2D81A09048AA__INCLUDED_)
#define AFX_TEXTDOC_H__00E6B0F1_67BB_43DD_A0CF_2D81A09048AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTextDoc : public CDocument
{
protected: // create from serialization only
	CTextDoc();
	DECLARE_DYNCREATE(CTextDoc)

// Attributes
public:
    CStringArray m_strArray; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTDOC_H__00E6B0F1_67BB_43DD_A0CF_2D81A09048AA__INCLUDED_)
