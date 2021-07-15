class Solution {
public:
    int jump(vector<int>& nums) {
        int n  = nums.size();
        if(n==1) 
            return 0;
        int left = nums[0];
        int mxjump = nums[0];
        int jumps = 1;
        for(int i = 1 ; i < n-1; ++i) {
            mxjump = max(mxjump , nums[i]+i);
            --left;
            if(left == 0) {
                ++jumps;
                left= mxjump - i;
            }
        }
        return jumps;
    }
};
