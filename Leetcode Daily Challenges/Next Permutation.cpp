class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return;
    
        int pos = len;
        for (int i = len-2; i >= 0; i--) {
            if (nums[i] >= nums[i+1]) continue;
            pos = i;
            break;
        }
        
        if (pos == len) return sort(nums.begin(), nums.end());
        
        int nearMax = pos+1;
        for (int i = pos+1; i < len; i++) {
            if (nums[i] > nums[pos]) {
                nearMax = (nums[nearMax] > nums[i])? i : nearMax;    
            }
            else break;
        }
        
        swap(nums[pos], nums[nearMax]);
        
        pos++;
        if (pos >= len) return;
        
        sort(nums.begin()+pos, nums.end());
    } 
};
