/*
CS 272 -- Lab 1 Class Implementation

Josh Klipstein

DUE:  September 30, 2018

Use the circleType class example from chapter 10 source code as your guide to create the classes for the circle and rectangle calculations.
You can use a single header for declaration and cpp file for implementation of both classes if you would like.
Create a program that displays a menu of options for the user to choose from:

1. Calculate circle area

2. Calculate circle circumference

3. Calculate rectangle area

4. Calculate rectangle perimeter

5. Exit

Under each option, you ask the user for the needed variables such a radius, length, or width, then print out the results.
The menu options continue to display until the user chooses to exit (hint: use a do-while loop).

Extra Credit (10 points): Input error checking at each option
*/

#include <iostream>
#include <cmath>
#include "shapes.h"

using namespace std;

const double PI = 3.1416;  //PI constant

//Functions for circle class

void circle::setRadius(double rad)
{
	
	if (rad >= 0)
		radius = rad;
	else
		radius = 0;

}//end function

double circle::getRadius()
{

	return radius;

}//end function

double circle::getArea()
{
	
	return PI * pow(radius, 2.0);

}//end function

double circle::getCircumference()
{

	return PI * 2 * radius;

}//end function

circle::circle(double rad)
{

	setRadius(rad);

}//end constructor

//Functions for rectangle class
void rectangle::setLengthWidth(double len, double wid)
{
	if (len >= 0 && wid >= 0)
	{
		length = len;
		width = wid;
	}
	else if (len >= 0 && wid < 0)
	{
		length = len;
		width = 0;

	}
	else if (len < 0 && wid >= 0)
	{
		length = 0;
		width = wid;
	}
	else
	{
		length = 0;
		width = 0;
	}//end if
	
}//end function

double rectangle::getLength()
{

	return length;

}//end function


double rectangle::getWidth()
{

	return width;

}//end function


double rectangle::getArea()
{

	return length * width;

}//end function


double rectangle::getPerimeter()
{

	return (2 * length) + (2 * width);

}//end function


rectangle::rectangle(double len, double wid)
{

	setLengthWidth(len, wid);

}//end constructor
