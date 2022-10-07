// solvng lcs problem by using dynamic programing by recursion and then memoistion method.

#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string &s1, string &s2, int n,int m, vector<vector<int> > &dp)
{
    if (n == 0 || m == 0) // if size of any string is 0 then return 0
        return 0; 
  
    int ans = 0;
    if (dp[n][m] != -1) // if lcs is previously computed then return from here
        return dp[n][m];
  
    if (s1[n - 1] == s2[m - 1]) // if char matches the we increase lcs value by 1 and then compute lcs for rest of string by recursion.
        ans = 1 + LongestCommonSubsequence(s1, s2, n - 1, m - 1,dp);
    else // if the chars doesn't matches then we take max lcs of excluding char of first string and then excluding char of 2nd string.
        ans = max(LongestCommonSubsequence(s1, s2, n - 1, m,dp), LongestCommonSubsequence(s1, s2, n, m - 1,dp));

    return dp[n][m] = ans;
}

int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // initialising dp vector of size (n+1)*(m+1) with value of each element is -1
    int lcs = LongestCommonSubsequence(text1, text2, n, m, dp); //calling the function to calculate lcs of text1 and text2.
    cout << "Length of Longest Common Subsequence is eaqual to " << lcs << endl;
}
