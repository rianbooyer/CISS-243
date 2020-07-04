#include "Circle.h"

Circle::Circle()
{
}

Circle::Circle(long cX, long cY, double rad)
{
	centerX = cX;
	centerY = cY;
	radius = rad;
}

Circle::~Circle()
{
}
//accessors
long Circle::getCenterX()
{	return centerX;}

long Circle::getCenterY()
{	return centerY;}

//mutators
void Circle::setCenterY(int cY)
{	centerY = cY;}

void Circle::setCenterX(int cX)
{	centerX = cX;}

//from the virtual function call
void Circle::calcArea()
{	area = pi * radius * radius;}
