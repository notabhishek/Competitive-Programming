class Solution {
public:
    vector<vector<vector<int>>> dp;
    // dp[i][j][k] = max score after solving i-j, where there are k boxes same as a[i] before idx i
    int rec(int i, int j, int k, vector<int> &b) {
        if(i > j) return 0;
        int &ret = dp[i][j][k];
        if(ret != -1)
            return ret;
        ret = 0;
        // case1: remove the boxes that you have at the start
        int idx = i;
        while(idx <=j && b[idx] == b[i]) ++idx;
        ret = max(ret, (k + idx-i)*(k + idx-i) + rec(idx, j, 0, b) );
        
        // case2: remove other boxes to increase boxes at the start
        for(int u = idx; u <= j; ++u) {
            if(b[u] == b[i])
                // .k...a[i]... | a[idx]....a[u-1] | a[u]...... a[j]
                // solve a[idx]...a[u-1] and then merge Left, Right halves
                ret = max(ret, rec(idx, u-1, 0, b) + rec(u, j, k+idx-i, b));
        }
        return ret;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = rec(0, n-1, 0, boxes);
        return ans;
    }
};
