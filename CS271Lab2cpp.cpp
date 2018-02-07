//This program takes in name, g.p.a. and scholarship amount 
//for different students from the user, then outputs
//this information with different output settings for
//the user.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Initialize the variables to be taken in by user.
	string name;
	double gpa;
	int scholarship;

	//Prompt user for name
	cout << "Enter your name: ";
	cin >> name;

	//Prompt user for g.p.a.
	cout << "Enter your GPA: ";
	cin >> gpa;

	//Prompt user for scholarship amount
	cout << "Enter your scholarship amount: ";
	cin >> scholarship;

	//Output the information entered with 3 different styles of output
	//First we create space for output
	cout << "\n";
	cout << fixed << showpoint << setprecision(2);
	cout << setw(10) << name << setw(10) << gpa
		 << setw(10) << scholarship << endl;

	//This output has spaces filled in with '*'
	cout << "\n";
	cout << setfill('*');
	cout << setw(7) << name << setw(8) << gpa
		 << setw(9) << scholarship << endl;

	//This output fills in spaces with different characters
	cout << "\n";
	cout << setfill('#') << setw(6) << name 
		 << setfill('@') << setw(7) << gpa 
		 << setfill('^') << setw(8) << scholarship 
		 << endl;

	//In this output, the fillers are removed and the information is reprinted
	cout << "\n";
	cout << setfill(' ');
	cout << setw(10) << name << setw(10) << gpa
		 << setw(10) << scholarship << endl;

	return 0;
}