class Solution {
public:
    bool chkPossible(string &s1, string &s2) {
        unordered_set<char> a(s1.begin(), s1.end());
        for(char c : s2) if(a.count(c) == 0) return false;
        return true;
    }
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(!chkPossible(s1, s2)) return false;
        int l1 = s1.length(), l2 = s2.length();
        vector<long long> dp(l1); // number of chars to make s2 a subseq
        for(int s = 0; s < l1; ++s) {
            int i = s, j = 0;
            while(j < l2) {
                if(s1[i%l1] == s2[j]) ++j;
                ++i;
            }
            dp[s] = i - s;
        }
        
        
        int cur = 0 , tchars = l1 * n1, ans = 0;
        int L = 1 + ceil(log2(tchars));
        vector<vector<long long>> st(L, vector<long long> (l1));
        st[0] = dp;
        for(int i = 1; i < L; ++i)  
            for(int j = 0; j < l1; ++j)
                st[i][j] = st[i-1][j] + st[i-1][ (j+st[i-1][j])%l1 ];
        // cout << st;
        for(int i = L-1; i >= 0; --i) {
            if(cur + st[i][cur%l1] <= tchars) {
                cur = cur + st[i][cur%l1];
                ans += (1<<i);
            }
        }
        return ans/n2;
        
    }
};
