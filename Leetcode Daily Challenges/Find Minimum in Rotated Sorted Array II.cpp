class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        1 1 1 1 1 1 2
        1 1 1 1 2 1 1
        case1: 
        0 0 0 0  1 1 1 1 1 1 2 3 4 -> min= nums0
        1 1 1 2 3 4 0 0 0 1 1 1 1
        1 2 3 4 0 1 1
        increasing | min elemnt increasing
        */
        int n = nums.size();
        int lo = 0, hi = n-1;
        if(nums[lo] < nums[hi]) return nums[lo];
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(nums[hi] > nums[mid]) { // mid is in right half of array
                hi = mid;
            } else if(nums[hi] < nums[mid]) { // mid is in left half of array
                lo = mid + 1;
            } else { // we are not sure which half we are in 
                --hi; // reduce the search space
            }
        }
        return nums[lo];
    }
};
