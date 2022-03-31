class Solution {
public:
    int required(vector<int> &nums, int mx) {
        int req = 0;
        int i = 0, n = nums.size(); 
        while(i < n) {
            if(nums[i] > mx) return INT_MAX;
            ++req;
            int cur = 0;
            while(i < n && cur + nums[i] <= mx) 
                cur += nums[i++];
        }
        return req;
    }
    int splitArray(vector<int>& nums, int m) {
        int lo = 0, hi = accumulate(nums.begin(), nums.end(), 0);
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(required(nums, mid) <= m) 
                hi = mid-1;
            else 
                lo = mid+1;
        }
        return hi+1;
    }
};
