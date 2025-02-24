#include "pch.h"
#include <iostream>
#include "Line.h"
using namespace std;

//Enable Serializtation
IMPLEMENT_SERIAL(Line, CObject, 1)

//Defult Constractor implement
Line::Line() : Figure2D() {}

//Constractor implement
Line::Line(CPoint& start, CPoint& end, COLORREF color, int BrushSize) : Figure2D(start, end, color, color, BrushSize) {}

//Draw Function 
void Line::draw(CPaintDC& dc) {
	dc.SelectObject(this->GetPen());

	//Create Line
	dc.MoveTo(this->GetStart());
	dc.LineTo(this->GetEnd());
}

Line::~Line() {} //Distractor implement