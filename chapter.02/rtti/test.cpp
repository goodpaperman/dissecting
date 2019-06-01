#include <typeinfo.h>
#include <iostream.h>
#include <string.h>

class graphicImage
{
protected:
    char name[80]; 

public:
    graphicImage()
    {
        strcpy(name, "graphicImage"); 
    }

    void display()
    {
        cout << "Display a generic image." << endl; 
    }

    virtual char* getName()
    {
        return name; 
    }
}; 


class GIFimage : public graphicImage
{
public:
    GIFimage()
    {
        strcpy(name, "GIFimage"); 
    }

    void display()
    {
        cout << "Display a GIF file." << endl; 
    }
}; 

class PICTimage : public graphicImage
{
public:
    PICTimage()
    {
        strcpy(name, "PICTimage"); 
    }

    void display()
    {
        cout << "Display a PICT file." << endl; 
    }
}; 

void processFile(graphicImage* type)
{
    cout << "Type: " << (typeid(*type)).name() << endl; 
    if(typeid(GIFimage) == typeid(*type))
    {
        ((GIFimage*)type)->display(); 
    }
    else if(typeid(PICTimage) == typeid(*type))
    {
        ((PICTimage*)type)->display(); 
    }
    else
        cout << "Unknown type!" << endl; //<< (typeid(*type)).name() << endl; 
}

void main()
{
    graphicImage* gImage = new GIFimage(); 
    graphicImage* pImage = new PICTimage(); 

    processFile(gImage); 
    processFile(pImage); 

    cout << "#1 testing" << endl; 
    gImage->display(); 
    pImage->display(); 

    delete pImage; 
    delete gImage; 
}