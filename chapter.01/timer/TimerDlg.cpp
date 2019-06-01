// TimerDlg.cpp : implementation file
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
// CTimerDlg dialog

CTimerDlg::CTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimerDlg, CDialog)
	//{{AFX_MSG_MAP(CTimerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg message handlers

BOOL CTimerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    DWORD ThreadID; 
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadTime, m_hWnd, 0, &ThreadID); 
    if(hThread)
        CloseHandle(hThread); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTimerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CTimerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

VOID ReadTime(HWND hDlg)
{
    char str[50]; 
    SYSTEMTIME st; 
    
    while(1)
    {
        GetSystemTime(&st); 
        sprintf(str, "%u:%u:%u", st.wHour, st.wMinute, st.wSecond); 
        SetDlgItemText(hDlg, IDC_TIMER, str); 
        Sleep(1000); 
    }
}