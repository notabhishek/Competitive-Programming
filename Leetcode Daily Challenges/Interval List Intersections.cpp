class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();
        if(n == 0 || m == 0) return res;
        int i = 0, j = 0;
        while(i < n && j < m) {
            /*
            l1 r1  l2 r2
            */
            int L = max(firstList[i][0], secondList[j][0]);
            int R = min(firstList[i][1], secondList[j][1]);
            if(L<=R) res.push_back({L,R});
            if(firstList[i][1] < secondList[j][1]) ++i;
            else ++j;
        } 
        return res;
    }
};
