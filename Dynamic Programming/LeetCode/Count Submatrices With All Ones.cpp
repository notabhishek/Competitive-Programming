class Solution {
public:
    // calculates number of rectangles in histogram,
    int calc(vector<int> &hist, int m) {
        int cur = 0;
        for(int i = 0 ; i < m; ++i) {
            int mn = hist[i]; //max height of rectangle
            for(int j = i; j < m; ++j){
                mn = min(mn , hist[j]);
                cur += mn;
            }
        }
        return cur;
    }
    int numSubmat(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        vector< int > pHist(m , 0);
        for(int i = 0; i < n; ++i) {
            vector<int> cHist(m , 0);
            for(int j = 0; j < m; ++j) 
                if(a[i][j] == 1) cHist[j] = pHist[j]+1;
            ans += calc(cHist , m);
            pHist = cHist;
        }
        return ans;
    }
};
