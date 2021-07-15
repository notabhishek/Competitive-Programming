class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back(1);
        if(rowIndex == 0)
            return prev;
        for(int i = 1; i <= rowIndex; ++i) {
            vector<int> cur(i+1);
            cur[0] = 1;
            cur[i] = 1;
            for(int j = 1; j < i; ++j ) 
                cur[j] = prev[j-1] + prev[j];
            prev = cur;
        }
        return prev;
    }
};
