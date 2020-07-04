#include "RoomDimension.h"



RoomDimension::RoomDimension()
{
}


RoomDimension::~RoomDimension()
{
}

//int carpetSquareFeet, costSquareFeet, TotalCost
RoomDimension RoomDimension::totalCost(const FeetInches &obj)
{
	carpetSquareFeet = obj.getFeet() + (obj.getInches() / 12);
	TotalCost = carpetSquareFeet * costSquareFeet;
	return *this;
}
void RoomDimension::setCost(int a)
{
	costSquareFeet = a;
}
int RoomDimension::getTotalCost()
{
	return TotalCost;
}