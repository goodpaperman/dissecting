// TraceItDoc.h : interface of the CTraceItDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACEITDOC_H__817BFB49_1EB8_4EDA_A394_1F0AAEBFE87B__INCLUDED_)
#define AFX_TRACEITDOC_H__817BFB49_1EB8_4EDA_A394_1F0AAEBFE87B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTraceItDoc : public CDocument
{
protected: // create from serialization only
	CTraceItDoc();
	DECLARE_DYNCREATE(CTraceItDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraceItDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTraceItDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTraceItDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACEITDOC_H__817BFB49_1EB8_4EDA_A394_1F0AAEBFE87B__INCLUDED_)
