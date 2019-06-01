#include "my.h"

CMyWinApp theApp; 

IMPLEMENT_DYNAMIC(CMyWinApp, CWinApp)
//IMPLEMENT_DYNAMIC(CMyFrameWnd, CFrameWnd)
//IMPLEMENT_DYNAMIC(CMyView, CView)
//IMPLEMENT_DYNAMIC(CMyDoc, CDocument)
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)
IMPLEMENT_DYNCREATE(CMyView, CView)
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
    ON_COMMAND(CMyWinAppid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
    ON_COMMAND(CMyFrameWndid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CMyView, CView)
    ON_COMMAND(CMyViewid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
    ON_COMMAND(CMyDocid, 0)
END_MESSAGE_MAP()


BOOL CMyWinApp::InitInstance()
{
    m_pMainWnd = new CMyFrameWnd; 
    return TRUE; 
}

CMyFrameWnd::CMyFrameWnd()
{
    //cout << "CMyFrameWnd Constructor \n";
    Create(); 
}

CObject* CRuntimeClass::CreateObject()
{
    if(m_pfnCreateObject == NULL)
    {
        TRACE1("Error: Trying to create object which is not "
            "DECLARE_DYNCREATE \nor DECLARE_SERIAL: %hs.\n", 
            m_lpszClassName); 

        return NULL; 
    }

    CObject* pObject = (*m_pfnCreateObject)(); 
    return pObject; 
}

CRuntimeClass* PASCAL CRuntimeClass::Load()
{
    char szClassName[64]; 
    CRuntimeClass* pClass; 
    cout << endl << "enter a class name... "; 
    cin >> szClassName; 

    for(pClass = pFirstClass; pClass != NULL; pClass = pClass->m_pNextClass)
    {
        if(strcmp(szClassName, pClass->m_lpszClassName) == 0)
            return pClass; 
    }

    TRACE1("Error: class not found: %s.\n", szClassName); 
    return NULL; 
}

void main()
{
    CWinApp* pApp = AfxGetApp(); 

    pApp->InitApplication(); 
    pApp->InitInstance(); 
    pApp->Run(); 

    CMyDoc* pDoc = new CMyDoc; 
    CMyView* pView = new CMyView; 
    CFrameWnd* pFrame = (CFrameWnd*)pApp->m_pMainWnd; 

    MsgMapPrinting(pApp);
    MsgMapPrinting(pDoc); 
    MsgMapPrinting(pView); 
    MsgMapPrinting(pFrame); 

    delete pDoc; 
    delete pView; 
    delete pFrame;     
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