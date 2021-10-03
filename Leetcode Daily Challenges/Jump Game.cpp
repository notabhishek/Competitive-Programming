class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canGo = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > canGo) return false;
            canGo = max(canGo, i + nums[i]);
        }
        return true;
    }
};
