/*	Week 6 Assignment 2 - addition recursion
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
using namespace std;

/*
Write a function that accepts an integer argument and returns 
the sum of all the integers from 1 up to the number passed as 
an argument. For example if 10 is passed as an argument, the 
function will return the sum of 1,2,3,4,5,6,7,8,9 and 10. Use 
recursion to calculate the sum. Show that this function works 
correctly for several values.*/
//global variables

//predefine functions
int addBack(int num);
void main()
{
	cout << "Summing numbers up to 10 inclusive: " << addBack(10) << endl;
	cout << "Summing numbers up to 100 inclusive: " << addBack(100) << endl;
	cout << "Summing numbers up to 1000 inclusive: " << addBack(1000) << endl;
	cout << endl;
	cout << "Summing numbers up to 20 inclusive: " << addBack(20) << endl;
	cout << "Summing numbers up to 200 inclusive: " << addBack(200) << endl;
	cout << "Summing numbers up to 2000 inclusive: " << addBack(2000) << endl;
	cout << endl;
	cout << "Summing numbers up to 30 inclusive: " << addBack(30) << endl;
	cout << "Summing numbers up to 300 inclusive: " << addBack(300) << endl;
	cout << "Summing numbers up to 3000 inclusive: " << addBack(3000) << endl;
	cout << endl;
	cout << "Summing numbers up to 40 inclusive: " << addBack(40) << endl;
	cout << "Summing numbers up to 400 inclusive: " << addBack(400) << endl;
	cout << "Summing numbers up to 4000 inclusive: " << addBack(4000) << endl;

}
int addBack(int num)
{
	if (num == 1)
		return 1;
	else
	{
		return num + addBack(num - 1);
	}
}