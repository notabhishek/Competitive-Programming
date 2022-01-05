class Solution {
public:
    bool palin(string s) {
        for(int i = 0; i < s.length(); ++i) 
            if(s[i] != s[s.length()-1-i]) 
                return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector< vector< string >> ans;
        if(s.size() == 1) {
            ans.push_back({s});
            return ans;
        }
        
        string cur = "";
        for(int i = 0; i + 1< s.length(); ++i) {
            cur += s[i];
            if(palin(cur)) {
                vector< vector< string >> tmp = partition(s.substr(i+1));
                for(auto &v : tmp){
                    v.insert(v.begin() , cur);
                    ans.push_back(v);
                }
            }    
        }
        if(palin(s)) {
            ans.push_back({s});
        }
        return ans;
    }
};
