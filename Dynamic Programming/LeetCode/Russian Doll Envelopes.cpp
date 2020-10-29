class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        if(e.size() == 0) 
                return 0;
        int n = e.size();
        sort(e.begin() , e.end() , [](vector<int> &a, vector<int> &b)->bool {
			return (a[0]!=b[0])?a[0]<b[0]:b[1]<a[1];
        });
        vector< int > h(n);
        for(int i = 0; i < n; ++i) h[i] = e[i][1];
        vector< int > lis;
        lis.push_back(h[0]);
        for(int i  =1 ; i <n; ++i) {
            int idx = lower_bound(lis.begin() , lis.end() ,h[i]) - lis.begin();
            if(idx == lis.size()) 
                lis.push_back(h[i]);
            else 
                lis[idx] = h[i];
        } 
        
        return lis.size();
    }
};