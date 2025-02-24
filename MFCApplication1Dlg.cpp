
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Figures Options 
//Tools 
enum function {
	SRectangles = 1, SEllipse, SLine, TSquare, STriangle, SMagenDavid, TMove, Tcolor, TClear
}function; 

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, ColorD); //Declaration Fill Color Control
	CheckRadioButton(IDC_RADIO2, IDC_RADIO7, 0);// Declaration Figures Control
	DDX_Control(pDX, IDC_SPIN1, SpinButton); // Spin Button Control
	DDX_Control(pDX, IDC_EDIT1, EditBox1);// Edit box for size 
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication1Dlg::NewRectangleRadio)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCApplication1Dlg::NewTriengleRadio)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication1Dlg::NewLineRadio)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCApplication1Dlg::NewEllipseRadio)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCApplication1Dlg::NewSquareRadio)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCApplication1Dlg::NewMagenDavidRadio)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnMoveButton)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnSaveButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnLoadButton)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMFCApplication1Dlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnClearDialogButton)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnUndoButton1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFCApplication1Dlg::OnDeltaposSpin1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	//Init
	CDialogEx::OnInitDialog();
	functionType = 0; // Retangle Selected For Start
	isMousePressed = false; 
	// Add "About..." menu item to system menu.

	//  Spin Button init 
	SpinButton.SetRange(0, 100);
	EditBox1.SetWindowText(L"Defult Size 3");

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

// Draw functions
void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++) {
			if (figs[i] != NULL)
				figs[i]->draw(dc); //polomarpism			
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Radio Figures Events Set
//Update according to the figure has been selected

void CMFCApplication1Dlg::NewRectangleRadio()
{
	functionType = SRectangles;
}
void CMFCApplication1Dlg::NewTriengleRadio()
{
	functionType = STriangle;
}
void CMFCApplication1Dlg::NewLineRadio()
{
	functionType = SLine;
}
void CMFCApplication1Dlg::NewSquareRadio()
{
	functionType = TSquare;
}
void CMFCApplication1Dlg::NewMagenDavidRadio()
{
	functionType = SMagenDavid;
}
void CMFCApplication1Dlg::NewEllipseRadio()
{
	functionType = SEllipse;
}

//Mouse Events Handlers Set 

// OnLButtonDown Event Handler
void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isMousePressed = true;
	switch (functionType)
	{
	case SLine:
		figs.Add(new Line(start, start, ColorD.GetColor(), BrushSize));
		break;
	case SEllipse:
		figs.Add(new EllipseShape(start, start, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
		break;
	case SRectangles:
		figs.Add(new RectangleShape(start, start, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
		break;
	case TSquare:
		figs.Add(new Square(start, start, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
		break;
	case STriangle:
		figs.Add(new Triangle(start, start, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
		break;
	case SMagenDavid:
		figs.Add(new MagenDavid(start, start, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
		break;
	case Tcolor:
		figs[i]->setColor(ColorD.GetColor());
		break;
	case TMove:
		for (i = figs.GetSize() - 1; i >= 0; i--) {
			if (figs[i]->IsInside(point)) {
				Move = true;
				movePoint.SetPoint(point.x, point.y);
				moveStart.SetPoint(figs[i]->GetStart().x, figs[i]->GetStart().y);
				moveEnd.SetPoint(figs[i]->GetEnd().x, figs[i]->GetEnd().y);
				CheckRadioButton(IDC_RADIO2, IDC_RADIO7, 0);
				break;
			}
		}
		break;
	default:
		break;
	}	
	CDialogEx::OnLButtonDown(nFlags, point);
}

//OnLButtonUp Event Handler
void CMFCApplication1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{	
	if (isMousePressed)
	{
		end = point;
		isMousePressed = false;
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}

// OnMouseMove Event Handler
void CMFCApplication1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isMousePressed) {
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		switch (functionType)
		{
		case TMove:
			if (Move)
			{
				// Caculate Shape Points 
				int changeX = point.x - movePoint.x;
				int changeY = point.y - movePoint.y;
				figs[i]->GetStart().SetPoint(moveStart.x + changeX, moveStart.y + changeY);
				figs[i]->GetEnd().SetPoint(moveEnd.x + changeX, moveEnd.y + changeY);
			}
			break;
		}
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

//Buttons Events Handler

// OnMoveButton Button Handle
void CMFCApplication1Dlg::OnMoveButton()
{
	functionType = TMove;
}
// OnSaveButton Button Handle
void CMFCApplication1Dlg::OnSaveButton()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar); //polomar...
		ar.Close();
		file.Close();
	}
}

// OnLoadbutton Button Handle
void CMFCApplication1Dlg::OnLoadButton()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}
//OnBnClickedMfccolorbutton1 Color Control Handle
void CMFCApplication1Dlg::OnBnClickedMfccolorbutton1()
{
	functionType = Tcolor;
	CheckRadioButton(IDC_RADIO2, IDC_RADIO7, 0);
}

//OnClearDialogButton Button Handle
void CMFCApplication1Dlg::OnClearDialogButton()
{
	for (int i = figs.GetSize() - 1; i >= 0; i--) {
		figs.RemoveAt(i, 1);
	}
	Invalidate();
}
// OnUndoButton1 Button Handle
void CMFCApplication1Dlg::OnUndoButton1()
{
	if (figs.GetSize() >= 1)
		figs.RemoveAt(figs.GetSize() - 1, 1);
	Invalidate();
}

//OnDeltaposSpin1 Spin Control Handle
void CMFCApplication1Dlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	int CurPos = pNMUpDown->iPos;
	// Convert the value to a string
	BrushSize = CurPos;
	CString str;
	str.Format(L"%d", CurPos);
	// Display the value into the accompanying edit box
	EditBox1.SetWindowText(str);
	*pResult = 0;
}