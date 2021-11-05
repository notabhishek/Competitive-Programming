/**
 * @type of arr: integer array
 * @return type: integer
 */
class Solution {
public:
    int maxWaterTrapped(vector<int>& arr) {
   		// write your awesome code here
       	int n = arr.size();
        vector<int> rmax(n, 0);
       	rmax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i)
            rmax[i] = max(rmax[i+1], arr[i]);
       	int lmax = arr[0];
        int water = 0;
        for(int i = 1; i < n-1; ++i) {
            int cwater = min(lmax, rmax[i+1]) - arr[i];
            water += max(0, cwater);
        	lmax = max(lmax, arr[i]);
        }
        return water;
    }
};
