#if !defined(AFX_TEXTVIEW_H__FD972717_D4DD_42BA_B51C_DE3C18E15B0A__INCLUDED_)
#define AFX_TEXTVIEW_H__FD972717_D4DD_42BA_B51C_DE3C18E15B0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextView view

class CTextView : public CView
{
protected:
	CTextView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTextView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTextView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTVIEW_H__FD972717_D4DD_42BA_B51C_DE3C18E15B0A__INCLUDED_)
