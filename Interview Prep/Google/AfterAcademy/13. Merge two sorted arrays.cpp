/**
 * @type of arr1: integer array(sorted)
 * @type of arr2: integer array(sorted)
 * @return type: integer array
 */
class Solution {
public:
    vector<int> mergeSortedArray(vector<int>& arr1, vector<int>& arr2) {
    	// write your awesome code here
        vector<int> c;
        int i = 0, j=0, n = arr1.size(), m = arr2.size();
        while(i < n && j < m) {
        	if(arr1[i] <=arr2[j]) {
                c.push_back(arr1[i++]);
            } else {
             	c.push_back(arr2[j++]);
            }
        }
        while(i < arr1.size()) c.push_back(arr1[i++]);
        while(j < arr2.size()) c.push_back(arr2[j++]);
        return c;
    }
};
