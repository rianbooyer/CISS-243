/*	Week 3 Assignment 1 - Test Scores
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include "TestScores.h"
using namespace std;

/*Test Scores.   Main will create 
the instance of the TestScores class and catch the exceptions. So it 
needs to handle both exceptions and display the error message with 
the score that is invalid.*/

void main()
{
	const int size = 8;
	int testScores[size] = { 15,8,9,3,10,6,19,2 };
	int testScoresNeg[size] = { -10 };
	int testScoresTooLarge[size] = { 120 };
	TestScores one(testScores,size);
	TestScores two(testScoresNeg, size);
	TestScores three(testScoresTooLarge, size);
	try
	{
		cout << "Testing Array one that has proper scores." << endl;
		cout << "Average of scores is: " << one.getAverage() << endl;
		
	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Score entered is: " << e.getScore() << " score cannot be less than 0." << endl;
		
	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Score entered is: " << e.getScore() << " Score cannot be over 100. " << endl;
		
	}

	try
	{
		cout << endl;
		cout << "Testing Array two that has a number that is Negative" << endl;
		cout << "Average of scores in array two is: " << two.getAverage() << endl;
		
		three.getAverage();
	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Score entered is: " << e.getScore() << " score cannot be less than 0." << endl;

	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Score entered is: " << e.getScore() << " Score cannot be over 100. " << endl;

	}
	try
	{
		cout << endl;
		cout << "Testing Array three that has a number that is too large." << endl;
		cout << "Average of scores in array three is: " << three.getAverage() << endl;
		
		
	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Score entered is: " << e.getScore() << " score cannot be less than 0." << endl;

	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Score entered is: " << e.getScore() << " Score cannot be over 100. " << endl;

	}
	
}