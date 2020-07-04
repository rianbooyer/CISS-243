#include "TestScores.h"
#include <iostream>
#include <vector>
using namespace std;
/*The function in TestScores called getAverages will calculate the average(as a double) of the test scores in
the array.It will also check if the score is negative or greater than 100. If it is negative it should throw an exception using the
NegativeScore class.If the score is greater than 100 it should
throw an excpetion using the TooLargeScore class.*/
TestScores::TestScores(int a[],int s)
{
	arraySize = s;
	scoreVector.resize(arraySize);
	for (int count = 0; count < arraySize-1; count++)
	{
		scoreVector[count] = a[count];
	}
		
}

TestScores::~TestScores()
{
}

double TestScores::getAverage()
{
	for (int count = 0; count < arraySize - 1; count++)
	{
		int temp = scoreVector[count];
		if (temp < 0)
			throw NegativeScore(temp);
			
		if (temp > 100)
			throw TooLargeScore(temp);
		else
			tempScores += scoreVector[count];
	}
	averageScore = tempScores / arraySize;
	return averageScore;
}

