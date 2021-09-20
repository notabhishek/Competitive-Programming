class Solution {
public:
    bool isWinner(vector<string> &b, char c) {
        for(int i = 0; i < 3; ++i) {
            if(b[i] == string(3, c)) return true;
            if(b[0][i] == c && b[1][i] == c && b[2][i] == c) return true; 
        }
        if(b[0][0]==c && b[1][1]==c && b[2][2]==c) return true;
        if(b[0][2]==c && b[1][1]==c && b[2][0]==c) return true;
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> b(3, string(3, '.'));
        for(int i = 0; i < moves.size(); ++i){
            char c = (i&1) ? 'O' : 'X';
            b[ moves[i][0] ][ moves[i][1] ] = c;
        }
        if(isWinner(b, 'X')) return "A";
        if(isWinner(b, 'O')) return "B";
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
