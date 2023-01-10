
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "计图2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
//	ON_COMMAND(ID_CDC32771, &CMainFrame::OnCdc32771)
//	ON_COMMAND(ID_CDC32772, &CMainFrame::OnCdc32772)
//	ON_COMMAND(ID_CDC32773, &CMainFrame::OnCdc32773)
//	ON_COMMAND(ID_CDC32774, &CMainFrame::OnCdc32774)
//	ON_COMMAND(ID_CDC32775, &CMainFrame::OnCdc32775)
//	ON_COMMAND(ID_CDC32776, &CMainFrame::OnCdc32776)
	ON_COMMAND(ID_32777, &CMainFrame::On32777)
	ON_COMMAND(ID_32779, &CMainFrame::On32779)
	ON_COMMAND(ID_CDC32784, &CMainFrame::OnCdc32784)
	ON_COMMAND(ID_CDC32785, &CMainFrame::OnCdc32785)
	ON_COMMAND(ID_32786, &CMainFrame::On32786)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



//void CMainFrame::OnCdc32771()
//{
	// TODO: 在此添加命令处理程序代码
//	CDC* pDC = GetDC();
//	pDC->SetPixel(100, 100, (0, 0, 0));
//	pDC->MoveTo(50, 50);
//	pDC->LineTo(300, 300);
//}


//void CMainFrame::OnCdc32772()
//{
	// TODO: 在此添加命令处理程序代码
//	CDC* pDC = GetDC();
	//第一个边
//	pDC->MoveTo(50, 50);
//	pDC->LineTo(300, 50);
	//第二个边
//	pDC->MoveTo(50, 50);
//	pDC->LineTo(50, 500);
	//第三个边
//	pDC->MoveTo(50, 500);
//	pDC->LineTo(300, 500);
	//第四个边
//	pDC->MoveTo(300, 500);
//	pDC->LineTo(300, 50);
//}


//void CMainFrame::OnCdc32773()
//{
	// TODO: 在此添加命令处理程序代码
//	CDC* pDC = GetDC();
//	int i;
//	for (i = 50; i < 100; i = i + 5)
//	{//左上角x
	 //左上角y
		//右上角x
		//右上角y
//		pDC->Rectangle(i, i, 200 - i, 200 - i);
//		Sleep(500);
//	}
//}


//void CMainFrame::OnCdc32774()
//{
	// TODO: 在此添加命令处理程序代码
//	CDC* pDC = GetDC();
	//第一个边
//	pDC->MoveTo(200, 200);
//	pDC->LineTo(300, 300);
	//第二个边
//	pDC->MoveTo(200, 200);
//	pDC->LineTo(100, 300);
	//第三个边
//	pDC->MoveTo(100, 300);
//	pDC->LineTo(300, 300);
//}


//void CMainFrame::OnCdc32775()
//{
	// TODO: 在此添加命令处理程序代码
//	CDC* pDC = GetDC();
//	int x = 500;//圆心x坐标
//	int y = 500;//圆心y坐标
//	int r = 100;//半径
//	double w, u, d;
//	int R = 0;
//	int G = 0;
//	int B = 0;
//	w = r;
//	d = w / 255;
	//for循环圆，while循环绘制半径不同的圆
//	while (w >= 0)
//	{
//		for (u = 0; u < 628; u = u + 1)
//		{
//			pDC->SetPixel((int)(x + w * cos(u / 100)), (int)(y + w * sin(u / 100)), RGB(R, G, B));
			//每次循环颜色加深

//		}
//		R++;
//		G++;
//		B++;
		//每次循环半径减小，圆向里面绘制
//		w = w - d;
//	}
//}


//void CMainFrame::OnCdc32776()
//{
	// TODO: 在此添加命令处理程序代码
//	CDC* pDC = GetDC();
	//第一个边
//	pDC->MoveTo(50, 50);
//	pDC->LineTo(300, 50);
	//第二个边
//	pDC->MoveTo(50, 50);
//	pDC->LineTo(50, 300);
	//第三个边
//	pDC->MoveTo(50, 300);
//	pDC->LineTo(300, 300);
	//第四个边
//	pDC->MoveTo(300, 300);
//	pDC->LineTo(300, 50);
//}


void CMainFrame::On32777()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	//定义直线2端和颜色
	int x0 = 100, y0 = 100,
		x1 = 300, y1 = 200, c = RGB(255, 0, 0);
	float x, y, i;
	float dx, dy, k;
	dx = (float)(x1 - x0);
	dy = (float)(y1 - y0);
	k = dy / dx;
	y = y0; x = x0;
	if (abs(k) < 1)
	{
		for (; x <= x1; x++)
		{
			pDC->SetPixel(x, int(y + 0.5), c);
			y = y + k;
		}
	}
	else {
		for (; y <= y1; y++)
		{
			pDC->SetPixel(int(x + 0.5), y, c);
			x = x + 1 / k;
		}
	}
	ReleaseDC(pDC);
}


