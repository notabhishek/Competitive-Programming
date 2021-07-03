class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool isop(char c) {
        return c =='+' || c=='-' || c=='*';
    }
    void merge(int i , int j , int k, char op){
        for(auto &x : dp[i][k-1]) {
            for(auto &y : dp[k+1][j]) {
                if(op == '+')
                    dp[i][j].push_back(x+y);
                else if(op == '-')
                    dp[i][j].push_back(x-y);
                else 
                    dp[i][j].push_back(x*y);
            }
        }
    }
    void F(int i , int j, string &a) {
        if(dp[i][j].size())
            return;
        bool allNum = true;
        for(int k = i; k <= j; ++k) if(isop(a[k])) allNum = false;
        if(allNum) {
            dp[i][j].push_back(stoi(a.substr(i , j-i+1)));
            return;
        }
        for(int k = i+1; k < j; ++k) {
            if( isop(a[k]) ) {
                F(i, k-1, a);
                F(k+1, j, a);
                
                merge(i, j , k , a[k]);
            }
        }
    }
    vector<int> diffWaysToCompute(string a) {
        int n = a.length();
        dp.resize(n , vector<vector<int>>(n));
        F(0, n-1, a);
        return dp[0][n-1];
    }
};
