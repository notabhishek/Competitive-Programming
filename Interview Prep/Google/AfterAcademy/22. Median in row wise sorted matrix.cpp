/**
 * @type of arr: 2D integer array
 * @return type: integer
 */
class Solution {
public:
	int rowMedian(vector<vector<int>>& arr) {
		// write your awesome code here
        int lo = INT_MAX, hi = INT_MIN;
        int n = arr.size(), m = arr[0].size();
        int medIdx = (m*n + 1)/2;
        for(int r = 0; r < n; ++r) {
            lo = min(lo, arr[r][0]);
            hi = max(hi, arr[r][m-1]);
        }
        while(lo <= hi) {
        	int mid = lo + (hi-lo)/2;
            int count = 0;
            for(int r = 0; r < n; ++r) {
            	count += upper_bound(arr[r].begin(), arr[r].end(), mid) -arr[r].begin();
            }
            if(count < medIdx) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi + 1;
	}
};
