/**
 * @type of arr: integer array
 * @type of target: integer
 * @return type: integer array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
    	// write your awesome code here
        int idx1 = lower_bound(arr.begin(), arr.end(), target)-arr.begin();
        int idx2 = upper_bound(arr.begin(), arr.end(), target)-arr.begin()-1;
        
        if(idx1==arr.size() || arr[idx1] != target || idx2 == -1 || arr[idx2]!=target) 
            return {-1,-1};
        return {idx1, idx2};
    }
};
