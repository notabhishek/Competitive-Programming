class Solution {
public:
    int dist(char a , char b) {
        int ra = (a - 'A')/6;
        int ca = (a - 'A') % 6;
        int rb = (b - 'A')/6;
        int cb = (b- 'A')%6;
        return abs(ra-rb) + abs(ca - cb);
    }
    int type(char f1,char f2 , int i , string &s , vector< vector< vector< int >>> &dp) {
        if(i == 0) 
            return 0;
        --i;
        int &ret = dp[f1 - 'A'][f2-'A'][i];
        if(ret != -1)
            return ret;
        return ret  = min(dist(s[i],f1)+type(s[i],f2,i,s,dp), dist(s[i],f2)+type(f1 ,s[i],i,s,dp ));
    }
    int minimumDistance(string word) {
        int ans = INT_MAX;
        int n = word.length();
        vector < vector < vector< int >> > dp(26 , vector< vector< int > >(26 , vector< int > (n , -1)) );
        for(char f1 = 'A'; f1 <= 'Z'; ++f1 ) {
               for(char f2 = 'A'; f2 <= 'Z'; ++f2 ) {
                ans = min(ans , type(f1 , f2 , n, word , dp));
               }
        }
        return ans;
    }
};