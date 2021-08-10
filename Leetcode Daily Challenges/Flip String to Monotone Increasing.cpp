class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int lz = 0, lo = 0, rz = count(s.begin(), s.end(), '0'), ro = count(s.begin(), s.end(), '1');
        int ans = s.length();
        for(int i = 0; i < s.length(); ++i) {
            ans = min(ans, lo + rz);
            if(s[i] == '0') {++lz; --rz;}
            else if(s[i]=='1') {++lo; --ro;};
        }
        ans = min(ans, lo + rz);
        return ans;
    }
};
