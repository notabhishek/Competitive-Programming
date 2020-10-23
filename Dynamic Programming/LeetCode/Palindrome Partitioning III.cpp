#define vt vector
class Solution {
public:
    int palin(int i , int j , string &s) {
        int c = 0;
        for(int k = i; k <=j; ++k) 
            if(s[k] != s[i-k+j])
                c++;
        return (c + 1)/2;
    }
    int cost(int i , int j ,int k ,string &s , vt<vt<vt<int>>> &dp) {
        assert( i <= j );
        int &ret = dp[i][j][k];
        if(ret != -1)
            return ret;
        if(k == 0) {
            return ret = palin(i , j , s);
        }
        ret = j - i + 1;
        for(int part = i; part < j; ++part) {
                ret = min(ret , cost(i , part , 0 ,s , dp) + cost(part + 1 , j , k-1, s , dp) );
        }
        return ret;
    } 
    int palindromePartition(string s, int k) {
        int n = s.length();
        vt< vt < vt< int >>> dp(n , vt< vt< int >> (n , vt< int > (k , -1)));
        return cost(0 , n-1, k-1 , s , dp);
    }
};