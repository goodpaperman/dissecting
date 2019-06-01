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

BOOL CFrameWnd::Create()
{
    CreateEx(); 
    return TRUE; 
}

BOOL CFrameWnd::PreCreateWindow()
{
    return TRUE; 
}

CWinApp* AfxGetApp()
{
    return theApp.m_pCurrentWinApp; 
}