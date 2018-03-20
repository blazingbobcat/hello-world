/*

CSCI 271 Lab 5
March 25, 2018
Header file for conversion functions

*/
#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//The centimeters to inches function converts centimeters to inches.
//There are 0.3937 inches per centimeter, so inches = 0.3937 * centimeters
void CentimetersToInches(int& counter)
{
	//Set precision of output
	cout << fixed << showpoint << setprecision(4);
	
	//Declare centimeters input
	float centimeters;

	//Increase counter variable
	counter++;

	//Start prompt for centimeters
	do
	{
		cout << "Please enter number of centimeters: ";
		cin >> centimeters;
		cout << endl;

		if (centimeters > 0)
			//Display conversion
			cout << "The number of inches is " << 0.3937 * centimeters << endl;
		else
			//Tell user if they entered not a positive number
			cout << "Please enter a positive number for centimeters." << endl;

		//Clean out cin stream if user entered a char
		cin.clear();
		cin.ignore(200, '\n');

	} while (centimeters < 0);//Keep looping as long as user enters invalid input
}//end function

//The inches to centimeters function converts inches to centimeters
//There are 2.54 centimeters per inch, so centimeters = 2.54 * inches
void InchesToCentimeters(int& counter)
{
	//Set precision of output
	cout << fixed << showpoint << setprecision(4);

	//Declare inches input
	float inches;

	//Increase counter variable
	counter++;

	//Start prompt for inches
	do
	{
		cout << "Please enter number of inches: ";
		cin >> inches;
		cout << endl;

		if (inches > 0)
			//Display number of centimeters after converting inches with InchesToCentimeters function
			cout << "The number of centimeters is " << 2.54 * inches << endl;
		else
			//Tell user if they entered not a positive number
			cout << "Please enter a positive number for inches." << endl;

		//Clean out cin stream if user entered a char
		cin.clear();
		cin.ignore(200, '\n');

	} while (inches < 0);//Keep looping as long as user enters invalid input

}//end function