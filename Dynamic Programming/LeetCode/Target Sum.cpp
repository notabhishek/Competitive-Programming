class Solution {
public:
    int ways(int i ,long long int S , vector<int> &nums) {
        if(i==0) {
            return S==0;
        }
        return ways(i-1 , S-nums[i-1] , nums) + ways(i-1 , S+nums[i-1] , nums);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return ways(nums.size() , S , nums);
    }
};
