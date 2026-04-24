
// ShuDuParserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ShuDuParser.h"
#include "ShuDuParserDlg.h"
#include "afxdialogex.h"
#include "CShuDuParser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CShuDuParserDlg 对话框




CShuDuParserDlg::CShuDuParserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShuDuParserDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShuDuParserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_0_0, m_valueEdit[0][0]);
	DDX_Control(pDX, IDC_EDIT_0_1, m_valueEdit[0][1]);
	DDX_Control(pDX, IDC_EDIT_0_2, m_valueEdit[0][2]);
	DDX_Control(pDX, IDC_EDIT_0_3, m_valueEdit[0][3]);
	DDX_Control(pDX, IDC_EDIT_0_4, m_valueEdit[0][4]);
	DDX_Control(pDX, IDC_EDIT_0_5, m_valueEdit[0][5]);
	DDX_Control(pDX, IDC_EDIT_0_6, m_valueEdit[0][6]);
	DDX_Control(pDX, IDC_EDIT_0_7, m_valueEdit[0][7]);
	DDX_Control(pDX, IDC_EDIT_0_8, m_valueEdit[0][8]);

	DDX_Control(pDX, IDC_EDIT_1_0, m_valueEdit[1][0]);
	DDX_Control(pDX, IDC_EDIT_1_1, m_valueEdit[1][1]);
	DDX_Control(pDX, IDC_EDIT_1_2, m_valueEdit[1][2]);
	DDX_Control(pDX, IDC_EDIT_1_3, m_valueEdit[1][3]);
	DDX_Control(pDX, IDC_EDIT_1_4, m_valueEdit[1][4]);
	DDX_Control(pDX, IDC_EDIT_1_5, m_valueEdit[1][5]);
	DDX_Control(pDX, IDC_EDIT_1_6, m_valueEdit[1][6]);
	DDX_Control(pDX, IDC_EDIT_1_7, m_valueEdit[1][7]);
	DDX_Control(pDX, IDC_EDIT_1_8, m_valueEdit[1][8]);

	DDX_Control(pDX, IDC_EDIT_2_0, m_valueEdit[2][0]);
	DDX_Control(pDX, IDC_EDIT_2_1, m_valueEdit[2][1]);
	DDX_Control(pDX, IDC_EDIT_2_2, m_valueEdit[2][2]);
	DDX_Control(pDX, IDC_EDIT_2_3, m_valueEdit[2][3]);
	DDX_Control(pDX, IDC_EDIT_2_4, m_valueEdit[2][4]);
	DDX_Control(pDX, IDC_EDIT_2_5, m_valueEdit[2][5]);
	DDX_Control(pDX, IDC_EDIT_2_6, m_valueEdit[2][6]);
	DDX_Control(pDX, IDC_EDIT_2_7, m_valueEdit[2][7]);
	DDX_Control(pDX, IDC_EDIT_2_8, m_valueEdit[2][8]);

	DDX_Control(pDX, IDC_EDIT_3_0, m_valueEdit[3][0]);
	DDX_Control(pDX, IDC_EDIT_3_1, m_valueEdit[3][1]);
	DDX_Control(pDX, IDC_EDIT_3_2, m_valueEdit[3][2]);
	DDX_Control(pDX, IDC_EDIT_3_3, m_valueEdit[3][3]);
	DDX_Control(pDX, IDC_EDIT_3_4, m_valueEdit[3][4]);
	DDX_Control(pDX, IDC_EDIT_3_5, m_valueEdit[3][5]);
	DDX_Control(pDX, IDC_EDIT_3_6, m_valueEdit[3][6]);
	DDX_Control(pDX, IDC_EDIT_3_7, m_valueEdit[3][7]);
	DDX_Control(pDX, IDC_EDIT_3_8, m_valueEdit[3][8]);

	DDX_Control(pDX, IDC_EDIT_4_0, m_valueEdit[4][0]);
	DDX_Control(pDX, IDC_EDIT_4_1, m_valueEdit[4][1]);
	DDX_Control(pDX, IDC_EDIT_4_2, m_valueEdit[4][2]);
	DDX_Control(pDX, IDC_EDIT_4_3, m_valueEdit[4][3]);
	DDX_Control(pDX, IDC_EDIT_4_4, m_valueEdit[4][4]);
	DDX_Control(pDX, IDC_EDIT_4_5, m_valueEdit[4][5]);
	DDX_Control(pDX, IDC_EDIT_4_6, m_valueEdit[4][6]);
	DDX_Control(pDX, IDC_EDIT_4_7, m_valueEdit[4][7]);
	DDX_Control(pDX, IDC_EDIT_4_8, m_valueEdit[4][8]);

	DDX_Control(pDX, IDC_EDIT_5_0, m_valueEdit[5][0]);
	DDX_Control(pDX, IDC_EDIT_5_1, m_valueEdit[5][1]);
	DDX_Control(pDX, IDC_EDIT_5_2, m_valueEdit[5][2]);
	DDX_Control(pDX, IDC_EDIT_5_3, m_valueEdit[5][3]);
	DDX_Control(pDX, IDC_EDIT_5_4, m_valueEdit[5][4]);
	DDX_Control(pDX, IDC_EDIT_5_5, m_valueEdit[5][5]);
	DDX_Control(pDX, IDC_EDIT_5_6, m_valueEdit[5][6]);
	DDX_Control(pDX, IDC_EDIT_5_7, m_valueEdit[5][7]);
	DDX_Control(pDX, IDC_EDIT_5_8, m_valueEdit[5][8]);

	DDX_Control(pDX, IDC_EDIT_6_0, m_valueEdit[6][0]);
	DDX_Control(pDX, IDC_EDIT_6_1, m_valueEdit[6][1]);
	DDX_Control(pDX, IDC_EDIT_6_2, m_valueEdit[6][2]);
	DDX_Control(pDX, IDC_EDIT_6_3, m_valueEdit[6][3]);
	DDX_Control(pDX, IDC_EDIT_6_4, m_valueEdit[6][4]);
	DDX_Control(pDX, IDC_EDIT_6_5, m_valueEdit[6][5]);
	DDX_Control(pDX, IDC_EDIT_6_6, m_valueEdit[6][6]);
	DDX_Control(pDX, IDC_EDIT_6_7, m_valueEdit[6][7]);
	DDX_Control(pDX, IDC_EDIT_6_8, m_valueEdit[6][8]);

	DDX_Control(pDX, IDC_EDIT_7_0, m_valueEdit[7][0]);
	DDX_Control(pDX, IDC_EDIT_7_1, m_valueEdit[7][1]);
	DDX_Control(pDX, IDC_EDIT_7_2, m_valueEdit[7][2]);
	DDX_Control(pDX, IDC_EDIT_7_3, m_valueEdit[7][3]);
	DDX_Control(pDX, IDC_EDIT_7_4, m_valueEdit[7][4]);
	DDX_Control(pDX, IDC_EDIT_7_5, m_valueEdit[7][5]);
	DDX_Control(pDX, IDC_EDIT_7_6, m_valueEdit[7][6]);
	DDX_Control(pDX, IDC_EDIT_7_7, m_valueEdit[7][7]);
	DDX_Control(pDX, IDC_EDIT_7_8, m_valueEdit[7][8]);

	DDX_Control(pDX, IDC_EDIT_8_0, m_valueEdit[8][0]);
	DDX_Control(pDX, IDC_EDIT_8_1, m_valueEdit[8][1]);
	DDX_Control(pDX, IDC_EDIT_8_2, m_valueEdit[8][2]);
	DDX_Control(pDX, IDC_EDIT_8_3, m_valueEdit[8][3]);
	DDX_Control(pDX, IDC_EDIT_8_4, m_valueEdit[8][4]);
	DDX_Control(pDX, IDC_EDIT_8_5, m_valueEdit[8][5]);
	DDX_Control(pDX, IDC_EDIT_8_6, m_valueEdit[8][6]);
	DDX_Control(pDX, IDC_EDIT_8_7, m_valueEdit[8][7]);
	DDX_Control(pDX, IDC_EDIT_8_8, m_valueEdit[8][8]);

}

