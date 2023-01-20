
// sangDlg.h : header file
//

#pragma once


// CsangDlg dialog
class CsangDlg : public CDialogEx
{
// Construction
public:
	CsangDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SANG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonsang();
	afx_msg void OnBnClickedButtonkaghaz();
	afx_msg void OnBnClickedButtongheychi();
	CString Show_User_Select;
	CString Show_Computer_Select;
	CString Show_res;
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	int Random(int min, int max);
//	int sPlayer1;
//	int sPlayer2;
	char Select_User;
	char Select_Computer;
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	void Action(void);
	CString Score_Board;
	int Score_User;
	int Score_Computer;
	void F_Select_Computer(void);
};
