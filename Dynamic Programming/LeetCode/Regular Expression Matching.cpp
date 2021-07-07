class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int m;
    
    bool f(int i , int j, string &s, string &p) {
        if(i < 0) {
            bool f = ((j+1)%2 == 0);
            for(int v = j; v >= 0; v-=2) f = f && (p[v] == '*');
            return f;
        }
        if(j < 0)
            return 0;
        
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        
        if(p[j] != '*') {
            return ret = (p[j] == '.' ||  s[i] == p[j]) && f(i-1, j-1, s, p);
        } else {
            char prev = p[j-1];
            ret = f(i, j-2, s, p);
            bool match = true;
            for(int u = 0; u <= i; ++u) {
                match = match && (prev == '.' || s[i-u] == prev);
                if ( !match )
                    break;
                ret = ret || (match && f(i-1-u, j-2, s, p));
            }
            return ret;
        }
    }
    bool isMatch(string s, string p) {
        string newp = "";
        for(int i = 0; i < p.size();) {
            newp += p[i];
            if(p[i] == '*' ){
                int j = i + 1;
                while(j < p.size() && p[j] == '*') ++j;
                i = j;
            } else ++i;
        }
        p = newp;
        
        n = s.size();
        m = p.size();
        dp.resize( n , vector<int> (m , -1));
        bool ans = f(n-1, m-1, s, p);
        return ans;
    }
};
