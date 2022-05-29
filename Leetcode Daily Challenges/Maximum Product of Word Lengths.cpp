class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n = w.size();
        int mask[n];
        for(int i = 0; i < n; ++i) {
            mask[i] = 0;
            for(char c : w[i]) {
                mask[i] |= 1 << (c - 'a');
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if((mask[i] & mask[j]) == 0)
                    ans = max(ans, (int)(w[i].length() * w[j].length()));
            }
        }
        return ans;
    }
};
