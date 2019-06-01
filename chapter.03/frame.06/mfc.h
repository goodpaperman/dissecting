#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR; 
#define UINT int
#define PASCAL _stdcall
#define TRACE1 printf

#include <iostream.h>
#include <stdio.h>
#include <string.h>

class CObject; 
struct CRuntimeClass
{
    LPCSTR m_lpszClassName; 
    int m_nObjectSize; 
    UINT m_wSchema; 
    CObject* (PASCAL* m_pfnCreateObject)(); 
    CRuntimeClass* m_pBaseClass; 

    CObject* CreateObject(); 
    static CRuntimeClass* PASCAL Load(); 

    static CRuntimeClass* pFirstClass; 
    CRuntimeClass* m_pNextClass; 
}; 

struct AFX_CLASSINIT
{
    AFX_CLASSINIT(CRuntimeClass* pNewClass); 
}; 

#define RUNTIME_CLASS(class_name) \
    (&class_name::class##class_name)

#define DECLARE_DYNAMIC(class_name) \
public: \
        static CRuntimeClass class##class_name; \
        virtual CRuntimeClass* GetRuntimeClass() const; 

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
    static char _lpsz##class_name[] = #class_name; \
    CRuntimeClass class_name::class##class_name = \
    { \
        _lpsz##class_name, sizeof(class_name), wSchema, pfnNew, RUNTIME_CLASS(base_class_name), NULL \
    }; \
    static AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS(class_name)); \
    CRuntimeClass* class_name::GetRuntimeClass() const \
    { return RUNTIME_CLASS(class_name); }

#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
    _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL)


#define DECLARE_DYNCREATE(class_name) \
    DECLARE_DYNAMIC(class_name) \
    static CObject* PASCAL CreateObject(); 

#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
    CObject* PASCAL class_name::CreateObject() \
        { return new class_name; } \
    _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, class_name::CreateObject)


class CObject
{
public:
    CObject::CObject() { cout << "CObject Constructor \n"; }
    CObject::~CObject() { cout << "CObject Destructor \n"; }

    BOOL IsKindOf(const CRuntimeClass* pClass) const; 

    DECLARE_DYNAMIC(CObject)
}; 

class CCmdTarget : public CObject
{ 
public:
    CCmdTarget::CCmdTarget() { cout << "CCmdTarget Constructor \n"; }
    CCmdTarget::~CCmdTarget() { cout << "CCmdTarget Destructor \n"; }

    DECLARE_DYNAMIC(CCmdTarget)
}; 

class CWinThread : public CObject
{
public:
    CWinThread::CWinThread() { cout << "CWinThread Constructor \n"; }
    CWinThread::~CWinThread() { cout << "CWinThread Destructor \n"; }

    virtual BOOL InitInstance()
    {
        return TRUE; 
    }

    virtual int Run()
    {
        return 1; 
    }

    DECLARE_DYNAMIC(CWinThread)
}; 

class CWnd; 
class CWinApp : public CWinThread
{
public:
    CWinApp* m_pCurrentWinApp; 
    CWnd* m_pMainWnd; 

public:
    CWinApp::CWinApp() { m_pCurrentWinApp = this; 
                         cout << "CWinApp Constructor \n"; }
    CWinApp::~CWinApp() { cout << "CWinApp Destructor \n"; }

    virtual BOOL InitApplication()
    {
        return TRUE; 
    }

    virtual BOOL InitInstance()
    {
        return TRUE; 
    }

    virtual int Run()
    {
        return CWinThread::Run(); 
    }

    DECLARE_DYNAMIC(CWinApp)
}; 

class CDocument : public CCmdTarget
{
public:
    CDocument::CDocument() { cout << "CDocument Constructor \n"; }
    CDocument::~CDocument() { cout << "CDocument Destructor \n"; }

    DECLARE_DYNAMIC(CDocument)
}; 

class CWnd : public CCmdTarget
{
public:
    CWnd::CWnd() { cout << "CWnd Constructor \n"; }
    CWnd::~CWnd() { cout << "CWnd Destructor \n"; }

    virtual BOOL Create(); 
    BOOL CreateEx(); 
    virtual BOOL PreCreateWindow(); 

    //DECLARE_DYNAMIC(CWnd)
    DECLARE_DYNCREATE(CWnd)
}; 

class CFrameWnd : public CWnd
{
public:
    CFrameWnd::CFrameWnd() { cout << "CFrameWnd Constructor \n"; }
    CFrameWnd::~CFrameWnd() { cout << "CFrameWnd Destructor \n"; }

    virtual BOOL Create(); 
    virtual BOOL PreCreateWindow();

    //DECLARE_DYNAMIC(CFrameWnd)
    DECLARE_DYNCREATE(CFrameWnd)
}; 

class CView : public CWnd
{
public:
    CView::CView() { cout << "CView Constructor \n"; }
    CView::~CView() { cout << "CView Destructor \n"; }

    DECLARE_DYNAMIC(CView)
}; 

CWinApp* AfxGetApp(); 