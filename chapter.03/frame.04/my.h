#include <iostream.h>
#include "mfc.h"

#define TestIsKindOf(object, class_name) \
    cout << object->GetRuntimeClass()->m_lpszClassName << " is kind of class [" << #class_name << "] : " << object->IsKindOf(RUNTIME_CLASS(class_name)) << endl

class CMyWinApp : public CWinApp
{
public:
    CMyWinApp::CMyWinApp() {}
    CMyWinApp::~CMyWinApp() {}

    virtual BOOL InitInstance(); 

    DECLARE_DYNAMIC(CMyWinApp)
}; 

class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd::CMyFrameWnd(); 
    CMyFrameWnd::~CMyFrameWnd() {}

    DECLARE_DYNAMIC(CMyFrameWnd)
}; 

class CMyView : public CView
{
public:
    CMyView() {}
    ~CMyView() {} 

    DECLARE_DYNAMIC(CMyView)
}; 

class CMyDoc : public CDocument
{
public:
    CMyDoc() {}
    ~CMyDoc() {}

    DECLARE_DYNAMIC(CMyDoc)
}; 

void PrintAllClasses(); 