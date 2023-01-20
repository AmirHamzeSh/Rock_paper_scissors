
// sangDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sang.h"
#include "sangDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsangDlg dialog



CsangDlg::CsangDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsangDlg::IDD, pParent)
	, Show_User_Select(_T(""))
	, Show_Computer_Select(_T(""))
	, Show_res(_T(""))
	, Select_User(0)
	, Select_Computer(0)
	, Score_Board(_T(""))
	, Score_User(0)
	, Score_Computer(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_show_select_user, Show_User_Select);
	DDX_Text(pDX, IDC_show_select_computer, Show_Computer_Select);
	DDX_Text(pDX, IDC_show_result, Show_res);
	DDX_Text(pDX, IDC_ScoreBoard, Score_Board);
}

BEGIN_MESSAGE_MAP(CsangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CsangDlg::OnBnClickedButtonExit)

	ON_BN_CLICKED(IDC_BUTTON_sang, &CsangDlg::OnBnClickedButtonsang)
	ON_BN_CLICKED(IDC_BUTTON_kaghaz, &CsangDlg::OnBnClickedButtonkaghaz)
	ON_BN_CLICKED(IDC_BUTTON_gheychi, &CsangDlg::OnBnClickedButtongheychi)
END_MESSAGE_MAP()


// CsangDlg message handlers

BOOL CsangDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Score_User = 0;
	Score_Computer=0;
	Score_Board = L"====امتیاز شما صفر و کامپیوتر صفر است====";
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CsangDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CsangDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CsangDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsangDlg::OnBnClickedButtonExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CsangDlg::OnBnClickedButtonsang()
{
	// TODO: Add your control notification handler code here
	Show_User_Select = L"انتخاب شما:سنگ";
	Select_User = 's';
	F_Select_Computer();
	Action();
	UpdateData(FALSE);
}


void CsangDlg::OnBnClickedButtonkaghaz()
{
	// TODO: Add your control notification handler code here
	Show_User_Select = L"انتخاب شما:کاغذ";
	Select_User = 'k';
	F_Select_Computer();
	Action();
	UpdateData(FALSE);
}


void CsangDlg::OnBnClickedButtongheychi()
{
	// TODO: Add your control notification handler code here
	Show_User_Select = L"انتخاب شما:قیچی";
	Select_User = 'g';
	F_Select_Computer();
	Action();
	UpdateData(FALSE);
	
}


//HRESULT CsangDlg::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}


int CsangDlg::Random(int min, int max)
{
    //srand(time(0));
    return rand()%(max-min+1)+min;
}


//HRESULT CsangDlg::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}

void CsangDlg::F_Select_Computer(void)
{
	Select_Computer = Random(1,3);

	if(Select_Computer == 1)
	{
		Select_Computer = 's';
		Show_Computer_Select = L"انتخاب کامپیوتر:سنگ";
	}
	else if (Select_Computer == 2)
	{
		Select_Computer = 'k';
		Show_Computer_Select = L"انتخاب کامپیوتر:کاغذ";
	}
	else if (Select_Computer == 3)
	{
		Select_Computer = 'g';
		Show_Computer_Select = L"انتخاب کامپیوتر:قیچی";
	}else
		Show_res = Select_Computer;
	UpdateData(FALSE);
}


void CsangDlg::Action(void)
{

	if (Select_Computer == Select_User)
	{
		Show_res = L"مساوی";
	}else if(Select_Computer == 's' && Select_User == 'k')
	{
		Show_res = L"شما برنده شدید";
		Score_User++;
	}else if(Select_Computer == 's' && Select_User == 'g')
	{
		Show_res = L"کامپیوتر برنده شد";
		Score_Computer++;
	}else if (Select_Computer == 'k' && Select_User == 's')
	{
		Show_res = L"کامپیوتر برنده شد";
		Score_Computer++;
	}else if (Select_Computer == 'k' && Select_User == 'g')
	{
		Show_res = L"شما برنده شدید";
		Score_User++;
	}else if (Select_Computer == 'g' && Select_User == 's')
	{
		Show_res = L"شما برنده شدید";
		Score_User++;
	}else if (Select_Computer == 'g' && Select_User == 'k')
	{
		Show_res = L"کامپیوتر برنده شد";
		Score_Computer++;
	}else
		Show_res = L"خطا";

	Score_Board.Format(_T("====امتیاز شما %i و کامپیوتر %d است.===="),Score_User,Score_Computer);
	UpdateData(FALSE);
}

