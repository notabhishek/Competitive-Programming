class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxNeg = INT_MIN;
        int pref = 1, ans = INT_MIN;
        for(int i : nums) {
            pref *= i;
            if(mxNeg != INT_MIN)
                ans = max(ans, pref / mxNeg);
            ans = max(ans, pref);
            if(pref == 0) {
                mxNeg = INT_MIN;
                pref = 1;
            } else 
                mxNeg = (pref < 0  && pref > mxNeg ? pref : mxNeg);
        } 
        return ans;
    }
};
