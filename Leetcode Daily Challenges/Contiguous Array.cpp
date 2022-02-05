class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> idx; // idx[sum] = idx; 0:-1
        idx[0] = -1;
        int csum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            csum += (nums[i] == 0 ? -1 : 1);
            if(idx.count(csum))
                ans = max(ans, i - idx[csum]);
            else 
                idx[csum] = i;
        }
        return ans;
    }
};
