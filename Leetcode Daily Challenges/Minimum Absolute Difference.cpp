class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minDif = INT_MAX;
        for(int i = 1; i < arr.size(); i++) {
				int d = arr[i] - arr[i - 1];
				if(d < minDif) {
					ans.clear();
					minDif = d;
					ans.push_back({arr[i - 1], arr[i]});
				}
				else if(d == minDif) {
				   ans.push_back({arr[i - 1], arr[i]});
				}
        }
        return ans;
    }
};
