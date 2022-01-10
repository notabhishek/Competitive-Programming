class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size() - 1, bLen = b.size() - 1, k = 0;
        string res = "";
        bool carry = 0;
        while(k <= aLen || k <= bLen) {
            int val = (k <= aLen && a[aLen-k] == '1') + (k <= bLen && b[bLen-k] == '1') +carry;
            res = to_string(val%2) + res;
            carry = val >= 2;
            k++;
        }
        return (carry ? to_string(carry) : "") + res;
    }
};
