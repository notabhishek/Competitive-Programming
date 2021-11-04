/**
 * @type of arr: 2D integer array
 * @return type: 1D integer array
 */
class Solution {
public:
	vector<int> spiralMatrix(vector<vector<int>>& arr) {
		// write your awesome code here
        int n = arr.size(), m = arr[0].size();
        int rs = 0, re = n-1, cs = 0, ce = m-1;
        vector<int> spiral;
        while(rs <= re && cs <= ce) {
         	for(int c = cs; c <= ce; ++c) spiral.push_back(arr[rs][c]);
            for(int r = rs+1; r <= re; ++r) spiral.push_back(arr[r][ce]);
            for(int c = ce-1; c>= cs; --c) spiral.push_back(arr[re][c]);
            for(int r = re-1; r>rs; --r) spiral.push_back(arr[r][cs]);
            ++rs;
            --re;
            ++cs;
            --ce;
        }
        return spiral;
	}
};
