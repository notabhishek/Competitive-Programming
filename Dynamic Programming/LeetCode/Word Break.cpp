class Solution {
public:
    bool match(int i , string &s , set<string> &dict , vector<int> &dp) {
        if(dp[i]!=-1)
            return dp[i];
        string tmp = "";
        dp[i] = 0;
        for(int j = i ; j < s.length(); ++j) {
            tmp += s[j];
            if(dict.find(tmp)!=dict.end() && match(j+1 , s , dict,dp)) {
                //cout << i << " match "<<endl;
                dp[i] = 1;
                break;
            }
        }
        return dp[i];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        vector<int> dp(s.length()+1 , -1);
        dp[s.length()] =1;
        for(auto &i : wordDict) dict.insert(i);
        return match(0 , s , dict , dp);
        
    }
};
