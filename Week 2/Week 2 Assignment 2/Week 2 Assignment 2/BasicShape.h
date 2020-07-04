#ifndef BASICSHAPE_H
#define BASICSHAPE_H	

/*Define a class called BasicShape
which will be a pure abstract class. The class will have one protected
data member that will be a double called area. It will provide a 
function called getArea which should return the value of the data member
area. It will also provide a function called calcArea which must be a 
pure virtual function.*/
class BasicShape
{
protected:
	double area;
public:
	BasicShape();
	~BasicShape();

	double getArea();
	virtual void calcArea() = 0;
};
#endif

