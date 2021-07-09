class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n  = a.size();
        vector<int> lis(n, 0);
        int len = 1;
        lis[0] = a[0];
        for(int i = 1; i < n; ++i ) {
            if(a[i] > lis[len-1]) {
                lis[len] = a[i];
                ++len;
            } else if(a[i] <= lis[0]) {
                lis[0] = a[i];
            } else {
                int lo = 0; 
                int hi = len-1;
                while( lo <= hi ) {
                    int mid = (lo + hi)/2;
                    if( lis[mid] < a[i] ) {
                        lo = mid + 1;
                    } else hi = mid-1;
                }
                lis[lo] = a[i];
            }
        }
        return len;
    }
};
