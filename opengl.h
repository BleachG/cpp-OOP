#pragma once
#include "afxdialogex.h"


// opengl 对话框

class opengl : public CDialogEx
{
	DECLARE_DYNAMIC(opengl)

public:
	opengl(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~opengl();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnOpengl();
	virtual BOOL OnInitDialog();
};
