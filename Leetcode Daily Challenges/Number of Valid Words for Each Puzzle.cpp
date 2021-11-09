class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int ,int> hash;
        
        for(string word : words){
            //cout<<bitmask(word)<<endl;
            hash[bitmask(word)]++;
        }
        
        
        vector<int> result;
        
        for(string puzzle : puzzles){
            int first = 1 << (puzzle[0] - 'a');
            
            int count = hash[first];
            
            int mask = bitmask(puzzle.substr(1));
            
            for(int submask = mask; submask > 0 ; submask = (submask - 1) & mask){
                count += hash[submask | first];
            }
            
            result.push_back(count);
        }
        
        return result;
    }
    
    int bitmask(const string &word){
        int mask = 0;
        
        for(char ch : word){
            mask |= 1 << (ch - 'a');
        }
        
        return mask;
    }
};
