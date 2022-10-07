// Solvng Longest Palindromic Subsequence problem by using dynamic recursion and then memoistion method.
// Since we have to find Longest Palindromic Subsequence which is also equal to lcs of the string itself and its reverse form.
// So here we will find the lcs of string itself and its reverse form.

#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string &s1, string &s2, int n,int m, vector<vector<int> > &dp)
{
    if (n == 0 || m == 0) // if size of any string is 0 then return 0
        return 0; 
  
    if (dp[n][m] != -1) // if lcs is previously computed then return from here
        return dp[n][m];
  
    int ans = 0;
    if (s1[n - 1] == s2[m - 1]) // if char matches
        ans = 1 + LongestCommonSubsequence(s1, s2, n - 1, m - 1,dp);
    else // if the chars doesn't matches then we take max lcs of excluding char of first string and then excluding char of 2nd string
        ans = max(LongestCommonSubsequence(s1, s2, n - 1, m,dp), LongestCommonSubsequence(s1, s2, n, m - 1,dp));

    return dp[n][m] = ans;
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    string rev = str;
    reverse(rev.begin(),rev.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // initialising dp vector of size (n+1)*(n+1) with value -1 each

    int lcs = LongestCommonSubsequence(str, rev, n, n, dp);
    //lcs of str and its reverse form is equal to length of Longest Palindromic Subsequence of str.
    cout << "Length of Longest Palindromic Subsequence is eaqual to " << lcs << endl;
}
