#include "InventoryBin.h"
#include <cstdlib>


InventoryBin::InventoryBin()
{
}


InventoryBin::~InventoryBin()
{
	
}

void InventoryBin::setAll(int sn, int ln, std::string md)
{
	serialNum = sn;
	lotNum = ln;
	manufactDate = md;
}
void InventoryBin::setSerialNumber(int sn)
{serialNum = sn;}
void InventoryBin::setLotNum(int ln)
{lotNum = ln;}
void InventoryBin::setManufactDate(std::string md)
{manufactDate = md;}
int InventoryBin::getSerialNumber()
{return serialNum;}

int InventoryBin::getLotNum()
{return lotNum;}
std::string InventoryBin::getManufactDate()
{return manufactDate;}


ostream &operator << (ostream &strm, InventoryBin &obj)
{
	strm << "Lot Number is: " << obj.getLotNum() << endl;
	strm << "Serial Number is: " << obj.getSerialNumber() << endl;
	strm << "Manufacturing date is: " << obj.getManufactDate() << endl;
	return strm;
}