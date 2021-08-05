class Solution {
public:
    vector<vector<int>> dp;
    int BIT;
    int rec(int i , int mask, vector<int> &s, vector<int> &m) {
        if(i < 0)
            return 0;
        int &ret = dp[i][mask];
        if(ret != -1)
            return ret;
        ret = 0;
        for(int j = 0; j < s.size(); ++j)
            if(mask & (1<<j)) {
                ret = max(ret, BIT - __builtin_popcount(m[j]^s[i]) + rec(i-1, mask ^ (1<<j), s , m));
                
            }
        return ret;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> s , m;
        int n = students.size();
        BIT = students[0].size();
        // store students, mentors as integers 
        // compatibility = BIT - setbits(s[i] ^ m[j])
        for(auto &i : students) {
            int c = 0;
            for(int j = 0; j < BIT; ++j) 
                c+= (1<<j) * i[j];
            s.push_back(c);
        }
        for(auto &i : mentors) {
            int c = 0;
            for(int j = 0; j < BIT; ++j) 
                c+= (1<<j) * i[j];
            m.push_back(c);
        }
        dp = vector< vector<int>> (n , vector<int>(1<<n, -1));
        int ans = rec(n-1, (1<<n)-1, s , m);
        return ans;
    }
};
