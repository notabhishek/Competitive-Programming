
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]\n";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v)
{
    os << "{";
    for (auto it : v)
    {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}
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
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << "(";
    os << v.first << ", " << v.second << ")";
    return os;
}
template <typename T> inline istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
}
class Solution {
public:
    vector<int> split(string &preorder){
        vector<int> pre;
        int i = 0, n = preorder.size(); 
        while(i < n){
            int j = i;
            while(j < n && preorder[j] != ',') ++j;
            if(preorder[i] == '#') pre.push_back(-1);
            else pre.push_back(stoi(preorder.substr(i, j-i)));
            i = j+1;
        }
        return pre;
    }
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        vector<int> pre = split(preorder);
        cout << pre;
        stack<pair<int, int>> s;
        bool f = false;
        for(auto &i : pre) {
            if(f) {
                if(s.empty()) return false;
            } else f = 1;
            
            if(i == -1) {
                if(s.empty()) return false;
                auto u = s.top(); s.pop();
                u.second++;
                if(u.second != 2) {
                    s.push(u);
                }
            } else {
                if(!s.empty()) {
                    auto u = s.top(); s.pop();
                    u.second++;
                    if(u.second != 2) {
                        s.push(u);
                    }
                }
                s.push({i, 0});
            }
            
            while(!s.empty() && s.top().second == 2) s.pop();
        }
        
        return s.size() == 0;
    }
};
