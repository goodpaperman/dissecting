#include <windows.h>
#include <process.h>

unsigned __stdcall myfunc(void* p); 

void main()
{
   unsigned long thd; 
   unsigned tid; 
   thd = _beginthreadex(NULL, 0, myfunc, NULL, 0, &tid); 
   if(thd)
       CloseHandle((HANDLE)thd); 
   Sleep(1000); 
}

unsigned __stdcall myfunc(void* p)
{
    int i = 0; 
    while(i < 100)
    {
        printf("%d.\n", i++);     
    }

    return 0; 
}