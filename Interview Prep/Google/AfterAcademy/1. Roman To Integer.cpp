/**
 * @type of s: string
 * @return type: integer
 */
class Solution {
public:
    int romanToInt(string s) {
        // write your awesome code here
        int ans = 0, n = s.length();
        for(int i = 0; i < n; ++i) {
        	switch(s[i]){
                case 'I': ans += (i+1<n && (s[i+1]=='V' || s[i+1]=='X')) ? -1:1; break;
                case 'V': ans += 5; break;
                case 'X': ans += (i+1<n && (s[i+1]=='L' || s[i+1]=='C')) ? -10:10; break;
                case 'L': ans += 50; break;
                case 'C': ans += (i+1<n && (s[i+1]=='D' || s[i+1]=='M')) ? -100:100; break;
                case 'D': ans += 500; break;
                case 'M': ans += 1000;
            }
        }
        return ans;
    }
};
