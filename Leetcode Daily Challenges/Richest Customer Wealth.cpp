class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto &i : accounts) 
            ans = max(ans, accumulate(i.begin(), i.end(), 0));
        return ans;
    }
};
