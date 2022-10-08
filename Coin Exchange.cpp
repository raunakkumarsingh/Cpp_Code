// Coin exchange 
//Dynamic approach
#include <bits/stdc++.h>
using namespace std;

int coins[] = {1,2,3,4,5}; 
int dp [1000] = {0};
int minCoins(int N, int M)
{
  //Initializing all values to INT_MAX i.e. minimum coins to make any
  //amount of sum is INT_MAX
  for(int i = 0;i<=N;i++)
    dp[i] = INT_MAX;
  
  //Base case 
  //Minimum coins to make sum = 0 cents is 0
  dp[0] = 0;
  
  //Iterating in the outer loop for possible values of sum between 1 to N
  //Since our final solution for sum = N might depend upon any of these values
  for(int i = 1;i<=N;i++)
  {
    //Inner loop denotes the index of coin array.
    //For each value of sum, to obtain the optimal solution.
    for(int j = 0;j<M;j++)
    {
      //i —> sum
      //j —> next coin index
      //If we can include this coin in our solution
      if(coins[j] <= i)
      {
        //Solution might include the newly included coin
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }
  return dp[N];
}

int main() {
  // your code goes here
  int sum = 50;
  int total_coins = 5;
  cout << minCoins(sum, total_coins);
}
