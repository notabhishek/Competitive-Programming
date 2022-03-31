class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        int lo = 0, hi = m*n-1;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(a[mid/n][mid%n] < k) 
                lo = mid+1;
            else 
                hi = mid-1;
        }
        ++hi;
        return hi < m*n && a[hi/n][hi%n] == k;
    }
};
