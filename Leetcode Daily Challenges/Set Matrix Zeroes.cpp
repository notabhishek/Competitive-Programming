class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool zerothcol = false, zerothrow = false;
        for(int i = 0; i < n; ++i) if(mat[i][0] == 0) zerothcol = true;
        for(int i = 0; i < m; ++i) if(mat[0][i] == 0) zerothrow = true;
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(mat[i][j] == 0) mat[0][j] = mat[i][0] = 0;
            }
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(mat[0][j] == 0 || mat[i][0] == 0) mat[i][j] = 0;
            }
        }
        if(zerothcol)
            for(int i = 0; i < n; ++i) mat[i][0] = 0;
        if(zerothrow)
            for(int i = 0; i < m; ++i) mat[0][i] = 0;
    }
};
