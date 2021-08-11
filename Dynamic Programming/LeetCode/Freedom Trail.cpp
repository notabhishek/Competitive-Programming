class Solution {
public: 
    vector<vector<int>> dp;
    int rec(int ridx, int kidx, string &ring, string &key) { 
        if(kidx >= key.length()) return 0;
        int &ret = dp[ridx][kidx];
        if(ret != -1) return ret;
        ret = 1e7;
        
        // rotate 
        for(int i = 0; i < ring.length(); ++i) {
            if(ring[i] == key[kidx]) {
                int cdist = (i-ridx + ring.length())%ring.length();
                int acdist = (ridx-i + ring.length())%ring.length();;
                ret = min(ret, min(cdist, acdist) + 1 + rec(i, kidx+1, ring, key));
            }
        }
        return ret;
    }
    int findRotateSteps(string ring, string key) {
        dp.resize(ring.length(), vector<int>(key.length(), -1));
        int ans = rec(0, 0, ring, key);
        return ans;
    }
};
