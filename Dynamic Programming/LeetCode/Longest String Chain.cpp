class Solution {
public:
    inline int longest(string a , unordered_set<string> &words , unordered_map<string , int > &dp) {
        if(words.find(a) == words.end())
            return 0;
        if(dp[a] != 0)
            return dp[a];
        dp[a] = 1 + longest(a.substr(1) , words , dp);
        for(int i = 1; i < a.length(); ++i) {
            dp[a] = max(dp[a] , 1 + longest(a.substr(0 , i) + a.substr(i+1) , words , dp));
        }
        return dp[a];
    }
    inline int longestStrChain(vector<string>& words) {
        unordered_set<string> s;
        for(auto &i : words) s.insert(i);
        unordered_map<string ,int> dp;
        int ans = 1;
        for(auto &i : words) 
            ans = max(ans , longest(i , s , dp));
        return ans;
    }
};
