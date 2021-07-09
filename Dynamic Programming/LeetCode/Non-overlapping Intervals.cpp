class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin() , a.end(), [](vector<int> &u, vector<int>&v) {
        if(u[1] == v[1])
            return u[0] < v[0];
           return u[1] < v[1]; 
        });
        int n = a.size();
        int ans = 0;
        int en = a[0][1];
        for(int i = 1; i < n; ++i) {
            if( en > a[i][0] )
                ++ans;
            else {
                en = max(en , a[i][1]);
            }
        }
        return ans;
    }
};
