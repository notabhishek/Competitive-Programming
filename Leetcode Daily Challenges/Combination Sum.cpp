class Solution {
public:
    void dfs(int n, vector<int> &c, vector<int>&cur,int target, vector< vector<int>> &ans) {
        if(target < 0 ) 
            return;
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(n < 0)
            return;
        dfs(n-1 , c, cur , target , ans);
        if(target >= c[n] ) {
            cur.push_back(c[n]);
            dfs(n , c , cur , target - c[n] , ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector< int >> ans;
        vector< int > cur;
        dfs(candidates.size()-1 , candidates,cur, target , ans);
        return ans;
    }
};
