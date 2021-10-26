class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> corners;
        for(auto &building: buildings) {
            corners.push_back({building[0], -building[2]});
            corners.push_back({building[1], building[2]});
        }
        sort(corners.begin(), corners.end());
        multiset<int> active; // active bhuilding heights
        active.insert(0); // floor is always there
        
        vector<vector<int>> res;
        int curHt = 0;
        for(pair<int,int> &corner : corners) {
            if(corner.second < 0) { // start point
                if(-corner.second > curHt) {
                    res.push_back({corner.first, -corner.second});
                    curHt = -corner.second;
                }
                active.insert(-corner.second);
            } else { // end point
                active.erase(active.find(corner.second));
                if(*active.rbegin() < curHt) {
                    curHt = *active.rbegin();
                    res.push_back({corner.first, curHt});
                }
            }
        }
        return res;
    }
};
