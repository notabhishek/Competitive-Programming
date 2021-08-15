class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        
        // assuming m < n, if not we can jus transpose the matrix
        // select 2 cols c1, c2 [also works for follow up problem]
        // insert all prefix row sums between these cols in a bst and search for curPrefSum-k
        // Complexity: m*m* n*logn (when m is small, -> nlogn)
        
        // calculate prefix row sums
        for(int i = 0; i < n; ++i) 
            for(int j = 1; j <m; ++j) a[i][j] += a[i][j-1];
        
        int ans = INT_MIN;
        // select 2 columns
        for(int c1 = 0; c1<m; ++c1) {
            for(int c2= c1; c2 <m; ++c2) {
                // make a set of all prefix sums between these rows
                set<int> prefSums;
                prefSums.insert(0);
                int cur = 0; 
                for(int i = 0; i < n; ++i) {
                    cur += a[i][c2] - (c1==0?0 : a[i][c1-1]);
                    
                    auto it = prefSums.lower_bound(cur - k);
                    if(it != prefSums.end()) {
                        ans = max(ans, cur - *it);
                    }
                    
                    prefSums.insert(cur); 
                }
            }
        }
        return ans;
    }
};
