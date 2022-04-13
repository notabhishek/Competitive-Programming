class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int> (n));
        int k = 1, r1 = 0, r2 = n-1, c1 = 0, c2 = n-1;
        while(r1 <= r2 && c1 <= c2) {
            for(int c = c1; c <= c2; ++c) 
                a[r1][c] = k++;
            for(int r = r1+1; r <= r2; ++r) 
                a[r][c2] = k++;
            for(int c = c2-1; c>=c1; --c)
                a[r2][c] = k++;
            for(int r = r2-1; r > r1; --r)
                a[r][c1] = k++;
            ++c1; --c2;
            ++r1; --r2;
        }
        return a;
    }
};
