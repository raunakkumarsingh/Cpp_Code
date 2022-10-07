#include <iostream>
#include <climits>
#include <vector>
using namespace std;
 
// Naive recursive function to find the minimum cost to reach
// cell (m, n) from cell (0, 0)
int findMinCost(vector<vector<int>> const &cost, int m, int n)
{
    // base case
    if (n == 0 || m == 0) {
        return INT_MAX;
    }
 
    // if we are in the first cell (0, 0)
    if (m == 1 && n == 1) {
        return cost[0][0];
    }
 
    // include the current cell's cost in the path and recur to find the minimum
    // of the path from the adjacent left cell and adjacent top cell.
    return min (findMinCost(cost, m - 1, n), findMinCost(cost, m, n - 1))
                + cost[m - 1][n - 1];
}
 
int findMinCost(vector<vector<int>> const &cost)
{
    // base case
    if (cost.size() == 0) {
        return 0;
    }
 
    // `M × N` matrix
    int M = cost.size();
    int N = cost[0].size();
 
    return findMinCost(cost, M, N);
}
 
int main()
{
    vector<vector<int>> cost =
    {
        { 4, 7, 8, 6, 4 },
        { 6, 7, 3, 9, 2 },
        { 3, 8, 1, 2, 4 },
        { 7, 1, 7, 3, 7 },
        { 2, 9, 8, 9, 3 }
    };
 
    cout << "The minimum cost is " << findMinCost(cost);
 
    return 0;
}