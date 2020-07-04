/* Programming 243 dea - course project
rian booyer

*/

#include <iostream>
#include "CD.h"
#include "DVD.h"
#include "Media.h"
using namespace std;
//global variables

//predeclare functions
int menu();
void addCD(Linked_List<CD> *);
void addDVD(Linked_List<DVD> *);
void removeCD(Linked_List<CD> *); 
void removeDVD(Linked_List<DVD> *);
void updateCD(Linked_List<CD> *);
void updateDVD(Linked_List<DVD> *);
void displayCDs(Linked_List<CD> *);
void displayDVDs(Linked_List<DVD> *);
void cdPopulate(Linked_List<CD> *);
void cdPopulate2(Linked_List<CD> *);
void dvdPopulate(Linked_List<DVD> *);
void main()
{
	Linked_List<CD> CD_List;
	Linked_List<CD> *CD_List_Ptr;
	CD_List_Ptr = &CD_List;

	Linked_List<DVD> DVD_List;
	Linked_List<DVD> *DVD_List_Ptr;
	DVD_List_Ptr = &DVD_List;
	cdPopulate(&CD_List);
	cdPopulate2(&CD_List);
	dvdPopulate(DVD_List_Ptr);
	displayDVDs(DVD_List_Ptr);
	int menuChoice;
	do
	{
		//system("cls");
		cin.clear();
		menuChoice = menu();

		switch (menuChoice)
		{
		case 1:
			addCD(CD_List_Ptr);
			break;
		case 2:
			addDVD(DVD_List_Ptr);
			break;
		case 3:
			removeCD(&CD_List);
			break;
		case 4:
			removeDVD(DVD_List_Ptr);
			break;
		case 5:
			updateCD(CD_List_Ptr);
			break;
		case 6:
			updateDVD(&DVD_List);
			break;
		case 7:
			displayCDs(CD_List_Ptr);
			break;
		case 8:
			displayDVDs(DVD_List_Ptr);
			break;
		}
	} while (menuChoice != 9);

	
	cout << endl;
	system("pause");
	
}
void cdPopulate(Linked_List<CD> *temp)
{

		CD myCD;
		string str;
		string art = "ac/dc";
		string len = "80 min";
		string slen = "1";
		string title = "Live";
		string songtitle = "thunderstruck";
		string songlength = "3:45";
		myCD.setArtist(art);
		myCD.setLength(len);
		myCD.setTitle(title);
		
		myCD.setSongInstanceTitle(songtitle);
		myCD.setSongInstanceLength(songlength);
		myCD.setSongList();		
		temp->appendNode(myCD);
}
void cdPopulate2(Linked_List<CD> *temp)
{

	CD myCD;
	string str;
	string art = "asdf";
	string len = "80 min";
	string slen = "1";
	string title = "two";
	string songtitle = "thunderstruck";
	string songlength = "3:45";
	myCD.setArtist(art);
	myCD.setLength(len);
	myCD.setTitle(title);
	
	myCD.setSongInstanceTitle(songtitle);
	myCD.setSongInstanceLength(songlength);
	myCD.setSongList();
	temp->appendNode(myCD);
}
void dvdPopulate(Linked_List<DVD> *dvdList)
{
	DVD myDVD;
	string str;
	myDVD.setTitle("Pacific Rim");
	myDVD.setLength("1hh 32min");
	myDVD.setYearReleased("2013");
	myDVD.setActorInstance("bobo");
	myDVD.setCharacterInstance("jypsy danger");
	myDVD.setActorList();

	dvdList->appendNode(myDVD);

}
int menu()
{
	int choice;
	cout << endl;
	cout << "Menu" << endl
		<< "1. Add CD" << endl
		<< "2. Add DVD" << endl
		<< "3. Remove CD" << endl
		<< "4. Remove DVD" << endl
		<< "5. Update CD" << endl
		<< "6. Update DVD" << endl
		<< "7. Display CDs" << endl
		<< "8. Display DVDs" << endl
		<< "9. Quit" << endl;
	cout << "Enter your choice (1-9): ";
	cin >> choice;

	while (choice < 1 || choice > 9)
	{
		cout << "Invalid choice. Reenter (1-9): ";
		cin >> choice;
	}

	return choice;
}

