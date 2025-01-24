
// CarDatabase_HPDlg.cpp: plik implementacji
//

#include "pch.h"
#include "framework.h"
#include "CarDatabase_HP.h"
#include "CarDatabase_HPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Okno dialogowe CAboutDlg używane na potrzeby informacji o aplikacji

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obsługa DDX/DDV

// Implementacja
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// okno dialogowe CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, Manufacturer(_T(""))
	, Model(_T(""))
	, Year(_T(""))
	, Color(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Manufacturer);
	DDX_Text(pDX, IDC_EDIT2, Model);
	DDX_Text(pDX, IDC_EDIT3, Year);
	DDX_Text(pDX, IDC_EDIT4, Color);
	DDX_Control(pDX, IDC_BUTTON1, Submit);
	//DDX_Control(pDX, IDC_BUTTON2, Search);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication2Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication2Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication2Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Procedury obsługi komunikatów CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Dodaj pozycję „Informacje...” do menu systemowego.

	// Element IDM_ABOUTBOX musi należeć do zakresu poleceń systemowych.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Ustaw ikonę dla tego okna dialogowego. Struktura wykonuje to automatycznie
	//  gdy okno główne aplikacji nie jest oknem dialogowym
	SetIcon(m_hIcon, TRUE);			// Ustaw duże ikony
	SetIcon(m_hIcon, FALSE);		// Ustaw małe ikony

	// TODO: Dodaj tutaj dodatkowe inicjowanie

	return TRUE;  // zwracaj wartość TRUE, dopóki fokus nie zostanie ustawiony na formant
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Jeśli dodasz przycisk minimalizacji do okna dialogowego, będziesz potrzebować poniższego kodu
//  aby narysować ikonę. Dla aplikacji MFC używających modelu dokumentu/widoku
//  to jest wykonywane automatycznie przez strukturę.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // kontekst urządzenia dotyczący malowania

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Wyśrodkuj ikonę w prostokącie klienta
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Rysuj ikonę
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// System wywołuje tę funkcję, aby uzyskać kursor wyświetlany podczas przeciągania przez użytkownika
//  zminimalizowane okno.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	// TODO:  Jeżeli to jest kontrolka RICHEDIT, to kontrolka nie będzie
	// wyślij to powiadomienie, chyba że przesłonisz element CDialogEx::OnInitDialog()
	// funkcja i wywołanie CRichEditCtrl().SetEventMask()
	// z flagą ENM_CHANGE zsumowaną logicznie z maską.
	
	// TODO:  Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// Aktualizuj zmienne z GUI
	UpdateData(TRUE);
	// Sprawdź, czy wszystkie pola są wypełnione
	if (Manufacturer.IsEmpty() || Model.IsEmpty() || Year.IsEmpty() || Color.IsEmpty())
	{
		AfxMessageBox(_T("All fields must be filled before adding data!"));
		return;
	}

	// Otwórz plik w trybie dodawania danych
	CStdioFile file;
	CString filePath = _T("cars.txt");
	if (file.Open(filePath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite))
	{
		// Ustaw wskaźnik pliku na koniec, aby dopisywać nowe dane
		file.SeekToEnd();

		// Formatowanie danych do zapisu
		CString carData;
		carData.Format(_T("Manufacturer: %s, Model: %s, Year: %s, Color: %s\n"),
			Manufacturer, Model, Year, Color);

		// Zapisz dane do pliku
		file.WriteString(carData);
		file.Close();

		// Pokaż komunikat o sukcesie
		AfxMessageBox(_T("Car data has been saved!"));
		Manufacturer = (_T(""));
		Model = (_T(""));
		Year = (_T(""));
		Color = (_T(""));

		UpdateData(FALSE);
	}
	else
	{
		// Pokaż komunikat o błędzie
		AfxMessageBox(_T("ERROR : Unable to access the database!"));
	}
}



void CMFCApplication2Dlg::OnEnChangeEdit4()
{
	// TODO:  Jeżeli to jest kontrolka RICHEDIT, to kontrolka nie będzie
	// wyślij to powiadomienie, chyba że przesłonisz element CDialogEx::OnInitDialog()
	// funkcja i wywołanie CRichEditCtrl().SetEventMask()
	// z flagą ENM_CHANGE zsumowaną logicznie z maską.

	// TODO:  Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
}


void CMFCApplication2Dlg::OnEnChangeEdit3()
{
	// TODO:  Jeżeli to jest kontrolka RICHEDIT, to kontrolka nie będzie
	// wyślij to powiadomienie, chyba że przesłonisz element CDialogEx::OnInitDialog()
	// funkcja i wywołanie CRichEditCtrl().SetEventMask()
	// z flagą ENM_CHANGE zsumowaną logicznie z maską.

	// TODO:  Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
}


void CMFCApplication2Dlg::OnEnChangeEdit2()
{
	// TODO:  Jeżeli to jest kontrolka RICHEDIT, to kontrolka nie będzie
	// wyślij to powiadomienie, chyba że przesłonisz element CDialogEx::OnInitDialog()
	// funkcja i wywołanie CRichEditCtrl().SetEventMask()
	// z flagą ENM_CHANGE zsumowaną logicznie z maską.

	// TODO:  Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
}

