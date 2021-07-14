class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // variation of stock selling problem 
        int64_t oddMax = nums[0] , evenMax = 0;
        for(int i = 1; i < nums.size(); ++i) {
            int64_t newEven = max(evenMax , oddMax - nums[i]); // sell
            int64_t newOdd = max(oddMax , evenMax + nums[i]);
            evenMax = newEven;
            oddMax = newOdd;
        }
        return oddMax;
    }
};
