class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0 ; 
        int mx = 0;
        while(i < nums.size()) {
            mx = max(mx , i + nums[i]);
            if(i == mx) 
                break;
            ++i;
        }
        return i>=nums.size()-1;
    }
};
