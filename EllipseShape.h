#pragma once
#include <iostream>
#include "RectangleShape.h"

// Ellipse Class Header 
// Public Inheritance from Rectangle 
using namespace std;

class EllipseShape : public RectangleShape {
private:
	//Enable Serialization
	DECLARE_SERIAL(EllipseShape)
public:
	EllipseShape(); // Defult Constractor
	EllipseShape(CPoint&, CPoint&, COLORREF, COLORREF, int); // Constractor
	virtual void draw(CPaintDC&); // Override Of Figure2D Draw Function 
	virtual bool IsInside(CPoint); // Override Of Figure2D IsInside Function 
	~EllipseShape(); // Distractor
};
