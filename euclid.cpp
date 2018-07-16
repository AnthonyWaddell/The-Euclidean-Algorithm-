//----------------------------------------------------------------------------
// File:		euclid.cpp
// 
// Description: Test Driver 
// 
// Programmer:	Anthony Waddell
//
// Functions:   main()
//				int greatestCommonFactor(int firstNum, int secondNum)
//					returns the greatest common factor of two ints 
// 
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015
//---------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

// Greatest Common Divisor forward declaration
int greatestCommonFactor(int firstNum, int secondNum);

//Sorry for the global variable
static unsigned int callCount = 0;


//-----------------------------------------------------------------------------
// Function:	main()
//
// Title:		Program entry point
//
// Description: This file contains function main() which tests the function
//				greatestCommonFactor()
//
// Programmer:	Anthony Waddell
//   
// Date:		10-14-17
// 
// Version:		1.0
//  
// Environment: Hardware: PC, i7
// Software:	OS: Windows 10 
//				Compiles under Microsoft Visual C++ 2015
// 
// Input:		int n; an integer from console to calculate the greatest number
//				of modulus operations between two numbers in the range of 8 to 
//				n
// 
// Output:		Screen display of the two numbers that incur the greatest
//				amount of modulus operations
// 
// Calls:		greatestCommonFactor(int firstNum, int secondNum)
// 
// Called By:	N/A
// 
// Parameters:	N/A
// 
// Returns:		EXIT_SUCCESS upon successful execution
//
// History Log:	10-14-17 AW Began Project
//				10-20-17 AW Completed Project
//-----------------------------------------------------------------------------
int main(void)
{
	int n;
	int a = 0;
	int b = 0;
	int greatestCount = 0;
	auto start = chrono::high_resolution_clock::now();
	// Get user input for n
	do
	{
		cout << "Please enter an integer (greater than 8) for n: ";
		cin >> n;
	} while (n <= 8);

	// Look at range of i to n
	for (int i = 8; i <= n; i++)
	{
		// Look for greatest mod count from a to b in range of i to n
		for (int j = 1; j <= i; j++)
		{
			greatestCommonFactor(i, j);
			if (callCount > greatestCount)
			{
				a = i;
				b = j;
				greatestCount = callCount;
			}
			// Reset the call count
			callCount = 0;
		}
		// Output greatest mod count of a and b in range of i to n to console
		cout << "At i = " << i << "; gcd(" << b << " " << a << ") = 1 took "
			<< greatestCount << " modulus operations ";

		// Get time count for each interval of i
		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double, std::milli> elapsed = (finish - start);
		cout << "Elapsed time: " << elapsed.count() << " m/s" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}

//------------------------------------------------------------------------
// Function:	greatestCommonFactor(int firstNum, int secondNum)
//
// Title:		Finds the greatest common factor of two numbers
// 
// Description: Recursively finds the greatest common factor of two
//				numbers
//
// Programmer:	Anthony Waddell
//
// Date:		10-14-17
//
// Version:		1.0
//
// Environment: Hardware: PC, i7
// Software:	OS: Windows 10 
//				Compiles under Microsoft Visual C++ 2015
//
// Input:		N/A 
// Output:		N/A
// Calls:		greatestCommonFactor(); recursively
// Called By:	main()
//				greatestCommonFactor(); recursively
// Parameters:	int firstNum; the lesser number
//				int secondNum; the greater number
// Returns:		the greatest common factor of the two numbers
// History Log: 10-14-17 AW Completed v 1.0
//------------------------------------------------------------------------
int greatestCommonFactor(int firstNum, int secondNum)
{
	int zero = 0;
	firstNum = abs(firstNum);
	secondNum = abs(secondNum);

	if (secondNum == zero)
		return firstNum;
	else
	{
		// Count the number of mod operations
		callCount++;
		return greatestCommonFactor(secondNum, firstNum % secondNum);
	}
}