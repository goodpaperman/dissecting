#if !defined(AFX_CSTM1DLG_H__FB6B726B_5536_4749_9673_FE6D317F90C2__INCLUDED_)
#define AFX_CSTM1DLG_H__FB6B726B_5536_4749_9673_FE6D317F90C2__INCLUDED_

// cstm1dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustom1Dlg dialog

class CCustom1Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom1Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom1Dlg)
	enum { IDD = IDD_CUSTOM1 };
	CString	m_szAuthor;
	CString	m_szComment;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom1Dlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM1DLG_H__FB6B726B_5536_4749_9673_FE6D317F90C2__INCLUDED_)
