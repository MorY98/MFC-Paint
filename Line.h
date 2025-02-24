#pragma once
#include <iostream>
#include "Figure2D.h"
using namespace std;

// Line class header 
// Public Inheritance From Figure2D 

class Line : public Figure2D
{
private:
	//Enable Serialization
	DECLARE_SERIAL(Line)
public:
	Line();// Defult Constractor 
	Line(CPoint&, CPoint&, COLORREF, int); // Constractor
	virtual void draw(CPaintDC&);  // Override Of Draw Function 
	~Line(); // Distractor
};

