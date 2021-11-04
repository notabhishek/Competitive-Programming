/**
 * @type of arr: 2D integer array
 * @return type: 2D integer array
 */
class Solution {
public:
	vector<vector<int>> matrixZero(vector<vector<int>>& arr) {
		// write your awesome code here
        bool row0 = false, col0 = false;
        int n = arr.size(), m = arr[0].size();
        for(int i =0; i < n; ++i) 
            if(arr[i][0] == 0) col0 = true;
        for(int i =0; i < m; ++i) 
            if(arr[0][i] == 0) row0 = true;
       	for(int i = 1; i < n; ++i) {
        	for(int j = 1; j < m; ++j) 
                if(arr[i][j] == 0)
                    arr[0][j] = arr[i][0] = 0;
        }
        for(int i = 1; i < n; ++i) {
         	if(arr[i][0] == 0) {
            	for(int j = 0; j < m; ++j) arr[i][j] = 0;
            }
        }
        for(int i = 1; i < m; ++i) {
         	if(arr[0][i] == 0) {
            	for(int j = 0; j < n; ++j) arr[j][i] = 0;
            }
        }
        if(row0) for(int j = 0; j < m; ++j) arr[0][j] = 0;
        if(col0) for(int i = 0; i < n; ++i) arr[i][0] = 0;
        return arr;
	}
};
