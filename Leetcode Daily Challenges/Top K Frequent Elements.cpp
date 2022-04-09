using pii = pair<int,int>;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i : nums) m[i]++;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto &i : m)
            if(pq.size() < k) pq.push({i.second, i.first});
            else if(pq.top().first < i.second) pq.pop(), pq.push({i.second, i.first});
        vector<int> res;
        while(!pq.empty())
            res.push_back(pq.top().second), pq.pop();
        return res;
    }
};
