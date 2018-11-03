/*
CS 272 -- Lab 2

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
#include <iomanip>
#include "shapesOverloaded.h"

using namespace std;

int main()
{
	char c;	   //menu selection variable
	double r1, r2;  //circles' radii variables
	double l1, l2;  //rectangles' length variables
	double w1, w2;  //rectangles' width variables

	//Create instances of both shapes
	circleType circle1, circle2;
	rectangleType rectangle1, rectangle2;

	//Format output
	cout << fixed << showpoint << setprecision(4);

	//Greet user and print out instructions
	cout << "Welcome to my enahnced shapes program!  This program allows you to find the area and circumference of a circle;"
		<< " or the area and \nperimeter of a rectangle.  It will also allow you to compare areas of a rectangle and circle; or" 
		<< "add the areas of two rectangles or two circles." << endl;

	//Begin main loop
	do
	{
		//Prompt for selection
		cout << "\nPlease select the number of the option you want below:" << endl;
		cout << "1. Calculate circle area\n2. Calculate circle circumference \n3. Calculate recatangle area"
			<< "\n4. Calculate rectangle perimeter" << "\n5. Add the areas of two circles\n6. Add the areas of two rectangles"
			<< "\n7. Compare the areas of a rectangle and circle\n8. Exit\nYour choice: ";
		cin >> c;
		cout << endl;

		//Check for choice
		switch (c)
		{
		case '1':
			//Prompt for circle radius
			cout << "Enter circle radius: ";
			cin >> r1;
			cout << endl;

			//Check for input failure
			if (cin.fail())
				//Print out error message
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Set circle radius
				circle1.setRadius(r1);

				cout << "The radius you entered for the circle is: " << circle1.getRadius() << "." << endl
					<< "The area is: " << circle1.getArea() << "." << endl;
			}//end if

			break;

		case '2':
			cout << "Enter circle radius: ";
			cin >> r1;
			cout << endl;

			if (cin.fail())
				//Print out error message
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				circle1.setRadius(r1);

				cout << "The radius you entered for the circle is: " << circle1.getRadius() << "." << endl
					<< "The circumference is: " << circle1.getCircumference() << "." << endl;
			}//end if

			break;

		case '3':
			//Prompt for rectangle length and width
			cout << "Enter rectangle width: ";
			cin >> w1;
			cout << endl << "Enter rectangle length: ";
			cin >> l1;
			cout << endl;

			if (cin.fail())
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Set rectangle length and width
				rectangle1.setLengthWidth(l1, w1);

				cout << "The length you enter for the rectangle is " << rectangle1.getLength() << ", and the width you entered is " 
					<< rectangle1.getWidth() << endl << "The area is: " << rectangle1.getArea() << "." << endl;
			}//end if

			break;

		case '4':
			cout << "Enter rectangle width: ";
			cin >> w1;
			cout << endl << "Enter rectangle length: ";
			cin >> l1;
			cout << endl;

			if (cin.fail())
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Set rectangle length and width
				rectangle1.setLengthWidth(l1, w1);

				cout << "The length you enter for the rectangle is " << rectangle1.getLength() << ", and the width you entered is " 
					<< rectangle1.getWidth() << endl << "The perimeter is: " << rectangle1.getPerimeter() << "." << endl;
			}//end if

			break;

		case '5':
			//Prompt for first radius
			cout << "Enter circle one's radius: ";
			cin >> r1;
			if (cin.fail())
				//Check if user entered something strange for first radius
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Prompt for second radius
				cout << endl << "Enter circle two's radius: ";
				cin >> r2;
				if (cin.fail())
					//Check if user entered something strange for second radius
					cout << "ERROR: Invalid input.  Restarting program..." << endl;
				else
				{
					cout << endl;
					//Set circle radii
					circle1.setRadius(r1);
					circle2.setRadius(r2);

					//Get the areas of the two circles, add them together, and then output the result
					cout << "The radius you entered for circle one is " << r1 << ".  The radius you enter for circle two is "
						<< r2 << ".  The area of circle one is " << circle1.getArea() << ".  The area of circle 2 is "
						<< circle2.getArea() << ".  And the sum of their areas is " << circle1 + circle2 << "." << endl;
				}//end if 2
			}//end if 1
			
			break;
		case '6':
			//Prompt for first rectangle's length
			cout << "Enter rectangle one's length: ";
			cin >> l1;
			if (cin.fail())
				//Check if user entered a wierd input, and continue checking for all inputs
				cout << "ERROR: Invalid input.  Restarting program..." << endl;
			else
			{
				//Prompt for first rectangle width
				cout << endl << "Enter rectangle one's width: ";
				cin >> w1;
				if (cin.fail())
					cout << "ERROR: Invalid input.  Restarting program..." << endl;
				else
				{
					//Prompt for second rectangle length
					cout << "Enter rectangle two's length: ";
					cin >> l2;
					if (cin.fail())
						cout << "ERROR: Invalid input.  Restarting program..." << endl;
					else
					{
						//Prompt for second rectangle width
						cout << endl << "Enter rectangle two's width: ";
						cin >> w2;
						if (cin.fail())
							cout << "ERROR: Invalid input.  Restarting program..." << endl;
						else
						{
							cout << endl;
							//Set rectangles' lengths and widths
							rectangle1.setLengthWidth(l1, w1);
							rectangle2.setLengthWidth(l2, w2);

							//Get the areas of the two circles, add them together, and then output the result
							cout << "The length you entered for rectangle one is " << l1 << ", and the width is " << w1
								<< ".  The area of rectangle one is " << rectangle1.getArea() << ".  The length you entered for"
								<< " rectangle two is " << l2 << ", and the width you entered is " << w2 << ".  The area of rectangle"
								<< " two is " << rectangle2.getArea() << ".  The sum of their areas then is " << rectangle1 + rectangle2
								<< "." << endl;
						}//end if 4
					}//end if 3
				}//end if 2
			}//end if 1
			
			break;
		case '7':
			//Prompt first for circle radius
			cout << "Enter the circle's radius: ";
			cin >> r1;
			if (cin.fail())
				//Check for input failure
				cout << "ERROR:  Invalid input.  Restarting program..." << endl;
			else
			{
				//Then prompt for rectangle length and width
				cout << endl << "Now enter the rectangle's length: ";
				cin >> l1;
				if (cin.fail())
					//Check for input failure again
					cout << "ERROR:  Invalid input.  Restarting program..." << endl;
				else
				{
					cout << endl << "Now enter the rectangle's width: ";
					cin >> w1;
					if (cin.fail())
						cout << "ERROR:  Invalid input.  Restarting program..." << endl;
					else
					{
						cout << endl << "The radius you entered for the circle is " << r1
							<< ".  The length of the rectangle you entered is " << l1
							<< ", and the width is " << w1 << "." << endl;

						//Set the appropriate parameters for both shapes
						circle1.setRadius(r1);
						rectangle1.setLengthWidth(l1, w1);

						//Check if the area of the circle's area and rectangle's area are equal
						//and then output the result
						cout << "The area of the circle is "
							<< circle1.getArea() << ".  The area of the rectangle is "
							<< rectangle1.getArea() << "." << endl;
						if (circle1 == rectangle1)
							cout << "Their areas are equal!" << endl;
						else
							cout << "Their areas are not equal!" << endl;
					}//end if 3
				}//end if 2
			}//end if 1
			break;
		case '8':
			//Exit program
			break;
		default:
			//Error for invalid choice
			cout << "ERROR: Invalid input.  Restarting program..." << endl;

		}//end switch

		 //Clear input stream
		cin.clear();
		cin.ignore(100, '\n');
	} while (c != '8');

	return 0;
}//end main