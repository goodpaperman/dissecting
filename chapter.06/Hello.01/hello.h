class CMyWinApp : public CWinApp
{
public:
    BOOL InitInstance(); 
}; 

class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd(); 
    afx_msg void OnPaint(); 
    afx_msg void OnAbout(); 
    void enumIt(CDC& dc); 

private:
    DECLARE_MESSAGE_MAP()
    static VOID CALLBACK LineDDACallback(int, int, LPARAM); 
    static int CALLBACK EnumObjectsProc(LPVOID lpLogObject, LPARAM lParam); 
}; 