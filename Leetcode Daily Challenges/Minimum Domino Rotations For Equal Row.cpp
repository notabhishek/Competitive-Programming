class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = tops.size();
        for(int v = 1; v <= 6; ++v) {
            int up = 0, bot = 0;
            for(int i = 0; i < tops.size(); ++i) {
                if(tops[i] != v && bottoms[i]!= v) {
                    up = bot = tops.size();
                    break;
                }
                up += tops[i] != v;
                bot += bottoms[i] != v;
            }
            ans = min(ans, up);
            ans = min(ans, bot);
        }
        
        if(ans == tops.size())
            return -1;
        return ans;
    }
};
