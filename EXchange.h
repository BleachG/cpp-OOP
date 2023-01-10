#pragma once
#include "afxdialogex.h"


// CEXchange 对话框

class CEXchange : public CDialogEx
{
	DECLARE_DYNAMIC(CEXchange)

public:
	CEXchange(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CEXchange();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
		virtual void OnOK();
public:
	CString px;
	CString py;
	CString sx;
	CString sy;
	CString xz;
	CEdit p1;
	CEdit p2;
	CEdit s1;
	CEdit s2;
	CEdit x;
};
