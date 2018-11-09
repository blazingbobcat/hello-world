/*
CS 272 -- Lab 3 Main Program

DUE:  October 28, 2018

Create a program that provides the following menu of options:

1. Enter 5 test scores and calculate the average //store the list of scores in a single dimensional array and print the average

2. Sort the list of scores from smallest to largest //check for an empty list, if list not empty sort and print

3. Exit

Be sure that the user puts in valid menu option and test scores from 0-100, 
check for input errors such as characters or larger or smaller numbers. 
Use exception handling methods we learned in chapter 14 (try, throw, catch) to do the exception handling
*/

#include <iostream>
#include <iomanip>
#include <exception>

using namespace std;

int main()
{
	int selection, index, temp;			   //Neccessary int variables
	int accum = 0;						   //Accumulator
	double average;						   //Average test score
	int test[5] = { 0 };				   //Test score list

	//Introduce user to program
	cout << "This program lets you find the average of 5 test scores from 0-100, or sort the list of scores "
		<< "from smallest to largest.  To sort a list of scores, you must create the list first in option 1." << endl;
	do
	{
		try
		{
			//Prompt user with menu options
			cout << "Menu:\n1. Find average\n2. Sort list of scores\n3. Exit\n"
				<< "Enter the number of your selection: ";
			cin >> selection;
			//Check if user entered an invalid choice
			if (!cin)
				throw selection;

			cout << endl;

			switch (selection)
			{
				case 1:
					//Prompt user to enter 5 test scores
					cout << "Enter the 5 test scores." << endl;
					
						for (index = 0; index < 5; index++)
						{
							try
							{
								cin.clear();//Clear input stream in case left-over invalid input
								cin.ignore(100, '\n');
								cout << "Test score " << index + 1 << ": ";
								cin >> test[index];
								cout << endl;
								//Check if user entered a negative integer, or not an integer
								if (!cin || test[index] < 0 || test[index] > 100)
									throw test[index];
							}//end try
							catch (int)
							{
								//Ask for numbers again if input is invalid
								do
								{
									cout << "ERROR: Invalid input.  Please enter an integer 0-100: ";
									cin.clear();//garbage-collecting
									cin.ignore(100, '\n');
									cin >> test[index];
								} while (!cin || test[index] < 0 || test[index] > 100);
							}//end catch
							accum += test[index];
						}//end for

					cout << endl;
					//Calculate the average and print
					average = accum / 5;

					cout << "The average of the test scores is " << average << "." << endl;
					accum = 0;  //Reset accumulator
					break;
				
				case 2:

					try
					{
						//Check if the list is empty
						for (index = 0; index < 5; index++)
							accum = accum + test[index];

						//Throw exception if so
						if (accum == 0)
							throw accum;

						//If list not empty, sort list
						for (index = 0; index < 5; index++)
						{
							for (int j = index; j < 5; j++)
								if (test[j] < test[index])
								{
									temp = test[index];
									test[index] = test[j];
									test[j] = temp;
								}//end if
						}//end for

						//Output the sorted list
						cout << "Using the test scores you entered, the sorted list is ";
						for (index = 0; index < 5; index++)
							cout << test[index] << " ";
						cout << endl;

						accum = 0;
					}//end try

					//Catch block for empty list
					catch (int accum)
					{
						cout << "ERROR:  List of test scores is empty.  Restarting program." << endl;
					}//end catch

					cout << endl;
					break;

				case 3:
					//Exit program
					break;

				default:
					throw selection;
			}//end switch
		}// end try

		//Catch block for invalid menu selection
		catch (int selection)
		{
			cout << "ERROR:  Invalid input.  Resarting program." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}//end catch

		cin.clear();//more garbage-collecting
		cin.ignore(100, '\n');
	} while (selection != 3);
	
}//end main