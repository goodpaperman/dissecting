// TraceIt.h : main header file for the TRACEIT application
//

#if !defined(AFX_TRACEIT_H__493E908B_A8BC_4614_9210_93C45DAB55E8__INCLUDED_)
#define AFX_TRACEIT_H__493E908B_A8BC_4614_9210_93C45DAB55E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTraceItApp:
// See TraceIt.cpp for the implementation of this class
//

class CTraceItApp : public CWinApp
{
public:
	CTraceItApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraceItApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTraceItApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACEIT_H__493E908B_A8BC_4614_9210_93C45DAB55E8__INCLUDED_)
