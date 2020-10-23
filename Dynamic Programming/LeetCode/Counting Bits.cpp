class Solution {
public:
    vector<int> countBits(int num) {
        vector< int > res(num + 1 , 0);
        // for(int i = 0; i <= num; ++i) {
        //     res[i] = __builtin_popcount(i);
        // }
        for(int i = 1; i <= num; ++i) {
            if( (i & (i-1) ) == 0 ) {
                res[i] = 1;
            } else {
                res[i] = 1 + res[i - (1 << (int) log2(i) )];
            }
        }
        return res;  
    }
};