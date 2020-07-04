#include "DVD.h"

DVD::DVD()
{
	yearReleased = ("none");
	actorInstance.actor = "(none)";
	actorInstance.character = "(none)";
}


void DVD::setYearReleased(string y)
	{ yearReleased = y; }
void DVD::setActorInstance(string a)
	{ actorInstance.actor = a; }
void DVD::setCharacterInstance(string c)
	{ actorInstance.character = c; }
void DVD::setActorList()
	{ actorsList.appendNode(actorInstance); }



string DVD::getYearReleased() const
	{ return yearReleased; }
DVDActors DVD::getActorsInstance() const
	{ return actorInstance; }
Linked_List<DVDActors> DVD::getActorsList() const
	{ return actorsList; }



ostream &operator << (ostream& strm, const DVDActors &obj)
{
	strm << left << setw(20) << "" << left << setw(20) << "" << left << setw(14) << "" << setw(20) << left << obj.actor << setw(20) << left << obj.character << endl;
	return strm;
}
ostream &operator << (ostream &strm, const DVD &obj)
{
	strm << setw(20) << left << "Movie Title" << setw(20) << left << "Length Of Movie" << setw(14) << left << "Year Released" << setw(20) << left << "Thesbian" << setw(20) << left << "Characters" << endl;
	strm << setw(20) << left << "-----------" << setw(20) << left << "---------------" << setw(14) << left << "-------------" << setw(20) << left << "--------" << setw(20) << left << "----------" << endl;
	strm << left << setw(20) << obj.getTitle() << left << setw(20) << obj.getLength() << left << setw(14) << obj.getYearReleased() << setw(0) << left << "" << endl;
	strm << obj.getActorsList();
	strm << endl;

	return strm;
}
ostream &operator << (ostream& strm, const Linked_List<DVDActors> &obj)
{
	obj.displayList();
	return strm;
}
ostream &operator << (ostream& strm, const Linked_List<DVD> &obj)
{
	obj.displayList();
	return strm;
}

bool DVD::operator=(string str)
{
	return this->getTitle() == str;
}
bool DVD::operator==(string str)
{
	return this->getTitle() == str;
}
bool DVD::operator==(const DVD &dvd)
{
	return this->getTitle() == dvd.getTitle();
}
bool DVD::operator!=(const DVD &dvd)
{
	return this->getTitle() == dvd.getTitle();
}