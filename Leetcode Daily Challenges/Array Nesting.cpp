class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int n = a.size();
        vector<bool> vis(n , 0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                int cur = i;
                int len = 0;
                while(!vis[cur]) {
                    ++len; vis[cur] = 1;
                    cur = a[cur];
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
