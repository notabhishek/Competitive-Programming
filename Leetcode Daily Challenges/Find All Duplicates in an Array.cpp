class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> r;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int v = abs(nums[i]);
            if(nums[v-1] < 0) r.push_back(v);
            else nums[v-1] = -nums[v-1];
        }
        return r;
    }
};
