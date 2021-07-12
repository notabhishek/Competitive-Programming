class Solution {
public:
    vector< vector< vector<int>>> dp;
    int rec(int idx, int z, int o, vector<pair<int,int>> &a) {
        int &ret = dp[idx][z][o];
        if(ret != -1)
            return ret;
        // dont take this element
        ret = rec(idx - 1 , z , o , a);
        // take this element
        if(z >= a[idx-1].first &&  o >= a[idx-1].second) 
            ret = max(ret , 1 + rec(idx-1, z-a[idx-1].first , o-a[idx-1].second, a));
        
        return ret;
    }
    int findMaxForm(vector<string>& strs, int zero, int one) {
        vector< pair<int,int>> a;
        int len = strs.size();
        for(auto &i : strs){
            int z = count(i.begin(), i.end() , '0');
            int o = i.length() - z;
            a.push_back({ z, o});
        }
        
        dp.resize(len + 1 , vector<vector<int>> (zero + 1, vector<int> (one + 1, -1)));
        for(int i = 0 ; i <= zero; ++i)
            for(int j = 0; j <= one; ++j)
                dp[0][i][j] = 0;
        
        int ans = rec(len, zero, one , a);
        return ans;
    }
};
