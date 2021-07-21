class Solution {
public:
    string pushDominoes(string d) {
        int n = d.length();
        queue<int> q;
        for(int i = 0 ; i < n; ++i){
            if(d[i]!='.') 
                q.push(i);
        }
        queue<int> p;
        while(!p.empty() || !q.empty()) {
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                int add = (d[cur] == 'L' ? -1 : 1);
                if(d[cur]== 'L' && cur > 0 && d[cur-1] != 'L' && d[cur-1]!='R') {
                    d[cur-1] += add;
                    p.push(cur-1);
                }
                if(d[cur]=='R' && cur < n-1 && d[cur+1] != 'L' && d[cur+1]!='R'){
                    d[cur+1] += add;
                    p.push(cur+1);
                }
            }
            while(!p.empty()) {
                int cur = p.front();
                p.pop();
                if(d[cur] == '.') continue;
                if(d[cur] > '.') d[cur] = 'R';
                else d[cur] = 'L';
                q.push(cur);
            }
        }
        return d;
    }
};
