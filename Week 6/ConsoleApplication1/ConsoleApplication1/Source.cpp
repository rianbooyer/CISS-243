#include <iostream>
#include <chrono>
using namespace std;
void numLoop();
int numCrunch(int num);
void main()
{
	//numLoop();
	numCrunch(0);
	cout << clock() << endl;
	system("pause");
}
int numCrunch(int num)
{
	
	if (num == 50)
		return 1;
	else
	{
		system("cls");
		cout << num << endl;
		return numCrunch(num + 1);
	}
}
void numLoop()
{int number = 0;
	do
	{
		system("cls");
		number++;
		cout << number << endl;
	} while (number != 50);
	//cout << clock() << endl;
	//system("pause");

}