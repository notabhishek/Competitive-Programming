class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            int cnt = 0;
            for(int i = 1; i <= m; ++i) 
                cnt += min(mid/i, n);
            if(cnt < k) lo = mid + 1;
            else hi = mid - 1;
        } 
        return hi + 1;
     }
};
