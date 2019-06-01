// File.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "File.h"

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

        char* pBuffer = new char[0x1000]; 

        try
        {
            CFile file("mydoc.txt", CFile::modeReadWrite); 
            DWORD dwBytesRemaining = file.GetLength(); 
            UINT nBytesRead; 
            DWORD dwPosition; 
    
            while(dwBytesRemaining)
            {
                dwPosition = file.GetPosition(); 
                nBytesRead = file.Read(pBuffer, 0x1000); 
                ::CharLowerBuff(pBuffer, nBytesRead); 
                file.Seek((LONG)dwPosition, CFile::begin); 
                file.Write(pBuffer, nBytesRead); 
                dwBytesRemaining -= nBytesRead; 
            }
        }
        catch(CFileException* e)
        {
            if(e->m_cause == CFileException::fileNotFound)
                cout << "File not found." << endl; 
            else if(e->m_cause == CFileException::tooManyOpenFiles)
                cout << "File handles not enough." << endl; 
            else if(e->m_cause == CFileException::hardIO)
                cout << "Hardware error." << endl; 
            else if(e->m_cause == CFileException::diskFull)
                cout << "Disk full." << endl; 
            else if(e->m_cause == CFileException::badPath)
                cout << "All or part of the path is invalid." << endl; 
            else 
                cout << "Unknow file error." << endl; 

            e->Delete(); 
        }

        delete[] pBuffer; 
	}

	return nRetCode;
}


