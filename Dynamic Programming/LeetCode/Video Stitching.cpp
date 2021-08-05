class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int s = 0;
        int cnt = 0;
        while( true ) {
            int e = -1;
            for(auto &i : clips) 
                if(i[0] <= s && i[1] > s) 
                    e = max( e , i[1]);
            ++cnt;
            if(e >= T) {
                return cnt;
            }
            s = e;
            if(e == -1) 
                return -1;
        }
        return -1;
    }
};
