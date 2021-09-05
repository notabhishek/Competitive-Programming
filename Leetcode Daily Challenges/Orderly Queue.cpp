class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            // only rotations are possible
            string res = s;
            for(int i = 1; i < s.length(); ++i) {
                s = s.substr(1) + s[0];
                res = min(res, s);
            }
            return res;
        } else {
            // all possible arrangements of string are possible
            sort(s.begin(), s.end());
            return s;
        }
    }
};
