class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int mx = a[0] + 0;
        int ans = INT_MIN;
        for(int j = 1; j < a.size(); ++j) {
            ans = max(ans , a[j]-j + mx);
            mx = max(mx , a[j] + j);
        }
        return ans;
    }
};
