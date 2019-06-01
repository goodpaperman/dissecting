// Mltithrd.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Mltithrd.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMltithrdApp

BEGIN_MESSAGE_MAP(CMltithrdApp, CWinApp)
	//{{AFX_MSG_MAP(CMltithrdApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMltithrdApp construction

CMltithrdApp::CMltithrdApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMltithrdApp object

CMltithrdApp theApp;

CWinThread* _pThread[5]; 
DWORD _ThreadArg[5] = {
    HIGHEST_THREAD,    // 0x00
    ABOVE_AVE_THREAD,  // 0x3F
    NORMAL_THREAD,     // 0x7F
    BELOW_AVE_THREAD,  // 0xBF
    LOWEST_THREAD      // 0xFF
    }; 

/////////////////////////////////////////////////////////////////////////////
// CMltithrdApp initialization

BOOL CMltithrdApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object.

	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	// create and load the frame with its resources

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

    for(int i=0; i<5; i++)
    {
        _pThread[i] = AfxBeginThread(CChildView::ThreadProc, 
            &_ThreadArg[i], 
            THREAD_PRIORITY_NORMAL, 
            0, 
            CREATE_SUSPENDED, 
            NULL); 
    }

    _pThread[0]->SetThreadPriority(THREAD_PRIORITY_HIGHEST); 
    _pThread[1]->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL); 
    _pThread[2]->SetThreadPriority(THREAD_PRIORITY_NORMAL); 
    _pThread[3]->SetThreadPriority(THREAD_PRIORITY_BELOW_NORMAL); 
    _pThread[4]->SetThreadPriority(THREAD_PRIORITY_LOWEST); 

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMltithrdApp message handlers





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMltithrdApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMltithrdApp message handlers

