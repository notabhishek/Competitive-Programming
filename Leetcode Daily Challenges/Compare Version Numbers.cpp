class Solution {
public:
    int compareVersion(string a, string b) {
        int i = 0, j = 0, n = a.length(), m = b.length();
        while(i < n || j < m) {
            int rev1 = 0, rev2 = 0;
            while(i < n && a[i] != '.') rev1 = rev1*10 + (a[i++]-'0');
            while(j < m && b[j] != '.') rev2 = rev2*10 + (b[j++]-'0');
            ++i, ++j;
            if(rev1 != rev2)
                return (rev1 - rev2) / abs(rev1 - rev2);
        }
        return 0;
    }
};
