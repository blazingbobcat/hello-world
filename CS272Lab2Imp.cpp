/*
CS 272 -- Lab 2 Implementation File

Josh Klipstein

DUE:  October 14, 2018

Use the circleType class and rectangleType class from lab#1 and add overloading functions for + and == to use when the user chooses the following menu options:

1. Add the area of 2 circles

(you need to ask the user for the radius of 2 circles, calculate the areas of both and add them using the overloaded +)

2. Add the area of 2 rectangles

(you need to ask the user for length and width of 2 rectangles, calculate the areas of both and add them using the overloaded +)

3. Compare the area of a circle and rectangle

(you need to ask the user for the radius of a circle and length and width of a rectangle, calculate the areas then find out if the areas are equal using the overloaded ==)

4. Exit

You can use a single header for declaration and cpp file for implementation of both classes if you would like.
*/
#include <iostream>
#include <cmath>
#include "shapesOverloaded.h"

using namespace std;

const double PI = 3.1416;  //PI constant

						   //Functions for circle class

void circleType::setRadius(double rad)
{

	if (rad >= 0)
		radius = rad;
	else
		radius = 0;

}//end function

double circleType::getRadius() const
{

	return radius;

}//end function

double circleType::getArea() const
{

	return PI * pow(radius, 2.0);

}//end function

double circleType::getCircumference() const
{

	return PI * 2 * radius;

}//end function

circleType::circleType(double rad)
{

	setRadius(rad);

}//end constructor

double circleType::operator+(const circleType& circle2) const
{
	
	return getArea() + circle2.getArea();

}//end function

bool operator==(const circleType& circle, const rectangleType& rectangle)
{
	
	return (circle.getArea() == rectangle.getArea());

}//end function

 //Functions for rectangle class
void rectangleType::setLengthWidth(double len, double wid)
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

double rectangleType::getLength() const
{

	return length;

}//end function


double rectangleType::getWidth() const
{

	return width;

}//end function


double rectangleType::getArea() const
{

	return length * width;

}//end function


double rectangleType::getPerimeter() const
{

	return (2 * length) + (2 * width);

}//end function


rectangleType::rectangleType(double len, double wid)
{

	setLengthWidth(len, wid);

}//end constructor

double rectangleType::operator+(const rectangleType& rectangle2) const
{

	return getArea() + rectangle2.getArea();

}//end function

