#include "my.h"

extern CMyWinApp theApp; 

CRuntimeClass* CRuntimeClass::pFirstClass = NULL; 

AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNewClass)
{
    pNewClass->m_pNextClass = CRuntimeClass::pFirstClass; 
    CRuntimeClass::pFirstClass = pNewClass; 
}

static char _lpszCObject[] = "CObject"; 
struct CRuntimeClass CObject::classCObject = 
{
    _lpszCObject, sizeof(CObject), 0xFFFF, NULL, NULL, NULL
}; 

static AFX_CLASSINIT _init_CObject(RUNTIME_CLASS(CObject)); 
CRuntimeClass* CObject::GetRuntimeClass() const
{
    return RUNTIME_CLASS(CObject); 
}

IMPLEMENT_DYNAMIC(CCmdTarget, CObject)
IMPLEMENT_DYNAMIC(CWinThread, CCmdTarget)
IMPLEMENT_DYNAMIC(CWinApp, CWinThread)
IMPLEMENT_DYNAMIC(CDocument, CCmdTarget)
//IMPLEMENT_DYNAMIC(CWnd, CCmdTarget)
//IMPLEMENT_DYNAMIC(CFrameWnd, CWnd)
IMPLEMENT_DYNCREATE(CWnd, CCmdTarget)
IMPLEMENT_DYNCREATE(CFrameWnd, CWnd)
IMPLEMENT_DYNAMIC(CView, CWnd)

BOOL CObject::IsKindOf(const CRuntimeClass* pClass) const
{
    for(CRuntimeClass* pThis = GetRuntimeClass(); pThis != NULL; pThis = pThis->m_pBaseClass)
    {
        if(pThis == pClass)
            return TRUE; 
    }

    return FALSE; 
}

AFX_MSGMAP CCmdTarget::messageMap = 
{
    NULL, 
    &CCmdTarget::_messageEntries[0]
}; 

AFX_MSGMAP_ENTRY CCmdTarget::_messageEntries[] = 
{
    //{0, 0, 1, 1, AfxSig_vv, 0}, 
    {0, 0, 0, 0, AfxSig_end, 0}
}; 

AFX_MSGMAP* CCmdTarget::GetMessageMap() const
{
    return &messageMap; 
}

BEGIN_MESSAGE_MAP(CWinApp, CCmdTarget)
    ON_COMMAND(CWinAppid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CDocument, CCmdTarget)
    ON_COMMAND(CDocumentid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CWnd, CCmdTarget)
    ON_COMMAND(CWndid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CFrameWnd, CWnd)
    ON_COMMAND(CFrameWndid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CView, CWnd)
    ON_COMMAND(CViewid, 0)
    //ON_COMMAND(CViewid, 0)
END_MESSAGE_MAP()

BOOL CCmdTarget::OnCmdMsg(UINT nID, int nCode)
{
    cout << "CCmdTarget::OnCmdMsg()" << endl; 
    MsgMapPrinting(this);
    return FALSE;
}

BOOL CDocument::OnCmdMsg(UINT nID, int nCode)
{
    cout << "CDocument::OnCmdMsg()" << endl; 
    return CCmdTarget::OnCmdMsg(nID, nCode); 
}

BOOL CWnd::Create()
{
    return TRUE; 
}

BOOL CWnd::CreateEx()
{
    PreCreateWindow();
    return TRUE; 
}

BOOL CWnd::PreCreateWindow()
{
    return TRUE; 
}

LRESULT CWnd::WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
{
    cout << "CWnd::WindowProc()" << endl; 
    if(nMsg == WM_COMMAND)
    {
        if(OnCommand(wParam, lParam))
            return 1L; 
        else 
            return (LRESULT)DefWindowProc(nMsg, wParam, lParam); 
    }
    else 
    {
        MsgMapPrinting(this); 
        //AFX_MSGMAP* pMessageMap = GetMessageMap(); 
        //for(; pMessageMap != NULL; pMessageMap = pMessageMap->pBaseMessageMap)
        //{
        //}
    }
    return 0; 
}

BOOL CWnd::OnCommand(WPARAM wParam, LPARAM lParam)
{
    cout << "CWnd::OnCommand()" << endl; 
    return OnCmdMsg(0, 0); 
}

LRESULT CWnd::DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
{
    cout << "CWnd::DefWindowProc()" << endl; 
    return 1L; 
}

BOOL CFrameWnd::Create()
{
    CreateEx(); 
    return TRUE; 
}

BOOL CFrameWnd::PreCreateWindow()
{
    return TRUE; 
}

CView* CFrameWnd::GetActiveView() const
{
    return m_pViewActive; 
}

BOOL CFrameWnd::OnCommand(WPARAM wParam, LPARAM lParam)
{
    cout << "CFrameWnd::OnCommand()" << endl; 
    return CWnd::OnCommand(wParam, lParam); 
}

BOOL CFrameWnd:: OnCmdMsg(UINT nID, int nCode)
{
    cout << "CFrameWnd::OnCmdMsg()" << endl; 
    CView* pView = GetActiveView(); 
    if(pView->OnCmdMsg(nID, nCode))
        return TRUE; 

    if(CWnd::OnCmdMsg(nID, nCode))
        return TRUE; 

    CWinApp* pApp = AfxGetApp(); 
    if(pApp->OnCmdMsg(nID, nCode))
        return TRUE; 

    return FALSE; 
}

BOOL CView::OnCmdMsg(UINT nID, int nCode)
{
    cout << "CView::OnCmdMsg()" << endl; 
    if(CWnd::OnCmdMsg(nID, nCode))
        return TRUE; 

    return m_pDocument->OnCmdMsg(nID, nCode); 
}


CWinApp* AfxGetApp()
{
    return theApp.m_pCurrentWinApp; 
}

LRESULT AfxWndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam, CWnd* pWnd)
{
    cout << "AfxWndProc()" << endl; 
    return AfxCallWndProc(pWnd, hWnd, nMsg, wParam, lParam); 
}


LRESULT AfxCallWndProc(CWnd* pWnd, HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
    cout << "AfxCallWndProc()" << endl; 
    LRESULT lResult = pWnd->WindowProc(nMsg, wParam, lParam); 
    return lResult; 
}

void MsgMapPrinting(CCmdTarget* pObj)
{
    AFX_MSGMAP* pMap = pObj->GetMessageMap(); 
    CRuntimeClass* pClass = pObj->GetRuntimeClass(); 
    cout << pClass->m_lpszClassName << " Message Map:  " << endl; 
    for(; pMap != NULL; pMap = pMap->pBaseMessageMap)
    {
        AFX_MSGMAP_ENTRY* pEntry = pMap->lpEntries; 
        for(; pEntry->nSig != AfxSig_end; pEntry++)
        {
            cout << pEntry->nID << "    " << pClass->m_lpszClassName << endl; 
        }

        pClass = pClass->m_pBaseClass; 
    }

    cout << endl; 
}
