class Solution {
public:
    vector<vector<vector<int>>> dp;
    int rec(int i, int j, int k, vector<int> &a) {
        if(i > j)
            return 0;
        int &ret = dp[i][j][k];
        if(ret != -1)
            return ret;
        int idx = i;
        while(idx <=j && a[idx] == a[i]) ++idx;
        ret = (k + idx - i) * (k + idx - i) + rec(idx, j, 0, a);
        for(int u = idx; u < j; ++u) {
            if(a[u+1] == a[i])
            ret = max(ret, rec(idx, u, 0, a) + rec(u+1, j, k+idx-i, a));
        }
        return ret;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n+1, -1)));
        int ans = rec(0, n-1, 0, boxes);
        return ans;
    }
};
