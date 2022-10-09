// The problem statement for Kadane's Algorithm states that,
// Given an array of intergers, find the maximum subarray sum from all possible non-empty subarrays
// ie find that contiguous subarray, containing at least one number, which has the largest sum


// Kadane's Algorithm makes use of dynamic programming, ie, it breaks down the larger problem into 
// a collection of simpler subproblems. 
// It calculates the maximum sum subarray ending at a particular position with the help of the maximum
// sum subarray ending at the prev index.

// Steps involved in the code:
// 1. maxOverall which stores the maximum sum so far. We initialize it to INT_MIN. This will be finally returned.
// 2. maxSofar which stores the maximum sum ending at current position. We initialize it to 0.
// 3. We iterate over the array and add the current element value to maxSofar, and at every position we check the following conditions:
//     -> If maxSofar is greater than maxOverall:
//             update maxOverall to equal maxSofar
//     -> If maxSofar is less than zero:
//             update maxSofar to equal zero
// 4. Return the value of maxOverall

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxOverall = INT_MIN;
    int maxSofar = 0;

    for(int i = 0 ; i < nums.size(); i++)
    {
        maxSofar = maxSofar + nums[i];

        if(maxSofar > maxOverall)
        {
            maxOverall = maxSofar;
        }
        if(maxSofar < 0)
        {
            maxSofar = 0;
        }
    }
    return maxOverall;

}
int main() {
    // Your code goes here;
    vector<int> a = {2, 5, 1, -6, 4, -9, 4};
    cout << maxSubArray(a) << endl;
    // output will be 8 [2,5,1]
    return 0;
}




