class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> a;
        for(int r = 0; r < mat.size(); ++r) {
            int c = 0;
            while(c < mat[r].size() && mat[r][c] == 1) ++c;
            a.push_back({c, r});
        }
        sort(a.begin(), a.end());
        vector<int> res(k);
        for(int i = 0; i < k; ++i) 
            res[i] = a[i].second;
        return res;
    }
};
