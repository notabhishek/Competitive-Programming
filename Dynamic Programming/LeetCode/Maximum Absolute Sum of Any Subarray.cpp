class Solution {
public:
    int kadane(vector<int> &a){
        int n = a.size();
        int csum = 0, msum = 0;
        for(auto &i : a) {
            msum = max(msum , csum);
            if(csum + i < 0) {
                csum = 0;
            } else csum += i;
        }
        msum = max(msum , csum);
        return msum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = kadane(nums);
        for(auto &i : nums) i = -i;
        ans = max(ans, kadane(nums));
        return ans;
    }
};
