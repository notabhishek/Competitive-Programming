class Solution {
public:
    #define pb push_back 
void dfs(int src , int par ,int cur_id, vector<int> &vis , vector<int> &id, vector<int> &low , vector<vector<int>> &bridges ,vector<vector<int>> &adj) {
	id[ src ] = cur_id;
	vis[src] = 1;
	low[src] = cur_id;
	++cur_id;
	for(auto &node : adj[src]) {
		if(node == par) continue;
		if(!vis[node]) { 
			 // call dfs
			dfs( node , src , cur_id , vis ,  id, low , bridges , adj);
			low[src] = min( low[src] , low[node]);  
			// Nope yahi par to bridge milenge
			if( low[node] > id[src] )  
				bridges.pb({ node , src });
			
} else 
low[ src] = min(low[src] , low[node]); // Already vis edge maybe a path to low Link
	}
} 

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
	    for(auto &i : connections) {
            adj[ i[0] ].pb( i[1] );
            adj[ i[1] ].pb( i[0] );
        }
        vector<vector<int>> bridges;
            //Now call dfs
            vector<int> vis(n , false);
            vector<int> id(n , 0); // id of the node
            vector<int> low(n , 0); //lowest link
            for(int i = 0 ; i < n; ++i) { 
            if(!vis[i]) 
            dfs(i , -1 ,0, vis  , id , low , bridges , adj);
        }
        return bridges;

    }
};
