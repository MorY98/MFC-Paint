#pragma once
#include <iostream>
#include "framework.h"

// Figure2D Class Header 
// Bas Class Of All Shapes
// Public Inheritance From CObject 

using namespace std;

class Figure2D : public CObject {
private:
	CPoint start, end;
	COLORREF brushColor, penColor;
	CPen pen;
	CBrush brush;
	//Enable Serialization
	DECLARE_SERIAL(Figure2D) 
public:
	int BrushSize = 3;
	Figure2D(CPoint&, CPoint&, COLORREF, COLORREF, int); // Constractor
	Figure2D(); // Defult Constractor
	virtual ~Figure2D(); // Distractor
	/* Figure2D Functions - 
	Inherited to all shapes */
	CPoint& GetStart();
	CPoint& GetEnd();
	void SetStart(double x, double y);
	virtual void SetEnd(double x, double y);
	virtual void Redefine(CPoint p1, CPoint p2);
	CBrush& GetBrush();
	CPen& GetPen();
	COLORREF getColor(Figure2D& f) const;
	virtual void setColor(COLORREF);
	COLORREF& MyColor();
	COLORREF& Myborder();
	void setBorder(COLORREF fillColor, int);
	COLORREF getBorder(Figure2D& f) const;
	virtual bool IsInside(CPoint);
	virtual void draw(CPaintDC&);
	virtual void Serialize(CArchive& ar);
};