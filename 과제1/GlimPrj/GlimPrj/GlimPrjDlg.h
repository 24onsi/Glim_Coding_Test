
// GlimPrjDlg.h: 헤더 파일
//

#pragma once

// CGlimPrjDlg 대화 상자
class CGlimPrjDlg : public CDialogEx
{
// 생성입니다.
private:
	CImage m_Image;
	int m_nStartX;
	int m_nStartY;
	int m_nEndX;
	int m_nEndY;
	int m_nRadius;

public:
	CGlimPrjDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIMPRJ_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();


	
public:
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();
	void MakeCircleImage(unsigned char* fm, int nX, int nY);
	void DisplayImage();
	bool CheckCircleArea(int nX, int nY, int nCenterX, int nCenterY);
	bool ValidImagePos(int nX, int nY);
	bool CheckGetPosXY();
	void SaveImage(int nX, int nY);
	void PrintCenterPos(int nCenterX, int nCenterY);
	CString CheckFolderCreate();
	void EditControlSetZero();

};
