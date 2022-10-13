/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] 
such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Four_sum
{
private:
    vector<int> nums;
    int target;

public:
    Four_sum(vector<int>& vec,int t) 
    {
        nums=vec;                       //the nums vector containing the elements of the given array
        target=t;                       //the target is the sum which we want to achieve by 4sum
    }
    vector<vector<int>> four_sum_solution()
    {
        if(nums.size()<4)               //handling the corner case when the size of the given array is less than 4
        {
            return {};
        }
        sort(nums.begin(),nums.end());   //first the elements are sorted, so we can apply an approach of two pointer
        set<vector<int>> res;            //first storing the solution vectors in the set to avoid duplicates
        for(int i=0;i<nums.size()-3;i++)    //the 1st element of the quadriple, starting from first element to 4th last element
        {
            for(int j=i+1;j<nums.size()-2;j++)  //the 2nd element, starting from i+1
            {
                int left=j+1;                   //3rd element, starting from right of j, which is j+1
                int right=nums.size()-1;        //4th element, starting from right most element of the given array
                while(left<right)               //applying the two pointer approach with these two variables
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)             //when we get the sum value as equal to the target value,...
                    {
                        vector<int> vec;        //crete a temporary vector is created and the elements are inserted
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[left]);
                        vec.push_back(nums[right]);
                        res.insert(vec);
                    }
                    if(sum<target)      //if the sum is less than the target, then we should move the left pointer to one position in right
                    {
                        left++;         //as we have already sorted the array, so it is gurranteed that the we would get larger value when we go left++
                    }
                    else
                    {
                        right--;       //if the sum is greater than the target, then we should move the right pointer to one position in left
                    }
                }
            }
        }
        vector<vector<int>> res_vec;
        for(auto i:res)
        {
           res_vec.push_back(i); //from the set of the vectors, the resulting vectors are inserted into the vector<vector<int>>
        }
        return res_vec;
    }

};
int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    int target;
    cin>>target;
    Four_sum obj(vec,target);
    vector<vector<int>> res=obj.four_sum_solution();
    if(res.size()!=0)
    {
        for(auto i:res)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"The given array does not contain 4 elements"<<endl;
    }
    
    return 0;
}