class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
        const int arrays = 3;
        
        int n = a.size();
        int pre[n+1];
        pre[0] = 0;
        for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i-1];
        // sum[i][j] = max sum till i, having j subarrays
        vector< vector<int>> sum(n+1, vector<int> (arrays+1, 0));
        // child[i][j] == 0 -> -- else -= k
        vector< vector<int>> child(n+1, vector<int> (arrays+1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= arrays; ++j) {
                sum[i][j] = sum[i-1][j];
                child[i][j] = 0;
                
                if(i >= k && (pre[i] - pre[i-k] + sum[i-k][j-1]) > sum[i][j]) {
                    sum[i][j] = sum[i-k][j-1] + pre[i] - pre[i-k];
                    child[i][j] = i;
                } 
            }
        }
        // get indices
        int cur = n, ar = arrays;
        vector<int> res;
        while(ar > 0 && cur > 0) {
            if(child[cur][ar] == 0) --cur;
            else {
                res.push_back(cur-k);
                cur -= k; --ar;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
