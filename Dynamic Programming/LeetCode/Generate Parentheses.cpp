class Solution {
public:
    void generate(string prefix , int l , int r , vector<string>  &res){
        //cout <<prefix <<" "<< l <<" "<< r << endl;
        if(r < l) {
            return;
        }
        if(l==0 && r==0) {
            res.push_back(prefix);
            return;
        }
        if(l>0)
        generate(prefix+"(" , l-1 , r , res);
        if(r>0)
        generate(prefix+")" , l , r-1 , res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("" , n , n , res);
        return res;
    }
};
