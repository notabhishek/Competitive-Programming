class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // Since the graph is unweighted we can use bfs
        // Multisource bfs
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector< vector<int >> dist( rows , vector<int> (cols, INT_MAX) );
        queue< array<int , 2 >> q;
        //Push all sources
        for(int r = 0 ; r < rows; ++r) 
        for(int c = 0 ; c < cols ; ++c) 
        if(matrix[r][c] == 0) { 
        dist[r][c] = 0;
        q.push({ r , c });
        }
	//BFS
        int dr[4] = { 0 , 0 , -1, 1};
        int dc[4] = {-1 , 1 , 0 , 0}; // Directions
        while(!q.empty()) { 
            int r , c;
            r =q.front()[0];
            c = q.front()[1]; 
            q.pop();
            for(int i = 0 ; i < 4; ++i) {
                int tr = r + dr[i];
                int tc = c + dc[i];
                if(tr >=0 && tr < rows && tc>=0 && tc < cols) {
                    if(dist[tr][tc] == INT_MAX)  {
                        dist[tr][tc] = dist[r][c] + 1;
                        q.push({tr ,tc });
                    } 
                }
            }
         }
        
	return dist;
    }
};
