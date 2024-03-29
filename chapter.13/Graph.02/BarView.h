#if !defined(AFX_BARVIEW_H__0DBA0B34_015D_41E1_BA83_EBA8A835803A__INCLUDED_)
#define AFX_BARVIEW_H__0DBA0B34_015D_41E1_BA83_EBA8A835803A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BarView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBarView view

class CBarView : public CView
{
protected:
	CBarView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBarView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CBarView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARVIEW_H__0DBA0B34_015D_41E1_BA83_EBA8A835803A__INCLUDED_)
