/**
 * @type of arr: integer array
 * @type of element: integer
 * @return type: integer
 */
class Solution {
public:
    int binarySearchASC(vector<int> &arr, int lo, int hi, int key) {
    	while(lo <= hi) {
            int mid = lo + ((hi-lo)>>1);
            if(arr[mid] == key) return mid;
        	if(arr[mid] < key) lo = mid + 1;
            else hi = mid - 1;
        }
        return  -1;
    }
    int binarySearchDESC(vector<int> &arr, int lo, int hi, int key) {
    	while(lo <= hi) {
            int mid = lo + ((hi-lo)>>1);
            if(arr[mid] == key) return mid;
        	if(arr[mid] < key) hi = mid - 1;
            else lo = mid + 1;
        }
        return  -1;
    }
    int findBitonic(vector<int>& arr, int element) {
   		// write your awesome code here
        int n = arr.size();
        if(n == 1) {
        	return (element == arr[0] ? 0 : -1);
        }
        // check if array is fully increasing 
        if(arr[n-1] > arr[n-2]) {
        	return binarySearchASC(arr, 0, n-1, element);
        }
        
        // check if array is full decrasing 
        if(arr[0] > arr[1]) {
        	return binarySearchDESC(arr, 0, n-1, element);
        }
        
        // find mountain peak
        int lo = 0, hi = n-2;
        while(lo <= hi) {
        	int mid = lo + ((hi-lo)>>1);
            if(arr[mid] < arr[mid+1]) lo = mid + 1;
            else hi = mid - 1;
        }
        // peak = lo
        int left = binarySearchASC(arr, 0, lo, element);
        if(left!=-1) return left;
        return binarySearchDESC(arr, lo+1, n-1, element);
    }
};
