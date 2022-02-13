template< typename T> ostream& operator << (ostream &os, vector<T> &v) {
    os << "[ ";
    for(T u : v) os << u << ", ";
    os << " ]\n";
    return os;
}
template< typename T> ostream& operator << (ostream &os, set<T> &v) {
    os << "{ ";
    for(T u : v) os << u << ", ";
    os << " }\n";
    return os;
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set< vector<int> > s;
        s.insert(vector<int>());
        for(int num : nums) {
            set< vector<int> > t;
            for(auto u : s) {
                u.push_back(num);
                t.insert(u);
            }
            for(auto &x : t)
                s.insert(x);
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};
