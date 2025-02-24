#include "pch.h"
#include "MagenDavid.h"
#include <iostream>
#include <cmath>
using namespace std;

//Enable Serializtation
IMPLEMENT_SERIAL(MagenDavid, CObject, 1)

// Defult Constractor implement
MagenDavid::MagenDavid() : Figure2D() {}

// Constractor implemen
MagenDavid::MagenDavid(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) : Figure2D(start, end, fillColor, borderColor, BrushSize) {}

//Draw Function
void MagenDavid::draw(CPaintDC& dc) {
	dc.SelectObject(this->GetPen());
	dc.SelectObject(this->GetBrush());
	center = this->GetStart() + this->GetEnd();
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(this->GetStart().x - this->GetEnd().x) < abs(this->GetStart().y
		- this->GetEnd().y) ? abs(this->GetStart().x - this->GetEnd().x) / 2.0 : abs(this->GetStart().y - this->GetEnd().y) / 2.0;
	double two_pi = atan(1) * 8;
	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			vertices[i].x = center.x + radius / sqrt(3) * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius / sqrt(3) * sin(two_pi / 12 * i);
		}
		else
		{
			vertices[i].x = center.x + radius * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius * sin(two_pi / 12 * i);
		}
	}
	dc.Polygon(vertices, 12);
}

//Serialize Function
void MagenDavid::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << this->GetStart();
		ar << this->GetEnd();
		ar << this->center;
		ar << this->vertices[0];
		ar << this->vertices[1];
		ar << this->vertices[2];
		ar << this->vertices[3];
		ar << this->vertices[4];
		ar << this->vertices[5];
		ar << this->vertices[6];
		ar << this->vertices[7];
		ar << this->vertices[8];
		ar << this->vertices[9];
		ar << this->vertices[10];
		ar << this->vertices[11];
		ar << this->MyColor();
		ar << this->Myborder();
		ar << this->BrushSize;
	}
	else // Loading, not storing
	{
		ar >> this->GetStart();
		ar >> this->GetEnd();
		ar >> this->center;
		ar >> this->vertices[0];
		ar >> this->vertices[1];
		ar >> this->vertices[2];
		ar >> this->vertices[3];
		ar >> this->vertices[4];
		ar >> this->vertices[5];
		ar >> this->vertices[6];
		ar >> this->vertices[7];
		ar >> this->vertices[8];
		ar >> this->vertices[9];
		ar >> this->vertices[10];
		ar >> this->vertices[11];
		ar >> this->MyColor();
		ar >> this->Myborder();
		ar >> this->BrushSize;
		this->setBorder(Myborder(), BrushSize);
		this->setColor(this->MyColor());
	}
}
MagenDavid::~MagenDavid() {} //Distractor
