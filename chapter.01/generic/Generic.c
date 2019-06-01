// Generic.cpp : Defines the entry point for the application.
//

#include <windows.h>
#include "resource.h"
#include "generic.h"

HINSTANCE _hInst; 
HWND _hWnd; 

char _szAppName[] = "Generic"; 
char _szTitle[] = "Generic Sample Application"; 

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

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
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
    int wmId, wmEvent; 
    switch(message)
    {
        case WM_COMMAND:
            wmId = LOWORD(wParam); 
            wmEvent = HIWORD(wParam); 
            switch(wmId)
            {
                case IDM_ABOUT:
                    DialogBox(_hInst, "AboutBox", hWnd, (DLGPROC)About); 
                    break; 
                case IDM_EXIT:
                    DestroyWindow(hWnd); 
                    break; 
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam); 
            }
            break; 
        case WM_DESTROY:
            PostQuitMessage(0); 
            break; 
        default:
            return DefWindowProc(hWnd, message, wParam, lParam); 
    }
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