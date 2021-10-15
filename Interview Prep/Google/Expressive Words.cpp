class Solution {
public:
    bool isStretchy(string &w, string &s) {
        int i = 0, j = 0;
        int n = w.length(), m = s.length();
        while(i < n && j < m){
            if(w[i] != s[j]) return false;
            int ti = i, tj = j;
            while(ti < n && w[ti] == w[i]) ++ti;
            while(tj < m && s[tj] == s[j]) ++tj;
            int scount = tj - j;
            int wcount = ti - i;
            if(scount == wcount || (scount >= 3  && scount >= wcount)) {
                i = ti;
                j = tj;
            } else return false;
        }
        return i == n && j == m;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for(string w : words) {
            if(isStretchy(w, s)) ++ans;
        }
        return ans;
    }
};
