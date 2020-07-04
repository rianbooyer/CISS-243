#ifndef MINMAX_H
#define MINMAX_H	
/*The class will have two data members which have a data type of 
the template. The class will provide two member functions called 
minimum and maximum. The function minimum will determine which 
of the two data members is the lower of the two and return that 
value. The function maximum will determine which of the two data 
members is the larger of the two and return that value.*/
template <class T>
class MinMax
{
private:
	T one;
	T two;

public:
	MinMax(T first, T second)
	{
		one = first;
		two = second;
	}
	~MinMax()
	{}
	T minimum()
	{
		if (one < two)
			return one;
		if (two < one)
			return two;
		// the following fixes an error: warning not all control paths return an error
		else
		{
			cout << "There is no minimum" << endl;
			return 0;
		}
	}
	T maximum()
	{
		if (one > two)
			return one;
		if (two > one)
			return two;
		// the following fixes an error: warning not all control paths return an error
		else 
		{
			cout << "There is no maximum" << endl;
			return 0;
		}
	}
};

#endif
