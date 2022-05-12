class Solution {
public:
    bool nextPerm(vector<int> &a) {
        int n = a.size();
        int i = n-2;
        while(i >= 0 && a[i] >= a[i+1]) --i;
        if(i == -1) {
            // decreasing order no next permutation
            return false;
        }
        int idx = i+1;
        for(int j = i+1; j < n; ++j) { // could use binary search here 
            if(a[j] > a[i]) idx = j;
            else break;
        }
        
        swap(a[i], a[idx]);
        reverse(a.begin()+i+1, a.end());
        return true;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
        } while(nextPerm(nums));
        return ans;
    }
};
