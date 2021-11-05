class Solution {
public:
    int arrangeCoins(long long n) {
        // (k*(k+1))/ 2 <= n
        // k*k + k <= 2*n
        long long k = sqrt(2ll*n);
        if(k*(k+1) <= 2ll*n) return k;
        return k-1;
    }
};
