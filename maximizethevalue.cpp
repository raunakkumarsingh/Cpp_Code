// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum result
int maximumResult(int a, int b, int c)
{

	// To store the count of negative integers
	int countOfNegative = 0;

	// Sum of all the three integers
	int sum = a + b + c;

	// Product of all the three integers
	int product = a * b * c;
	
	// To store the smallest and the largest
	// among all the three integers
	int largest = max(a,max(b,c));
	int smallest = min(a,min(b,c) );
	
	
	// Calculate the count of negative integers
	if (a < 0)
		countOfNegative++;
	if (b < 0)
		countOfNegative++;
	if (c < 0)
		countOfNegative++;

	// Depending upon count of negatives
	switch (countOfNegative) {

	// When all three are positive integers
	case 0:
		return (sum - largest) * largest;

	// For single negative integer
	case 1:
		return (product / smallest) + smallest;

	// For two negative integers
	case 2:
		return (product / largest) + largest;

	// For three negative integers
	case 3:
		return (sum - smallest) * smallest;
	}
}

// Driver Code
int main()
{
	int a=-2,b=-1,c=-4;
	cout << maximumResult(a, b, c);

	return 0;
}
// This code contributed by Nikhil
