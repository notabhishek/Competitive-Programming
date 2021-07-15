class Solution {
public:
    int minimumDeletions(string s) {
        // same as 01 problem 
        int n = s.length();
        int c[2] = {0};
        int pre[n+1];
        pre[0] = 0;
        for(int i = 1; i <= n; ++i)  {
            pre[i] = pre[i-1] + (s[i-1] - 'a');
            c[s[i-1]-'a']++;
        }
        
        int ans =  c[0];// all bs
        // all a <i and b >= i
        for(int i = 1; i <= n; ++i) {
            // cur =  cnt b < i + cnt a >= i
            int cur = pre[i] + (n-i - pre[n] + pre[i]);
            ans = min(ans, cur);
        }
        return ans;
    }
};
