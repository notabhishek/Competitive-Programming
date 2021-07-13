class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int p = -1 , n = INT_MAX;
        int prod = 1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                p = i;
                n = INT_MAX;
                prod = 1;
                continue;
            }
            nums[i]/= abs(nums[i]);
            prod *= nums[i];
            if(prod > 0) 
                ans =max(ans, i - p);
            else {
                n = min(n , i);
                ans = max(ans, i-n);
            }
        }
        return ans;
    }
};
