#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H
#include "feetInches.h"
/*Next create a class called RoomCarpet class that has a RoomDimension 
object as an attribute. This class will have its class declaration in 
RoomCarpet.h and its implementation in RoomCarpet.cpp.  It should also 
have an attribute for the cost of the carpet per square foot. It will 
have a member function that returns the total cost of the carpet. For 
example, a room that is 12 feet long and 10 feet wide has an area of 
120 square feet. If the cost per square foot is $8 then the cost to 
carpet the room will be $960 (120 x 8).
*/
class RoomDimension
{
private:
	int carpetSquareFeet, costSquareFeet, TotalCost;
public:
	RoomDimension();
	~RoomDimension();
	RoomDimension totalCost(const FeetInches &obj);
	void setCost(int a);
	int getTotalCost();
};
#endif
