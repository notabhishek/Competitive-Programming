class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        // chk if already sorted
        if(a[0] < a[n-1]) return a[0];
        //find the rotating point
        int lo = 0 , hi = n-1;
        int idx = -1;
        while( lo <= hi ) {
            int mid = (lo+hi)/2;
            if(a[mid] > a[(mid+1)%n]) {
                idx = mid; break;
            } else if(a[mid] >= a[0]) {
                lo = mid + 1; // we are in left of rotation point
            } else {
                hi = mid - 1; // we are in right of rotation point
            }
        }
        return a[(idx + 1)%n];
    }
};
