// Specification file for the FeetInches class
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const FeetInches &);
istream &operator >> (istream &, FeetInches &);

// The FeetInches class holds distances or measurements 
// expressed in feet and inches.
/*Modify the FeetInches class by overloading 
the following operators which should all return a bool.
<=
>=
!=
Next add a copy constructor to the FeetInches class and a multiply function.

The copy constructor should accept a FeetInches object as an 
argument. It will assign the feet attribute the value in the 
argument’s feet attribute and do the same for the inches attributes.

The multiply function should accept a FeetInches object as an 
argument. The argument object’s feet and inches attributes will 
be multiplied by the calling object’s feet and inches attributes. 
It will return a FeetInches object containing the result of the 
multiplication.*/
class FeetInches
{
private:
   int feet;        // To hold a number of feet
   int inches;      // To hold a number of inches
   void simplify(); // Defined in FeetInches.cpp
public:
   // Constructor
   FeetInches(int f = 0, int i = 0)
      { feet = f;
        inches = i;
        simplify(); }
   
   // Mutator functions
   void setFeet(int f)
      { feet = f; }

   void setInches(int i)
      { inches = i;
        simplify(); }
   
   // Accessor functions
   int getFeet() const
      { return feet; }

   int getInches() const
      { return inches; }

   // Overloaded operator functions
   FeetInches operator + (const FeetInches &);
   FeetInches operator - (const FeetInches &);
   FeetInches operator ++ ();    // Prefix ++
   FeetInches operator ++ (int); // Postfix ++
   bool operator > (const FeetInches &);
   bool operator < (const FeetInches &);
   bool operator == (const FeetInches &);
   
   //added per instructions
   //overload operators
   bool operator <= (const FeetInches &);
   bool operator >= (const FeetInches &);
   bool operator != (const FeetInches &);
   // copy constructors
   /*The copy constructor should accept a FeetInches object as an 
argument. It will assign the feet attribute the value in the 
argument’s feet attribute and do the same for the inches attributes.*/
   FeetInches(FeetInches &obj)
   {
	   feet = obj.getFeet();
	   inches = obj.getInches();
   }
   //multiply function
   /*The multiply function should accept a FeetInches object as an 
argument. The argument object’s feet and inches attributes will 
be multiplied by the calling object’s feet and inches attributes. 
It will return a FeetInches object containing the result of the 
multiplication.*/
   FeetInches multiply(const FeetInches &obj);
  
   // Conversion functions
   operator double();
   operator int();
   
   // Friends
   friend ostream &operator << (ostream &, const FeetInches &);
   friend istream &operator >> (istream &, FeetInches &);
};

#endif