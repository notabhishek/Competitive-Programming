class Solution {
public:

    int numWays(int steps, int n) {
        vector< long long int > cur(n , 0);
        vector< long long int > prev(n , 0);
        prev[0] = 1;
        const int MOD = 1e9 + 7;
        for(int step = 0; step < steps; ++step) {
            for(int pos = 0; pos <= min(step+1,n-1); ++pos) {
                cur[pos] = (pos > 0 ? prev[pos-1] : 0) + prev[pos] + (pos+1< n ? prev[pos + 1] : 0);
                cur[pos] %= MOD;
            }
            for(int i = 0 ; i <= min(steps+1,n-1); ++i) 
                prev[i] = cur[i];
        }
        return (int)prev[0];
    }
};