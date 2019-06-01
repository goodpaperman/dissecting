// Generic.cpp : Defines the entry point for the application.
//

#include <windows.h>
#include "resource.h"
#include "generic.h"

HINSTANCE _hInst; 
HWND _hWnd; 

char _szAppName[] = "Generic"; 
char _szTitle[] = "Generic Sample Application"; 

struct MSGMAP_ENTRY _messageEntries[] = 
{
    WM_COMMAND, OnCommand, 
    WM_DESTROY, OnDestroy, 
}; 

struct MSGMAP_ENTRY _commandEntries[] = 
{
    IDM_ABOUT, OnAbout, 
    IDM_EXIT, OnExit, 
}; 

int CALLBACK WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
    MSG msg; 
    UNREFERENCED_PARAMETER(lpCmdLine); 
    if(!hPrevInstance)
        if(!InitApplication(hInstance))
            return FALSE; 

    if(!InitInstance(hInstance, nCmdShow))
        return FALSE; 

    //while(GetMessage(&msg, NULL, 0, 0))
    //{
    //    TranslateMessage(&msg); 
    //    DispatchMessage(&msg); 
    //}

    while(TRUE)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
                break; 

            TranslateMessage(&msg); 
            DispatchMessage(&msg); 
        }
        else 
            OnIdle(); 
    }

	return msg.wParam;
}

BOOL InitApplication(HINSTANCE hInstance)
{
    WNDCLASS wc; 
    wc.style = CS_HREDRAW | CS_VREDRAW; 
    wc.lpfnWndProc = (WNDPROC)WndProc; 
    wc.cbClsExtra = 0; 
    wc.cbWndExtra = 0; 
    wc.hInstance = hInstance; 
    wc.hIcon = LoadIcon(hInstance, "jjhouricon"); 
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
    wc.hbrBackground = GetStockObject(WHITE_BRUSH); 
    wc.lpszMenuName = "GenericMenu"; 
    wc.lpszClassName = _szAppName; 
    return RegisterClass(&wc); 
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    _hInst = hInstance; 
    _hWnd = CreateWindow(
        _szAppName, 
        _szTitle, 
        WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        NULL, 
        NULL, 
        hInstance, 
        NULL); 

    if(!_hWnd)
        return FALSE; 

    ShowWindow(_hWnd, nCmdShow); 
    UpdateWindow(_hWnd); 
    return TRUE; 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //int wmId, wmEvent; 
    //switch(message)
    //{
    //    case WM_COMMAND:
    //        wmId = LOWORD(wParam); 
    //        wmEvent = HIWORD(wParam); 
    //        switch(wmId)
    //        {
    //            case IDM_ABOUT:
    //                DialogBox(_hInst, "AboutBox", hWnd, (DLGPROC)About); 
    //                break; 
    //            case IDM_EXIT:
    //                DestroyWindow(hWnd); 
    //                break; 
    //            default:
    //                return DefWindowProc(hWnd, message, wParam, lParam); 
    //        }
    //        break; 
    //    case WM_DESTROY:
    //        PostQuitMessage(0); 
    //        break; 
    //    default:
    //        return DefWindowProc(hWnd, message, wParam, lParam); 
    //}

    int i; 
    for(i=0; i<dim(_messageEntries); i++)
        if(message == _messageEntries[i].nMessage)
            return ((*_messageEntries[i].pfn)(hWnd, message, wParam, lParam)); 

    return DefWindowProc(hWnd, message, wParam, lParam); 
}

LRESULT OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int i; 
    for(i=0; i<dim(_commandEntries); i++)
        if(LOWORD(wParam) == _commandEntries[i].nMessage)
            return ((*_commandEntries[i].pfn)(hWnd, message, wParam, lParam)); 

    return DefWindowProc(hWnd, message, wParam, lParam); 
}

LRESULT OnDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return DestroyWindow(hWnd); 
}

LRESULT OnAbout(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return DialogBox(_hInst, "AboutBox", hWnd, (DLGPROC)About); 
}

LRESULT OnExit(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0); 
    return 0; 
}

LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam); 
    switch(message)
    {
        case WM_INITDIALOG:
            return TRUE; 
        case WM_COMMAND:
            if(LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, TRUE); 
                return TRUE; 
            }
            break; 
    }

    return FALSE; 
}

void OnIdle()
{
    static int i=1; 
    char szText[81]; 
    wsprintf(szText, "I'm Idling %d.\n", i++); 
    OutputDebugString(szText); 
}