// 1
void addCD(Linked_List<CD> *cdList)
{
	CD myCD;
	string str;
	cin.ignore();

	cout << endl << "Enter CD Artist Name: ";
	getline(cin, str);
	myCD.setArtist(str);

	cout << "Enter CD Length: ";
	cin >> str;
	myCD.setLength(str);

	cin.ignore();
	cout << "Enter CD Album Title: ";
	getline(cin, str);
	myCD.setTitle(str);

	cin.clear();
	char more = 'Y';
	int acc = 0;

	while (toupper(more) == 'Y')
	{
		acc++;
		//cin.ignore();
		cout << "Enter Track " << acc << " Title: ";
		getline(cin, str);
		myCD.setSongInstanceTitle(str);

		cout << "Enter Track " << acc << " Lenth: ";
		getline(cin, str);
		myCD.setSongInstanceLength(str);
		myCD.setSongList();

		cout << "Is there another track? (Y/N): ";
		cin >> more;
	}
	
	cdList->appendNode(myCD);
}

// 2 add dvd
void addDVD(Linked_List<DVD> *dvdList)
{
	DVD myDVD;
	string str;
	cin.ignore();

	cout << endl << "Enter DVD Title: ";
	getline(cin, str);
	myDVD.setTitle(str);

	cout << "Enter Length of Movie: ";
	getline(cin, str);
	myDVD.setLength(str);

	cout << "Enter Year Released: ";
	getline(cin, str);
	myDVD.setYearReleased(str);

	char more = 'Y';
	int acc = 0;

	while (toupper(more) == 'Y')
	{
		acc++;
		cin.ignore();
		cout << "Enter Actor/Actress " << acc << " Name: ";
		getline(cin, str);
		myDVD.setActorInstance(str);

		cout << "Enter Character " << acc << " Name: ";
		getline(cin, str);
		myDVD.setCharacterInstance(str);
		myDVD.setActorList();

		cout << "Is there another actor/actress/character? (Y/N): ";
		cin >> more;
	}

	dvdList->appendNode(myDVD);
}

// 3 remove cd
void removeCD(Linked_List<CD> *cdList)
{
	CD myCD;
	string str;

	cdList->displayList();

	cin.ignore();
	cout << endl << "What CD would you like to remove? ";
	getline(cin, str);
	cout << endl;

	myCD.setTitle(str);

	if (cdList->searchList(myCD) == -1)
		cout << "That CD does not exist in your collection." << endl;
	else
		cdList->deleteNode(myCD);
}

// 4 remove dvd
void removeDVD(Linked_List<DVD> *dvdList)
{
	DVD myDVD;
	string str;

	dvdList->displayList();

	cin.ignore();
	cout << endl << "What DVD would you like to remove? ";
	getline(cin, str);
	cout << endl;

	myDVD.setTitle(str);

	if (dvdList->searchList(myDVD) == -1)
		cout << "That DVD does not exist in your collection." << endl;
	else
		dvdList->deleteNode(myDVD);
}

// 5 update cd
void updateCD(Linked_List<CD> *cdList)
{
	CD oldCD;
	CD newCD;
	CD tempCD;
	string str;

	cdList->displayList();
	cin.ignore();
	cout << endl << "What CD would you like to update? ";
	getline(cin, str);
	cout << endl;

	oldCD.setTitle(str);

	int choice;
	char more = 'Y';
	int acc = 0;

	if (cdList->searchList(oldCD) == -1)
		cout << "That CD does not exist in your collection." << endl;
	else
	{
		string artist, title, length;
		oldCD = cdList->returnItem(oldCD);//sets ALL values from the pointers passed to oldCD
		newCD = cdList->returnItem(oldCD);//stores values of oldCD into newCD
		newCD.setArtist(oldCD.getArtist());//copies artist from old to new cd
		newCD.setTitle(oldCD.getTitle());// copies title from old to new cd
		newCD.setLength(oldCD.getLength());//copies length from old to new cd

		/*The following 3 lines stores the data for when 
		you want to update the tracks to restore the values.*/
		artist =oldCD.getArtist();
		title = oldCD.getTitle();
		length = oldCD.getLength();

		cdList->deleteNode(oldCD);//delete's old cd

		cout << "What would you like to update? " << endl
			<< "1. Artist" << endl
			<< "2. Album" << endl
			<< "3. Length" << endl
			<< "4. Song List" << endl
			<< "Enter 1 - 4: ";
		cin >> choice;
		
		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter the new Artist: ";
			getline(cin, str);
			newCD.setArtist(str);
		}
		else if (choice == 2) 
		{
			cin.ignore();
			cout << "Enter the new Album: ";
			getline(cin, str);
			newCD.setTitle(str);
		}
		else if (choice == 3)
		{
			cin.ignore();
			cout << "Enter the new Length: ";
			getline(cin, str);
			newCD.setLength(str);
		}
		else if (choice == 4)
		{
			/* the following 4 lines clears the data in new cd then restores the artist, title, and length, it clears so when you add
			new tracks it clears the old tracks as well*/
			newCD = cdList->returnItem(tempCD);
				newCD.setArtist(artist);
				newCD.setTitle(title);
				newCD.setLength(length);
			//cin.ignore();
			while (toupper(more) == 'Y')
			{
				
				acc++;
				cin.ignore();
				cout << "Enter Track " << acc << " Title: ";
				getline(cin, str);
				newCD.setSongInstanceTitle(str);

				cout << "Enter Track " << acc << " Lenth: ";
				getline(cin, str);
				newCD.setSongInstanceLength(str);
				newCD.setSongList();

				cout << "Is there another track? (Y/N): ";
				cin >> more;
			}
		}
		cdList->appendNode(newCD);
	}
}

