/**
 * @type of arr: 2D integer array
 * @return type: 2D integer array
 */
class Solution {
public:
	vector<vector<int>> rotateMatrix(vector<vector<int>>& arr) {
		// write your awesome code here
        int n = arr.size();
        /*
        00 01 02 03 04 05 06
        10 11 12 13 14 15 16
        20 21 22 23 24 25 25
        30 31 32 33 34 35 36
        40 41 42 43 44 45 46 
        60 51 52 53 54 55 56
        60 61 62 63 64 65 66
        
        00 06 66 60
        01 16 65 60
        02 25 64 40
        
        i,j   j,n-1-i   n-1-i,n-1-j  n-1-j,i
        
        11 15 55 5
        */
        
        
        auto rotate = [&](int i, int j) {
//             cout << "rot " << i << " " << j << endl;
         	int t = arr[i][j];
            arr[i][j] = arr[n-1-j][i];
            arr[n-1-j][i] = arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j] = arr[j][n-1-i];
            arr[j][n-1-i] = t;
        };
        for(int i = 0; i < n/2; ++i) {
        	for(int j = i; j < n-1-i; ++j) {
            	  rotate(i, j);
            }
        }
        return arr;
	}
};
