class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> triplets;
        for(int i = 0; i < n;) {
            int j = i+1, k = n-1;
            while(j < k) {
                if(nums[j]+nums[k] == -nums[i]) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(j<n && nums[j-1] == nums[j]) ++j;
                    --k;
                    while(k>=0 && nums[k+1] == nums[k]) --k;
                } else if(nums[j]+nums[k] < -nums[i]) {
                    ++j;
                } else {
                    --k;
                }
            }
            j = i+1;
            while(j < n && nums[j] == nums[i])++j;
            i = j;
        }
        return triplets;
    }
};
