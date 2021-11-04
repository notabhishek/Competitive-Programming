/**
 * @type of arr: integer array
 * @return type: integer array
 */
class Solution {
public:
    vector<int> moveZeroes(vector<int>& arr) {
    	// write your awesome code here
        int j = -1;
        for(int i = 0; i < arr.size(); ++i) {
        	if(arr[i] != 0) {
             	++j;
                swap(arr[i], arr[j]);
            }
        }
        return arr;
    }
};
