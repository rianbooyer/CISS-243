#ifndef TESTSCORES_H
#define TESTSCORES_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
/* Write a class called TestScores. 
The class constructor should accept an array of test scores as its argument. The class should have a member 
function that returns the average of the test scores. If any test score in the array is negative or greater than 
100, the class should throw an exception. There should be two classes for the exceptions; one should be called NegativeScore 
and other should be TooLargeScore. These exception classes will have a data member that is an integer value called score. This 
data member will be set in the constructor via the parameter. It should also provide a member function called getScore which returns 
score data member. The function in TestScores called getAverages will calculate the average (as a double) of the test scores in 
the array. It will also check if the score is negative or greater than 100. If it is negative it should throw an exception using the 
NegativeScore class. If the score is greater than 100 it should 
throw an excpetion using the TooLargeScore class.*/
class TestScores
{
private:
		double averageScore;
		int arraySize;
		int tempScores;
		vector<int> scoreVector;
public:
		//Exception classes
	class NegativeScore
	{
	private:
		int score;
		 
	public:
		
		NegativeScore(int s) 
		{score = s; }
		~NegativeScore()
		{}
		double getScore()
		{return score;}
	};
	class TooLargeScore
	{
	private: 
		int score;
	public:
		TooLargeScore(int s)
		{score = s;	}
		~TooLargeScore()
		{}
		double getScore()
		{return score;}
	};

	TestScores(int a[],int s);
	~TestScores();
	
	double getAverage();
};

#endif 