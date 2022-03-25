template<typename T> ostream & operator << (ostream &os, const vector<T> &v) {
    os << "[ ";
    for(T a : v) os << a << ", ";
    os << "]\n";
    return os;
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<int> prev(n+1, 1e9);
        prev[0] = 0;
        for(auto &cost: costs) {
            vector<int> cur(n+1);
            cur[0] = prev[0] + cost[1];
            for(int i = 1; i <= n; ++i) {
                cur[i] = min(prev[i] + cost[1], prev[i-1] + cost[0]);
            }
            // cout << cur;
            swap(cur, prev);
        }
        return prev[n];
    }
};
