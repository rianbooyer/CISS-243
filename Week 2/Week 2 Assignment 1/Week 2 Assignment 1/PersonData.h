#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>
/*Create a class called PersonData and it will have its class declaration in 
PersonData.h and its implementation in PersonData.cpp. This class will have 
private data member’s lastName, firstName, address, city, state, zip and 
phone number as strings. Write the appropriate accessor and mutator functions 
for these member variables. It should have two constructors. One constructor 
is a default constructor that sets all of the data members to empty strings. 
A second constructor has parameters for all of its data members.*/
class PersonData
{
	protected:

	std::string lastName, firstName, address, city, state, zipCode, phoneNumber;
public:
	PersonData();
	PersonData(std::string ln,std::string fn, std::string addr, std::string cit,std::string st,std::string zc, std::string pn);
	~PersonData();
	//accessor functions
	std::string getLastName();
	std::string getFirstName();
	std::string getAddress();
	std::string getCity();
	std::string getState();
	std::string getZipCode();
	std::string getPhoneNumber();

	//mutator functions
	void setLastName(std::string ln);
	void setFirstName(std::string fn);
	void setAddress(std::string addr);
	void setCity(std::string cit);
	void setState(std::string st);
	void setZipCode(std::string zc);
	void setPhoneNumber(std::string pn);

};

#endif // !PERSONDATA_H
