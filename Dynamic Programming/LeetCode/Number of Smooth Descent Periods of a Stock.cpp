class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0, tmp;
        int i = 0, n = prices.size();
        while(i < n) {
            int j = i+1;
            while(j < n && prices[j]+1 == prices[j-1]) 
                ++j;
            tmp = j-i;
            ans += (tmp*(tmp+1))/2;
            i = j;
        }
        return ans;
    }
};
