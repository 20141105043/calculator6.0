
// caculater001Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "caculater001.h"
#include "caculater001Dlg.h"
#include "afxdialogex.h"
#include "math.h"

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
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
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


// Ccaculater001Dlg 对话框




Ccaculater001Dlg::Ccaculater001Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccaculater001Dlg::IDD, pParent)
	, m_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=180;
	c1=174;
	c2=180;
	c3=174;
	c4=180;
	c5=174;
}

void Ccaculater001Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_string);
}

BEGIN_MESSAGE_MAP(Ccaculater001Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_1, &Ccaculater001Dlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &Ccaculater001Dlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &Ccaculater001Dlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &Ccaculater001Dlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &Ccaculater001Dlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &Ccaculater001Dlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &Ccaculater001Dlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &Ccaculater001Dlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &Ccaculater001Dlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &Ccaculater001Dlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_ADD, &Ccaculater001Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &Ccaculater001Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &Ccaculater001Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &Ccaculater001Dlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_Point, &Ccaculater001Dlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_Backspace, &Ccaculater001Dlg::OnBnClickedBackspace)
    ON_BN_CLICKED(IDC_Clear, &Ccaculater001Dlg::OnClickedClear)
	ON_BN_CLICKED(IDC_Value, &Ccaculater001Dlg::OnClickedValue)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Ccaculater001Dlg 消息处理程序

BOOL Ccaculater001Dlg::OnInitDialog()
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
	SetTimer(1,1000,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ccaculater001Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Ccaculater001Dlg::OnPaint()
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
HCURSOR Ccaculater001Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Ccaculater001Dlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"1";
	UpdateData(false);
}   

void Ccaculater001Dlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"2";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"3";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"4";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"5";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"6";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"7";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"8";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"9";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"0";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue();
	flag=0;
}

void Ccaculater001Dlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
    SaveValue();
	flag=1;
}

void Ccaculater001Dlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue();
	flag=2;
}

void Ccaculater001Dlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue();
	flag=3;
}

void Ccaculater001Dlg::OnBnClickedPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(-1==m_string.Find(L"."))
	m_string=m_string+L".";
	UpdateData(false);
}


void Ccaculater001Dlg::OnBnClickedBackspace()
{
	// TODO: 在此添加控件通知处理程序代码 
    if(!m_string.IsEmpty()) 
    { 
        m_string=m_string.Left(m_string.GetLength()-1); 
    } 
    UpdateData(false);
}




void Ccaculater001Dlg::OnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string="";
	m_num1=0.0f;
	m_num2=0.0f;
	flag=0;
	UpdateData(false);
}


void Ccaculater001Dlg::OnClickedValue()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculator(); 
}
void Ccaculater001Dlg::SaveValue()  
{  
    UpdateData(true);  
    m_num1 = _ttof(m_string);  
    m_string = "";  
    UpdateData(false);  
} 
void Ccaculater001Dlg::Calculator()  
{  
    UpdateData(true);  
    m_num2 = _ttof(m_string);  
    double f = 0.0f;
	if(flag==0)
	{
		UpdateData(true);
		f = m_num1 + m_num2;
	}
	if(flag==1)
	{
		UpdateData(true);
		f = m_num1 - m_num2;
	}
	if(flag==2)
	{
		UpdateData(true);
		f = m_num1 *m_num2;
	}
	if(flag==3)
	{
		UpdateData(true);
		f = m_num1 /m_num2;
	}
	while(m_string.Right(1)=="0.")
	{
		m_string.Delete(m_string.GetLength()-1,1);
		UpdateData(false);
	}
	m_string.Format(L"%lf",f); 
	UpdateData(false);
}
   
