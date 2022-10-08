class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == candidate) vote++;
            else vote--;
            if(vote <= 0){
                candidate = nums[i];
                vote=1;
            }
        }
        return candidate;
    }
};