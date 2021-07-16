class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        bool allNeg = true;
        for(auto &i  : A) 
            if( i > 0 ) 
                allNeg = false;
        if(allNeg) 
            return *max_element(A.begin() , A.end());
        int ans = 0;
        int cur = 0;
        for(auto &i : A) {
            cur += i;
            ans = max(ans , cur);
            if(cur < 0 ){
                cur = 0;
            }
        }
        int n = A.size();
        int suf[n];
        suf[n-1] = A[n-1];
        for(int i = n-2; i>=0; --i) suf[i] = A[i] + suf[i + 1];
        int sufmax = suf[n-1];
        for(int i = n-1; i>=0 ; --i) {
            sufmax = max(sufmax , suf[i]);
            suf[i] = sufmax;
        } 
        int presum = A[0];
        for(int i = 1 ; i < n; ++i) {
            ans = max(ans , presum + suf[i]);
            presum+= A[i];
        }
        return ans;
    }
};
