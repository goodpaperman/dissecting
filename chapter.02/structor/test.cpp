#include <iostream.h>
#include <string.h>

class CDemo
{
public:
    CDemo(const char* str); 
    ~CDemo(); 
private:
    char name[20]; 
}; 

CDemo::CDemo(const char* str)
{
    strncpy(name, str, 20); 
    cout << "Constructor called for " << name << endl; 
}

CDemo::~CDemo()
{
    cout << "Destructor called for " << name << endl; 
}

void func()
{
    CDemo LocalObjectInFunc("LocalObjectInFunc"); 
    static CDemo StaticObject("StaticObject"); 
    CDemo* pHeapObjectInFunc = new CDemo("HeapObjectInFunc"); 
    cout << "Inside func" << endl; 
    delete pHeapObjectInFunc; 
}

CDemo GlobalObject("GlobalObject"); 

void main()
{
    CDemo LocalObjectInMain("LocalObjectInMain"); 
    CDemo* pHeapObjectInMain = new CDemo("HeapObjectInMain"); 
    cout << "In main, before calling func\n"; 
    func(); 
    cout << "In main, after calling func\n"; 
    delete pHeapObjectInMain; 
}