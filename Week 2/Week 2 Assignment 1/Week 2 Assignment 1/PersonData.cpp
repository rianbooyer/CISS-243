#include "PersonData.h"
/*Create a class called PersonData and it will have its class declaration in 
PersonData.h and its implementation in PersonData.cpp. This class will have 
private data member’s lastName, firstName, address, city, state, zip and 
phone number as strings. Write the appropriate accessor and mutator functions 
for these member variables. It should have two constructors. One constructor 
is a default constructor that sets all of the data members to empty strings. 
A second constructor has parameters for all of its data members.*/

//default constructor
PersonData::PersonData()
{
	lastName = "";
	firstName = "";
	address = "";
	city = "";
	state = "";
	zipCode = "";
	phoneNumber = "";
}
// following is constructor number two that accepts arguments for all variables 
PersonData::PersonData(std::string ln, std::string fn, std::string addr, std::string cit, std::string st, std::string zc, std::string pn)
{
	lastName = ln;
	firstName = fn;
	address = addr;
	city = cit;
	state = st;
	zipCode = zc;
	phoneNumber = pn;
}


PersonData::~PersonData()
{
	
}

//accessor functions
std::string PersonData::getLastName()
{	return lastName;}
std::string PersonData::getFirstName()
{	return firstName;}
std::string PersonData::getAddress()
{	return address;}
std::string PersonData::getCity()
{	return city;}
std::string PersonData::getState()
{	return state;}
std::string PersonData::getZipCode()
{	return zipCode;}
std::string PersonData::getPhoneNumber()
{	return phoneNumber;}

//mutator functions
void PersonData::setLastName(std::string ln)
{	lastName = ln;}
void PersonData::setFirstName(std::string fn)
{	firstName = fn;}
void PersonData::setAddress(std::string addr)
{	address = addr;}
void PersonData::setCity(std::string cit)
{	city = cit;}
void PersonData::setState(std::string st)
{	state = st;}
void PersonData::setZipCode(std::string zc)
{	zipCode = zc;}
void PersonData::setPhoneNumber(std::string pn)
{	phoneNumber = pn;}