BEGIN_MESSAGE_MAP(CShuDuParserDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CShuDuParserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShuDuParserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CShuDuParserDlg 消息处理程序

BOOL CShuDuParserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CShuDuParserDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CShuDuParserDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CShuDuParserDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShuDuParserDlg::OnBnClickedButton1()
{
	int iVal[9][9];
	memset(iVal,0,sizeof(iVal));

	//init val
	for(int w=0;w<9;w++)
	{
		for(int h=0;h<9;h++)
		{
			CString str;
			m_valueEdit[w][h].GetWindowText(str);
			int iTmpVal = _wtoi(str);

			if(iTmpVal >= 1 && iTmpVal <= 9)
			{
				iVal[w][h] = iTmpVal;
			}
			else
			{
				iVal[w][h] = 0;
			}
		}
	}

	//
	CShuDuParser parser;

	int iRes = 0;
	iRes = parser.Parse(iVal);

	//
	for(int w=0;w<9;w++)
	{
		for(int h=0;h<9;h++)
		{
			CString str;
			str.Format(L"%d",iVal[w][h]);
			m_valueEdit[w][h].SetWindowText(str);
		}
	}

	//
	if(iRes == 0)
	{
		MessageBox(L"Parse OK");
	}
	else
	{
		MessageBox(L"Parse Fail");
	}

}


void CShuDuParserDlg::OnBnClickedButton2()
{
	for(int w=0;w<9;w++)
	{
		for(int h=0;h<9;h++)
		{
			CString str;
			str.Format(L"");
			m_valueEdit[w][h].SetWindowText(str);
		}
	}
}
