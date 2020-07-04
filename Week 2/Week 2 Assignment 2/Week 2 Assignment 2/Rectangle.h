#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"
/*Define a class called Rectangle. It should be a derived class of the BasicShape 
class. This class will have 2 private data members called width and length. 
Both data members should be long integers. Its constructor will have parameters 
for both the width and length. It will also override the calcArea function. For 
this class the calcArea function will use the formula area = length * width. It 
will provide member function called getWidth and getLength which should return 
the correct values.*/
class Rectangle : public BasicShape
{
private:
	long width;
	long length;

public:
	Rectangle();
	Rectangle(long w, long l);
	~Rectangle();
	//accessors
	long getWidth();
	long getLength();
	//mutators
	void setWidth(long w);
	void setLength(long l);
	//Override function
	virtual void calcArea();
};
#endif
