template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &v)
{
    os << "{";
    for (auto it : v)
    {
        os << "(" << it.first << " : " << it.second << ")";
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}
using umap = map<char,int>;
class Solution {
public:
    bool chk(umap &a, umap &b) {
        for(auto  &c : b) if(c.second > a[c.first]) return false;
        return true;
    }
    string minWindow(string s, string t) {
        umap fs;
        umap ft;
        for(auto &c : t) ft[c]++;
        int len = 1e9, st;
        int i = 0, j = 0;
        while(i < s.size()) {
            j = max(j, i);
            while(j < s.size() && chk(fs, ft) == false) {
                fs[s[j]]++;
                ++j;
            }
            // cout << fs;
            if(chk(fs, ft) && len > j-i) {
                len = j-i;
                st = i; 
            }
            fs[s[i]]--;
            ++i;
        }
        if(len > s.size()) return "";
        return s.substr(st, len);
    }
};
