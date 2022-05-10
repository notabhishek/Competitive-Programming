class Solution {
    vector<vector<int>> res;
    vector<int> cur;
public:
    void rec(int n, int k, int d) {
        if(d == 0) {
            if(k == 0 && n == 0) 
                res.push_back(cur);
            return;
        }
        // dont take 
        rec(n, k, d-1);
        // take
        cur.push_back(d);
        rec(n-d, k-1, d-1);
        cur.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        rec(n, k, 9);
        return res;
    }
};
