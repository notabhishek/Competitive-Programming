class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int u = pq.top(); pq.pop();
            int v = pq.top(); pq.pop();
            if(u==v) continue;
            pq.push(u-v);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
