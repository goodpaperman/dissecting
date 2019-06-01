// Scribble.h : main header file for the SCRIBBLE application
//

#if !defined(AFX_SCRIBBLE_H__160F5DC3_522D_4249_B38F_B9FB1CF7915A__INCLUDED_)
#define AFX_SCRIBBLE_H__160F5DC3_522D_4249_B38F_B9FB1CF7915A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CScribbleApp:
// See Scribble.cpp for the implementation of this class
//

class CScribbleApp : public CWinApp
{
public:
	CScribbleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScribbleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CScribbleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIBBLE_H__160F5DC3_522D_4249_B38F_B9FB1CF7915A__INCLUDED_)
