/*
CS 272 -- Lab 1

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
#include <iomanip>
#include "shapes.h"

using namespace std;

int main()
{
	char c;	   //menu selection variable
	double r;  //circle radius variable
	double l;  //rectangle length variable
	double w;  //rectangle width variable

	//Create instances of both shapes
	circle i;
	rectangle e;

	//Format output
	cout << fixed << showpoint << setprecision(2);

	//Greet user and print out instructions
	cout << "Welcome to my shapes program!  This program allows you to find the area and circumference of a circle;"
		<< " or the area and \nperimeter of a rectangle." << endl; 

	//Begin main loop
	do
	{
		//Prompt for selection
		cout << "\nPlease select the number of the option you want below:" << endl;
		cout << "1. Calculate circle area\n2. Calculate circle circumference \n3. Calculate recatangle area"
			<<"\n4. Calculate rectangle perimeter" << "\n5. Exit\nYour choice: ";
		cin >> c;
		cout << endl;

		//Check for choice
		switch (c)
		{
		case '1':
			//Prompt for circle radius
			cout << "Enter circle radius: ";
			cin >> r;
			cout << endl;

			//Check for input failure
			if (cin.fail())
				//Print out error message
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Set circle radius
				i.setRadius(r);

				cout << "The radius you entered for the circle is: " << i.getRadius() << "." << endl
					<< "The area is: " << i.getArea() << "." << endl;
			}//end if
			
			break;

		case '2':
			cout << "Enter circle radius: ";
			cin >> r;
			cout << endl;

			if (cin.fail())
				//Print out error message
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				i.setRadius(r);

				cout << "The radius you entered for the circle is: " << i.getRadius() << "." << endl
					<< "The circumference is: " << i.getCircumference() << "." << endl;
			}//end if

			break;

		case '3':
			//Prompt for rectangle length and width
			cout << "Enter rectangle width: ";
			cin >> w;
			cout << endl << "Enter rectangle length: ";
			cin >> l;
			cout << endl;

			if (cin.fail())
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Set rectangle length and width
				e.setLengthWidth(l, w);

				cout << "The length you enter for the rectangle is " << e.getLength() << ", and the width you entered is " << e.getWidth() << endl
					<< "The area is: " << e.getArea() << "." << endl;
			}//end if
			
			break;

		case '4':
			cout << "Enter rectangle width: ";
			cin >> w;
			cout << endl << "Enter rectangle length: ";
			cin >> l;
			cout << endl;

			if (cin.fail())
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Set rectangle length and width
				e.setLengthWidth(l, w);

				cout << "The length you enter for the rectangle is " << e.getLength() << ", and the width you entered is " << e.getWidth() << endl
					<< "The perimeter is: " << e.getPerimeter() << "." << endl;
			}//end if

			break;

		case '5':
			break;

		default:
			cout << "ERROR: Invalid input.  Restarting program..." << endl;

		}//end switch

		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');
	} while (c != '5');

	return 0;
}//end main