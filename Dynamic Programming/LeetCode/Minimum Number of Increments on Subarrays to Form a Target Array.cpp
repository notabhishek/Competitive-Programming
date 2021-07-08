class Solution {
public:
    // could be simulated using segTree + recursion in nlogn 
    // rangeMin  and rangeUpdate
    int minNumberOperations(vector<int>& a) {
        int ans = 0;
        int cur = 0;
        for(auto &i : a )  {
            ans += ( i > cur ? i - cur : 0);
            cur = i;
        }
        return ans;
    } 
};
