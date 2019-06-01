// Timer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Timer.h"
#include "TimerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerApp

BEGIN_MESSAGE_MAP(CTimerApp, CWinApp)
	//{{AFX_MSG_MAP(CTimerApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerApp construction

CTimerApp::CTimerApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTimerApp object

CTimerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTimerApp initialization

BOOL CTimerApp::InitInstance()
{
	// Standard initialization

	CTimerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
