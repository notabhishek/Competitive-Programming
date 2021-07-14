class Solution {
public:
    int max_width;
    vector<vector<int>> dp;
    int rec(int idx, int aw,int ch,vector<vector<int>> &b) {
        if(idx == b.size())
            return ch;
        int &ret = dp[idx][aw];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        // place idx book on current shelf 
        if(aw >= b[idx][0]) 
            ret = min(ret, rec(idx+1, aw-b[idx][0] , max(ch, b[idx][1]), b));
        // place idx book on new shelf 
        ret = min(ret, ch + rec(idx+1, max_width-b[idx][0], b[idx][1], b));
        return ret;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        max_width = shelf_width;
        dp.resize(n + 1, vector<int> (shelf_width + 1 , -1));
        int ans = rec(0, max_width,0, books);
        // for(auto &i : dp) {
        //     for(auto &j : i) cout << j << " ";
        //     cout << endl;
        // }
        return ans;
    }
};
