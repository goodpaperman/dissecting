; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewDoc
LastTemplate=CDocument
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Graph.h"
LastPage=0

ClassCount=12
Class1=CGraphApp
Class2=CGraphDoc
Class3=CGraphView
Class4=CMainFrame
Class7=CChildFrame
Class9=CAboutDlg

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDR_GRAPHTYPE
Class10=CTextView
Class11=CBarView
Resource3=IDD_ABOUTBOX
Class12=CNewDoc
Resource4=IDR_NEWTYPE

[CLS:CGraphApp]
Type=0
HeaderFile=Graph.h
ImplementationFile=Graph.cpp
Filter=N

[CLS:CGraphDoc]
Type=0
HeaderFile=GraphDoc.h
ImplementationFile=GraphDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CGraphView]
Type=0
HeaderFile=GraphView.h
ImplementationFile=GraphView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=Graph.cpp
ImplementationFile=Graph.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_GRAPH_DATA1
Command10=ID_GRAPH_DATA2
Command11=ID_GRAPH_DATA3
CommandCount=11

[MNU:IDR_GRAPHTYPE]
Type=1
Class=CGraphView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_GRAPH_DATA1
Command18=ID_GRAPH_DATA2
Command19=ID_GRAPH_DATA3
Command20=ID_WINDOW_NEW
Command21=ID_WINDOW_CASCADE
Command22=ID_WINDOW_TILE_HORZ
Command23=ID_WINDOW_ARRANGE
Command24=ID_WINDOW_SPLIT
Command25=ID_APP_ABOUT
CommandCount=25

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[CLS:CTextView]
Type=0
HeaderFile=TextView.h
ImplementationFile=TextView.cpp
BaseClass=CView
Filter=C

[CLS:CBarView]
Type=0
HeaderFile=BarView.h
ImplementationFile=BarView.cpp
BaseClass=CView
Filter=C

[CLS:CNewDoc]
Type=0
HeaderFile=NewDoc.h
ImplementationFile=NewDoc.cpp
BaseClass=CDocument
Filter=N

[MNU:IDR_NEWTYPE]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_WINDOW_SPLIT
Command22=ID_APP_ABOUT
CommandCount=22

