class Solution {
public:
    int findComplement(int num) {
        return (1ll<<(1+(int)log2(num))) - num-1;
    }
};
