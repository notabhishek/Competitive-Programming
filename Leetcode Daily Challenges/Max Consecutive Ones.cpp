class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int cur = 0;
        for(auto &i : nums) {
            if(i == 0) cur = 0;
            else ans = max(ans, ++cur);
        }
        return ans;
    }
};
