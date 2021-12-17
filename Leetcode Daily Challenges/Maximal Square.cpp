class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H = matrix.size(), W = matrix[0].size();
        
        vector<vector<int>>dp(H, vector<int>(W));
        int maxSquare = 0;
        
        for(int row = 0; row < H; row++){
            for(int col = 0; col < W; col++){
                if(matrix[row][col] == '1'){
                    if(row == 0 || col == 0){
                        dp[row][col] = 1;
                    }else{
                        dp[row][col] = min({ dp[row - 1][col - 1], 
                                             dp[row][col - 1],
                                             dp[row - 1][col]}) + 1;
                    }   
                }
                
                maxSquare = max(maxSquare, dp[row][col]);
            }
        }
        
        return maxSquare * maxSquare;
    }
};
