class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i = nums.size()-1; i >= 0; --i) 
            ans ^= i ^ nums[i];
        return ans;
    }
};
