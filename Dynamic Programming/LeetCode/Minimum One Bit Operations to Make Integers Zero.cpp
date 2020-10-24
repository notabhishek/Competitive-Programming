class Solution {
public:
    int minimumOneBitOperations(int n) {
        // 2 : 10 -> 11 -> 01 -> 00 
        // 4 : 100 -> 101 -> 111 -> 110 -> 010-> 011 -> 001 -> 000
        // For 2^n ans = 2^(n+1) - 1
        // dp[n] = moves to make this number from 0 
        // dp[n] = moves to make 111111 - moves to make (number after removing last bit)
        if(n == 0)
            return 0;
        int l = log2(n);
        return (1<<(l + 1)) - 1 - minimumOneBitOperations(n - (1<<l));
    }
};