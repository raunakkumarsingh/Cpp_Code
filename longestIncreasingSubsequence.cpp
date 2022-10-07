class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;  // creating a vector which will store LIS
        for(auto it:nums){
            if(!lis.size() || lis.back()<it){ // if lis is empty or last element of lis is less than current element then add current element to lis
                lis.push_back(it);
                continue;
            }
            auto it1=lower_bound(lis.begin(),lis.end(),it); // if current element is less than last element of lis then put it at a position where it should be
            *it1=it;
        }
        return lis.size();
    }
};