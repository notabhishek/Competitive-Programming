class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        if(lo == hi) return nums[lo];
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            bool can;
            if(mid&1) can = nums[mid] != nums[mid-1];
            else can = nums[mid]!= nums[mid+1];
            
            if(can) hi = mid-1;
            else lo = mid + 1;
        }
        return nums[hi+1];
    }
};
