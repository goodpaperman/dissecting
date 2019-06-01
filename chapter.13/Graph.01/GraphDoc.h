// GraphDoc.h : interface of the CGraphDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHDOC_H__33EDD49F_B1CD_487E_8AC9_E88FB8D2C16E__INCLUDED_)
#define AFX_GRAPHDOC_H__33EDD49F_B1CD_487E_8AC9_E88FB8D2C16E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraphDoc : public CDocument
{
protected: // create from serialization only
	CGraphDoc();
	DECLARE_DYNCREATE(CGraphDoc)

// Attributes
public:
    CArray<int, int> m_intArray; 

// Operations
public:
    void SetValue(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGraphDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphDoc)
	afx_msg void OnGraphData1();
	afx_msg void OnUpdateGraphData1(CCmdUI* pCmdUI);
	afx_msg void OnGraphData2();
	afx_msg void OnUpdateGraphData2(CCmdUI* pCmdUI);
	afx_msg void OnGraphData3();
	afx_msg void OnUpdateGraphData3(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHDOC_H__33EDD49F_B1CD_487E_8AC9_E88FB8D2C16E__INCLUDED_)
