#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(long w, long l)
{
	width = w;
	length = l;
}

Rectangle::~Rectangle()
{
}

//accessors
long Rectangle::getWidth()
{	return width;}
long Rectangle::getLength()
{	return length;}

//mutators
void Rectangle::setWidth(long w)
{	width = w;}
void Rectangle::setLength(long l)
{	length = l;}

//Override function
void Rectangle::calcArea()
{
	area = length * width;
}