class Solution {
public:
        bool safe(int row, int col , vector<string> &board) {
            //check same column
            for(int r = row+1; r < board.size(); ++r) 
                if(board[r][col] == 'Q')
                    return false;
            for(int r = row+1 , c = col-1; r < board.size() && 0 <= c; ++r , --c) {
                if(board[r][c] == 'Q')
                    return false;
            }
            for(int r = row+1 , c = col+1; r < board.size() && c < board.size(); ++r , ++c) {
                if(board[r][c] == 'Q')
                    return false;
            }
            return true;
        }
        void placeQueens(int row , vector<string> &board , vector<vector<string>> &res) {
            if(row == -1) {
                // Reached a valid config
                res.push_back(board);
                return;
            }
            for(int col = 0; col < board.size(); ++col) {
               if( safe(row , col , board ) ) {
                   board[row][col] = 'Q'; // Place Queen
                   placeQueens(row -1 , board , res);
                   board[row][col] = '.'; // Backtrack
               } 
            }
        }
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string > > res;
        vector< string > board(n , string(n , '.'));
        if( n ==0 )
            return res;
        placeQueens(n- 1, board , res);
        return res;
    }
};
