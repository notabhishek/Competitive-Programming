class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // rge
        int n = t.size();
        vector<int> rge(n, 0);
        stack<int> s;
        for(int i = 0; i < n;) {
            if(s.empty() || t[i] <= t[s.top()]) {
                s.push(i++);
            } else {
                rge[s.top()] = i - s.top();
                s.pop();
            }
        }
        return rge;
    }
};
