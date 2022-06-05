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
        int placeQueens(int row , vector<string> &board ) {
            if(row == -1) {
                // Reached a valid config
                return 1;
            }
            int total = 0;
            for(int col = 0; col < board.size(); ++col) {
               if( safe(row , col , board ) ) {
                   board[row][col] = 'Q'; // Place Queen
                   total +=placeQueens(row -1 , board);
                   board[row][col] = '.'; // Backtrack
               } 
            }
            return total;
        }
    int totalNQueens(int n) {
        vector< string > board(n , string(n , '.'));
        if( n ==0 )
            return 0;
        return placeQueens(n- 1, board);
    }
};
