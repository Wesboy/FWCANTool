// ECanTestDlg.h : header file
//

#if !defined(AFX_ECANTESTDLG_H__3DCE6D96_0B95_4875_A915_D7FF433C6E07__INCLUDED_)
#define AFX_ECANTESTDLG_H__3DCE6D96_0B95_4875_A915_D7FF433C6E07__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CECanTestDlg dialog


/*
1000
800
666
500
400
250
200
125
100
80
50

*/

#include "EcanVci.h"
#include "afxcmn.h"
#include "Update.h"
#include "CANFilter.h"


class CECanTestDlg : public CDialog
{
// Construction
public:
	CECanTestDlg(CWnd* pParent = NULL);	// standard constructor


	int m_devtype;
	static UINT ReceiveThread(void *param);
	static UINT RecvListShowThread(void *param);
	int m_connect;

	CAN_OBJ m_recvframe[10];
	unsigned int m_recvHigh;
	unsigned int m_recvLow;

	void ShowInfo(CString str, int code);
	int strtodata(unsigned char *str, unsigned char *data,int len,int flag);
	int chartoint(unsigned char chr, unsigned char *cint);

// Dialog Data
	enum { IDD = IDD_ECANTEST_DIALOG };
	CComboBox	m_ComboSendFrmFmt;
	CComboBox	m_ComboSendFrmType;
	CListBox	m_ListInfo;
	CComboBox	m_ComboBaud;
	CComboBox	m_ComboDeviceID;
	CString	m_EditSendData;
	CString	m_EditSendFrmID;
	CTabCtrl m_TabFunc;

	CANFilter m_FilterPager;
	Update m_UpdatePager;

	// ClassWizard generated virtual function overrides
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void InitFunctionTab(void);
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonStartcan();
	afx_msg void OnButtonResetcan();
	afx_msg void OnButtonSend();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabFun(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ECANTESTDLG_H__3DCE6D96_0B95_4875_A915_D7FF433C6E07__INCLUDED_)
