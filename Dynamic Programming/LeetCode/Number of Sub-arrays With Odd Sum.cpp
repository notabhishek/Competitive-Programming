class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt[2] = {0};
        cnt[0] = 1;
        int ans = 0;
        const int mod = 1e9 + 7;
        int pre = 0;
        for(auto &i : arr) {
            pre ^= (i&1);
            ans = (ans + cnt[1-pre]) % mod;
            cnt[pre]++;
        } 
        return ans;
    } 
};
