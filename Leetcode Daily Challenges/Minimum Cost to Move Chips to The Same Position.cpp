class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int c[2] = {0};
        for(int i : position)
            c[i&1] ++;
        return min(c[0], c[1]);
    }
};
