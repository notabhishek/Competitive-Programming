class Solution {
public:
    string customSortString(string order, string str) {
        map< char, int > m;
        for(auto &i : str) m[i]++;
        str = "";
        for(auto &i : order) {
            str += string(m[i] , i);
            m.erase(i);
        }
        for(auto &i : m) str += string(i.second, i.first);
        cout << str;
        return str;
    }
};
