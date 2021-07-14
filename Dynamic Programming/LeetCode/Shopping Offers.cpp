class Solution {
public:
    map< pair< int, vector<int>> , int > dp;
    // either take the ith special offer or don't
    int rec(vector<int> &a, vector<int> &p,  int idx , vector<vector<int>> &s) {
        if(dp.count({idx, a}))
            return dp[{idx, a}];
        int ans = INT_MAX;
        // fill remaining using prices
        int cur = 0;
        for(int i = 0; i < a.size(); ++i) {
            cur += p[i] * a[i];
        }
        ans = min(ans , cur);
    
        // try taking the idx th special offer
        vector<int> red = a;
        bool ff = true;
        for(int i = 0; i < a.size(); ++i) {
            if(red[i] >= s[idx][i]) red[i]-=s[idx][i];
            else {
                ff = false;
                break;
            }
        }
        if(ff) 
            ans = min(ans, s[idx][a.size()] + rec(red, p, idx , s));
        
        // do not take special offer
        if(idx > 0)
            ans = min(ans , rec(a, p , idx-1, s));
        return dp[{idx, a}] = ans;
    }
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& a) {
        int ans = rec(a, p, s.size()-1, s);
        return ans;
    }
};
