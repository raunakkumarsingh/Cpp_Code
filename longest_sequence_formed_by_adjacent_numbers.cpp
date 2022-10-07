// Find longest sequence formed by adjacent numbers in the matrix Diff Utility code using DP.
//here I am using dynamic programing concept.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
// This is the Function to check if a cell (i, j) is valid or not
bool isValid(int i, int j, int N) {
    return (i >= 0 && i < N && j >= 0 && j < N);
}
 
vector<int> findLongestPath(vector<vector<int>> const &mat, int i, int j)
{
    // string to store path starting (i, j)
    vector<int> path;
 
    // `N × N` matrix
    int N = mat.size();
 
    // if the cell is invalid
    if (!isValid (i, j, N)) {
        return path;
    }
 
    // Since the matrix contains all distinct elements,
    // there is only one path possible from the current cell
 
    // recur top cell if its value is +1 of value at (i, j)
    if (i > 0 && mat[i - 1][j] - mat[i][j] == 1) {
        path = findLongestPath(mat, i - 1, j);
    }
 
    // recur right cell if its value is +1 of value at (i, j)
    if (j + 1 < N && mat[i][j + 1] - mat[i][j] == 1) {
        path = findLongestPath(mat, i, j + 1);
    }
 
    // recur bottom cell if its value is +1 of value at (i, j)
    if (i + 1 < N && mat[i + 1][j] - mat[i][j] == 1) {
        path = findLongestPath(mat, i + 1, j);
    }
 
    // recur left cell if its value is +1 of value at (i, j)
    if (j > 0 && mat[i][j - 1] - mat[i][j] == 1) {
        path = findLongestPath(mat, i, j - 1);
    }
 
    // return path starting from (i, j)
    path.push_back(mat[i][j]);
    return path;
}
 
vector<int> findLongestPath(vector<vector<int>> const &mat)
{
    // stores the longest path found so far
    vector<int> longest_path;
 
    // from each cell (i, j), find the longest path starting from it
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            vector<int> path = findLongestPath(mat, i, j);
 
            // update result if a longer path is found
            if (path.size() > longest_path.size()) {
                longest_path = path;
            }
        }
    }
 
    reverse(longest_path.begin(), longest_path.end());
    return longest_path;
}
 
template <typename T>
void printVector(vector<T> const &input)
{
    cout << "[";
    int n = input.size();
    for (int i = 0; i < n; i++) {
        cout << input[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}
 
int main()
{
    // passing the matrix
    vector<vector<int>> mat =
    {
        { 10, 13, 14, 21, 23 },
        { 11, 16, 17, 2, 3 },
        { 19, 19, 18, 5, 4 },
        { 15, 8, 7, 6, 20 },
        { 16, 17, 18, 19, 25 }
    };
 
    vector<int> output = findLongestPath(mat);
    printVector(output);
 
    return 0;
}