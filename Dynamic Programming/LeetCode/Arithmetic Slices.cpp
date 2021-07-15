class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i = 2; 
        int slices = 0;
        while(i < A.size()) {
            if((A[i] - A[i-1]) == (A[i-1]-A[i-2])) {
                int d = A[i] - A[i-1];
                int cur = 0;
                while( i < A.size() && A[i] - A[i-1] == d) {++i; ++cur;}
                slices += (cur*(cur+1))/2;
            } else 
                ++i;
        }
        return slices;
    }
};
