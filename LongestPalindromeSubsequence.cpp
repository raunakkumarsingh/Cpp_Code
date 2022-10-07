#include<iostream>
#include<string.h>
 
using namespace std;

int max (int x, int y) { return (x > y)? x : y; }   // this function gives us the 
 
int lps(string str)
{
   int n = str.length();
   int i, j, cl; //cl is length of substring
   int L[n][n];  // table for storing results of subproblems
 
 
   for (i = 0; i < n; i++)
      L[i][i] = 1;            // fills all the diagnol elements with 1
	
	// these 2 for loops compute values of table from previous values
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][n-1];
}
 

int main()
{
    string seq;
  	cout << "enter the string: "; 
  	cin >> seq;
	int n = seq.length();
	cout << "The length of the LPS is "<< lps(seq);
	return 0;
}

/*
The Longest Subsequence formed from "bbabcbcab" is abbcbcbba
So the max length of palindrome is 7
*/