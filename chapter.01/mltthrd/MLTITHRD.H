//--------------------------------------------------------------------
// ÀÉ¦W : mltithrd.h
//--------------------------------------------------------------------
#define IDM_RESUME    1
#define IDM_SUSPEND   2
#define IDM_FOR       3
#define IDM_SLEEP     4
#define IDM_NODELAY   5

#define HIGHEST_THREAD    0x00 //0
#define ABOVE_AVE_THREAD  0x3F //63
#define NORMAL_THREAD     0x7F //127
#define BELOW_AVE_THREAD  0xBF //191
#define LOWEST_THREAD     0xFF //255
#define SLEEPDELAY        1
#define FORLOOPDELAY      2
#define NODELAY           3

// ¨ç¦¡«Å§i
LONG APIENTRY MainWndProc (HWND, UINT, UINT, LONG);
VOID ThreadProc (DWORD *ThreadArg);
