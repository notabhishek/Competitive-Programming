class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;
        int two = nums.size();
        int i = 0;
        while(i < two) {
            if(nums[i] == 0) {
                ++zero;
                swap(nums[zero], nums[i]);
                ++i;
            } 
            else if(nums[i] == 2) {
                --two;
                swap(nums[two], nums[i]);
            } 
            else ++i;
        }
    }
};
