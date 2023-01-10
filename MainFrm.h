
// MainFrm.h: CMainFrame 类的接口
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
//	afx_msg void OnCdc32771();
	afx_msg void OnCdc32772();
//	afx_msg void OnCdc32773();
//	afx_msg void OnCdc32774();
//	afx_msg void OnCdc32775();
//	afx_msg void OnCdc32776();
	afx_msg void On32777();
	afx_msg void On32779();
	afx_msg void OnCdc32784();
	afx_msg void OnCdc32785();
	afx_msg void On32786();
};


