class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0, i = 0, n = points.size(), shoot; 
        int minEnding[n];
        minEnding[n-1] = points[n-1][1];
        for(int i = n-2; i >= 0; --i)
            minEnding[i] = min(minEnding[i+1], points[i][1]);
        
        while(i<n) {
            // shoot at first ending 
            shoot = minEnding[i];
            while(i < n && points[i][0] <= shoot) ++i;
            ++ans;
        }
        
        return ans;
    }
};
