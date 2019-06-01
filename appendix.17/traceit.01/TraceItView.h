// TraceItView.h : interface of the CTraceItView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACEITVIEW_H__A4E44F57_B515_45D3_B575_3DC2962D1DD2__INCLUDED_)
#define AFX_TRACEITVIEW_H__A4E44F57_B515_45D3_B575_3DC2962D1DD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTraceItView : public CView
{
protected: // create from serialization only
	CTraceItView();
	DECLARE_DYNCREATE(CTraceItView)

// Attributes
public:
	CTraceItDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraceItView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTraceItView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTraceItView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TraceItView.cpp
inline CTraceItDoc* CTraceItView::GetDocument()
   { return (CTraceItDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACEITVIEW_H__A4E44F57_B515_45D3_B575_3DC2962D1DD2__INCLUDED_)
