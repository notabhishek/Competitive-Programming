/**
 * @type of arr: integer array
 * @return type: integer
 */
class Solution {
public:
    int arrIndexDifference(vector<int>& arr) {
    	// write your awesome code here 
        int n = arr.size();
        vector<int> lmin(n, 0);
        vector<int> rmax(n, 0);
        int ans = INT_MIN;
        lmin[0] = arr[0];
        for(int i = 1; i < n; ++i) 
            lmin[i] = min(arr[i], lmin[i-1]);
        rmax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) 
            rmax[i] = max(arr[i], rmax[i+1]);
       	
        int i = 0, j = 0;
        while(i < n && j < n) {
        	if(lmin[i] >= rmax[j]) {
            	++i;
            } else {
            	ans = max(ans, j-i);
                ++j;
            }
        }
        return ans;
    }
};
