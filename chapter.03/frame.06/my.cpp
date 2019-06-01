#include "my.h"

CMyWinApp theApp; 

IMPLEMENT_DYNAMIC(CMyWinApp, CWinApp)
//IMPLEMENT_DYNAMIC(CMyFrameWnd, CFrameWnd)
//IMPLEMENT_DYNAMIC(CMyView, CView)
//IMPLEMENT_DYNAMIC(CMyDoc, CDocument)
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)
IMPLEMENT_DYNCREATE(CMyView, CView)
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

BOOL CMyWinApp::InitInstance()
{
    m_pMainWnd = new CMyFrameWnd; 
    return TRUE; 
}

CMyFrameWnd::CMyFrameWnd()
{
    cout << "CMyFrameWnd Constructor \n";
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
    //CWinApp* pApp = AfxGetApp(); 

    //pApp->InitApplication(); 
    //pApp->InitInstance(); 
    //pApp->Run(); 

    CRuntimeClass* pClass; 
    CObject* pObj; 
    while(TRUE)
    {
        if((pClass = CRuntimeClass::Load()) == NULL)
            break; 

        pObj = pClass->CreateObject(); 
        if(pObj != NULL)
        {
            delete pObj; 
            pObj = NULL; 
        }
    }
}