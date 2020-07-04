#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H
#include <iostream>
#include <string>
using namespace std;
/*
EmployeeInfo that holds two private data
members. One data member is an integer called empID which holds the id number of
the employee. The second data member is a string called empName which holds the
full name of the employee.*/
//class EmployeeInfo;
//ostream &operator<< (ostream &, EmployeeInfo &);
class EmployeeInfo
{
private:
	int empID;
	string empName;
public:
	EmployeeInfo();
	EmployeeInfo(int eid, string en);
	~EmployeeInfo()
	{}
	void setAll(int eid, string en);
	
	void setEmpID(int eid)
	{empID = eid;}
	void setEmpName(string en)
	{empName = en;}
	int getEmpID()
	{return empID;}
	string getEmpName()
	{return empName;}

	friend ostream &operator << (ostream &, EmployeeInfo &);
	bool operator < (EmployeeInfo &);
	bool operator > (EmployeeInfo &);
	bool operator == (EmployeeInfo &);
};
#endif
