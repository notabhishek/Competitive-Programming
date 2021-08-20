class Solution {
public:
    bool chkR(int r, vector<vector<char>> &b) {
        vector<int> vis(10, 0);
        for(int i = 0; i < b[r].size(); ++i) {
            if(b[r][i]!='.' && vis[b[r][i]-'0'] != 0) return false;
             if(b[r][i]!='.') vis[b[r][i]-'0'] = 1;
        }
        return true;
    }
    bool chkC(int c, vector<vector<char>> &b) {
        vector<int> vis(10, 0);
        for(int i = 0; i < b.size(); ++i) {
            if(b[i][c]!='.' && vis[b[i][c]-'0'] != 0) return false;
             if(b[i][c]!='.') vis[b[i][c]-'0'] = 1;
        }
        return true;
    }
    bool chk3(int r, int c, vector<vector<char>> &b) {
        vector<int> vis(10, 0);
        for(int i = 0; i < 3; ++i){
            for(int j= 0; j < 3; ++j) {
                if(b[i+r][c+j]!='.' && vis[b[i+r][c+j]-'0'] != 0) return false;
                if(b[i+r][c+j]!='.') vis[b[i+r][c+j]-'0'] = 1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i = 0; i < 9; ++i) if(!chkR(i, b) || !chkC(i, b)) return false;
        for(int i = 0; i < 9; i+=3)
            for(int j =0; j < 9; j+=3) 
                if(!chk3(i,j,b)) return false;
        return true;
    }
};
