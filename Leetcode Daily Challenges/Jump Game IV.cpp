class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < n; ++i) 
            um[arr[i]].push_back(i);
        
        // bfs : find min dist between 0, n-1
        const int INF = 1e9;
        queue<int> q; 
        vector<int> dist(n, INF);
        dist[0] = 0;
        q.push(0);
        while(dist[n-1] == INF && !q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : um[arr[u]]) {
                if(dist[v] == INF) {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                }
            }
            um.erase(arr[u]); // erase from map as this won't be used ever: n^2 -> n
            
            if(u > 0 && dist[u-1] == INF) {
                dist[u-1] = 1 + dist[u];
                q.push(u-1);
            } 
            if(u < n-1 && dist[u+1] == INF) {
                dist[u+1] = 1 + dist[u];
                q.push(u+1);
            }
        }
        return dist[n-1];
    }
};
