class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& p) {
        vector<int> ugly(1, 1);
        int m = p.size();
        vector<int> ptr( m , 0);
        for(int u = 1; u < n; ++u) {
            vector<int> newugly(m, 0);
            int mn = INT_MAX;
            for(int i = 0 ; i < m; ++i) {
                newugly[i] = ugly[ptr[i]] * p[i];
                if(newugly[i] > ugly.back())
                    mn = min(mn , newugly[i]);
            }
            ugly.push_back(mn);
            for(int i = 0 ; i < m; ++i) 
                if(newugly[i] == mn) 
                    ++ptr[i];
        }
        // for(auto &i : ugly) cout << i << " ";
        return ugly[n-1];
    }
};
