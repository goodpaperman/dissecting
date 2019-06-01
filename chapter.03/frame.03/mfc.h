#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR; 
#define UINT int
#define PASCAL _stdcall

#include <iostream.h>

class CObject; 
struct CRuntimeClass
{
    LPCSTR m_lpszClassName; 
    int m_nObjectSize; 
    UINT m_wSchema; 
    CObject* (PASCAL* m_pfnCreateObject)(); 
    CRuntimeClass* m_pBaseClass; 

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



class CObject
{
public:
    CObject::CObject() {}
    CObject::~CObject() {}

    DECLARE_DYNAMIC(CObject)
}; 

class CCmdTarget : public CObject
{ 
public:
    CCmdTarget::CCmdTarget() {}
    CCmdTarget::~CCmdTarget() {}

    DECLARE_DYNAMIC(CCmdTarget)
}; 

class CWinThread : public CObject
{
public:
    CWinThread::CWinThread() {}
    CWinThread::~CWinThread() {}

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
    CWinApp::CWinApp() { m_pCurrentWinApp = this;}
    CWinApp::~CWinApp() {}

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
    CDocument::CDocument() {}
    CDocument::~CDocument() {}

    DECLARE_DYNAMIC(CDocument)
}; 

class CWnd : public CCmdTarget
{
public:
    CWnd::CWnd() {}
    CWnd::~CWnd() {}

    virtual BOOL Create(); 
    BOOL CreateEx(); 
    virtual BOOL PreCreateWindow(); 

    DECLARE_DYNAMIC(CWnd)
}; 

class CFrameWnd : public CWnd
{
public:
    CFrameWnd::CFrameWnd() {}
    CFrameWnd::~CFrameWnd() {}

    virtual BOOL Create(); 
    virtual BOOL PreCreateWindow();

    DECLARE_DYNAMIC(CFrameWnd)
}; 

class CView : public CWnd
{
public:
    CView::CView() {}
    CView::~CView() {}

    DECLARE_DYNAMIC(CView)
}; 

CWinApp* AfxGetApp(); 