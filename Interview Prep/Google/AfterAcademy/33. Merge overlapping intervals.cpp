/**
 * @type of intervals: 2D integer array
 * @return type: 2D integer array
 */
class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
   		// write your awesome code here
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0];
        int en = intervals[0][1];
        vector<vector<int>> mergedIntervals;
        for(int i = 1; i < intervals.size(); ++i) {
        	if(intervals[i][0] <= en) {
            	en = max(en, intervals[i][1]);
            } else {
            	mergedIntervals.push_back({st, en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }
        mergedIntervals.push_back({st, en});
        return mergedIntervals;
    }
};
