/*

CSCI 271 Lab 4

This program uses the same menu program from lab 3, only it uses a do-while loop for the menu, and remprompts the user
to enter valid values for test score and gpa if user had not done so at first.

*/
#include <iostream>

using namespace std;

int main()
{
	//declare all our variables
	char choice;
	int score;
	float gpa;

	//begin main do-while loop
	do
	{
		//prompt user to enter a choice from the main menu
		cout << "\nMenu Options:" << endl << "1. Enter your test score, I'll tell you the grade." << endl
			<< "\t(0-59 F, 60-69 D, 70-79 C, 80-89 B, 90-100 A, everything else is invalid)" << endl
			<< "2. Enter your GPA to see if you made the Dean's List. " << endl
			<< "\t(3.9 - 4 makes the dean's list, 0-3.8 doesn't, everything else is invalid)" << endl
			<< "3. Exit" << endl << "Enter a choice: ";

		//take in user's choice
		cin >> choice;

		//start switch structure to check which choice user entered, or if user entered an invalid choice
		switch (choice)
		{
		case '1':
			//begin another do-while to check if user entered a valid value
			//for test score, and reprompt user if not.

			do
			{
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

			} while (score < 0 || score > 100);//end do-while loop

			//break from switch structure
			break;

		case '2':
			//begin third do-while loop to check if user entered valid gpa, and remprompt
			//user for gpa if not.

			do
			{
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

			} while (gpa < 0.0 || gpa > 4.0);//end do-while loop
	
			break;

		case '3':
			//give message for exiting program
			cout << "\nThank you for using my program!" << endl;
			break;

		default:
			cout << "\nInvalid choice.  Please enter a number 1, 2 or 3." << endl;
		}//end switch structure

	} while (choice != '3'); //end do-while loop

	return 0;
}//end function