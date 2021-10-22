class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;
        for(char c : s) frequency[c]++;
        
        auto compare = [&](char a, char b) -> bool {
           if(frequency[a] == frequency[b]) return a < b;
           return frequency[a] >= frequency[b]; 
        };
        
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
