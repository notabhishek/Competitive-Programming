class Solution {
public:
    int play(int idx, vector< int> &a, vector<int> &dp) {
        if(idx >= a.size())
            return 0;
        int &ret = dp[idx];
        if(ret != INT_MIN)
            return ret;
        ret = INT_MIN;
        int sum = 0;
        for(int j : {idx , idx + 1 , idx + 2}) {
            if( j >= a.size() )
                break;
            sum += a[j];
            ret = max(ret , sum - play(j + 1 , a , dp));
        }
        return ret;
    }
    string stoneGameIII(vector<int>& a) {
        vector< int > dp(a.size() , INT_MIN);
        int d = play(0 , a , dp);
        if(d == 0)
            return "Tie";
        return (d > 0 ? "Alice" : "Bob");
    }
};