/*

CSCI 271 Lab 5
March 25, 2018
Inches to Centimeters and Centimeters to Inches Conversions -- Main program

*/
#include <iostream>
#include "CS271Lab5header.h"

using namespace std;

int main()
{
	//Initialize menu choice and counter variables
	int counter = 1;
	char choice;

	//Introduce the user to the program
	cout << "This program converts centimeters to inches and inches to centimeters." << endl;

	do
	{
		//Prompt user with menu, instructing them to make a choice with the appropriate number (a char value)
		cout << "\nMain Menu.  Please select one of the options below by entering the number." << endl
			<< "1. Convert centimeters to inches." << endl << "2. Convert inches to centimeters." << endl 
			<< "3. Exit." << endl
			<< "Selection: ";
		cin >> choice;
		cout << endl;

		//Check what the user entered using switch structure
		switch (choice)
		{
		
		case '1':
			//Call centimeters to inches function for first option, passing counter by reference
			CentimetersToInches(counter);
			break;//end case 1

		case '2':
			//Call inches to centimeters function for second option, passing counter by reference
			InchesToCentimeters(counter);
			break;//end case 2

		case '3':
			//Tell user how many times they accessed the main menu (counter) and thank them for acccessing program
			cout << "You have accessed the main menu " << counter << " times." << endl;
			cout << "Thank you for using my conversion program!" << endl;
			break;

		default:
			//If user enters invalid choice, remprompt the user for one of the numbered choices
			cout << "Your entry is invalid.  Please select option 1, 2 or 3." << endl;

			//Clean out cin stream
			cin.clear();
			cin.ignore(200, '\n');

		}//end switch

	} while (choice != '3');//end do-while

	return 0;
}//end main