void CMainFrame::On32779()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int x0 = 250, y0 = 250;
	int x, y, r = 200;
	int c = 0;
	float e, d = 0;
	e = 3 - 2 * r;
	x = 0;
	y = r;
	while (x <= y)
	{
		if (e < 0)
		{
			e = e + 4 * x + 6;
			x++;
		}
		else
		{
			e = e + 4 * (x - y) + 10;
			x++;
			y--;
			pDC->SetPixel(x + x0, y + y0, c);
			pDC->SetPixel(-x + x0, y + y0, c);
			pDC->SetPixel(-x + x0, -y + y0, c);
			pDC->SetPixel(x + x0, -y + y0, c);
			pDC->SetPixel(y + x0, x + y0, c);
			pDC->SetPixel(-y + x0, x + y0, c);
			pDC->SetPixel(-y + x0, -x + y0, c);
			pDC->SetPixel(y + x0, -x + y0, c);
		}
	}
	ReleaseDC(pDC);
}


void CMainFrame::OnCdc32784()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	//绘制海绵主体
	pDC->MoveTo(700, 200);
	pDC->LineTo(1200, 200);
	pDC->MoveTo(700, 200);
	pDC->LineTo(700, 800);
	pDC->MoveTo(700, 800);
	pDC->LineTo(1200, 800);
	pDC->MoveTo(1200, 800);
	pDC->LineTo(1200, 200);
	//绘制头和身体的分界
	pDC->MoveTo(700, 700);
	pDC->LineTo(1200, 700);
	//绘制手脚
	pDC->MoveTo(700, 400);
	pDC->LineTo(400, 600);
	pDC->MoveTo(430, 580);
	pDC->LineTo(420, 550);
	pDC->MoveTo(430, 580);
	pDC->LineTo(420, 610);

	pDC->MoveTo(1200, 400);
	pDC->LineTo(1500, 600);
	pDC->MoveTo(1450, 570);
	pDC->LineTo(1480, 620);
	pDC->MoveTo(1450, 570);
	pDC->LineTo(1480, 550);

	pDC->MoveTo(700, 800);
	pDC->LineTo(700, 1100);
	pDC->MoveTo(700, 1100);
	pDC->LineTo(670, 1130);
	pDC->MoveTo(730, 1130);
	pDC->LineTo(700, 1100);

	pDC->MoveTo(1200, 800);
	pDC->LineTo(1200, 1100);
	pDC->MoveTo(1200, 1100);
	pDC->LineTo(1170, 1130);
	pDC->MoveTo(1200, 1100);
	pDC->LineTo(1230, 1130);




	//填充颜色
	pDC->FillSolidRect(700, 200, 500, 500, RGB(255, 255, 0));
	pDC->FillSolidRect(700, 700, 500, 100, RGB(240, 230, 140));
	//绘制眼睛鼻子嘴巴

	pDC->Ellipse(800, 350, 900, 400);
	pDC->Ellipse(1000, 350, 1100, 400);
	pDC->MoveTo(950, 400);
	pDC->LineTo(850, 500);
	pDC->MoveTo(850, 500);
	pDC->LineTo(950, 500);
	pDC->Pie(850, 550, 1000, 600, 850, 570, 1000, 570);
}


void CMainFrame::OnCdc32785()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int i = 0;

	for (i = 0; i < 450; i = i + 50)
	{
		//建立车身
		pDC->MoveTo(500 - i, 300);
		pDC->LineTo(800 - i, 300);
		pDC->MoveTo(500 - i, 300);
		pDC->LineTo(500 - i, 500);
		pDC->MoveTo(500 - i, 500);
		pDC->LineTo(800 - i, 500);
		pDC->MoveTo(800 - i, 300);
		pDC->LineTo(800 - i, 500);
		//上色
		pDC->FillSolidRect(500 - i, 300, 300, 200, RGB(0, 0, 255));
		//建立车轮
		pDC->Ellipse(500 - i, 500, 600 - i, 600);
		pDC->Ellipse(700 - i, 500, 800 - i, 600);
		Sleep(500);
		CRect rectDlg;
		GetClientRect(rectDlg);
		int pointwidth = rectDlg.Width();
		int pointHeight = rectDlg.Height();
		RedrawWindow(CRect(0, 0, pointwidth, pointHeight));
	}
}
void B(int x, int y, int c1, int c2, CDC* pDC)
{
	long c = pDC->GetPixel(x, y);
	if (c != c1 && c != c2)
	{
		pDC->SetPixel(x, y, c1);
		Sleep(1);
		B(x + 1, y, c1, c2, pDC);
		B(x - 1, y, c1, c2, pDC);
		B(x, y + 1, c1, c2, pDC);
		B(x, y - 1, c1, c2, pDC);
	}
}

void CMainFrame::On32786()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	pDC->Rectangle(20, 50, 120, 150);
	B(80, 60, 15663, 0, pDC);
}
