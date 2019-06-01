#include "my.h"

CMyWinApp theApp; 

IMPLEMENT_DYNAMIC(CMyWinApp, CWinApp)
IMPLEMENT_DYNAMIC(CMyFrameWnd, CFrameWnd)
IMPLEMENT_DYNAMIC(CMyView, CView)
IMPLEMENT_DYNAMIC(CMyDoc, CDocument)

BOOL CMyWinApp::InitInstance()
{
    m_pMainWnd = new CMyFrameWnd; 
    return TRUE; 
}

CMyFrameWnd::CMyFrameWnd()
{
    Create(); 
}

void PrintAllClasses()
{
    for(CRuntimeClass* pClass = CRuntimeClass::pFirstClass; pClass != NULL; pClass = pClass->m_pNextClass)
    {
        cout << "Class Name: " << pClass->m_lpszClassName << endl; 
        cout << "Class Size: " << pClass->m_nObjectSize << endl; 
        cout << "Schema :    " << pClass->m_wSchema << endl; 
        if(pClass->m_pBaseClass == NULL)
            cout << "Base Class: " << "NULL" << endl; 
        else 
            cout << "Base Class: " << pClass->m_pBaseClass->m_lpszClassName << endl; 
        cout << endl; 
    }
}

void main()
{
    CWinApp* pApp = AfxGetApp(); 

    pApp->InitApplication(); 
    pApp->InitInstance(); 
    pApp->Run(); 
    //PrintAllClasses(); 

    CMyDoc* pDoc = new CMyDoc; 
    CMyView* pView = new CMyView; 
    CWnd* pWnd = pApp->m_pMainWnd; 

    TestIsKindOf(pDoc, CMyDoc); 
    TestIsKindOf(pDoc, CDocument); 
    TestIsKindOf(pDoc, CCmdTarget); 
    TestIsKindOf(pDoc, CObject); 
    TestIsKindOf(pDoc, CWinApp); 
    TestIsKindOf(pDoc, CView); 

    TestIsKindOf(pView, CView); 
    TestIsKindOf(pView, CObject); 
    TestIsKindOf(pView, CWnd); 
    TestIsKindOf(pView, CFrameWnd); 

    TestIsKindOf(pWnd, CFrameWnd); 
    TestIsKindOf(pWnd, CWnd); 
    TestIsKindOf(pWnd, CObject); 
    TestIsKindOf(pWnd, CDocument); 

    delete pWnd; 
    delete pView; 
    delete pDoc; 
}