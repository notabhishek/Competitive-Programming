class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> s(people.begin(), people.end());
        int ans = 0;
        while(!s.empty()) {
            int a = *s.rbegin();
            s.erase(s.find(a));
            if(!s.empty() && *s.begin() <= limit - a) {
                int b = *prev(s.upper_bound(limit - a));
                s.erase(s.find(b));
            }
            ++ans;
        }
        return ans;
    }
};
