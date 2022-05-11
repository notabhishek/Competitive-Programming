class Solution {
public:
    vector< vector< int >> dp;
    int cnt(int n , int r) {
        
        
        int &ans = dp[n][r]; 
        if(ans != -1)
            return ans;
        if(n == 0)
            return dp[n][r] = 1;
        ans = 0;
        for(int i = 1; i <= r; ++i) 
            ans += cnt(n-1 , i);
        return ans;
    }
    int countVowelStrings(int n) {
        dp.assign(n+1, vector<int> (6 , -1));
        return cnt(n,5);
    }
};
