
// 计图2View.h: C计图2View 类的接口
//

#pragma once


class C计图2View : public CView
{
protected: // 仅从序列化创建
	C计图2View() noexcept;
	DECLARE_DYNCREATE(C计图2View)

// 特性
public:
	C计图2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C计图2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32778();
	afx_msg void OnOpengl();
	afx_msg void OnExchange();
};

#ifndef _DEBUG  // 计图2View.cpp 中的调试版本
inline C计图2Doc* C计图2View::GetDocument() const
   { return reinterpret_cast<C计图2Doc*>(m_pDocument); }
#endif

