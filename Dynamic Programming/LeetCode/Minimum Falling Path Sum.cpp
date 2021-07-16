class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        if(!n) return 0;
        for(int i = n-2; i>=0; --i) 
            for(int j = 0; j <n; ++j) {
                int mn = INT_MAX;
                for(int k : {j-1 , j , j+1}) 
                    if(k>=0 && k<n)
                        mn = min(mn , A[i+1][k]);
                A[i][j]+=mn;
            }
        return *min_element(A[0].begin() , A[0].end());
    }
};
