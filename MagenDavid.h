#include "Figure2D.h"

// MagenDavid class header 
// Public Inheritance From Figure2D 

class MagenDavid : public Figure2D {
private:
	CPoint vertices[12]; // An array of vertices
	CPoint center; // Center Point
	//Enable Serialization
	DECLARE_SERIAL(MagenDavid)
public:
	MagenDavid(); // Defult Constractor
	MagenDavid(CPoint&, CPoint&, COLORREF, COLORREF, int); //Constractor
	virtual void draw(CPaintDC&); // Override Of Draw Function 
	virtual void Serialize(CArchive& ar); // Override Of Serialize Function 
	~MagenDavid(); // Distractor
};
