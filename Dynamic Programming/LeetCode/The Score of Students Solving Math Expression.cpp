template<typename T> ostream& operator << (ostream &os, vector<T> &v) {
    os << "[ ";
    for(int i: v) os << i << ", "; 
    os << "]\n";
    return os;
}
template<typename T> ostream& operator << (ostream &os, unordered_set<T> &v) {
    os << "{ ";
    for(int i: v) os << i << ", "; 
    os << "}\n";
    return os;
}
class Solution {
public:
    int correct(string &a) {
        vector<int> s;
        int cur = 0, n = a.length();
        bool mul = false;
        for(int i = 0; i < n; ++i) {
            if(a[i] >= '0' && a[i] <= '9') 
                cur = cur * 10 + a[i]-'0';
            else {
                if(mul) s[s.size()-1]*= cur;
                else s.push_back(cur);
                mul = false;
                cur = 0;
                if(a[i] == '*') mul = true;
            }
        }
        if(mul) s[s.size()-1]*= cur;
        else s.push_back(cur);
        return accumulate(s.begin(), s.end(), 0);
    }
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.length();
        const int MX = 1000;
        vector< vector< unordered_set<int> >> dp(n, vector<unordered_set<int>>(n));
        for(int l = 1; l <= n; ++l) {
            for(int i = 0; i+l-1 < n; ++i) {
                if(s[i] == '+' || s[i] == '*') continue;
                int j = i+l-1;
                if(l == 1) 
                    dp[i][i].insert(s[i]-'0');
                else {
                    for(int k = i+1; k < j; ++k) {
                        if(s[k] == '+' || s[k] == '*') {
                            for(auto u : dp[i][k-1]) 
                                for(auto v : dp[k+1][j]) {
                                    if(s[k] == '+' && u+v <= MX) dp[i][j].insert(u+v);
                                    if(s[k] == '*' && u*v <= MX) dp[i][j].insert(u*v);
                                }
                        }
                    }
                }
            }
        }
        // cout << dp[0][n-1];
        int p = 0, c = correct(s);
        // cout << c << endl;
        unordered_set<int> &st = dp[0][n-1];
        for(int i : answers) 
            if(i == c) p+=5;
            else if(st.count(i)) p+=2;
        return p;
    }  
};
