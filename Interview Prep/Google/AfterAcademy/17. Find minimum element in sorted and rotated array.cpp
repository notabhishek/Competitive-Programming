/**
 * @type of arr: integer array
 * @return type: integer
 */
class Solution {
public:
	int findMinElement(vector<int>& arr) {
    	// write your awesome code here   
        int n = arr.size();
        if(n == 1) {
        	return arr[0];
        }
        // find mountain peak
        int lo = 0, hi = n-2;
        while(lo <= hi) {
        	int mid = lo + ((hi-lo)>>1);
            if(arr[mid] >= arr[0]) lo = mid + 1;
            else hi = mid - 1;
        }
        // peak = lo-1
        return arr[lo];
    }
};
