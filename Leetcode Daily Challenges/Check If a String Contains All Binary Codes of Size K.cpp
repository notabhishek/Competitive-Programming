class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        int cur = 0;
        for(int i = 0; i < k; ++i) 
            cur = (cur<<1) + s[i]-'0';
        vector<bool> present(1<<k, false);
        present[cur] = true;
        int p = 1;
        for(int i = k; i < s.length(); ++i) {
            if(s[i-k] == '1')
                cur ^= (1<<(k-1));
            cur = (cur<<1) + s[i]-'0';
            if(!present[cur]) {
                present[cur] = true;
                ++p;
            }
        }
        return p == (1<<k);
    }
};
