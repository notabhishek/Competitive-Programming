class Solution {
public:
    int bitwiseComplement(int n) {
        return (n == 0 ? 1 : ((1<<(1+(int)log2(n)))-1)^n);
    }
};
