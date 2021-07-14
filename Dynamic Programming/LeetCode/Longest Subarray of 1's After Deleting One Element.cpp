class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        if(n == 1)
            return 0;
        
        vector<int> l(n + 1, 0) , r(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            if(a[i-1] == 1) l[i] = 1 + l[i-1];
            else l[i] = 0;
        }
        for(int i = n-1; i>=0; --i){
            if(a[i] == 1) r[i] = 1 + r[i+1];
            else r[i] = 0;
        }
        int ans = max( r[1] , l[n-1] );
        for(int i = 1; i < n-1; ++i) {
            ans = max(ans, l[i] + r[i+1]);
        }
        return ans;
    }
};
