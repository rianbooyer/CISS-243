#include "EmployeeInfo.h"
#include <cstdlib>
#include <iomanip>


EmployeeInfo::EmployeeInfo()
{
}


EmployeeInfo::EmployeeInfo(int eid, string en)
{
	empID = eid;
	empName = en;
}

void EmployeeInfo::setAll(int eid, string en)
{
	empID = eid;
	empName = en;
}
ostream &operator << (ostream &strm, EmployeeInfo &obj)
{
	strm <<setw(15) << left << "Employee Number: " << obj.getEmpID() << "\tName: " << obj.getEmpName();
	
	return strm;
}
bool EmployeeInfo::operator < (EmployeeInfo &val)
{
	bool temp;
	if (empID < val.empID)
		temp = true;
	else if (empID == val.empID)
		temp = true;
	else
		temp = false;
	return temp;
}

bool EmployeeInfo::operator > (EmployeeInfo &val)
{
	bool temp;
	if (empID > val.empID)
		temp = true;
	else if (empID == val.empID)
		temp = true;
	else
		temp = false;
	return temp;
}
bool EmployeeInfo::operator == (EmployeeInfo &val)
{
	return empID == val.empID;
	/*bool temp;
	if (empID == val.empID)
		temp = true;
	else
		temp = false;
	return temp;
	*/
}


