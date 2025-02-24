#pragma once
// MFCApplication1Dlg.h : header file

//All Classes Headers
#include "RectangleShape.h"
#include "Figure2D.h"
#include "Line.h"
#include "Triangle.h"
#include "EllipseShape.h"
#include "Square.h"
#include "MagenDavid.h"
#include "Quad.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// Standard constructor
	int BrushSize = 3; // Defult size of brush
	CPoint start, end; // Start and end point of figure drawing 
	bool isMousePressed = FALSE, Move = FALSE; // Is mouse or mov button pressed? 
	CTypedPtrArray< CObArray, Figure2D*> figs; //Save shapes
	int functionType; // Which radio is chosen
	CPoint movePoint, moveStart, moveEnd; // Point for move functions 
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void NewRectangleRadio();
	afx_msg void NewTriengleRadio();
	afx_msg void NewLineRadio();
	afx_msg void NewEllipseRadio();
	afx_msg void NewMagenDavidRadio();
	afx_msg void NewSquareRadio();
	afx_msg void OnMoveButton();
	afx_msg void OnSaveButton();
	afx_msg void OnLoadButton();
	int i;
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnClearDialogButton();
	afx_msg void OnUndoButton1();
	CMFCColorButton ColorD, ColorB;
	CSpinButtonCtrl SpinButton;
	CEdit EditBox1;
};
