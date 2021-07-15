class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p;
        if(numRows == 0) 
            return p;
        vector<int> curr;
        curr.push_back(1);
        p.push_back(curr);
        for(int i = 2; i<=numRows; ++i) {
            curr.push_back(1);
            curr[0] = 1;
            for(int j = 1; j <curr.size()-1; ++j) {
                curr[j] = p[p.size()-1][j-1] + p[p.size()-1][j];
            }
            p.push_back(curr);
        }
        return p;
    }
};
