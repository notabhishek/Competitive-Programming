class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(string &email : emails) {
            auto idx = find(email.begin(), email.end(), '@') - email.begin();
            string res = "";
            for(int i = 0 ; i < idx; ++i) 
                if(email[i] == '+') break;
                else if(email[i] != '.') res += email[i];
            res += email.substr(idx);
            s.insert(res);
        }
        
        return s.size();
    }
};
