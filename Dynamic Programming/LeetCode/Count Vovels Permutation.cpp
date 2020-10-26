using ll = long long int;
class Solution {
public:
    const int M = 1e9 + 7;
    vector< vector< ll >> dp;
    ll ways(int n ,char prev) {
        if(n == 0) 
            return 1;
        ll &ret = dp[n][prev - 'a'];
        if(ret != -1)
            return ret;
        --n;
        if(prev == 'a')
            return ret = ways(n, 'e');
        if(prev == 'e')
            return ret = (ways(n , 'a') + ways(n,'i'))%M;
        if(prev == 'i') 
            return ret = (ways(n , 'a') + ways(n,'e') + ways(n , 'o') + ways(n,'u'))%M;
        if(prev == 'o')
            return ret = (ways(n , 'i') + ways(n,'u'))%M;
        if(prev == 'u')
            return ret = ways(n , 'a');
        return ret = (ways(n , 'a') + ways(n,'e') + ways(n , 'o') + ways(n,'u') + ways(n , 'i'))%M;
    }
    int countVowelPermutation(int n) {
        // a->e
        // e->a,i
        // i->i X
        // o-> i , u
        // u -> a
        dp.clear();
        dp.resize(n + 1 , vector<ll> (26 , -1));
        return (ways(n , 'x') + M) % M;
            
    }
};