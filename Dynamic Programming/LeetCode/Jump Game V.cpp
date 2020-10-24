class Solution {
public:
    
    int jump(int idx , vector< int > &a , int d , vector< int > &dp) {
        int &ret = dp[idx];
        if(ret != -1)
            return ret;
        ret = 1;
        for(int j = idx + 1; j < a.size(); ++j) {
            if(abs(j - idx) > d || a[j] >= a[idx]) 
                break;
            ret = max(ret , 1 + jump(j ,a , d , dp));
        }
        
        for(int j = idx -1 ; j>=0; --j) {
            if(abs(j - idx) > d || a[j] >= a[idx])
                break;
            ret = max(ret , 1 + jump(j,a,d , dp));
        }
        return ret;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        vector< int > dp(arr.size() , -1);
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i) {
            ans = max(ans , jump(i , arr, d , dp));
        }
        return ans;
    }
};