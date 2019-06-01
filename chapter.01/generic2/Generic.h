
BOOL InitApplication(HANDLE); 
BOOL InitInstance(HANDLE, int); 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
LRESULT OnCommand(HWND, UINT, WPARAM, LPARAM); 
LRESULT OnDestroy(HWND, UINT, WPARAM, LPARAM); 
LRESULT OnExit(HWND, UINT, WPARAM, LPARAM);
LRESULT OnAbout(HWND, UINT, WPARAM, LPARAM);  
LRESULT CALLBACK About(HWND, UINT, WPARAM, LPARAM); 
void OnIdle();  



struct MSGMAP_ENTRY
{
    UINT nMessage; 
    LONG (*pfn)(HWND, UINT, WPARAM, LPARAM); 
}; 

#define dim(x) (sizeof(x) / sizeof(x[0]))