
// CarDatabase_HP.cpp: definiuje zachowania klasy dla aplikacji.
//

#include "pch.h"
#include "framework.h"
#include "CarDatabase_HP.h"
#include "CarDatabase_HPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2App

BEGIN_MESSAGE_MAP(CMFCApplication2App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Konstrukcja klasy CMFCApplication2App

CMFCApplication2App::CMFCApplication2App()
{
	// obsługa menedżera ponownego uruchamiania
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: W tym miejscu dodaj kod konstruktora,
	// Umieść wszystkie znaczące inicjacje w InitInstance
}


// Jedyny obiekt CMFCApplication2App

CMFCApplication2App theApp;


// Inicjowanie klasy CMFCApplication2App

BOOL CMFCApplication2App::InitInstance()
{
	// Funkcja InitCommonControlsEx() jest wymagana w systemie Windows XP, jeśli aplikacja
	// manifest określa użycie pliku ComCtl32.dll w wersji 6 lub nowszej, który ma zostać użyty
	// style wizualne. W przeciwnym razie utworzenie jakiegokolwiek okna nie powiedzie się.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Ustaw ten element tak, aby uwzględniał wszystkie typowe klasy kontrolek, których chcesz użyć
	// w aplikacji.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Utwórz menedżera powłoki, jeśli okno dialogowe zawiera
	// dowolne kontrolki widoku drzewa powłoki lub widoku listy powłoki.
	CShellManager *pShellManager = new CShellManager;

	// Aktywuj natywnego menedżera obiektów wizualnych systemu Windows, aby włączyć kompozycje dla kontrolek MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Inicjowanie standardowe
	// Jeśli nie używasz tych funkcji i chcesz zmniejszyć rozmiar
	// końcowego pliku wykonywalnego, usuń poniżej
	// określone procedury inicjowania, które nie są potrzebne
	// Zmień klucz rejestru, w którym są przechowywane ustawienia
	// TODO: zmodyfikuj ten ciąg, aby był poprawny
	// takie jak nazwa firmy lub organizacji
	SetRegistryKey(_T("Aplikacje lokalne wygenerowane przez kreatora aplikacji"));

	CMFCApplication2Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: umieść tutaj kod, który ma być obsługiwany, gdy okno dialogowe
		//  odrzucone za pomocą pozycji OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: umieść tutaj kod, który ma być obsługiwany, gdy okno dialogowe
		//  odrzucone za pomocą polecenia Anuluj
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Ostrzeżenie: tworzenie okna dialogowego nie powiodło się, więc praca aplikacji została nieoczekiwanie przerwana.\n");
		TRACE(traceAppMsg, 0, "Ostrzeżenie: jeśli używasz kontrolek MFC w oknie dialogowym, nie możesz użyć instrukcji #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Usuń menedżera powłoki utworzonego powyżej.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Ponieważ okno dialogowe zostało zamknięte, zwróć wartość FALSE, aby zakończyć
	//  aplikację zamiast uruchomić pompę komunikatów aplikacji.
	return FALSE;
}

