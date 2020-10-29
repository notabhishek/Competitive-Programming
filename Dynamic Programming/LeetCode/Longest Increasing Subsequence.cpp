class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            int idx = lower_bound(lis.begin() , lis.end(), nums[i]) - lis.begin();
            if(idx == lis.size()) 
                lis.push_back(nums[i]);
            else 
                lis[idx] = nums[i];
        }
        return lis.size();
    }
};