// 6 update dvd
void updateDVD(Linked_List<DVD> *dvdList)
{
	DVD oldDVD;
	DVD newDVD;
	DVD tempDVD;
	string str;

	dvdList->displayList();
	cin.ignore();
	cout << endl << "What DVD would you like to update? ";
	getline(cin, str);
	cout << endl;

	oldDVD.setTitle(str);

	int choice;
	char more = 'Y';
	int acc = 0;

	if (dvdList->searchList(oldDVD) == -1)
		cout << "That DVD does not exist in your collection." << endl;
	else
	{
		string title, yr, length;

		oldDVD = dvdList->returnItem(oldDVD);//copies the values from dvdlist into old dvd
		newDVD = dvdList->returnItem(oldDVD);// copies old dvd thesbians into the new dvd so you don't loose them
		newDVD.setTitle(oldDVD.getTitle());
		newDVD.setYearReleased(oldDVD.getYearReleased());
		newDVD.setLength(oldDVD.getLength());
		/*following stores data like in update cd for later use*/
		title = oldDVD.getTitle();
		yr = oldDVD.getYearReleased();
		length = oldDVD.getLength();
		
		
		dvdList->deleteNode(oldDVD);//delete's old dvd

		cout << "What would you like to update? " << endl
			<< "1. Title" << endl
			<< "2. Length of Movie" << endl
			<< "3. Year Released" << endl
			<< "4. Actors/Actresses/Characters List" << endl
			<< "Enter 1 - 4: ";
		cin >> choice;

		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter the new Title: ";
			getline(cin, str);
			newDVD.setTitle(str);
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter the new Length: ";
			cin >> str;
			newDVD.setLength(str);
			
		}
		else if (choice == 3)
		{
			cin.ignore();
			cout << "Enter the new Year Released: ";
			cin >> str;
			newDVD.setYearReleased(str);
			
		}
		else if (choice == 4)
		{
			newDVD = dvdList->returnItem(tempDVD); //clears values in newDVD (including thesbian list important)

			//following lines restore the values for the title year released and length of movie
			newDVD.setTitle(title);
			newDVD.setYearReleased(yr);
			newDVD.setLength(length);
			cin.ignore();
			while (toupper(more) == 'Y')
			{
				acc++;
				cin.ignore();
				cout << "Enter Actor/Actress " << acc << " Name: ";
				getline(cin, str);
				newDVD.setActorInstance(str);

				cout << "Enter Character " << acc << " Name: ";
				getline(cin, str);
				newDVD.setCharacterInstance(str);
				newDVD.setActorList();

				cout << "Is there another Actor/Actress? (Y/N): ";
				cin >> more;
				
			}
		}
		dvdList->appendNode(newDVD);
	}
}

// 7 display cd
void displayCDs(Linked_List<CD> *cdList)
{
	cdList->displayList();
}

// 8 display dvd
void displayDVDs(Linked_List<DVD> *dvdList)
{
	dvdList->displayList();
}
}
