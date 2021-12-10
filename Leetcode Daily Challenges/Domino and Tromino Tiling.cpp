class Solution {
public:
    int numTilings(int n) {
        /*
        __  ||  |-  |
        __      |   |_
        
        0 = flat
        1 = r
        2 = L
        */
        const int MOD = 1e9+7;
        array<unsigned int,3> pre1 = {1,0,0}, pre2 = {0,0,0}, cur;
        
        for(int i = 1; i <= n; ++i) {
            // flat
            cur[0] = (pre1[0] + pre2[0] + pre1[1] + pre1[2]) % MOD;
            // r
            cur[1] = (pre1[2] + pre2[0]) % MOD;
            // L
            cur[2] = (pre1[1] + pre2[0]) % MOD;
            
            swap(pre2, pre1);
            swap(cur, pre1);
        }
        return pre1[0];
    }
};
