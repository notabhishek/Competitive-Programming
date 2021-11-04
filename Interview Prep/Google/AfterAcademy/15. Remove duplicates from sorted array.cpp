/**
 * @type of arr: integer array
 * @return type: integer 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
    	// write your awesome code here
        unordered_set<int> seen;
        int j = -1, n = arr.size();
        for(int i = 0; i < n; ++i) {
        	if(seen.find(arr[i]) == seen.end()) {
                seen.insert(arr[i]);
                swap(arr[i], arr[++j]);
            }
        }
        return j+1;
    }
};
