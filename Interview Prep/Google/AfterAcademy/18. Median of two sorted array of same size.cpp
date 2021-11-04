/**
 * @type of arr1: sorted integer array
 * @type of arr2: sorted integer array
 * @return type: integer
 */
class Solution {
public:
    /*
    // log(Max) * (log(m) + log(n)) solution 
    int countLessEqual(vector<int> &arr, int mid){
    	return upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
    }
	int medianSortedEqualArray(vector<int>& arr1, vector<int>& arr2) {
    	int n = arr1.size(), m = arr2.size();
        
        int lo = min(arr1[0], arr2[0]);
        int hi = max(arr1[n-1], arr2[m-1]);
        while(lo <= hi) {
        	int mid = lo + ((hi-lo)>>1);
            int lessEqual = countLessEqual(arr1, mid) + countLessEqual(arr2,mid);
            if(lessEqual >= n) {
            	hi = mid - 1;
            } else {
            	lo = mid + 1;
            }
        }
        int median1 = *lower_bound(arr1.begin(), arr1.end(), lo);
        int median2 = *lower_bound(arr2.begin(), arr2.end(), lo);
        return (median1 + median2)/2;
    }
    */

	int medianSortedEqualArray(vector<int>& arr1, vector<int>& arr2) {
		return 0;
    }
};
