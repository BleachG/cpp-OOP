
// 计图2View.cpp: C计图2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "计图2.h"
#endif
#include"opengl.h"
#include "计图2Doc.h"
#include "计图2View.h"
#include "CP2.h"
#include "TarnsForm2.h"
#include"EXchange.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CPoint m_StartPoint;
CPoint m_lastEndPoint;
int flag;

// C计图2View

IMPLEMENT_DYNCREATE(C计图2View, CView)

BEGIN_MESSAGE_MAP(C计图2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32778, &C计图2View::On32778)
	ON_COMMAND(OPENGL, &C计图2View::OnOpengl)
	ON_COMMAND(Exchange, &C计图2View::OnExchange)
END_MESSAGE_MAP()

// C计图2View 构造/析构

C计图2View::C计图2View() noexcept
{
	// TODO: 在此处添加构造代码

}

C计图2View::~C计图2View()
{
}

BOOL C计图2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C计图2View 绘图

void C计图2View::OnDraw(CDC* /*pDC*/)
{
	C计图2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C计图2View 打印

BOOL C计图2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C计图2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C计图2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C计图2View 诊断

#ifdef _DEBUG
void C计图2View::AssertValid() const
{
	CView::AssertValid();
}

void C计图2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C计图2Doc* C计图2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C计图2Doc)));
	return (C计图2Doc*)m_pDocument;
}
#endif //_DEBUG


// C计图2View 消息处理程序


void C计图2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_StartPoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void C计图2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_lastEndPoint = point;
	CDC* pDC = GetDC();
	if (flag == 1)
	{
		int x0 = m_StartPoint.x;
		int y0 = m_StartPoint.y;
		int x1 = m_lastEndPoint.x;
		int y1 = m_lastEndPoint.y;
		int c = RGB(0, 0, 0);
		float a = 0;
		float b = 0;
		float d1 = 0;
		float d2 = 0;
		float d = 0;
		float x = 0;
		float y = 0;
		float m = 0;
		if (x1 < x0)
		{
			d = x0;
			x0 = x1;
			x1 = d;
			d = y0;
			y0 = y1;
			y1 = d;
		}
		a = y0 - y1, b = x1 - x0;
		if (b == 0)
		{
			m = -1 * a * 100;
		}
		else
		{
			m = (float)a / (x0 - x1);
			x = x0, y = y0;
			pDC->SetPixel(x, y, c);
		}
		if (m >= 0 && m <= 1)//斜率大于0小于1
		{
			d = 2 * a + b;
			d1 = 2 * a;
			d2 = 2 * (a + b);
			while (x < x1)
			{
				if (d <= 0)
				{
					x++;
					y++;
					d += d2;
				}
				else
				{
					x++;
					d += d1;
				}
				pDC->SetPixel(x, y, c);
			}
		}
		else if (m <= 0 && m >= -1)//斜率小于0大于负1
		{
			d = 2 * a - b;
			d1 = 2 * a - 2 * b;
			d2 = 2 * a;
			while (x < x1)
			{
				if (d > 0)
				{
					x++;
					y--;
					d += d1;
				}
				else
				{
					x++;
					d += d2;
				}
				pDC->SetPixel(x, y, c);
			}
		}
		else if (m > 1)//斜率大于1
		{
			d = a + 2 * b;
			d1 = 2 * (a + b);
			d2 = 2 * b;
			while (y < y1)
			{
				if (d > 0)
				{
					x++;
					y++;
					d += d1;
				}
				else
				{
					y++;
					d += d2;
				}
				pDC->SetPixel(x, y, c);
			}
		}
		else
		{
			d = a - 2 * b;
			d1 = -2 * b;
			d2 = 2 * (a + b);
			while (y > y1)
			{
				if (d <= 0)
				{
					x++;
					y--;
					d += d2;
				}
				else
				{
					y--;
					d += d1;
				}
				pDC->SetPixel(x, y, c);
			}
		}
	}
	ReleaseDC(pDC); //释放设备指针
	CView::OnLButtonUp(nFlags, point);
}


void C计图2View::On32778()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
}


void C计图2View::OnOpengl()
{
	opengl my;
	my.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void C计图2View::OnExchange()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	CDC* pDC = GetDC();
	CRect rect;//定义客户区矩形
	GetClientRect(&rect);//获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(), -rect.Height());//设置视区范围,x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//客户区中心为原点   
	CEXchange my;
	if (my.DoModal() == IDOK) {
		CPoint P[3] = { CPoint(0,0),CPoint(200,100), CPoint(400,0) };
		pDC->Polygon(P, 3);
		pDC->TextOutW(200, 50, CString("原图形"));
		CP2 pol[3] = { CP2(0 - 400,0),CP2(200 - 400,100), CP2(400 - 400,0) };
		CTransForm2 c1(3, pol);
		c1.Rotate(_wtof(my.xz.GetBuffer()));//旋转
		CPoint pt2[3] = { CPoint(pol[0].x, pol[0].y),CPoint(pol[1].x, pol[1].y), CPoint(pol[2].x, pol[2].y) };
		pDC->Polygon(pt2, 3);
		CP2 pol1[3] = { CP2(0 ,0),CP2(200,100), CP2(400,0) };
		CTransForm2 c11(3, pol1);
		c11.Scale(_wtof(my.sx.GetBuffer()), _wtof(my.sy.GetBuffer()));//缩放
		CPoint pt21[3] = { CPoint(pol1[0].x, pol1[0].y),CPoint(pol1[1].x, pol1[1].y), CPoint(pol1[2].x, pol1[2].y) };
		pDC->Polygon(pt21, 3);
		CP2 pol2[3] = { CP2(0,0),CP2(200,100), CP2(400,0) };
		CTransForm2 c12(3, pol2);
		c12.Translate(_wtof(my.px.GetBuffer()), _wtof(my.py.GetBuffer()));//平移
		CPoint pt22[3] = { CPoint(pol2[0].x, pol2[0].y),CPoint(pol2[1].x, pol2[1].y), CPoint(pol2[2].x, pol2[2].y) };
		pDC->Polygon(pt22, 3);
	}
}
