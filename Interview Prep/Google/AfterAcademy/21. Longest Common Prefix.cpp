/**
 * @type of arr: array of strings
 * @return type: string
 */
class Solution {
public:
	string longestCommonPrefix(vector<string>& arr) {
   		// write your awesome code here
        string pref = "";
        int minLen = INT_MAX;
        for(auto &s : arr) minLen = min(minLen, (int)s.length());
        for(int i = 0; i < minLen; ++i) {
            bool f = true;
        	for(int j = 1; j < arr.size(); ++j)
                if(arr[j][i] != arr[0][i]) {
                    f = 0;
                    break;
                }
            if(!f) break;
           	pref += arr[0][i];
        }
        return pref;
    }
};
