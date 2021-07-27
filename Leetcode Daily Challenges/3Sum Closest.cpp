class Solution {
public:
    int threeSumClosest(vector<int>& a, int k) {
        multiset<int> s;
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        int sum = -1, mind = INT_MAX;
        for(int i = 0; i < n; ++i) {
            s.erase(s.find(a[i]));
            for(int j = i+1; j < n; ++j) {
                s.erase(s.find(a[j]));
                auto it1 = s.lower_bound(k - a[i] - a[j]);  // sum >= k
                if(it1 != s.end()) {
                    if(mind > abs(k-a[i]-a[j]-*it1)) {
                        sum = a[i]+a[j]+*it1;
                        mind = abs(k-a[i]-a[j]-*it1);
                    }
                }
                if(it1 != s.begin()) {
                    --it1;
                    if(mind > abs(k-a[i]-a[j]-*it1)) {
                        sum = a[i]+a[j]+*it1;
                        mind = abs(k-a[i]-a[j]-*it1);
                    }
                }
                s.insert(a[j]);
            }
            s.insert(a[i]);
        }
        return sum;
        
    }
};
