class Solution {
public:
    int solveRows(vector<vector<int>> &a) {
        int ans = 0, n = a.size();
        map< vector<int>, vector<int>> m;
        for(int i = 0; i < n; ++i) m[a[i]].push_back(i);
        if(m.size() != 2) return -1; // there can be at max 2 different rows
        int c1 = m.begin()->second.size();
        int c2 = next(m.begin())->second.size();
        if(abs(c2-c1) > 1) return -1;
        auto it = (c1 <= c2 ? m.begin() : next(m.begin()));
        int cnt[2] = {0};
        for(auto &i : it->second) cnt[i%2]++;
        if(n&1) return cnt[0];
        return min(cnt[0], cnt[1]);
    }
    int solveCols(vector<vector<int>> &a) {
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j){
                swap(a[i][j], a[j][i]);
            }
        }
        return solveRows(a);
    }
    int movesToChessboard(vector<vector<int>>& board) {
        int rowans = solveRows(board);
        if(rowans == -1) return -1;
        int colans = solveCols(board);
        if(colans == -1) return -1;
        return rowans + colans;
    }
};
