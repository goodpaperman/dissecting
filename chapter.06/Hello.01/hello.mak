# filename : hello.mak
# make file for hello.exe (MFC 4.0 Application)
# usage : nmake hello.mak (Visual C++ 5.0)

Hello.exe : stdafx.obj hello.obj hello.res
    link.exe /nologo /subsystem:windows /incremental:no \
        /machine:I386 /out:"Hello.exe" \
        hello.obj stdafx.obj hello.res \
        msvcrt.lib kernel32.lib user32.lib gdi32.lib mfc42.lib

stdafx.obj : stdafx.cpp stdafx.h
    cl.exe /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" \
        /D "_AFXDLL" /D "_MBCS" /Fp"Hello.pch" /Yc"stdafx.h" \
        /c stdafx.cpp

hello.obj : hello.cpp hello.h stdafx.h
    cl.exe /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" \
        /D "_AFXDLL" /D "_MBCS" /Fp"Hello.pch" /Yu"stdafx.h" \
        /c hello.cpp

hello.res : hello.rc hello.ico jjhour.ico 
    rc.exe /l 0x404 /Fo"hello.res" /D "NDEBUG" /D "_AFXDLL" hello.rc