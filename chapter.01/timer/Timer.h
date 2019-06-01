// Timer.h : main header file for the TIMER application
//

#if !defined(AFX_TIMER_H__5A4A4CCC_2F48_44CE_9A52_5336E0757DA4__INCLUDED_)
#define AFX_TIMER_H__5A4A4CCC_2F48_44CE_9A52_5336E0757DA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimerApp:
// See Timer.cpp for the implementation of this class
//

class CTimerApp : public CWinApp
{
public:
	CTimerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimerApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMER_H__5A4A4CCC_2F48_44CE_9A52_5336E0757DA4__INCLUDED_)
