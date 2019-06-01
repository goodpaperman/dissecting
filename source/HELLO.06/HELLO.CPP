//--------------------------------------------------------------------
//                MFC 4.0  Hello sample program
//        Copyright (c) 1996   Top Studio * J.J.Hou
//
// �ɦW      : hello.cpp
// �@��      : �J�T��
// �sĶ�p��  : �аѦ� hello.mak
//
// ���ҥܽd��²�椧 MFC ���ε{���A���t Document/View �[�c�C�{���C����
// WM_PAINT �Y�Q�� GDI �禡 LineDDA() �� "Hello, MFC" �r��q�Ѧӭ��C
//--------------------------------------------------------------------
#include "Stdafx.h"
#include "Hello.h"
#include "Resource.h"

CMyWinApp theApp;   // application object

//--------------------------------------------------------------------
// CMyWinApp's member
//--------------------------------------------------------------------
BOOL CMyWinApp::InitInstance()
{
   m_pMainWnd = new CMyFrameWnd();
   m_pMainWnd->ShowWindow(m_nCmdShow);
   m_pMainWnd->UpdateWindow();
   return TRUE;
}
//--------------------------------------------------------------------
// CMyWinApp's member
//--------------------------------------------------------------------
BOOL CMyWinApp::OnIdle(LONG lCount)
{
   CMyFrameWnd* pWnd = (CMyFrameWnd*)m_pMainWnd;
   pWnd->IdleTimeHandler(lCount);

   return TRUE;
}
//--------------------------------------------------------------------
// CMyFrameWnd's member
//--------------------------------------------------------------------
CMyFrameWnd::CMyFrameWnd()
{
   Create(NULL, "Hello MFC", WS_OVERLAPPEDWINDOW, rectDefault,
          NULL, "MainMenu");     // "MainMenu" �w�q�� RC ��
}
//--------------------------------------------------------------------
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
   ON_COMMAND(IDM_ABOUT, OnAbout)
   ON_WM_PAINT()
END_MESSAGE_MAP()
//--------------------------------------------------------------------
void CMyFrameWnd::OnPaint()
{
CPaintDC dc(this);
CRect rect;

   GetClientRect(rect);

   dc.SetTextAlign(TA_BOTTOM | TA_CENTER);

   ::LineDDA(rect.right/2, 0, rect.right/2, rect.bottom/2,
       (LINEDDAPROC) LineDDACallback, (LPARAM) (LPVOID) &dc);
}
//--------------------------------------------------------------------
VOID CALLBACK CMyFrameWnd::LineDDACallback(int x, int y, LPARAM lpdc)
{
static char szText[] = "Hello, MFC";

   ((CDC*)lpdc)->TextOut(x, y, szText, sizeof(szText)-1);
   for(int i=1; i<50000; i++);  // �º�O���F����U���t�סA�H�Q�[��
}
//--------------------------------------------------------------------
void CMyFrameWnd::OnAbout()
{
   CDialog about("AboutBox", this);  // "AboutBox" �w�q�� RC ��
   about.DoModal();
}
//--------------------------------------------------------------------
void CMyFrameWnd::IdleTimeHandler(LONG lCount)
{
  CString str;
  CRect rect(10,10,200,30);
  CDC* pDC = new CClientDC(this);

  str.Format("%010d", lCount);
  pDC->DrawText(str, &rect, DT_LEFT | DT_TOP);
}
//--------------------------------------------------------------------
