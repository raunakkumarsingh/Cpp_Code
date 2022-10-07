#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[2][W + 1];
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0){
                // if remaining weight == 0 or the number of items left ==0, then knapsack is empty.
                K[i % 2][w] = 0;
            }
            else if (wt[i - 1] <= w){
                // take the max of either taking this 
                // element and finding knapsack for the remaining problem
                // or do not take this element and find 
                // the total weight left with the i-1 items.
                K[i % 2][w] = max(
                    val[i - 1] + K[(i - 1) % 2][w - wt[i - 1]],
                    K[(i - 1) % 2][w]);
            }
            else{
                // if the item weight more than remaining weight, do not take that item.
                K[i % 2][w] = K[(i - 1) % 2][w];}
        }
    }
    return K[n % 2][W];
}
 
// Driver Code
int main()
{
    int val[] = { 60, 100, 250, 120, 400 };
    int wt[] = { 10, 20, 30, 25, 15 };
    int W = 60;
    int n = sizeof(val) / sizeof(val[0]);
 
    cout << knapSack(W, wt, val, n);
 
    return 0;
}