// helloapp.cpp : Minimal MFC Windows app.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
#include <afxwin.h>

class CHelloAppAndFrame : public CFrameWnd, public CWinApp
{ 
public:
    CHelloAppAndFrame()
        { }

    // Necessary evil for MI disambiguity
    void* operator new(size_t nSize)
        { return CFrameWnd::operator new(nSize); }
    void operator delete(void* p)
        { CFrameWnd::operator delete(p); }

// Implementation
    // CWinApp overrides
    virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
    // CFrameWnd overrides
    virtual void PostNcDestroy();
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()

};

BEGIN_MESSAGE_MAP(CHelloAppAndFrame, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

// since the frame window is not allocated on the heap, we must
// override PostNCDestroy not to delete the frame object
void CHelloAppAndFrame::PostNcDestroy()
{
    // do nothing (do not call base class)
}

void CHelloAppAndFrame::OnPaint()
{
    CPaintDC dc(this);
    CRect rect;
    GetClientRect(rect);

    CString s = "Hello, Windows!";
    dc.SetTextAlign(TA_BASELINE | TA_CENTER);
    dc.SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
    dc.SetBkMode(TRANSPARENT);
    dc.TextOut(rect.right / 2, rect.bottom / 2, s);
}

// Application initialization
BOOL CHelloAppAndFrame::InitInstance()
{
    // first create the main frame
    if (!CFrameWnd::Create(NULL, "Multiple Inheritance Sample",
        WS_OVERLAPPEDWINDOW, rectDefault))
        return FALSE;

    // the application object is also a frame window
    m_pMainWnd = this;          
    ShowWindow(m_nCmdShow);
    return TRUE;
}

BOOL CHelloAppAndFrame::PreTranslateMessage(MSG* pMsg)
{
    return FALSE; 
}

CHelloAppAndFrame theHelloAppAndFrame;
