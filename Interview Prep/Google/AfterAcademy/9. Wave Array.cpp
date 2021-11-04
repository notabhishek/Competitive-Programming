/**
 * @type of arr: integer array
 * @return type: integer array
 */
class Solution {
public:
	vector<int> waveArray(vector<int>& arr) {
   		// write your awesome code here
        sort(arr.begin(),arr.end());
        for(int i = 1; i < arr.size(); i+=2) swap(arr[i], arr[i-1]);
        return arr;
    }
};
