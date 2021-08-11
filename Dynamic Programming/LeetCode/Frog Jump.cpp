class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int k = n+1;
        set<int> jumps[n];
        jumps[0].insert(0);
        
        map<int, int> pos;
        for(int i = 0; i < n; ++i) pos[stones[i]] = i;
        
        for(int i = 0; i < stones.size(); ++i) {
            for(auto &j : jumps[i]) {
                for(auto nxt : {j-1, j , j+1}) 
                    if(nxt>0 && pos.count(stones[i] + nxt)) 
                        jumps[ pos[ stones[i]+nxt ]].insert(nxt);
            }        
        }
        return jumps[n-1].size() > 0;
    }
};
