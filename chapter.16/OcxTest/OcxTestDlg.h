// OcxTestDlg.h : header file
//
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_OCXTESTDLG_H__824E7734_D792_4D58_BF33_344C44315CCB__INCLUDED_)
#define AFX_OCXTESTDLG_H__824E7734_D792_4D58_BF33_344C44315CCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAXCOL 7
#define MAXROW 14

/////////////////////////////////////////////////////////////////////////////
// COcxTestDlg dialog

class COcxTestDlg : public CDialog
{
// Construction
public:
	COcxTestDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(COcxTestDlg)
	enum { IDD = IDD_OCXTEST_DIALOG };
	CMSFlexGrid	m_OcxGrid;
	CString	m_cellValue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

private:
    void ComputeSums(); 

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COcxTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelChangeGrid();
	afx_msg void OnUpdatevalue();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXTESTDLG_H__824E7734_D792_4D58_BF33_344C44315CCB__INCLUDED_)
