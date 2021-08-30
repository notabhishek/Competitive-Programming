class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mnR = m, mnC= n;
        // everything is max until min xi, min yi
        for(auto &i : ops) mnR = min(mnR, i[0]), mnC = min(mnC, i[1]);
        return mnR * mnC;
    }
};
