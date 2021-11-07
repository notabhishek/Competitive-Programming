class Solution {
public:
    string add(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c = "";
        int carry = 0;
        int i = 0;
        while(i < a.length() && i < b.length()) {
            carry += a[i] - '0' + b[i]-'0';
            c+= '0' + carry % 10;
            carry /= 10;
            ++i;
        }
        while(i < a.length()) {
            carry += a[i] - '0';
            c+= '0' + carry % 10;
            carry /= 10;
            ++i;
        }
        while(i < b.length()) {
            carry += b[i] - '0';
            c+= '0' + carry % 10;
            carry /= 10;
            ++i;
        }
        while(carry != 0) {
            c+= '0' + carry % 10;
            carry /= 10;
        }
        reverse(c.begin(), c.end());
        return c;
    }
    string multiply(string a, int b) {
        string c = "";
        reverse(a.begin(), a.end());
        int carry = 0;
        for(int i = 0; i < a.length(); ++i) {
            carry += (a[i] - '0') * b;
            c += '0' + carry %10;
            carry /= 10;
        }
        while(carry != 0) {
            c +='0' + carry%10;
            carry /= 10;
        }
        reverse(c.begin(), c.end());
        return c;
    }
    string multiply(string a, string b) {
        if(a=="0" || b == "0") return "0";
        string ans = "";
        reverse(b.begin(), b.end());
        int zero = 0;
        for(auto i : b) {
            string c = multiply(a, i-'0');
            c += string(zero, '0');
            zero ++;
            ans = add(ans, c);
        }
        return ans;
    }
};
