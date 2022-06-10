class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.length(), ans = 0;
        bitset<256> seen(0);
        while(j < n) {
            if(seen[s[j]]) {
                ans = max(ans, j-i);
                while(seen[s[j]]) 
                    seen[s[i++]] = 0;
                j = max(j, i);
            }
            else
                seen[s[j++]] = 1;
        }
        ans = max(ans, j-i);
        return ans;
    }
};
