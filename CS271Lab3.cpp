/*

CSCI 271 Lab 3

This program presents a menu for the user that gives three options, to enter their test score on their last test
and get a letter grade, to enter their gpa to see if their on the dean's list, and to exit the program.

*/
#include <iostream>

using namespace std;

int main()
{
	//declare all our variables
	char choice;
	int score;
	float gpa;

	//prompt user to enter a choice from the main menu
	cout << "\nMenu Options:" << endl << "1. Enter your test score, I'll tell you the grade." << endl
		<< "\t(0-59 F, 60-69 D, 70-79 C, 80-89 B, 90-100 A, everything else is invalid)" << endl
		<< "2. Enter your GPA to see if you made the Dean's List. " << endl
		<< "\t(3.9 - 4 makes the dean's list, 0-3.8 doesn't, everything else is invalid)" << endl
		<< "3. Exit" << endl << "Enter a choice: ";
	
	//take in user's choice
	cin >> choice;

	//start while loop
	while (choice != '3')
	{
		//start switch structure to check which choice user entered, or if user entered an invalid choice
		switch (choice)
		{
			case '1':
				//prompt user to enter test score
				cout << "\nEnter your test score: ";
				cin >> score;

				//check to see what grade is appropriate for the score, and if score is valid, using if-else structure
				if (score >= 0 && score <= 59)
					cout << "\nYou got an F." << endl;
				else if (score > 59 && score <= 69)
					cout << "\nYou got a D." << endl;
				else if (score > 69 && score <= 79)
					cout << "\nYou got a C." << endl;
				else if (score > 79 && score <= 89)
					cout << "\nYou got a B." << endl;
				else if (score > 89 && score <= 100)
					cout << "\nYou got an A." << endl;
				else
					cout << "\nInvalid test score.  Please enter a number from 0 to 100." << endl;
				
				//break from switch structure
				break;

			case '2':
				//prompt use to enter gpa
				cout << "\nEnter your gpa: ";
				cin >> gpa;

				//check if gpa is high enough for student to be on Dean's List, or if entry is invalid
				if (gpa >= 3.9 && gpa <= 4.0)
					cout << "\nYou are on the Dean's List!" << endl;
				else if (gpa >= 0.0 && gpa < 3.9)
					cout << "\nYou are not on the Dean's List." << endl;
				else
					cout << "\nInvalid gpa.  Please enter a decimal number from 0.0 to 4.0." << endl;
				break;

			case '3':
				//exit program
				break;

			default:
				cout << "\nInvalid choice.  Please enter a number 1, 2 or 3." << endl;
		}//end switch structure

		 //reprompt the user to select an option from the menu
		cout << "\nMenu Options:" << endl << "1. Enter your test score, I'll tell you the grade." << endl
			<< "\t(0-59 F, 60-69 D, 70-79 C, 80-89 B, 90-100 A, everything else is invalid)" << endl
			<< "2. Enter your GPA to see if you made the Dean's List. " << endl
			<< "\t(3.9 - 4 makes the dean's list, 0-3.8 doesn't, everything else is invalid)" << endl
			<< "3. Exit" << endl << "Enter a choice: ";

		//take in choice again
		cin >> choice;

	}//end while loop

	return 0;
}//end function