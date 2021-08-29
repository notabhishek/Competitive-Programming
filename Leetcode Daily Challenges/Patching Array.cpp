using ll = long long;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0; 
        ll sum = 0;
        int patch = 0;
        while(i < nums.size() && sum < n) {
            if(nums[i] <= sum+1) {
                sum += nums[i]; ++i;
            } else {
                sum += sum+1;
                ++patch;
            }
        }
        while(sum < n) ++patch, sum+= sum+1;
        return patch;
    }
};
