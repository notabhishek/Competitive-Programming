class Solution {
public:
    int countTriplets(vector<int>& a) {
        const int MXN =  1 << 16;
        int n = a.size();
        vector< int > dp(MXN , 0);
        for(int i = 0 ; i < n; ++i){
            for(int j = 0; j<n; ++j ) {
                dp[ a[i] & a[j] ]++;
            }
        }
        int ans = 0;
        for(auto &i : a) {
            for(int j = 0; j < MXN; ++j) 
                if( (j & i) == 0)
                    ans += dp[j];
        }
        return ans;
    }
};