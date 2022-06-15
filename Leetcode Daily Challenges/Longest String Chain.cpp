class Solution {
public:
    bool chain(string &s, string &t) {
        if(s.length() != t.length()-1) return false;
        int i = 0; 
        while(i < s.length() && s[i] == t[i])++i;
        if(i == s.length()) return true;
        while(i < s.length() && s[i] == t[i+1])++i;
        return i == s.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a , string &b){
            return a.length() < b.length(); 
        });
        int n = words.size(), ans = 1;
        vector<int> chainLength(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = i-1; j >= 0 && words[j].length() >= words[i].length()-1; --j) {
                if(chain(words[j], words[i])) 
                    chainLength[i] = max(chainLength[i], 1 + chainLength[j]);
            }
            ans = max(ans, chainLength[i]);
        }
        return ans;
    }
};
