#define vt vector
class Solution {
public:
    const int MOD = 1e9 + 7;
    int walk(int s , int e , int f , vector< int > &a , vt<vt<vt<int>>> &dp){
        int &ret = dp[s][e][f];
        if(ret != -1)
            return ret;
        ret = 0;
        if(s == e) {
            ++ret;
        }
        for(int i = 0 ; i < a.size(); ++i) {
            if(i != s && f >= abs(a[s] - a[i])) {
                ret += walk( i , e , f - abs(a[s] - a[i]) , a, dp );
                ret %= MOD;
            }
        }
        return ret;
    }
    int countRoutes(vector<int>& a, int start, int finish, int fuel) {
        int n = a.size();
        vt<vt<vt<int>>> dp(n , vt<vt<int>> (n , vt<int> (fuel+1 , -1)));
        return walk(start , finish , fuel , a , dp);
    }
};