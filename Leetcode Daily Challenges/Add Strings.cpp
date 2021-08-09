class Solution {
public:
    string addStrings(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res = "";
        int n = a.length(), i = 0;
        int m = b.length(), j = 0;
        int carry = 0;
        while(!(i==n && j ==m && carry == 0)) {
            int d = carry;
            if(i < n) {
                d += a[i] - '0'; ++i;
            }
            if(j < m) {
                d += b[j] - '0'; ++j;
            }
            res += '0' + (d%10);
            carry = d/10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
