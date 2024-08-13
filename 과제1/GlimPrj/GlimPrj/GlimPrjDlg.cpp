
// GlimPrjDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GlimPrj.h"
#include "GlimPrjDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGlimPrjDlg 대화 상자



CGlimPrjDlg::CGlimPrjDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIMPRJ_DIALOG, pParent)
	, m_nStartX(0)
	, m_nStartY(0)
	, m_nEndX(0)
	, m_nEndY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGlimPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_START_X, m_nStartX);
	DDX_Text(pDX, IDC_START_Y, m_nStartY);
	DDX_Text(pDX, IDC_END_X, m_nEndX);
	DDX_Text(pDX, IDC_END_Y, m_nEndY);
}

BEGIN_MESSAGE_MAP(CGlimPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CGlimPrjDlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CGlimPrjDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CGlimPrjDlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CGlimPrjDlg 메시지 처리기

BOOL CGlimPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGlimPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGlimPrjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGlimPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CGlimPrjDlg::EditControlSetZero()
{

	SetDlgItemInt(IDC_START_X, 0);
	SetDlgItemInt(IDC_START_Y, 0);
	SetDlgItemInt(IDC_END_X, 0);
	SetDlgItemInt(IDC_END_Y, 0);

}

void CGlimPrjDlg::DisplayImage()
{
	CClientDC dc(this);
	m_Image.Draw(dc, 0, 0);
}

bool CGlimPrjDlg::CheckGetPosXY()
{
	UpdateData(TRUE);

	m_nStartX = GetDlgItemInt(IDC_START_X);
	m_nStartY = GetDlgItemInt(IDC_START_Y);
	m_nEndX = GetDlgItemInt(IDC_END_X);
	m_nEndY = GetDlgItemInt(IDC_END_Y);


	if (m_nStartX == m_nEndX && m_nStartY == m_nEndY)
	{
		MessageBox(_T("시작좌표와 종료좌표가 동일합니다.\n다시 입력해주시길 바랍니다."),
			_T("안내 메시지"), MB_ICONASTERISK);

		EditControlSetZero();

		return false;
	}
	else if (m_nStartX >= 601 || m_nStartY >= 601 || m_nEndX >= 601 || m_nEndY >= 601)
	{
		MessageBox(_T("입력 좌표의 범위는 0 ~ 600 사이로 입력해주세요."),
			_T("안내 메시지"), MB_ICONASTERISK);

		EditControlSetZero();

		return false;
	}

	return true;
}


void CGlimPrjDlg::OnBnClickedBtnDraw()
{
	bool bCheckPos = CheckGetPosXY();	// 시작좌표, 종료좌표 멤버변수에 입력되었다면 true

	if (bCheckPos)
	{
		if (m_Image != NULL)
		{
			m_Image.Destroy();
		}

		CRect Rect;
		GetClientRect(&Rect);

		int nWidth = Rect.Width() - 200;
		int nHeight = Rect.Height();
		int nBpp = 8;

		m_Image.Create(nWidth, -nHeight, nBpp);

		if (nBpp == 8)
		{
			static RGBQUAD rgb[256];
			for (int i = 0; i < 256; i++)
			{
				rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			}
			m_Image.SetColorTable(0, 256, rgb);
		}
		unsigned char* fm = (unsigned char*)m_Image.GetBits();

		SYSTEMTIME st;
		GetLocalTime(&st);
		srand((unsigned int)st.wMilliseconds);
		m_nRadius = rand() % 89 + 10;	// 반지름 : 10 ~ 100 사이의 수를 랜덤으로 지정
		MakeCircleImage(fm, m_nStartX, m_nStartY);				// 원 이미지 생성

		DisplayImage();
	}
}



CString CGlimPrjDlg::CheckFolderCreate()
{
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	CString strPath(szPath);
	int nLength = strPath.ReverseFind('\\');
	if (nLength > 0)
		strPath = strPath.Left(nLength);

	CString strFolderPath = strPath + (_T("\\image"));
	if (GetFileAttributes(strFolderPath) == 0xFFFFFFFF)	// 현재 폴더가 없다면 폴더 생성 (0xFFFFFFFF 16진수 -1)
	{
		CreateDirectory(strFolderPath, NULL);
	}

	return strFolderPath;
}


void CGlimPrjDlg::SaveImage(int nX, int nY)
{
	CString strX;
	CString strY;
	CString strRadius;

	strX.Format(_T("%d"), nX);
	strY.Format(_T("%d"), nY);
	strRadius.Format(_T("%d"), m_nRadius);

	CTime cTime = CTime::GetCurrentTime();
	CString strDate;
	strDate.Format(_T("%04d년%02d월%02d일%02d시%02d분%02d초"),
		cTime.GetYear(), cTime.GetMonth(), cTime.GetDay(), cTime.GetHour(), cTime.GetMinute(), cTime.GetSecond());

	CString strFileName = strDate + (_T("-")) + strX + (_T(",")) + strY + (_T(",")) + strRadius;
	CString strPath = CheckFolderCreate();

	m_Image.Save(strPath + (_T("\\")) + strFileName + (_T(".bmp")));
}


bool CGlimPrjDlg::ValidImagePos(int nX, int nY)
{
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();

	CRect Rect(0, 0, nWidth, nHeight);

	return Rect.PtInRect(CPoint(nX, nY));
}


bool CGlimPrjDlg::CheckCircleArea(int nX, int nY, int nCenterX, int nCenterY)
{
	double dDistX = nX - nCenterX;
	double dDistY = nY - nCenterY;
	double dDist = dDistX * dDistX + dDistY * dDistY;

	if (dDist < m_nRadius * m_nRadius)
	{
		return true;
	}

	return false;
}


void CGlimPrjDlg::MakeCircleImage(unsigned char* fm, int nX, int nY)
{
	int nPitch = m_Image.GetPitch();
	int nCenterX = nX + m_nRadius;
	int nCenterY = nY + m_nRadius;
	int nWhite = 0xff;

	for (int j = nY; j < nCenterY * 2; j++)
	{
		for (int i = nX; i < nCenterX * 2; i++)
		{
			if (ValidImagePos(i, j))
			{
				if (CheckCircleArea(i, j, nCenterX, nCenterY))
					fm[j * nPitch + i] = nWhite;
			}
		}
	}

	DisplayImage();

	SetDlgItemInt(IDC_CENTER_X, nCenterX);
	SetDlgItemInt(IDC_CENTER_Y, nCenterY);
	SetDlgItemInt(IDC_CENTER_RADIUS, m_nRadius);

	SaveImage(nX, nY);
}


void CGlimPrjDlg::OnBnClickedBtnAction()
{
	if (m_Image != NULL)
	{
		int nX = m_nStartX;
		int nY = m_nStartY;

		int nWidth = m_Image.GetWidth();
		int nHeight = m_Image.GetHeight();
		int nPitch = m_Image.GetPitch();

		int nBlack = 0000;
		unsigned char* fm = (unsigned char*)m_Image.GetBits();

		while (1)
		{
			memset(fm, nBlack, nWidth * nHeight);
			MakeCircleImage(fm, nX, nY);
			Sleep(10);

			if (nX != m_nEndX)
			{
				(nX > m_nEndX ? --nX : ++nX);
			}
			if (nY != m_nEndY)
			{
				(nY > m_nEndY ? --nY : ++nY);
			}
			if (nX == m_nEndX && nY == m_nEndY)
				break;
		}

		m_Image.Destroy();
		EditControlSetZero();
	}
	else
	{
		MessageBox(_T("[Draw] 버튼을 먼저 눌러주시길 바랍니다."), _T("안내 메시지"), MB_ICONASTERISK);
	}
}



void CGlimPrjDlg::PrintCenterPos(int nCenterX, int nCenterY)
{
	int nBlack = 0000;
	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	for (int j = nCenterY - 4; j < nCenterY + 5; j++)
	{
		for (int i = nCenterX - 4; i < nCenterX + 5; i++)
		{
			int nDif = nCenterY - j;

			if (i == nCenterX - nDif || i == nCenterX + nDif)
				fm[j * nPitch + i] = nBlack;
		}
	}

	DisplayImage();

	CClientDC dc(this);
	CString strCenterXY;
	strCenterXY.Format(_T("(%d, %d)"), nCenterX, nCenterY);
	dc.TextOutW(nCenterX - 30, nCenterY + 20, strCenterXY);
	
}


void CGlimPrjDlg::OnBnClickedBtnOpen()
{
	CString strFilter = _T("Image (*.jpg, *.jpeg, *.bmp)|*.jpg;*.jpeg;*.bmp|");
	CFileDialog filedlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

	CString strPath = CheckFolderCreate();
	filedlg.m_ofn.lpstrInitialDir = strPath;

	if (IDOK == filedlg.DoModal())
	{
		CString strFilePath = filedlg.GetPathName();
		CString strFileName = filedlg.GetFileName();

		if (m_Image != NULL)
		{
			m_Image.Destroy();
		}

		CString strX, strY, strRadius;
		AfxExtractSubString(strFileName, strFileName, 1, '-');
		AfxExtractSubString(strX, strFileName, 0, ',');
		AfxExtractSubString(strY, strFileName, 1, ',');
		AfxExtractSubString(strRadius, strFileName, 2, ',');

		int nRadius = _ttoi(strRadius);
		int nCenterX = _ttoi(strX) + nRadius;
		int nCenterY = _ttoi(strY) + nRadius;

		SetDlgItemInt(IDC_CENTER_X, nCenterX);
		SetDlgItemInt(IDC_CENTER_Y, nCenterY);
		SetDlgItemInt(IDC_CENTER_RADIUS, nRadius);

		m_Image.Load(strFilePath);				// 이미지 불러오기
		PrintCenterPos(nCenterX, nCenterY);		// 중심좌표에 X표시하는 함수

		m_Image.Destroy();
	}
}
