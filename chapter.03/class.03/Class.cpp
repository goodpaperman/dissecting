// Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Class.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
	}

    PrintAllClasses(); 
	return nRetCode;
}

void PrintAllClasses()
{
    //for(CRuntimeClass* pClass = CRuntimeClass::pFirstClass; pClass != NULL; pClass = pClass->m_pNextClass)
    //{
    //}
    
	AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
	//AfxLockGlobals(CRIT_RUNTIMECLASSLIST);
	for (CRuntimeClass* pClass = pModuleState->m_classList; pClass != NULL;
		pClass = pClass->m_pNextClass)
	{
		cout << "Class Name:   " << pClass->m_lpszClassName << endl; 
        cout << "Class Size:   " << pClass->m_nObjectSize << endl; 
        cout << "Class Schema: " << pClass->m_wSchema << endl; 
        cout << endl; 
	}
	//AfxUnlockGlobals(CRIT_RUNTIMECLASSLIST);
#ifdef _AFXDLL
	// walk through the list of dynlink library registered classes
	//AfxLockGlobals(CRIT_DYNLINKLIST);
	for (CDynLinkLibrary* pDLL = pModuleState->m_libraryList; pDLL != NULL;
		pDLL = pDLL->m_pNextDLL)
	{
		for (pClass = pDLL->m_classList; pClass != NULL;
			pClass = pClass->m_pNextClass)
		{
    		cout << "Class Name:   " << pClass->m_lpszClassName << endl; 
            cout << "Class Size:   " << pClass->m_nObjectSize << endl; 
            cout << "Class Schema: " << pClass->m_wSchema << endl; 
            cout << endl; 
		}
	}
	//AfxUnlockGlobals(CRIT_DYNLINKLIST);
#endif
}


