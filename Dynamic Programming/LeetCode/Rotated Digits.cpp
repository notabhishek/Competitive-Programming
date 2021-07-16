class Solution {
public:
    int valid(int N) {
        if(N==0) return false;
        set<int> s;
        while(N!=0) {
            int r = N%10;
            s.insert(r);
            N/=10;
        }
        if(s.find(3)!=s.end() || s.find(4)!=s.end() || s.find(7)!=s.end()) 
                return false;
        return s.find(2)!=s.end() || s.find(5)!=s.end() || s.find(6)!=s.end() || s.find(9)!=s.end();
    }
    int rotatedDigits(int N) {
        int c = 0;
        for(int i = 1 ; i <= N; ++i) {
            c+= valid(i);
        }
        return c;
    }
};
