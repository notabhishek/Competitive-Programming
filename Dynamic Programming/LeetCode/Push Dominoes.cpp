class Solution {
public:
    // multi source bfs
    string pushDominoes(string s) {
        queue<int> q;
        int n = s.length();
        vector<int> d(n , 0);
        for(int i = 0; i < n; ++i)
            if(s[i] != '.')  {
                q.push(i);
                d[i] = (s[i] == 'L' ? -1 : 1);
            }
        queue<int> p;
        while(!p.empty() || !q.empty()) {
            while(!q.empty()) {
                int tp = q.front(); 
                q.pop();

                if(d[tp] == 1 && tp+1<n && s[tp+1] == '.') {
                    d[tp+1]++;
                    p.push(tp + 1);
                }
                if(d[tp] == -1 && tp>0 && s[tp-1] == '.') {
                    d[tp-1]--;
                    p.push(tp-1);
                }
            }
            
            while(!p.empty()) {
                if(d[p.front()] == -1){
                    s[p.front()]='L';
                    q.push(p.front());
                } else if(d[p.front()] == 1) {
                    s[p.front()]='R';
                    q.push(p.front());
                }
                p.pop();
            }
        }

        return s;
    }
};
