class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29});
        int n = nums.size();
        int psz = primes.size();
        vector<int> maskf(1<<psz);
        int ones = 0;
        for(int i = 0; i < n; ++i) {
            int t = nums[i], mask = 0;
            bool rem = false;
            if(t == 1) {
                ++ones;
                continue;
            }
            for(int p = 0; p < psz; ++p) {
                int c = 0;
                while(t%primes[p] == 0){
                    t /=primes[p]; 
                    c++;
                }
                if(c > 1) {
                    rem = true;
                    break;
                }
                if(c == 1)
                mask ^= 1 << p;
            }
            if(!rem) 
                maskf[mask]++;
        }
        // for(int i = 0; i < n; ++i) cout << dmask[i] << " "; cout << endl;
        vector<int> prev(1<<psz, 0);
        prev[0] = 1;
        for(int i = 1; i < (1<<psz); ++i) {
            vector<int> dp = prev;
            // take current
            int m = i ^ ((1<<psz)-1);
            for(int s = m; s; s = (s-1) & m) {
                dp[s ^ i] = (dp[s ^ i] + (long long)maskf[i] * prev[s] % MOD) % MOD;
            }
            dp[i] =(dp[i] + (long long)maskf[i] * dp[0] % MOD)%MOD;
            swap(dp, prev);
        }
        int ans = 0;
        for(int s = (1<<psz)-1; s; --s) 
            ans = (ans + prev[s]) % MOD;
        while(ones-- > 0) 
            ans = (ans << 1) % MOD;
        return ans;
    }
};
