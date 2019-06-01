// stdafx.cpp : source file that includes just the standard includes
//	$$root$$.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

/*
    This project was created using the Top Studio AppWizard

    $$PROJ_COMMENT$$

    Project:    $$Root$$
    Author:     $$PROJ_AUTHOR$$
    Date:       $$PROJ_DATE$$
*/


#include "stdafx.h"

$$IF(ATL_SUPPORT)
#include <atlimpl.cpp>
$$ENDIF

$$IF(OLEDB)
CComModule _Module;
#include <atlimpl.cpp>
$$ENDIF

