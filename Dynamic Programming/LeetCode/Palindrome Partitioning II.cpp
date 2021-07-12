class Solution {
public:
    vector< vector< bool >> palin;
    void initPalin(string &s, int n) {
        palin.resize(n , vector<bool>(n, false));
        
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i + len<= n; ++i) {
                int j = i + len-1;
                if(len == 1) 
                    palin[i][i] = 1;
                else if(len==2) palin[i][j] = s[i] == s[j];
                else palin[i][j] = (s[i]==s[j]) & palin[i+1][j-1];
            }
        }
    }
    int minCut(string s) {
        int n = s.length(); 
        
        // fill palindrome dp
        initPalin(s, n);
        
        // cuts[i] = number of cuts for s[0...i]
        int cuts[n];
        cuts[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(palin[0][i])
                cuts[i] = 0;
            else {
                cuts[i] = i+1;
                for(int j = 0; j < i; ++j) 
                    if(palin[j+1][i]) cuts[i] = min(cuts[i] , 1 + cuts[j]);
             }
        }
        // for(int i = 0; i < n; ++i) cout << cuts[i] << " "; cout << endl;
        return cuts[n-1];
    }
};
