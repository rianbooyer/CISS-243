#ifndef CUTOMERDATA_H
#define CUSTOMERDATA_H
#include "PersonData.h"
/*This class will be
a derived class of PersonData. This class will have two private data members
for the customer number (customerNumber) as an integer; the other will be
called mailingList which is a bool to indicate if they want to be on the
mailing list or not. Write appropriate accessor and mutator functions for these
data members. This class will also have two constructors. It will have a default
constructor that sets its data members to zero and false. The other constructor
will have parameters to set all of the data members of the two classes.*/
class CustomerData : public PersonData
{
private:
	int customerNumber;
	bool mailingList;
public:
	CustomerData();
	CustomerData(int cn, bool ml, std::string ln, std::string fn, std::string addr, std::string cit, std::string st, std::string zc, std::string pn);// :PersonData() {};
	~CustomerData();

	//accessor functions
	int getCustomerNumber();
	bool getMailingList();

	//mutator functions
	void setCustomerNumber(int cn);
	void setMailingList(bool ml);
};
#endif // !CUTOMERDATA_H
