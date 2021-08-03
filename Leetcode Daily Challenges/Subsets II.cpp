class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin() , a.end());
        int n = a.size();
        vector<vector<int>> powerSet(1<<n);
        powerSet[0] = vector<int>(); 
        for(int m = 1; m < (1<<n); ++m) { // mask
            int msb = log2(m);
            powerSet[m] = powerSet[m^(1<<msb)];
            powerSet[m].push_back(a[msb]);
        }
        
        sort(powerSet.begin(), powerSet.end());
        auto it = unique(powerSet.begin(), powerSet.end());
        powerSet.resize(distance(powerSet.begin(), it));
        return powerSet;
    }
};
