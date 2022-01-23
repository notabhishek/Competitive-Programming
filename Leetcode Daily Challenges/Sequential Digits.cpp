class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int s = 1; s <= 9; ++s) {
            int cur = 0;
            for(int d = s; d <= 9; ++d) {
                cur = cur*10 + d;
                if(cur >= low && cur <= high)
                    res.push_back(cur);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
