class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> g;
        map<vector<int>, vector<string>> m;
        for(auto &i : strs) {
            vector<int> f(26, 0);
            for(auto &j : i) f[j-'a']++;
            m[f].push_back(i);
        }
        vector<vector<string>> res;
        for(auto &i : m) res.push_back(i.second);
        return res;
    }
};
