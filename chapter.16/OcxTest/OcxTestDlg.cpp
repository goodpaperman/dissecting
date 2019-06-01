// OcxTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OcxTest.h"
#include "OcxTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// COcxTestDlg dialog

COcxTestDlg::COcxTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COcxTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COcxTestDlg)
	m_cellValue = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COcxTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COcxTestDlg)
	DDX_Control(pDX, IDC_GRID, m_OcxGrid);
	DDX_Text(pDX, IDC_VALUE, m_cellValue);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COcxTestDlg, CDialog)
	//{{AFX_MSG_MAP(COcxTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_UPDATEVALUE, OnUpdatevalue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COcxTestDlg message handlers

BOOL COcxTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    CString str; 
    int i, j; 
    CRect rect; 
    srand(time(NULL)); 

    VERIFY(m_OcxGrid.GetCols() == (long)MAXCOL); 
    VERIFY(m_OcxGrid.GetRows() == (long)MAXROW); 

    m_OcxGrid.SetRow(0); 
    for(i =0; i<MAXCOL; i++)
    {
        if(i > 0)
        {
            m_OcxGrid.SetCol(i); 
            if(i == MAXCOL - 1)
                m_OcxGrid.SetText(CString("Total")); 
            else 
                m_OcxGrid.SetText(CString('A' + i - 1)); 
        }
    }

    m_OcxGrid.SetCol(0); 
    for(j=0; j<MAXROW; j++)
    {
        if(j>0)
        {
            m_OcxGrid.SetRow(j); 
            if(j == MAXROW - 1)
                m_OcxGrid.SetText(CString("Total")); 
            else 
            {
                str.Format("%d", j);
                m_OcxGrid.SetText(str); 
            }
        }
    }

    for(i = 1; i<MAXCOL-1; i++)
    {
        m_OcxGrid.SetCol(i); 
        for(j=1; j<MAXROW-1; j++)
        {
            m_OcxGrid.SetRow(j); 
            str.Format("%d", rand()%100); 
            m_OcxGrid.SetText(str); 
        }
    }

    ComputeSums(); 

    m_OcxGrid.SetCol(1); 
    m_OcxGrid.SetRow(1); 
    m_cellValue = m_OcxGrid.GetText(); 
    UpdateData(FALSE);	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COcxTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COcxTestDlg::OnPaint() 
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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COcxTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(COcxTestDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(COcxTestDlg)
	ON_EVENT(COcxTestDlg, IDC_GRID, 69 /* SelChange */, OnSelChangeGrid, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void COcxTestDlg::OnSelChangeGrid() 
{
	// TODO: Add your control notification handler code here
	if(m_OcxGrid)
    {
        m_cellValue = m_OcxGrid.GetText(); 
        UpdateData(FALSE); 
        GotoDlgCtrl(GetDlgItem(IDC_VALUE)); 
    }
}

void COcxTestDlg::OnUpdatevalue() 
{
	// TODO: Add your control notification handler code here
	CString str; 
    int value; 
    int Row, Col; 

    UpdateData(TRUE);
    value = atoi(m_cellValue); 
    str.Format("%d", value); 

    Col = m_OcxGrid.GetCol(); 
    Row = m_OcxGrid.GetRow(); 

    m_OcxGrid.SetText(str); 
    ComputeSums(); 

    m_OcxGrid.SetCol(Col); 
    m_OcxGrid.SetRow(Row); 
}

void COcxTestDlg::ComputeSums()
{
    int i, j, nRows, nCols, sum; 
    CString str; 

    nCols = (int)m_OcxGrid.GetCols(); 
    for(j=1; j<MAXROW-1; j++)
    {
        m_OcxGrid.SetRow(j); 
        sum = 0; 
        for(i=1; i<nCols-1; i++)
        {
            m_OcxGrid.SetCol(i); 
            sum += atoi(m_OcxGrid.GetText()); 
        }

        str.Format("%d", sum); 
        m_OcxGrid.SetCol(nCols - 1); 
        m_OcxGrid.SetText(str); 
    }

    nRows = (int)m_OcxGrid.GetRows(); 
    for(i = 1; i<MAXCOL; i++)
    {
        m_OcxGrid.SetCol(i); 
        sum = 0; 
        for(j=1; j<nRows-1; j++)
        {
            m_OcxGrid.SetRow(j); 
            sum += atoi(m_OcxGrid.GetText()); 
        }

        str.Format("%d", sum); 
        m_OcxGrid.SetRow(nRows - 1); 
        m_OcxGrid.SetText(str); 
    }
}