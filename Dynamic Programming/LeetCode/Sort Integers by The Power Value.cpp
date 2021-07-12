class Solution {
public:
    unordered_map<int,int> m;
    int p(int n) {
        if(m.count(n)) 
            return m[n];
        if(n % 2 == 0)
            return m[n] = 1 + p(n/2);
        return m[n] = 1 + p(3*n + 1);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> a;
        m[1] = 0;
        for(int i = lo; i <= hi; ++i ) {
            a.push_back({p(i) , i});
        }
        sort(a.begin() , a.end());
        return a[k-1].second;
    }
};
