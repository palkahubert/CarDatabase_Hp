
// MFCApplication2Dlg.h: plik nagłówkowy
//

#pragma once


// okno dialogowe CMFCApplication2Dlg
class CMFCApplication2Dlg : public CDialogEx
{
// Konstrukcja
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// konstruktor standardowy

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// obsługa DDX/DDV


// Implementacja
protected:
	HICON m_hIcon;

	// Wygenerowano funkcje mapy komunikatów
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Manufacturer;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CString Model;
	CString Year;
	CString Color;
	CButton Submit;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton2();
	CButton Clear;
	afx_msg void OnBnClickedButton3();
};
