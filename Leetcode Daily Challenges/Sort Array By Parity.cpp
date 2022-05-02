class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i <= j) {
            if((nums[i]&1) == 0) {
                ++i;
                continue;
            }
            if(nums[j]&1) {
                --j; 
                continue;
            }
            swap(nums[i], nums[j]);
            ++i; --j;
        }
        return nums;
    }
};
