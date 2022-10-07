#include <bits/stdc++.h>
using namespace std;
// topdown
int solve(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += solve(n - i, k);
    }
    return ans;
}
// topdown optimised
int solvetd(int n, int k, int *dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += solvetd(n - i, k, dp);
    }
    return dp[n] = ans;
}
// bottomUp
int bottomup(int n, int k)
{
    int dp[1000] = {0};
    int ans = 0;
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= k; j++)
        {
            if ((i - j) >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}
// bottomUp Optimise
int bottomUpOptimise(int n, int k)
{
    int dp[1000] = {0};
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if ((i - (k + 1)) < 0)
            dp[i] = (2 * dp[i - 1]);
        else
            dp[i] = (2 * dp[i - 1]) - dp[i - (k + 1)];
    }
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int dp[1000] = {0};

        cout << "topdown " << solve(n, k) << endl;
        cout << "topdown optimise " << solvetd(n, k, dp) << endl;

        cout << "bottomup " << bottomup(n, k) << endl;
        cout << "bottomup optimise " << bottomUpOptimise(n, k) << endl;

        cout << endl;
    }
    return 0;
}
