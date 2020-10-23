class Solution {
public:
    int longestDecomposition(string text) {
        string s = "";
        string t;
        int k = 0;
        int n  = text.length();
        for(int i = 0 ; i < n; ++i) {
            s+=text[i];
            t = text.substr(n-1-i, s.length());
            if(s == t) {
                ++k;
                s = "";
                t = "";
            }
        }
        return k;
    }
};