class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int i : nums)
            if(i&1) s.insert(2*i);
            else s.insert(i);
        int ans = INT_MAX;
        while(true) {
            int mx = *s.rbegin(), mn = *s.begin();
            ans = min(ans, mx - mn);
            if(mx%2 == 0) {
                s.erase(mx); 
                mx/=2; 
                s.insert(mx);
            } else 
                break;
        }
        return ans;
    }
};
