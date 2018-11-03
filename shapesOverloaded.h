#pragma once
/*
CS 272 -- Lab 2 Header File

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

class rectangleType;  //Declare rectangleType before comparing

//Our circle class
class circleType
{
	friend bool operator==(const circleType&, const rectangleType&);  //Function to overload == operator
																	  //to compare areas of circle and rectangle
private:
	double radius; //our radius

public:
	double operator+(const circleType&) const;	 //Function to overload + operator for class circleType

	void setRadius(double rad);
	//Function to set radius
	//Postcondition:  set radius to 'radius', or if no
	//radius is given, set it to zero.

	double getRadius() const;
	//Function to retrieve radius of circle
	//Postcondition:  returns radius

	double getArea() const;
	//Function to calculate and return area of circle based on radius
	//Postcondition:  returns area of circle

	double getCircumference() const;
	//Function to calculate and return circumference on circle off of radius
	//Postcondition:  returns circumference of circle

	circleType(double rad = 0);
	//Constructor for circle class
	//Sets radius of circle to parameter or zero if no parameter is given
	//Postcondition:  radius of circle is 0.0 or 'radius'

};//end class

  //Our rectangle class
class rectangleType
{
private:
	double length;  //our length
	double width;  //our width

public:
	double operator+(const rectangleType&) const;  //Function to overload + operator for rectangleType

	void setLengthWidth(double len, double wid);
	//Function to set the length and width of a rectangle
	//Postcondition:  set length and width to parameters given

	double getLength() const;
	//Function to retrieve length of rectangle
	//Postcondition:  returns length of rectangle

	double getWidth() const;
	//Function to retrieve width of rectangle
	//Postcondition:  returns width of rectangle

	double getArea() const;
	//Function to calculate and return area of rectangle
	//Postcondition:  returns area of rectangle

	double getPerimeter() const;
	//Function to calculate and return perimeter of rectangle
	//Postcondition:  returns perimeter of rectangle

	rectangleType(double len = 0, double wid = 0);
	//Constructor of rectange class
	//Sets length and width to given parameters, or both to zero if no parameters are given
	//Postcondition:  length set to 0.0 or 'length' and width set to 0.0 or 'width'

};//end class