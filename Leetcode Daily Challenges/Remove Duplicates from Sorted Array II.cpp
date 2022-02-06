class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), j = 0, count = 1, total = 0;
        for(int i = 1; i<n; i++) {
            if(nums[j] != nums[i]) {
                nums[++j] = nums[i];
                count = 1;
            }
            else if(nums[j] == nums[i] and count < 2) {
                nums[++j] = nums[i];
                count++;
            }
        }
        return j+1;
    }
};
