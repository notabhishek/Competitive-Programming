const int NAX = 1e3 + 5;
class Solution {
public:
    int P[NAX][NAX];
    bool pal(int i , int j , string &s) {
        int &ret = P[i][j];
        if(ret != -1)
            return ret;
        if(j-i == 1) {
            return ret = (s[i] == s[j]);
        }
        return ret = (s[i]==s[j] && pal(i + 1 , j-1 , s));
    }
    int countSubstrings(string s) {
        memset(P , -1 , sizeof P);
        for(int i = 0 ; i < s.length(); ++i) 
            P[i][i] = 1;
        int ans = 0;
        for(int i = 0 ; i < s.length(); ++i) {
            for(int j = i; j < s.length(); ++j) {
                if(pal(i, j , s))
                    ++ans;
            }
        }
        return ans;
    }
};
