class Solution {
public:
    vector< int > dp;
    int msum;
    int rec(int sum, vector<int> &a) {
        int &ret = dp[sum];
        if(ret != -1)
            return ret;
        ret = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(sum >= a[i])
            ret += rec( sum - a[i] , a); 
        }
        return ret;
    }
    int combinationSum4(vector<int>& a, int sum) {
        int n = a.size();
        dp.resize( sum + 1 , -1 );
        dp[0] = 1;
        return rec(sum, a);
    }
};
