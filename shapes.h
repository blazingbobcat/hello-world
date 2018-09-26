#pragma once
/*
CS 272 -- Lab 1 Header File

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

//Our circle class
class circle
{
private:
	double radius; //our radius

public:
	void setRadius(double rad);
	//Function to set radius
	//Postcondition:  set radius to 'radius', or if no
	//radius is given, set it to zero.

	double getRadius();
	//Function to retrieve radius of circle
	//Postcondition:  returns radius

	double getArea();
	//Function to calculate and return area of circle based on radius
	//Postcondition:  returns area of circle

	double getCircumference();
	//Function to calculate and return circumference on circle off of radius
	//Postcondition:  returns circumference of circle

	circle(double rad = 0);
	//Constructor for circle class
	//Sets radius of circle to parameter or zero if no parameter is given
	//Postcondition:  radius of circle is 0.0 or 'radius'

};//end class

//Our rectangle class
class rectangle
{
private:
	double length;  //our length
	double width;  //our width

public:
	void setLengthWidth(double len, double wid);
	//Function to set the length and width of a rectangle
	//Postcondition:  set length and width to parameters given

	double getLength();
	//Function to retrieve length of rectangle
	//Postcondition:  returns length of rectangle

	double getWidth();
	//Function to retrieve width of rectangle
	//Postcondition:  returns width of rectangle

	double getArea();
	//Function to calculate and return area of rectangle
	//Postcondition:  returns area of rectangle

	double getPerimeter();
	//Function to calculate and return perimeter of rectangle
	//Postcondition:  returns perimeter of rectangle

	rectangle(double len = 0, double wid = 0);
	//Constructor of rectange class
	//Sets length and width to given parameters, or both to zero if no parameters are given
	//Postcondition:  length set to 0.0 or 'length' and width set to 0.0 or 'width'

};//end class