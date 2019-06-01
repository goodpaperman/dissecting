// ScribbleDoc.h : interface of the CScribbleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCRIBBLEDOC_H__97901BD3_FFD8_4165_B66B_E16E0C461554__INCLUDED_)
#define AFX_SCRIBBLEDOC_H__97901BD3_FFD8_4165_B66B_E16E0C461554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stroke.h"

//class CStroke; 
class CScribbleDoc : public CDocument
{
protected: // create from serialization only
	CScribbleDoc();
	DECLARE_DYNCREATE(CScribbleDoc)

// Attributes
protected:
    BOOL m_bThickPen; 
    UINT m_nThinWidth; 
    UINT m_nThickWidth; 
    UINT m_nPenWidth; 
    CPen m_penCur; 

protected:
    void ReplacePen(); 

public:
    CTypedPtrList<CObList, CStroke*> m_strokeList; 
    CPen* GetCurrentPen() { return &m_penCur; }

// Operations
public:
    CStroke* NewStroke(); 

protected:
    void InitDocument(); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScribbleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScribbleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScribbleDoc)
	afx_msg void OnEditClearAll();
	afx_msg void OnPenThickOrThin();
	afx_msg void OnUpdateEditClearAll(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePenThickOrThin(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//#include "stroke.h"

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIBBLEDOC_H__97901BD3_FFD8_4165_B66B_E16E0C461554__INCLUDED_)
