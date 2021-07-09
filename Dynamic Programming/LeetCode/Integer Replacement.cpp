class Solution {
public:
    int rec(long long n) {
        if(n == 1)
            return 0;
        if(n%2)
            return 1 + min( rec(n+1), rec(n-1));
        return rec(n/2) + 1;
    }
    int integerReplacement(int n) {
        return rec(n);
    }
};
