// subset sum problem solution by dynamic method

#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset of set[] with sum equal to given sum

bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i

    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,then answer is false

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main()
{
    int n, sum;
    cout << "Enter the size of array that will be used to performe the opretaion : \n";
    cin >> n;
    int set[n];
    cout << "Enter the sum : \n";
    cin >> sum;
    cout << "Enter the array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum in the array \n");
    else
        printf("No subset found with given sum in the array \n");
    return 0;
}
