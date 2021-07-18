// using dp + bitmask  O(n*sum)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        
        int dp[sum + 1];
        // dp[i] = 000101010   if kth bit is 1 then using k length we can get sum=i
        memset(dp, 0 , sizeof dp);
        dp[0] = 1; // using 0 length we can get sum 0
        for(int i = 0; i < n; ++i) {
            for(int j = sum; j > 0; --j) {
                if(j >= a[i])
                    dp[j] |= (dp[j-a[i]] << 1);  // left shift to increase length
            }
        }
        
        for(int s = 0; s <= sum; ++s) {
            for(int la = 1; la < n; ++la) {
                if(dp[s] & (1<<la)) {
                    int lb = n - la;
                    if(s * lb == ( sum - s) *la) 
                        return true;
                }
            }
        }
        return false;
    }
};
