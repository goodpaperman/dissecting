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
    m_pViewActive = new CMyView; 
}

CMyView::CMyView()
{
    m_pDocument = new CMyDoc; 
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

    CFrameWnd* pFrame = (CFrameWnd*)pApp->m_pMainWnd; 
    CView* pView = pFrame->m_pViewActive; 
    CDocument* pDoc = pView->m_pDocument; 

    cout << endl << "Frame received a WM_CREATE, routing path:" << endl; 
    AfxWndProc(0, WM_CREATE, 0, 0, pFrame); 

    cout << endl << "View received a WM_PAINT, routing path:" << endl; 
    AfxWndProc(0, WM_PAINT, 0, 0, pView); 

    cout << endl << "View received a WM_COMMAND, routing path:" << endl; 
    AfxWndProc(0, WM_COMMAND, 0, 0, pView); 

    cout << endl << "Frame received a WM_COMMAND, routing path:" << endl; 
    AfxWndProc(0, WM_COMMAND, 0, 0, pFrame); 

    delete pDoc; 
    delete pView; 
    delete pFrame; 
}