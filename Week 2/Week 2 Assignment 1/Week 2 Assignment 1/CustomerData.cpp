#include "CustomerData.h"
/*This class will be 
a derived class of PersonData. This class will have two private data members 
for the customer number (customerNumber) as an integer; the other will be 
called mailingList which is a bool to indicate if they want to be on the 
mailing list or not. Write appropriate accessor and mutator functions for these 
data members. This class will also have two constructors. It will have a default 
constructor that sets its data members to zero and false. The other constructor 
will have parameters to set all of the data members of the two classes.*/

CustomerData::CustomerData() 
{
	
	customerNumber = 0;
	mailingList = false;
};

//Constructor 2 that sets all the parameters of the data members for both classes
CustomerData::CustomerData(int cn, bool ml, std::string ln, std::string fn, std::string addr, std::string cit, std::string st, std::string zc, std::string pn)
{
	lastName = ln;
	firstName = fn;
	address = addr;
	city = cit;
	state = st;
	zipCode = zc;
	phoneNumber = pn;
	customerNumber = cn;
	mailingList = ml;
}
//default destructor
CustomerData::~CustomerData()
{
	
}

//accessor functions
int CustomerData::getCustomerNumber()
{
	return customerNumber;
}
bool CustomerData::getMailingList()
{
	return mailingList;
}

//mutator functions
void CustomerData::setCustomerNumber(int cn)
{
	customerNumber = cn;
}
void CustomerData::setMailingList(bool ml)
{
	mailingList = ml;
}
