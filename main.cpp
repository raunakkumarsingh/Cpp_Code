#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the differences between two strings
void diff(string X, string Y, int m, int n, auto &lookup)
{
	// if the last character of `X` and `Y` matches
	if (m > 0 && n > 0 && X[m - 1] == Y[n - 1])
	{
		diff(X, Y, m - 1, n - 1, lookup);
		cout << " " << X[m - 1];
	}

	// if the current character of `Y` is not present in `X`
	else if (n > 0 && (m == 0 || lookup[m][n - 1] >= lookup[m - 1][n]))
	{
		diff(X, Y, m, n - 1, lookup);
		cout << " +" << Y[n - 1];
	}

	// if the current character of `X` is not present in `Y`
	else if (m > 0 && (n == 0 || lookup[m][n - 1] < lookup[m - 1][n]))
	{
		diff(X, Y, m - 1, n, lookup);
		cout << " -" << X[m - 1];
	}
}

// Function to fill the lookup table by finding the length of LCS of substring
vector<vector<int>> findLCS(string X, string Y, int m, int n)
{
	// lookup[i][j] stores the length of LCS of substring X[0…i-1] and Y[0…j-1]
	vector<vector<int>> lookup(m + 1, vector<int>(n + 1));

	// first column of the lookup table will be all 0
	for (int i = 0; i <= m; i++) {
		lookup[i][0] = 0;
	}

	// first row of the lookup table will be all 0
	for (int j = 0; j <= n; j++) {
		lookup[0][j] = 0;
	}

	// fill the lookup table in a bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of `X` and `Y` matches
			if (X[i - 1] == Y[j - 1]) {
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
			}
			// otherwise, if the current character of `X` and `Y` don't match
			else {
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
			}
		}
	}

	return lookup;
}

// Implementation of diff utility in C++
int main()
{
	string X;
	string Y;
	cout << "Enter string 1 : ";
	cin >> X;
	cout << "Enter string 2 : ";
	cin >>Y;

	int m = X.length(), n = Y.length();

	// fill lookup table
	vector<vector<int>> lookup = findLCS(X, Y, m, n);

	// find difference by reading the lookup table in a top-down manner
	diff(X, Y, m, n, lookup);

	return 0;
}

// - indicates that character is deleted from Y but it was present in X
// + indicates that character is inserted in Y but it was not present in X

/*
logic :
		This problem is similar to LCS where we need to find which letters are extra or not there in a sequence od characters
		
		First create a look up table same as for LCS and then pass the lookup table, strings and their respective lengths to
		the diff function.
		
		It will check is both char in X and Y are same then it will give the output as normal characters
		Ex: 
			if "A" is first char of both X and Y    ->   output : "A"
		
		If current char in X is not same as current char in Y then - and the letter
		Ex:
			if "A" is first char of X and "B" is first char of Y   -> output : "-A"
		
		
		If current char in Y is not same as current char in X then + and the letter
		Ex:
			if "A" is first char of X and "B" is first char of Y   -> output : "+B"
		
		Like this it goes on until the end of the string giving us whole output.
*/