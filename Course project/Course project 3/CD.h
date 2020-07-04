#ifndef CD_H
#define CD_H
#include "Media.h"
#include <string>
#include <iomanip>
using namespace std;

class CD;
struct SongInfo
	{
		string songName;
		string songLength;
		SongInfo *next;
	};


ostream &operator << (ostream&, const CD&);
ostream &operator << (ostream&, const SongInfo&);
ostream &operator << (ostream&, const Linked_List<CD>&);
ostream &operator << (ostream&, const Linked_List<SongInfo>&);


class CD : public Media
{
public:
	//variables
	SongInfo songInstance;
	Linked_List<SongInfo> songList;
	SongInfo *head;
	SongInfo *prev;
	SongInfo *nodePtr;
	
	string artist;
	
	SongInfo getSongInstance() const;
	Linked_List<SongInfo> getSongList() const;

	
	
	CD();
	
	void setArtist(string);
	void setSongInstanceTitle(string);
	void setSongInstanceLength(string);
	void setSongList();
	
	string getArtist() const;

		
	friend ostream &operator << (ostream&, const CD&);
	friend ostream &operator << (ostream&, const SongInfo&);
	friend ostream &operator << (ostream&, const Linked_List<CD>&);
	friend ostream &operator << (ostream&, const Linked_List<SongInfo>&);

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
	//bool operator=(string);
	//bool operator<(const CD &);
	//bool operator==(string);
	//bool operator==(const CD &);
	//bool operator!=(const CD &);
		
#endif