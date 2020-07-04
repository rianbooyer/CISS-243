#ifndef INVENTORYBIN_H
#define INVENTORYBIN_H
#include <string>
#include <iostream>
using namespace std;
class InventoryBin;
ostream &operator<< (ostream &, InventoryBin &);
/*
InventoryBin. This class will have its
class declaration in InventoryBin.h and its implementation in Inventory.cpp.
It will have three private data members, an integer serialNum which holds the
part’s serial number, manufactDate which should be a string that holds the date
the item was manufactured, then lotNum which will be an integer that holds the
part’s lot number.
*/
class InventoryBin
{
private:
	int serialNum, lotNum;
	std::string manufactDate;

public:
	InventoryBin();
	~InventoryBin();
	void setAll(int sn, int ln, std::string md);
	void setSerialNumber(int sn);
	void setLotNum(int ln);
	void setManufactDate(std::string md);
	int getSerialNumber();
	int getLotNum();
	std::string getManufactDate();
	
	friend ostream &operator << (ostream &, InventoryBin &);
};

#endif