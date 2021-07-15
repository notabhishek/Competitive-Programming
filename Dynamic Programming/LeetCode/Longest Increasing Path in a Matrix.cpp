class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        if(!m) return 0;
        vector<vector<int> > in(n , vector<int>(m , 0));
        int dr[4] = {-1 , 1 , 0 , 0 };
        int dc[4] = {0 , 0 , -1 , 1};
        queue<array<int ,2 >> q;
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) {
                for(int k = 0 ; k < 4; ++k) {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if(r>=0 && r < n && c>=0 && c<m && matrix[r][c] > matrix[i][j])
                        in[i][j]++;
                }
                if(in[i][j]==0)
                    q.push({i , j});
            }
        vector<array<int , 2>> tops;
        while(!q.empty()) {
            array<int , 2> src = q.front();
            tops.push_back(src);
            q.pop();
            for(int i = 0 ; i < 4; ++i) {
                int r = src[0] + dr[i];
                int c = src[1] + dc[i];
                if(r>=0 && r<n && c>=0 && c<m && matrix[src[0]][src[1]]>matrix[r][c] && --in[r][c]==0)
                    q.push({r,c});
            }
        }
        //for(auto &i : tops )cout <<i[0] << " " << i[1] << " = " << matrix[i[0]][i[1]] <<endl; 
        int len = 1;
        for(int j = tops.size()-1; j>=0; --j){
            int r = tops[j][0];
            int c= tops[j][1];
            in[r][c] = 1;
            for(int k = 0 ; k <4; ++k){
                int tr = r + dr[k];
                int tc = c + dc[k];
                if(tr>=0 && tr<n && tc>=0 && tc<m && matrix[tr][tc] < matrix[r][c])
                    in[r][c] = max(in[r][c] , 1 + in[tr][tc]); 
            }
            len = max(len , in[r][c]);
        }
        //for(int i = 0 ; i < n; ++i) {for(int j = 0 ; j < m; ++j)cout << in[i][j] << " "; cout << endl; }
        return len;
    }
};
