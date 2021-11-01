class Solution {
public:
    const int r4[4] = {1, -1, 0, 0};
    const int c4[4] = {0, 0, 1, -1};
    void dfs(int r, int c, vector<vector<char>> &board, char c1, char c2) {
        board[r][c] = c2;
        for(int i = 0; i < 4; ++i) {
            int tr = r + r4[i];
            int tc = c + c4[i];
            if(tr >= 0 && tr < board.size() && tc >= 0 && tc < board[0].size() && board[tr][tc] == c1) 
                dfs(tr, tc, board, c1, c2);
        } 
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        if(m == 0) return;
        char c1 = 'O', c2 = '#';
        for(int r = 0; r < n; ++r) {
            if(board[r][0] == c1) dfs(r, 0, board, c1, c2);
            if(board[r][m-1] == c1) dfs(r, m-1, board, c1, c2);
        }
        for(int c = 0; c < m; ++c) {
            if(board[0][c] == c1) dfs(0, c, board, c1, c2);
            if(board[n-1][c] == c1) dfs(n-1, c, board, c1, c2);
        }
        
        for(int i = 1; i < n-1; ++i) 
            for(int j = 1; j < m-1; ++j)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        swap(c1, c2);
        for(int r = 0; r < n; ++r) {
            if(board[r][0] == c1) dfs(r, 0, board, c1, c2);
            if(board[r][m-1] == c1) dfs(r, m-1, board, c1, c2);
        }
        for(int c = 0; c < m; ++c) {
            if(board[0][c] == c1) dfs(0, c, board, c1, c2);
            if(board[n-1][c] == c1) dfs(n-1, c, board, c1, c2);
        }
    }
};
