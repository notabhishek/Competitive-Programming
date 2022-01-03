class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0);
        unordered_map<int,int> m;
        for(auto p : trust) {
            in[p[1]]++;
            m[p[0]] = p[1];
        }
        int ans = -1;
        for(int i = 1; i <= n; ++i) {
            if(in[i] == n-1) {
                if(ans == -1 && m.count(i) == 0) {
                    ans = i;
                } else return -1;
            } 
        }
        return ans;
    }
};
