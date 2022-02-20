class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int ans = a.size();
        sort(a.begin(), a.end(), [](vector<int> &p, vector<int> &q) {
           if(p[0] == q[0])
               return p[1] > q[1];
            return p[0] < q[0];
        });
        int en = a[0][1];
        for(int i = 1; i < a.size(); ++i) {
            if(a[i][1] > en) 
                en = a[i][1];
            else 
                --ans;
        }
        return ans;
    }
};
