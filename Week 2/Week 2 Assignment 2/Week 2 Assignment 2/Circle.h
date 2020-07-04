#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

/*Define a class called Circle. It should be a derived class of the BasicShape 
class. This class will have 3 private data members. It will have 2 long 
integer data members called centerX and centerY. The last data member is a 
double called radius. It will have a constructor that accepts values for 
centerX, centerY and radius. This constructor should call the overridden 
calcArea function of this class. This class defines its version of the 
calcArea function which determines the area of the circle using the formula 
area = 3.14159 * radius * radius. The class will also provide two functions 
called getCenterX and getCenterY which return the correct values.*/
class Circle : public BasicShape
{
private:
	long centerX, centerY;
	double radius;
	double const pi = 3.14159;

public:
	Circle();
	//constructor that accepts variables as arguments
	Circle(long cX, long cY, double rad);
	~Circle();
	//accessors
	long getCenterX();
	long getCenterY();
	//mutators
	void setCenterX(int cX);
	void setCenterY(int cY);
	
	//Override function
	virtual void calcArea();
};
#endif


