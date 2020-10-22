class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rows = mat.size();
        int cols = mat[0].size();
        for(int r = 0 ; r < rows; ++r)
        for(int c = 1; c < cols ; ++c )
            mat[r][c] += mat[r][c-1];
        
        for(int c = 0 ; c < cols; ++c )
            for(int r = 1; r < rows; ++r)
                mat[r][c] += mat[r-1][c];
        
        vector<vector<int>> res(rows ,  vector<int> (cols));
        for(int r = 0 ; r < rows; ++r)
            for(int c = 0; c < cols; ++c) {
                int tr = max( 0 , r - K) , tc = max(0 , c - K);
                int br = min( rows-1 , r+K) , bc = min(cols-1 , c + K);
                
                res[r][c] = mat[br][bc];
                if(tr !=0 ) {
                    res[r][c] -= mat[tr - 1][bc];
                } 
                if(tc !=0 ) {
                    res[r][c] -= mat[br][ tc - 1 ];
                }
                if(tr!=0 && tc!=0) {
                    res[r][c] += mat[tr-1][tc-1];
                }
            }
        return res;
    }
};