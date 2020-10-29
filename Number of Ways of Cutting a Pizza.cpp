#define vt vector
class Solution {
public:
    const int M = 1e9 + 7;
    int n , m;
    int cut(int sr, int sc, int k , vt<vt<vt<int>>> &dp , vt<string> &a)  {
        int &ret = dp[sr][sc][k];
        if(ret != -1)
            return ret;
        
        ret = 0;
        
        if(k == 1) {
            // Can be done in O(1) using precomputation
            for(int i = sr; i < n; ++i) 
                for(int j = sc; j <m; ++j) 
                    if(a[i][j] == 'A')
                        return ret = 1;
            return ret;
        }
        
        //Cut Vertically
        bool apples = 0;
        for(int c = sc; c < m-1; ++c) {
            
            // Can be done in O(1) using precomputation
            for(int r = sr; r < n; ++r )
                apples |= a[r][c] == 'A';
            if(apples) {
                ret = (ret + cut(sr , c+1 , k-1 , dp , a)) % M;
            }
        }
        apples = false;
        for(int r = sr; r < n-1; ++r) {
            // Can be done in O(1) using precomputation
            for(int c = sc; c < m; ++c) 
                apples |= a[r][c] == 'A';
            if(apples)
                ret = (ret + cut(r+1, sc , k-1 , dp, a)) % M;
        }
        return ret;
    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        vt<vt<vt<int>>> dp(n , vt<vt<int>>(m , vt<int>(k + 1, -1)));
        return cut(0 , 0 , k , dp, pizza);
    }
};
