class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.length()-1;
        while(i < j && s[i] == s[j]) ++i, --j;
        return i >= j ? 1 : 2;
    }
};
