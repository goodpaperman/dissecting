// Text.h : main header file for the TEXT application
//

#if !defined(AFX_TEXT_H__AB0D1845_52E1_4881_AF72_99FBF8AE051A__INCLUDED_)
#define AFX_TEXT_H__AB0D1845_52E1_4881_AF72_99FBF8AE051A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextApp:
// See Text.cpp for the implementation of this class
//

class CTextApp : public CWinApp
{
public:
	CTextApp();

    CMultiDocTemplate* m_pTemplateTxt; 
    CMultiDocTemplate* m_pTemplateHex; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXT_H__AB0D1845_52E1_4881_AF72_99FBF8AE051A__INCLUDED_)
