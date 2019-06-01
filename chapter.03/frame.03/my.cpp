#include "my.h"

CMyWinApp theApp; 

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

    PrintAllClasses(); 
}