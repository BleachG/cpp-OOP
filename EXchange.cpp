// EXchange.cpp: 实现文件
//

#include "pch.h"
#include "计图2.h"
#include "afxdialogex.h"
#include "EXchange.h"


// CEXchange 对话框

IMPLEMENT_DYNAMIC(CEXchange, CDialogEx)

CEXchange::CEXchange(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, px(_T(""))
	, py(_T(""))
	, sx(_T(""))
	, sy(_T(""))
	, xz(_T(""))
{

}

CEXchange::~CEXchange()
{
}

void CEXchange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, px);
	DDX_Text(pDX, IDC_EDIT2, py);
	DDX_Text(pDX, IDC_EDIT3, sx);
	DDX_Text(pDX, IDC_EDIT4, sy);
	DDX_Text(pDX, IDC_EDIT5, xz);
	DDX_Control(pDX, IDC_EDIT1, p1);
	DDX_Control(pDX, IDC_EDIT2, p2);
	DDX_Control(pDX, IDC_EDIT3, s1);
	DDX_Control(pDX, IDC_EDIT4, s2);
	DDX_Control(pDX, IDC_EDIT5, x);
}


BEGIN_MESSAGE_MAP(CEXchange, CDialogEx)
END_MESSAGE_MAP()


// CEXchange 消息处理程序


void CEXchange::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	p1.GetWindowText(px);
	p2.GetWindowText(py);
	s1.GetWindowText(sx);
	s2.GetWindowText(sy);
	x.GetWindowText(xz);
	this->UpdateData(FALSE);

	CDialogEx::OnOK();
}
