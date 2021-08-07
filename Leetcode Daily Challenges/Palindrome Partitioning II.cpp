class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        // fill isPal
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i+len-1<n; ++i) {
                int j = i+len-1;
                if(len == 1) isPal[i][j] = 1;
                else if(len == 2) isPal[i][j] = s[i] == s[j];
                else isPal[i][j] = (s[i]==s[j]) && isPal[i+1][j-1];
            }
        }
        
        vector<int> cuts(n, 0);
        for(int i = 0; i < n; ++i) {
            cuts[i] = i+1;
            for(int j = i; j >= 0; --j) {
                //cuts[i] =  cuts[j-1] + (j...i) 
                if(isPal[j][i]) 
                    cuts[i] = min(cuts[i], (j>0 ? 1 + cuts[j-1] : 0));
            }
        }
        return cuts[n-1];
        
    }
};
