class Solution {
public:
    vector<int> R[9];
    vector<int> C[9];
    vector<int> sub[9];
    bool fill(int r,int c, vector<vector<char>> &b) {
        if(r == 9) return true;
        if(c >= 9) 
            return fill(r+1, 0, b);
        if(b[r][c]!='.') return fill(r, c+1, b);
        for(int i = 1; i <= 9; ++i) {
            // chk if i can be filled 
            if(R[r][i] || C[c][i] || sub[(r/3)*3 + (c/3)][i])
                continue;
            
            b[r][c] = char(i + '0');
            R[r][i]++, C[c][i]++, sub[(r/3)*3 + (c/3)][i]++;
            
            if(fill(r,c+1, b)) return true;
            
            //backtrack
            b[r][c] = '.';
            R[r][i]--, C[c][i]--, sub[(r/3)*3 + (c/3)][i]--;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& b) {
        
        for(int i = 0; i < 9; ++i) sub[i] = R[i] = C[i] = vector<int>(10, 0);
        for(int i = 0; i < 9; ++i) {
            for(int j =0; j < 9; ++j) {
                if(b[i][j]!= '.') {
                    R[i][b[i][j]-'0']++;
                    C[j][b[i][j]-'0']++;
                    sub[ (i/3)*3 + (j/3) ][ b[i][j]-'0'] ++;
                }
            }
        }
        fill(0, 0, b);
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) cout << b[i][j] << " ";
            cout << "\n";
        }
    }
};
