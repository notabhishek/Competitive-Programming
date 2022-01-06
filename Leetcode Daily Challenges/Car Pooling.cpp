template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {
    os << "[";
    for(T u : v) {
        os << u << ", ";
    }
    os << "]\n";
    return os;
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> &u, vector<int> &v){
           if(u[1] == v[1]) return u[2] < v[2];
            return u[1] < v[1];
        });
        // cout << trips;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto trip : trips) {
            while(!pq.empty() && pq.top().first <= trip[1]) {
                capacity += pq.top().second;
                pq.pop();
            }
            // cout << capacity << endl;
            if(capacity < trip[0]) return false;
            pq.push({trip[2], trip[0]});
            capacity -= trip[0];
        }
        return true;
    }
};
