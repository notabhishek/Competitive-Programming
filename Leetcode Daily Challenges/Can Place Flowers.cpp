class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        for(int i = 0; i < bed.size(); ++i) {
            if(bed[i] == 0 && (i==0 || bed[i-1]==0) && (i==bed.size()-1 || bed[i+1] == 0)) {
                bed[i] = 1; --n;
            }
            // cout << bed[i] << " ";
        }
        return n <= 0;
    }
};
