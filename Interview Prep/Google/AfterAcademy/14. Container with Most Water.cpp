/**
 * @type of arr: integer array
 * @return type: integer
 */
class Solution {
public:
	int mostWater(vector<int>& arr) {
    	// write your awesome code here 
        int n = arr.size();
        int i = 0, j = n-1;
        int ans = 0;
        while( i < j ) {
           	ans = max(ans, (j-i) * min(arr[j],arr[i]));
            if(arr[i] > arr[j]) --j;
            else ++i;
        }
        return ans;
    }
};
