class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int u, vector<int> &path, int dest, vector<vector<int>> &g) {
        path.push_back(u);
        if(u == dest) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(int v : g[u])
            dfs(v, path, dest, g);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, path, graph.size()-1, graph);
        return ans;
    }
};
