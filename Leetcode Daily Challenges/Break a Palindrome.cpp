class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if(n == 1) return "";
        bool allA = true;
        for(int i = 0; i < n/2; ++i) {
            if(s[i] != 'a') {
                allA = false;
                s[i] = 'a';
                break;
            }
        }
        if(allA) s[n-1] = 'b';
        return s;
    }
};
