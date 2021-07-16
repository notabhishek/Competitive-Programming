class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int k) {
        set< vector<int>> s;
        int n = a.size();
        map< int, vector< pair< int, int >> > m;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j) {
                m[a[i]+a[j]].push_back({i,j});
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j) {
                if(m.count(k - a[i]-a[j])) {
                    for(auto &p : m[k-a[i]-a[j]]) {
                        if(p.first == i || p.first == j ||  p.second == i || p.second == j)
                            continue;
                        vector<int> res = {a[i], a[j], a[p.first], a[p.second]};
                        sort(res.begin(), res.end());
                        s.insert(res);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto &u : s) ans.push_back(u);
        return ans;
    }
};
