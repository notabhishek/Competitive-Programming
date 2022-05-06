class Solution {
public:
    string removeDuplicates(string a, int k) {
        stack<pair<char, int>> s;
        for(char c : a) {
            if(!s.empty() && s.top().first == c) {
                pair<char, int> p = s.top(); s.pop();
                p.second += 1;
                if(p.second < k)
                    s.push(p);
            } else {
                s.push({c, 1});
            }
        }
        a = "";
        while(!s.empty()) {
            a += string(s.top().second, s.top().first);
            s.pop();
        }
        reverse(a.begin(), a.end());
        return a;
    }
};
