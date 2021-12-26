class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        int d;
        for(auto &p : points) {
            d = p[0]*p[0] + p[1]*p[1];
            if(pq.size() < k) {
                pq.push({d, p[0], p[1]});
            } else if(pq.top()[0] > d) {
                pq.pop();
                pq.push({d, p[0], p[1]});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return res;
    }
};
