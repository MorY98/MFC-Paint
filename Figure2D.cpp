#include "pch.h"
#include "Figure2D.h"
using namespace std;

//Enable Serializtation
IMPLEMENT_SERIAL(Figure2D, CObject, 1) 

//Constractor implement
Figure2D::Figure2D(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) {
	this->start.x = start.x;
	this->start.y = start.y;
	this->end.x = end.x;
	this->end.y = end.y;
	this->brush.CreateSolidBrush(fillColor);
	this->pen.CreatePen(BS_SOLID, BrushSize, borderColor);
	this->brushColor = fillColor;
	this->penColor = borderColor;
	this->BrushSize = BrushSize;
}

// Defult Constractor implement
Figure2D::Figure2D() {
	this->start.x = 0;
	this->start.y = 0;
	this->end.x = 0;
	this->end.y = 0;
	this->brushColor = RGB(0, 0, 0);
	this->penColor = RGB(0, 0, 0);
	this->BrushSize = 3;
	this->brush.CreateSolidBrush(brushColor);
	this->pen.CreatePen(BS_SOLID, 3, penColor);
}

// GetStart Function (Start Point)
CPoint& Figure2D::GetStart() {
	return this->start;
}

// GetEnd Function (End Point)
CPoint& Figure2D::GetEnd() {
	return this->end;
}

// SetStart Function
void Figure2D::SetStart(double x, double y) {
	this->start.x = x;
	this->start.y = y;
}

// SetEnd Function
void Figure2D::SetEnd(double x, double y) {
	this->end.x = x;
	this->end.y = y;
}

// getColor Function (Brush Color)
COLORREF Figure2D::getColor(Figure2D& f) const {
	LOGBRUSH lb;
	f.brush.GetLogBrush(&lb);
	return lb.lbColor;
}

//setColor Function (fillColor)
void Figure2D::setColor(COLORREF fillColor) {
	this->brush.DeleteObject();
	this->brush.CreateSolidBrush(fillColor);
	this->brushColor = fillColor;
}

// MyColor Function 
COLORREF& Figure2D::MyColor() {
	return this->brushColor;
}

// Myborder Function 
COLORREF& Figure2D::Myborder() {
	return this->penColor;
}

// setBorder Function 
void Figure2D::setBorder(COLORREF BColor, int BrushSize) {
	this->pen.DeleteObject();
	this->pen.CreatePen(BS_SOLID, BrushSize, BColor);
	this->penColor = BColor;
}

//getBorder Function
COLORREF Figure2D::getBorder(Figure2D& f) const {
	LOGPEN lp;
	f.pen.GetLogPen(&lp);
	return lp.lopnColor;
}

//GetBrush Function
CBrush& Figure2D::GetBrush() {
	return this->brush;
}

// GetPen Function
CPen& Figure2D::GetPen() {
	return this->pen;
}

// IsInside Function
bool Figure2D::IsInside(CPoint point) {
	if (this->start.x <= this->end.x) {
		//Left down - > Right up
		if ((point.x >= this->start.x && point.x <= this->end.x) &&
			(point.y >= this->start.y && point.y <= this->end.y))
			return true;

		//left up -> Right Down
		else if ((point.x >= this->start.x && point.x <= this->end.x) &&
			(point.y <= this->start.y && point.y >= this->end.y))
			return true;
	}
	// Right down -> Left Up
	else if (this->start.x >= this->end.x) {
		if ((point.x <= this->start.x && point.x >= this->end.x) &&
			(point.y <= this->start.y && point.y >= this->end.y))
			return true;

		// Right Up - > left Down
		else if ((point.x <= this->start.x && point.x >= this->end.x) &&
			(point.y >= this->start.y && point.y <= this->end.y))
			return true;
	}
	return false;
}
// Draw Function (no override)
void Figure2D::draw(CPaintDC& dc) {}

// Serialize Function 
void Figure2D::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->start;
		ar << this->end;
		ar << this->brushColor;
		ar << this->penColor;
		ar << this->BrushSize;
	}
	else {
		ar >> this->start;
		ar >> this->end;
		ar >> this->brushColor;
		ar >> this->penColor;
		ar >> this->BrushSize;
		this->setBorder(penColor, BrushSize);
		this->setColor(brushColor);
	}
}

// Redefine Function
void Figure2D::Redefine(CPoint p1, CPoint p2)
{
	start = p1; 
	end = p2; 
}

Figure2D::~Figure2D() {} // Distractor implement
