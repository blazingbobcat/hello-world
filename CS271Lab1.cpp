#include <iostream>
using namespace std;

int main()
{
	//create variables needed for calculating perimeter and area of rectangle
	float rectangleWidth, rectangleLength, rectanglePerimeter, rectangleArea;

	//prompt the user for the length and width of rectangle
	cout << "Please enter the length of rectangle: ";
	cin >> rectangleLength;

	cout << "Please enter the width of rectangle: ";
	cin >> rectangleWidth;

	//calculate perimeter and area of rectangle
	rectanglePerimeter = 2 * (rectangleLength + rectangleWidth);
	rectangleArea = rectangleLength * rectangleWidth;

	//print out results
	cout << endl;
	cout << "The perimeter of the rectangle is " << rectanglePerimeter << endl;
	cout << "The area of the rectangle is " << rectangleArea << endl;

	return 0;
}