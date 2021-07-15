class Solution {
public:
    int numTrees(int n) {
        vector<int> catalan(n+1 , 0);
        catalan[0] = 1;
        for(int i = 1 ; i <= n; ++i) {
            for(int j = 1; j <=i; ++j) {
                catalan[i]+= catalan[j-1] * catalan[i-j]; 
            }
        }
        return catalan[n];
    }
};