void CMFCApplication2Dlg::OnBnClickedButton2() {
	// Aktualizuj zmienne z GUI
	UpdateData(TRUE);

	CStdioFile file;
	// Otwarcie pliku w trybie odczytu
	if (file.Open(_T("cars.txt"), CFile::modeRead))
	{
		CString line;
		CString matchingCars;
		bool found = false;
		while (file.ReadString(line))
		{
			// Wyszukiwanie konkretnego pojazdu spośród dostępnych w bazie danych
			bool match = true;
			if (!Manufacturer.IsEmpty() && line.Find(_T("Manufacturer: ") + Manufacturer) == -1)
				match = false;
			if (!Model.IsEmpty() && line.Find(_T("Model: ") + Model) == -1)
				match = false;
			if (!Year.IsEmpty() && line.Find(_T("Year: ") + Year) == -1)
				match = false;
			if (!Color.IsEmpty() && line.Find(_T("Color: ") + Color) == -1)
				match = false;

			if (match)
			{
				// Jeśli odnaleziono pojazd, dodaj do elementów, które zostaną wyświetlone
				matchingCars += line + _T("\n");
				found = true;
			}
		}
		file.Close();
		if (found)
		{
			// Wyświetl znaleziony pojazd/pojazdy
			AfxMessageBox(_T("Car exists in the database: \n") + matchingCars);
			Manufacturer = (_T(""));
			Model = (_T(""));
			Year = (_T(""));
			Color = (_T(""));
			UpdateData(false);
		}
		else
		{
			// Wyświetl komunikat o braku pojazdu w bazie danych
			AfxMessageBox(_T("Not found in the database"));
		}
	}
	else
	{
		// Wyświetl komunikat o błędzie otwierania pliku
		AfxMessageBox(_T("Błąd otwierania pliku!"));
	}
}

void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// Aktualizuj zmienne z GUI
	UpdateData(TRUE);
	CString filePath = _T("cars.txt");

	// Usuń istniejący plik
	if (_tremove(filePath) == 0 || errno == ENOENT)
	{
		// Stwórz nowy pusty plik
		CStdioFile file;
		if (file.Open(filePath, CFile::modeCreate | CFile::modeWrite))
		{
			// Zamknij i zapisz pusty plik oraz wyświetl komunikat o sukcesie
			file.Close();
			AfxMessageBox(_T("Database has been erased!"));
			Manufacturer = (_T(""));
			Model = (_T(""));
			Year = (_T(""));
			Color = (_T(""));
		}
		else
		{
			// Wyświetl komunikat o błędzie stworzenia nowej, pustej bazy danych
			AfxMessageBox(_T("ERROR : Unable to create a new database!"));
		}
	}
	else
	{
		// Wyświetl komunikat o błędzie usuwania bazy danych
		AfxMessageBox(_T("ERROR : Unable to erase the database!"));
	}

	UpdateData(FALSE);
}



void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// Aktualizuj zmienne z GUI
	UpdateData(TRUE);
	//Sprawdzenie czy podane są wszystkie dane
	if (Manufacturer.IsEmpty() || Model.IsEmpty() || Year.IsEmpty() || Color.IsEmpty())
	{
		AfxMessageBox(_T("All fields must be filled before adding data!"));
		return;
	}

	CString filePath = _T("cars.txt");
	// Ścieżka tymczasowego pliku
	CString tempFilePath = _T("cars_temp.txt");

	CStdioFile file, tempFile;

	if (!file.Open(filePath, CFile::modeRead))
	{
		AfxMessageBox(_T("ERROR : Unable to open the database!"));
		return;
	}
	if (!tempFile.Open(tempFilePath,CFile::modeCreate | CFile::modeWrite ))
	{
		AfxMessageBox(_T("ERROR : Unable to delete the database! \n Unable to create a temporary file."));
		return;
	}

	CString line;
	bool deleted = false;
	//Wyszukiwanie podanego samochodu
	while (file.ReadString(line))
	{
		if (line.Find(_T("Manufacturer: ") + Manufacturer) != -1 &&
			line.Find(_T("Model: ") + Model) != -1 &&
			line.Find(_T("Year: ") + Year) != -1 &&
			line.Find(_T("Color: ") + Color) != -1)
		{
			deleted = true;
		}
		else
		{
			tempFile.WriteString(line + _T("\n"));
		}
	}
	file.Close();
	tempFile.Close();
	//Podmiana plików po wykonaniu procesu usuwania pojazdu
	if (deleted)
	{
		if (_tremove(filePath) != 0 || _trename(tempFilePath, filePath) != 0)
		{
			AfxMessageBox(_T("ERROR : Unable to update the database!"));
		}
		else
		{
			AfxMessageBox(_T("Car was successfuly deleted from the database"));
			Manufacturer = (_T(""));
			Model = (_T(""));
			Year = (_T(""));
			Color = (_T(""));
		}
	}
	else
	{
		_tremove(tempFilePath);
		AfxMessageBox(_T("No matching car found in the database"));
	}
	UpdateData(FALSE);
}
