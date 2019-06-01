#include "mfc.h"

#define TestIsKindOf(object, class_name) \
    cout << object->GetRuntimeClass()->m_lpszClassName << " is kind of class [" << #class_name << "] : " << object->IsKindOf(RUNTIME_CLASS(class_name)) << endl

class CMyWinApp : public CWinApp
{
public:
    //CMyWinApp::CMyWinApp() { cout << "CMyWinApp Constructor \n"; }
    //CMyWinApp::~CMyWinApp() { cout << "CMyWinApp Destructor \n"; }

    virtual BOOL InitInstance(); 

    DECLARE_DYNAMIC(CMyWinApp)
    DECLARE_MESSAGE_MAP()
}; 

class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd(); 
    //~CMyFrameWnd() { cout << "CMyFrameWnd Destructor \n"; }

    //DECLARE_DYNAMIC(CMyFrameWnd)
    DECLARE_DYNCREATE(CMyFrameWnd)
    DECLARE_MESSAGE_MAP()
}; 

class CMyView : public CView
{
public:
    //CMyView() { cout << "CMyView Constructor \n"; }
    //~CMyView() { cout << "CMyView Destructor \n"; } 
    CMyView(); 

    //DECLARE_DYNAMIC(CMyView)
    DECLARE_DYNCREATE(CMyView)
    DECLARE_MESSAGE_MAP()
}; 

class CMyDoc : public CDocument
{
public:
    //CMyDoc() { cout << "CMyDoc Constructor \n"; }
    //~CMyDoc() { cout << "CMyDoc Destructor \n"; }

    //DECLARE_DYNAMIC(CMyDoc)
    DECLARE_DYNCREATE(CMyDoc)
    DECLARE_MESSAGE_MAP()
}; 

void PrintAllClasses(); 
