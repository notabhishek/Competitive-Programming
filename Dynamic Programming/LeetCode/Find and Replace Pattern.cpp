class Solution {
public:
    bool match(string &a, string &b){
        vector<int> f(26, -1);
        vector<bool> can(26, 1);
        for(int i = 0; i < b.length(); ++i) {
            if(f[b[i] - 'a'] == -1) {
                if(!can[ a[i]-'a' ]) return false;
                f[b[i]-'a'] = a[i]-'a';
                can[ a[i] - 'a' ] = 0;
            } else if(f[b[i]-'a'] != (a[i] - 'a')) return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for(auto &w : words) {
            if(match(w, pattern))
                res.push_back(w);
        }
        return res;
    }
};
