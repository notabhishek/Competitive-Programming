class Solution {
public:
    inline bool isCap(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(char c : word)
            cnt += isCap(c);
        return isCap(word[0]) ? (cnt == 1 || cnt == word.length()): cnt == 0;
    }
};
