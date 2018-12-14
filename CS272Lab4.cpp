/*
CS 272 -- Lab 4

DUE:  November 18, 2018

Create a program that provides the following menu options:

1. Add a number to the list

2. Delete a number from list

3. Search for a number on the list

4. Print the list

5. How many numbers are on the list?

6. Exit

You will create a linked list that stores integers. All the work can be done in your main function. 
Refer to chapter 16 for creating an un-ordered linked list with insertion at the end.
*/
#include <iostream>
//#include <iomanip>
using namespace std;

//Each node of linked list is a struct
struct IntNode
{
	int Num;  //Value of node
	IntNode *link; //pointer to node
};

int main()
{
	int choice, temp;  //User inputs
	int count = 0;	   //Number of list elements
	int index;		   //Index of current list element
	bool found;		   //Found list item

	IntNode *first = nullptr;			 //First list element pointer
	IntNode *last = nullptr;			 //Last list element pointer
	IntNode *newNode = nullptr;			 //New list element pointer
	IntNode *current, *next;			 //List element pointers:  current node, next node

	//Introduction
	cout << "This program allows you to create a list of numbers and modify the list as you see fit." << endl;

	//Main loop
	do
	{

		//Check for input error
		try
		{
			//Prompt user for option
			cout << "Please enter an option:\n"
				<< "1. Add number to the list\n"
				<< "2. Search for item in the list\n"
				<< "3. Delete a number from the list\n"
				<< "4. Print the list\n"
				<< "5. How many numbers on the list?\n"
				<< "6. Exit" << endl;
			cout << "Choose an option: ";
			cin >> choice;
			cout << endl;

			//If user enters anything other than a number, throw exception
			if (cin.fail())
				throw choice;

			//Check which option chosen and execute appropriate program
			switch (choice)
			{
			case 1:
				cin.clear();
				cin.ignore(100, '\n');
				try
				{
					//Prompt user for element to add to list
					newNode = new IntNode;
					cout << "Enter a number to add to the list: ";
					cin >> temp;

					//Check for invalid input and reprompt user for input if invalid
					if (cin.fail())
						throw temp;

					//Insert value as node in list
					cout << "You have inserted " << temp << " into the list." << endl;
					newNode->Num = temp;
					newNode->link = nullptr;

					//If list empty, insert element as first
					if (first == nullptr)
					{
						first = newNode;
						last = newNode;
						count++;
					}
					else
					{
						//Otherwise, insert element after last element
						last->link = newNode;
						last = newNode;
						count++;
					}//end if
				}//end try

				 //Catch block for temp
				catch (int)
				{
					do
					{
						//Clear input stream and reprompt user for temp
						cin.clear();
						cin.ignore(100, '\n');
						cout << "ERROR: Invalid input.  Please enter an integer: ";
						cin >> temp;
						cout << endl;
					} while (cin.fail());

					//Do everything in try block afterwards
					cout << "You have inserted " << temp << " into the list." << endl;
					newNode->Num = temp;
					newNode->link = nullptr;

					if (first == nullptr)
					{
						first = newNode;
						last = newNode;
						count++;
					}
					else
					{
						last->link = newNode;
						last = newNode;
						count++;
					}//end if
				}//end catch

				break;
			case 2:
				cin.clear();
				cin.ignore(100, '\n');
				found = false; //reset found
							 
				try
				{
					//Prompt user to enter element to search
					cout << "Enter the item to be searched in the list: ";
					cin >> temp;
					cout << endl;

					if (cin.fail())
						throw temp;

					//List is empty
					if (first == nullptr)
						cout << "The list is empty!" << endl;
					else
					{
						//Otherwise, start at first index and compare elements to input element
						index = 0;
						current = first;
						while (current != nullptr)
						{
							++index;
							if (current->Num == temp)
							{
								//Flag-controlled while loop
								found = true;
								break;
							}//end if	
							current = current->link;
						}//end while

						 //Output if element is found or not
						if (found)
							cout << "The number has been found at index " << index << endl;
						else
							cout << "The number has not been found!" << endl;
					}//end if
				}//end try

				catch (int)
				{
					do
					{
						cin.clear();
						cin.ignore(100, '\n');
						cout << "ERROR: Invalid input.  Please enter an integer: ";
						cin >> temp;
						cout << endl;
					} while (cin.fail());

					if (first == nullptr)
						cout << "The list is empty!" << endl;
					else
					{
						index = 0;
						current = first;
						while (current != nullptr)
						{
							++index;
							if (current->Num == temp)
							{
								found = true;
								break;
							}//end if	
							current = current->link;
						}//end while

						if (found)
							cout << "The number has been found at index " << index << endl;
						else
							cout << "The number has not been found!" << endl;
					}//end if
				}//end catch
					break;
			case 3:
				cin.clear();
				cin.ignore(100, '\n');
				found = false;
				try
				{
					//Prompt user for element to be deleted
					cout << "Enter the item to be deleted from the list: ";
					cin >> temp;
					cout << endl;

					if (cin.fail())
						throw temp;

					//List is empty
					if (first == nullptr)
						cout << "The list is empty!" << endl;
					else if (first->link == nullptr)
					{
						//List has only one element.  Check temp against element number
						current = first;
						if (temp == current->Num)
						{
							cout << "The element you want to delete is the only element.  Deleting..." << endl;
							first = nullptr;
							last = nullptr;
							delete current;
							count--;
							cout << "Done!" << endl;
						}
						else
							//Output error message if temp does not match number
							cout << "The number has not been found!" << endl;
					}
					else
					{
						//Otherwise, find element, then delete
						index = 0;
						current = first;
						if (current->Num == temp)
						{
							//Element is first in list
							cout << "Element you want to delete is first in list.  Deleting...";
							first = current->link;
							delete current; //Delete first node
							count--;
							cout << "Done!" << endl;
						}
						else
						{
							while (current->link != nullptr)
							{
								index++;
								if (current->link->Num == temp)
								{
									found = true;
									break;
								}//end if
								 //Move current pointer if next element does not contain desired number
								current = current->link;
							}//end while

							if (found)
							{
								//If element found, disconnect from list and delete
								cout << "The number has been found at index " << index << ". Deleting..." << endl;
								next = current->link;
								current->link = next->link;
								delete next;
								count--;
								cout << "Done!" << endl;
							}
							else
								cout << "The number has not been found!" << endl;
						}//end if 2
					}//end if 1
				}//end try

				catch (int)
				{
					do
					{
						cin.clear();
						cin.ignore(100, '\n');
						cout << "ERROR: Invalid input.  Please enter an integer: ";
						cin >> temp;
						cout << endl;
					} while (cin.fail());

					if (first == nullptr)
						cout << "The list is empty!" << endl;
					else if (first->link == nullptr)
					{
						current = first;
						if (temp == current->Num)
						{
							cout << "The element you want to delete is the only element.  Deleting..." << endl;
							first = nullptr;
							last = nullptr;
							delete current;
							count--;
							cout << "Done!" << endl;
						}
						else
							cout << "The number has not been found!" << endl;
					}
					else
					{
						index = 0;
						current = first;
						if (current->Num == temp)
						{
							cout << "Element you want to delete is first in list.  Deleting...";
							first = current->link;
							delete current;
							count--;
							cout << "Done!" << endl;
						}
						else
						{
							while (current->link != nullptr)
							{
								index++;
								if (current->link->Num == temp)
								{
									found = true;
									break;
								}//end if
								current = current->link;
							}//end while

							if (found)
							{
								cout << "The number has been found at index " << index << ". Deleting..." << endl;
								next = current->link;
								current->link = next->link;
								delete next;
								count--;
								cout << "Done!" << endl;
							}
							else
								cout << "The number has not been found!" << endl;
						}//end if 1
					}//end if 2
				}//end catch

				break;
			case 4:
				//Print the list for the user
				if (first == nullptr)
					//Output error message if list empty
					cout << "The list is empty!" << endl;
				else
				{
					//Otherwise, start from first node and print out list link-by-link
					current = first;
					cout << "The list contains the following numbers: ";
					while (current != nullptr)
					{
						cout << current->Num << " ";
						current = current->link;
					}//end while
					cout << endl;
				}//end if
				break;
			case 5:
				//Show number of nodes on list using 'count'
				if (count == 0)
					//List is empty
					cout << "The list is empty!" << endl;
				else
					cout << "There are " << count << " numbers on the list." << endl;
				break;
			case 6:
				//User exits program
				cout << "You chose to exit." << endl;
				break;
			default:
				//Return error message for anything other than 1-6
				cout << "Invalid choice.  Restarting..." << endl;
				}//end switch
			}//end try

		catch (...)
		{
			//Output error message and clear input stream for invalid input
			cout << "ERROR: Invalid input." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}//end catch

		 //Clear input stream if residue input error
		cin.clear();
		cin.ignore(100, '\n');
	} while (choice != 6);
}//end main