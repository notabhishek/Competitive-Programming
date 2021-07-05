class Solution {
public:
    int tribonacci(int n) {
        int tri[n+3];
        tri[0] = 0;
        tri[1] = tri[2] = 1;
        for(int i = 3; i <= n; ++i) tri[i] = tri[i-1] + tri[i-2] + tri[i-3];
        return tri[n];
    }
};
