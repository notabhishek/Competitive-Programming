class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;
        int i = 0, n = s.length();
        while( i < n ) {
            int j = i+1 , mc = cost[i], tc = cost[i];
            while(s[j] == s[i]) {
                mc = max(mc, cost[j]);
                tc += cost[j];
                ++j;
            }
            res += tc - mc;
            i = j;
        }
        return res;
    }
};