void Ccaculater001Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x,x1,y,y1,ox=450,oy=450;
	int x2,y2,x3,y3;
	int x4,y4,x5,y5;
	if(nIDEvent==1)
    {
	    int r=80;
	    CDC *pDC;
	    CPen newpen;
	    newpen.CreatePen(PS_SOLID,1,RGB(240,240,240));
	    pDC=GetDC();
	    CPen*oldpen=pDC->SelectObject(&newpen);
	    x=ox+r*sin(c*3.1415926/180);
	    y=ox+r*cos(c*3.1415926/180);
	    pDC->MoveTo(ox,oy);
	    pDC->LineTo(x,y);
	    newpen.DeleteObject();
	    c=c-6;
	    pDC->SelectObject(oldpen);
	    if(c<=-180&&c>=180)
	    {
		     c==180;
	    }
	    CDC *pDC1;
	    CPen newpen1;
	    newpen1.CreatePen(PS_SOLID,1,RGB(0,0,0));
	    pDC1=GetDC();
	    CPen*oldpen1=pDC1->SelectObject(&newpen1);
	    x1=ox+r*sin(c1*3.1415926/180);
	    y1=ox+r*cos(c1*3.1415926/180);
	    pDC1->MoveTo(ox,oy);
	    pDC1->LineTo(x1,y1);
	    newpen1.DeleteObject();
	    pDC->SelectObject(oldpen1);
	    c1=c1-6;
	    if(c1<=-174&&c1>=174)
	    {
		      c1==174;
	    }
	}
    if(nIDEvent==2)
    {
	    int r=70;
	    CDC *pDC2;
	    CPen newpen2;
	    newpen2.CreatePen(PS_SOLID,3,RGB(240,240,240));
	    pDC2=GetDC();
	    CPen*oldpen2=pDC2->SelectObject(&newpen2);
	    x2=ox+r*sin(c2*3.1415926/180);
	    y2=ox+r*cos(c2*3.1415926/180);
	    pDC2->MoveTo(ox,oy);
	    pDC2->LineTo(x2,y2);
	    newpen2.DeleteObject();
	    c2=c2-6;
	    pDC2->SelectObject(oldpen2);
	    if(c2<=-180&&c2>=180)
	    {
		     c2<=180;
	    }
	    CDC *pDC3;
	    CPen newpen3;
	    newpen3.CreatePen(PS_SOLID,3,RGB(0,0,0));
	    pDC3=GetDC();
	    CPen*oldpen3=pDC3->SelectObject(&newpen3);
	    x3=ox+r*sin(c3*3.1415926/180);
	    y3=ox+r*cos(c3*3.1415926/180);
	    pDC3->MoveTo(ox,oy);
	    pDC3->LineTo(x3,y3);
	    newpen3.DeleteObject();
	    c3=c3-6;
	    pDC3->SelectObject(oldpen3);
	    if(c3<=-174&&c3>=174)
	    {
		     c3==174;
	    }
	//CDialogEx::OnTimer(nIDEvent);
	}
    if(nIDEvent==3)
    {
	      int r=50;
	      CDC *pDC4;
	      CPen newpen4;
	      newpen4.CreatePen(PS_SOLID,5,RGB(240,240,240));
	      pDC4=GetDC();
	      CPen*oldpen4=pDC4->SelectObject(&newpen4);
	      x4=ox+r*sin(c4*3.1415926/180);
	      y4=ox+r*cos(c4*3.1415926/180);
	      pDC4->MoveTo(ox,oy);
	      pDC4->LineTo(x4,y4);
	      newpen4.DeleteObject();
	      c4=c4-6;
	      pDC4->SelectObject(oldpen4);
	      if(c4<=-180&&c4>=180)
	      {
		        c4<=180;
	      }
	      CDC *pDC5;
	      CPen newpen5;
	      newpen5.CreatePen(PS_SOLID,5,RGB(0,0,0));
	      pDC5=GetDC();
	      CPen*oldpen5=pDC5->SelectObject(&newpen5);
	      x5=ox+r*sin(c5*3.1415926/180);
	      y5=ox+r*cos(c5*3.1415926/180);
	      pDC5->MoveTo(ox,oy);
	      pDC5->LineTo(x5,y5);
	      newpen5.DeleteObject();
	      c5=c5-6;
	      pDC5->SelectObject(oldpen5);
	      if(c5<=-174&&c5>=174)
	      {
		       c5==174;
	      }
	      CDialogEx::OnTimer(nIDEvent);
	}
}



