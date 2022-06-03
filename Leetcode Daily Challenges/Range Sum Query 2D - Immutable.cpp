class NumMatrix {
    vector<vector<int>> s;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        s = vector<vector<int>>(n+1, vector<int>(m+1));
        for(int r = 1; r <= n; ++r)
            for(int c = 1; c <= m; ++c) 
                s[r][c] = s[r-1][c] + s[r][c-1] - s[r-1][c-1] + mat[r-1][c-1];
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return s[r2+1][c2+1] - s[r1][c2+1] - s[r2+1][c1] + s[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
