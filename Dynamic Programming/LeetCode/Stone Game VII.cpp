class Solution {
public:
    vector<vector<int>> dp;
    inline int sum(int i, int j, vector<int> &pre) {
        return pre[j+1] - pre[i];
    }
    int rec(int i, int j, vector<int> &a, vector<int> &pre) {
        int &ret = dp[i][j];
        if(ret != INT_MIN) 
            return ret;
         
        if(i == j) 
            return ret = 0;
        
        ret = max(
            sum(i+1, j, pre) - rec(i+1, j, a, pre),
            sum(i, j-1, pre) - rec(i, j-1, a, pre)    
                 );
        
        return ret;
    }
    int stoneGameVII(vector<int>& a) { 
        int n = a.size();
        dp.assign(n, vector<int> (n, INT_MIN));
        vector<int> pre(n+1);
        for(int i = 1; i <= n; ++i)
            pre[i] = pre[i-1] + a[i-1];
        return rec(0, n-1, a, pre);
    }
};
