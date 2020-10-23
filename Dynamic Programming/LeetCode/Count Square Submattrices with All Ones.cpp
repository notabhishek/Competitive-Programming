class Solution {
public:
    bool square(int i , int j , int x , int y , vector<vector<int>> &csum) {
        int ones = csum[x][y] + csum[i][j] - csum[i][y] - csum[x][j];
        return ones == (x-i)*(y-j);
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> csum(n+1 , vector<int> (m+1 , 0));
        for(int i = 1 ; i <= n;++i)
            for(int j= 1; j <= m; ++j)
                csum[i][j] = matrix[i-1][j-1] + csum[i][j-1];
        for(int j = 1; j <= m; ++j)
            for(int i = 1; i <= n; ++i)
                csum[i][j]+=csum[i-1][j];
        //for(auto &i : csum) {for(auto &j : i ) cout << j << " "; cout << endl;}
        int ans = 0;
        for(int len = 1; len<= min(m , n); ++len){
            for(int i = 0; i <=(n-len); ++i)
                for(int j = 0; j <=(m-len); ++j) {
                    int x = i+len;
                    int y = j+len;
                    if(square(i , j , x , y , csum)){
                        //cout <<i << " "<<j << " " << x << " "<< y << endl;
                        ++ans;
                    }
                }
        }
        return ans;
    }
};