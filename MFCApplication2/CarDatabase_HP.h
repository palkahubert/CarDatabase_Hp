
// MFCApplication2.h: główny plik nagłówkowy aplikacji PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "dołącz nagłówek „pch.h” przed dołączeniem tego pliku na potrzeby optymalizacji PCH"
#endif

#include "resource.h"		// główne symbole


// CMFCApplication2App:
// Aby uzyskać implementację klasy, zobacz MFCApplication2.cpp
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();

// Przesłania
public:
	virtual BOOL InitInstance();

// Implementacja

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
