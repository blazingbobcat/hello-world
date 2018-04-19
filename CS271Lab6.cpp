/*

CSCI 271 Lab 6

This program takes user input for 5 test scores, calculates the average, and then outputs the average score.  It then sorts the scores in a list
in ascending order before printing the list.

*/
#include <iostream>
using namespace std;

int main()
{
	//Initialize all variables
	int list[5];
	int index;
	int sum = 0;
	int smallestIndex;
	int temp;
	int loc;
	double average;

	//Greet user to program
	cout << "Welcome!  This program will calculate the average of 5 test scores and present the test scores in ascending order." << endl;

	//Begin input loop
	for (index = 0; index < 5; index++)
	{

		//Prompt user for each score
		do
		{
			cout << "Enter score #" << index + 1 << ": ";
			cin >> list[index];
			//Check for input errors and keep asking user for correct input if any
			if (cin.fail() || list[index] < 0 || list[index] > 100)
			{
				//Prompt user again for score
				cout << "\nWrong input. Please enter number between 0-100. " << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}

		} while (cin.fail() || list[index] < 0 || list[index] > 100);
			
		//Aggregate input scores to sum
		sum = sum + list[index];
	}

	//Calculate average score and output it
	average = sum / 5.0;
	cout << "\nThe average score is " << average << endl;

	//Start sorting the scores from least to greatest
	for (index = 0; index < 4; index++)
	{
		//Assume index of smallest number is current index
		smallestIndex = index;

		//Start comparing scores after current score to current score
		for (loc = index + 1; loc < 5; loc++)
		{
			if (list[loc] < list[smallestIndex])
				//If score at location of comparison is smaller than score of smallestindex, that location is the smallest index
				smallestIndex = loc;
		}

		//Temporarily hold score of smallest index to switch with the score at the current index
		temp = list[smallestIndex];

		//We then switch the score of the current index with the score of the smallest index.
		//This will put the scores in order.
		list[smallestIndex] = list[index];
		list[index] = temp;

	}

	//Print out the sorted list of scores
	cout << "The scores in ascending order are ";

	//Go through each score and print out with a space
	for (index = 0; index < 5; index++)
	{
		cout << list[index] << " ";
	}
	cout << endl;
	
	cout << "Thank you for using my program!" << endl;
	return 0;

}//end main