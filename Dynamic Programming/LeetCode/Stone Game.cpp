class Solution {
public:
    int win(int i , int j , vector<int> &piles, vector<vector<int>> &dp) {
        if(j < i) 
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if((j-i)%2 == 1) {
            dp[i][j] = max(piles[i] + win(i+1 , j , piles , dp) , piles[j] + win(i , j-1 , piles , dp));
        } else {
           dp[i][j] = max(win(i+1 , j , piles , dp)-piles[i] , win(i , j-1 , piles , dp) - piles[j]); 
        }
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        int a = piles.size();
        vector< vector<int> > dp(a+1, vector<int> (a+1 , -1));
        return win(0 , piles.size()-1, piles , dp) > 0;
    }
};
