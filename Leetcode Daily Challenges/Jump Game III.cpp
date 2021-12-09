class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(arr[u] == 0) return true;
            if(u>=arr[u] && !vis[u-arr[u]]) {
                q.push(u-arr[u]);
                vis[u-arr[u]] = 1;
            } 
            if(u+arr[u]<n && !vis[u+arr[u]]) {
                q.push(u+arr[u]);
                vis[u+arr[u]] = 1;
            } 
        }
        return false;
    }
};
