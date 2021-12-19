class Solution {
public:
    string decodeString(string s) {
        string decoded;
        int idx = 0, number = 0;
        
        while(idx < s.length()){
            if(s[idx] >= '0' && s[idx] <= '9'){
                number = number * 10 + (s[idx] - '0');
            }else if(s[idx] == '['){
                
                pair<string, int> data = helper(s, idx+1);
                
                data.first = decodeString(data.first);
                
                for(int i = 0; i < number; i++){
                    decoded += data.first;
                }
                
                number = 0;
                
                idx = data.second;
                
            }else{
                decoded += s[idx];
            }
            
            idx++;
        }
        
        return decoded;
    }
    
    pair<string, int> helper(string s, int idx){
        int count = 1; string calc;
        
        while(count != 0){

            if(s[idx] == '['){
                count++;
            }else if(s[idx] == ']'){
                count--;
            }
            
            if(count != 0){
                calc += s[idx];
                idx++;
            }
        }
        
        return { calc , idx};
        
    }
};
