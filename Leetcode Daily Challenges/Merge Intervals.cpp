class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int st = a[0][0], en = a[0][1];
        vector<vector<int>> res;
        for(int i = 1; i < a.size(); ++i) {
            if(en < a[i][0]) {
                res.push_back({st, en});
                st = a[i][0];
                en = a[i][1];
            } else en = max(en, a[i][1]);
        }
        res.push_back({st, en});
        return res;
    }
};
