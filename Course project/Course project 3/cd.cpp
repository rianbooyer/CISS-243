#include "CD.h"
using namespace std;
CD::CD()
{
	head = nullptr;
	artist = "(none)";
	songInstance.songName = "(none)";
	songInstance.songLength = "(none)";
}

void CD::setArtist(string a)
	{ artist = a; }
void CD::setSongInstanceTitle(string t)
	{ songInstance.songName = t; }
void CD::setSongInstanceLength(string len)
	{ songInstance.songLength = len; }
void CD::setSongList()
	{ songList.appendNode(songInstance); }

string CD::getArtist() const
	{ return artist; }
SongInfo CD::getSongInstance() const
	{ return songInstance; }
Linked_List<SongInfo> CD::getSongList() const
{
	return songList;
}


//ostream overloads
ostream &operator << (ostream& strm, const SongInfo &obj)
{	
	strm <<left << setw(40) << "" << left << setw(30) << obj.songName<< left << setw(10) << obj.songLength << endl;
	return strm;
}
ostream &operator << (ostream &strm, const CD &obj)
{
	strm << setw(16) << left << "Artist Name" << setw(16) << left << "Album Title" << setw(8) << left << "Length" << setw(30) << left << "Song  Title" << setw(10) << left << "length" << endl;
	strm << setw(16) << left << "-----------" << setw(16) << left << "-----------" << setw(8) << left << "------" << setw(30) << left << "-----------" << setw(10) << left << "------" << endl;
	strm << left << setw(16) << obj.getArtist() << left << setw(16) << obj.getTitle() << left << setw(8) << obj.getLength() << setw(0) << left << "" << endl;
	strm << obj.getSongList();
	strm << endl;
		
	return strm;
}
ostream &operator << (ostream& strm, const Linked_List<SongInfo> &obj)
{
	obj.displayList();
	return strm;
}
ostream &operator << (ostream& strm, const Linked_List<CD> &obj)
{
	obj.displayList();
	return strm;
}
/*
//bool overloads
bool CD::operator=(string str)
{
	return this->getTitle() == str;
}
bool CD::operator<(const CD &cd)
{
	return this->getTitle() == cd.getTitle();
}
bool CD::operator==(string str)
{
	return this->getTitle() == str;
}
bool CD::operator==(const CD &cd)
{
	return this->getTitle() == cd.getTitle();
}
bool CD::operator!=(const CD &cd)
{
	return this->getTitle() == cd.getTitle();
}
*/