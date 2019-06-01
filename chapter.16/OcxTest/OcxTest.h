// OcxTest.h : main header file for the OCXTEST application
//

#if !defined(AFX_OCXTEST_H__49C76E22_5AD9_49B7_AA82_F481E31159B8__INCLUDED_)
#define AFX_OCXTEST_H__49C76E22_5AD9_49B7_AA82_F481E31159B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COcxTestApp:
// See OcxTest.cpp for the implementation of this class
//

class COcxTestApp : public CWinApp
{
public:
	COcxTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COcxTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXTEST_H__49C76E22_5AD9_49B7_AA82_F481E31159B8__INCLUDED_)
