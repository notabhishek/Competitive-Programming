class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        int lo = 0, hi = n-1;
        while( lo <= hi ){ 
            int mid = lo + (hi-lo)/2;
            bool peak = (mid == 0 ? 1: a[mid] > a[mid-1]) && (mid==n-1 ? 1 : a[mid]>a[mid+1]);
            if( peak ) 
                return mid;
            else if( mid==0 || a[mid+1] > a[mid-1] ) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
};
