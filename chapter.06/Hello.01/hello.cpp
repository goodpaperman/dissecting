#include "stdafx.h"
#include "hello.h"
#include "resource.h"

CMyWinApp theApp; 
//CWinApp theApp; 

BOOL CMyWinApp::InitInstance()
{
    m_pMainWnd = new CMyFrameWnd(); 
    m_pMainWnd->ShowWindow(m_nCmdShow); 
    m_pMainWnd->UpdateWindow(); 
    return TRUE; 
}

CMyFrameWnd::CMyFrameWnd()
{
    Create(NULL, "Hello MFC", WS_OVERLAPPEDWINDOW, rectDefault, NULL, "MainMenu"); 
}

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
    ON_COMMAND(IDM_ABOUT, OnAbout)
    ON_WM_PAINT()
END_MESSAGE_MAP()

void CMyFrameWnd::OnPaint()
{
    CPaintDC dc(this); 
    CRect rect; 
    GetClientRect(&rect); 
    dc.SetTextAlign(TA_BOTTOM | TA_CENTER); 
    ::LineDDA(rect.right/2, 0, rect.right/2, rect.bottom/2, 
        (LINEDDAPROC)LineDDACallback, (LPARAM)(LPVOID)&dc); 

    enumIt(dc); 
}

void CMyFrameWnd::enumIt(CDC& dc)
{
    dc.EnumObjects(OBJ_BRUSH, EnumObjectsProc, NULL); 
}

int CALLBACK CMyFrameWnd::EnumObjectsProc(LPVOID lpLogObject, LPARAM lParam)
{
    //TRACE("%s.\n", lpLogObject); 
    LOGBRUSH* pBrush = (LOGBRUSH*)lpLogObject; 
    CString str; 
    str.Format("style = [%d], color = [%d], hatch = [%d].", pBrush->lbStyle, pBrush->lbColor, pBrush->lbHatch); 
    return AfxMessageBox(str, MB_YESNO) == IDYES; 
}

void CALLBACK CMyFrameWnd::LineDDACallback(int x, int y, LPARAM lpdc)
{
    static char szText[] = "Hello, MFC"; 
    ((CDC*)lpdc)->TextOut(x, y, szText, sizeof(szText)-1); 
    Sleep(1); 
    //for(int i=0; i<500000000; i++)
    //    ; 
}

void CMyFrameWnd::OnAbout()
{
    CDialog about("AboutBox", this); 
    about.DoModal(); 
}