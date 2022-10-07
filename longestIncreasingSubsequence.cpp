class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(auto it:nums){
            if(!lis.size() || lis.back()<it){
                lis.push_back(it);
                continue;
            }
            auto it1=lower_bound(lis.begin(),lis.end(),it);
            *it1=it;
        }
        return lis.size();
    }
};