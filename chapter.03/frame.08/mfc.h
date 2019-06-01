#define TRUE 1
#define FALSE 0

typedef char* LPSTR; 
typedef const char* LPCSTR; 

typedef unsigned long DWORD; 
typedef int BOOL; 
typedef unsigned char BYTE; 
typedef unsigned short WORD; 
typedef int INT; 
typedef unsigned int UINT; 
typedef long LONG; 

typedef UINT WPARAM; 
typedef LONG LPARAM; 
typedef LONG LRESULT; 
typedef int HWND; 

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



#define WM_COMMAND 0x0111
#define WM_CREATE 0x0001
#define WM_PAINT 0x000F
#define WM_NOTIFY 0x004E

#define CCmdTargetid 1
#define     CWinAppid 11
#define         CMyWinAppid 111
#define     CWndid 12
#define         CFrameWndid 121
#define             CMyFrameWndid 1211
#define         CViewid 122
#define             CMyViewid 1221
#define     CDocumentid 13
#define         CMyDocid 131



class CCmdTarget; 
typedef void (CCmdTarget::*AFX_PMSG)(void); 

struct AFX_MSGMAP_ENTRY
{
    UINT nMessage; 
    UINT nCode; 
    UINT nID; 
    UINT nLastID; 
    UINT nSig; 
    AFX_PMSG pfn; 
}; 

struct AFX_MSGMAP
{
    AFX_MSGMAP* pBaseMessageMap; 
    AFX_MSGMAP_ENTRY* lpEntries; 
}; 

enum AfxSig
{
    AfxSig_end = 0, 
    AfxSig_vv, 
}; 

#define DECLARE_MESSAGE_MAP() \
    static AFX_MSGMAP_ENTRY _messageEntries[]; \
    static AFX_MSGMAP messageMap; \
    virtual AFX_MSGMAP* GetMessageMap() const; 

#define BEGIN_MESSAGE_MAP(theClass, baseClass) \
    AFX_MSGMAP* theClass::GetMessageMap() const \
        { return &theClass::messageMap; } \
    AFX_MSGMAP theClass::messageMap = \
    { &(baseClass::messageMap), \
      (AFX_MSGMAP_ENTRY*) &(theClass::_messageEntries) }; \
    AFX_MSGMAP_ENTRY theClass::_messageEntries[] = \
    {

#define ON_COMMAND(id, memberFxn) \
        { WM_COMMAND, 0, (WORD)id, (WORD)id, AfxSig_vv, (AFX_PMSG)memberFxn }, 

#define END_MESSAGE_MAP() \
        { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
    }; 



class CObject
{
public:
    //CObject::CObject() { cout << "CObject Constructor \n"; }
    //CObject::~CObject() { cout << "CObject Destructor \n"; }

    BOOL IsKindOf(const CRuntimeClass* pClass) const; 

    DECLARE_DYNAMIC(CObject)
}; 

class CCmdTarget : public CObject
{ 
public:
    //CCmdTarget::CCmdTarget() { cout << "CCmdTarget Constructor \n"; }
    //CCmdTarget::~CCmdTarget() { cout << "CCmdTarget Destructor \n"; }
    virtual BOOL OnCmdMsg(UINT nID, int nCode); 

    DECLARE_DYNAMIC(CCmdTarget)
    DECLARE_MESSAGE_MAP()
}; 

class CWinThread : public CCmdTarget
{
public:
    //CWinThread::CWinThread() { cout << "CWinThread Constructor \n"; }
    //CWinThread::~CWinThread() { cout << "CWinThread Destructor \n"; }

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
    CWinApp::CWinApp() { m_pCurrentWinApp = this; }
                        // cout << "CWinApp Constructor \n"; }
    //CWinApp::~CWinApp() { cout << "CWinApp Destructor \n"; }

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
    DECLARE_MESSAGE_MAP()
}; 

class CDocument : public CCmdTarget
{
public:
    //CDocument::CDocument() { cout << "CDocument Constructor \n"; }
    //CDocument::~CDocument() { cout << "CDocument Destructor \n"; }
    virtual BOOL OnCmdMsg(UINT nID, int nCode); 

    DECLARE_DYNAMIC(CDocument)
    DECLARE_MESSAGE_MAP()
}; 

class CWnd : public CCmdTarget
{
public:
    //CWnd::CWnd() { cout << "CWnd Constructor \n"; }
    //CWnd::~CWnd() { cout << "CWnd Destructor \n"; }

    virtual BOOL Create(); 
    BOOL CreateEx(); 
    virtual BOOL PreCreateWindow(); 

    virtual LRESULT WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam); 
    virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam); 
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam); 

    //DECLARE_DYNAMIC(CWnd)
    DECLARE_DYNCREATE(CWnd)
    DECLARE_MESSAGE_MAP()
}; 

class CView; 
class CFrameWnd : public CWnd
{
public:
    CView* m_pViewActive; 

public:
    //CFrameWnd::CFrameWnd() { cout << "CFrameWnd Constructor \n"; }
    //CFrameWnd::~CFrameWnd() { cout << "CFrameWnd Destructor \n"; }

    virtual BOOL Create(); 
    virtual BOOL PreCreateWindow();
    CView* GetActiveView() const; 

    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam); 
    virtual BOOL OnCmdMsg(UINT nID, int nCode); 

    //DECLARE_DYNAMIC(CFrameWnd)
    DECLARE_DYNCREATE(CFrameWnd)
    DECLARE_MESSAGE_MAP()
}; 

class CView : public CWnd
{
public:
    CDocument* m_pDocument; 

public:
    //CView::CView() { cout << "CView Constructor \n"; }
    //CView::~CView() { cout << "CView Destructor \n"; }
    virtual BOOL OnCmdMsg(UINT nID, int nCode); 

    DECLARE_DYNAMIC(CView)
    DECLARE_MESSAGE_MAP()
}; 

CWinApp* AfxGetApp(); 
LRESULT AfxWndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam, CWnd* pWnd); 
LRESULT AfxCallWndProc(CWnd* pWnd, HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam); 
void MsgMapPrinting(CCmdTarget* pObj); 
