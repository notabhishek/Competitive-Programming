class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long lo = 1, hi = 4e13 + 10, mid, cnt;
        const int MOD = 1e9 + 7;
        int lcm = a*b/__gcd(a,b);
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            cnt = (mid/a) + (mid/b) - (mid/lcm);
            if(cnt < n) 
                lo = mid+1;
            else 
                hi = mid-1;
        }
        return (hi+1)%MOD;
    }
};
