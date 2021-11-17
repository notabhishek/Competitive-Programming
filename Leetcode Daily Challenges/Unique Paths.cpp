class Solution {
public:
    int ncr(int n, int r) {
        long long ans = 1;
        int tn = n - r;
        while(r > 0 || n > tn) {
            if(r> 0 && ans % r == 0) ans/= r--;
            else ans *= n--;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return ncr(m+n-2, m-1);
    }
};
