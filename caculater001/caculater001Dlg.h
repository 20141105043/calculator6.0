
// caculater001Dlg.h : ͷ�ļ�
//

#pragma once


// Ccaculater001Dlg �Ի���
class Ccaculater001Dlg : public CDialogEx
{
// ����
public:
	Ccaculater001Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CACULATER001_DIALOG };
	CString m_string;
	void SaveValue();
	void Calculator();
	double m_num1;
	double m_num2;
	int flag;
	int c,c1,c2,c3,c4,c5;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedBackspace();
    
    afx_msg void OnClickedClear();
	afx_msg void OnClickedValue();
	
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


