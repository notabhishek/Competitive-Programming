class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if( sum & 1 )
                return false;
        // using bitsets
        bitset< 200*100 + 1 > b;
        b[0] = 1;
        for(auto &i : a)
            b |= b << i;
        return b[sum/2];
    }
};
