class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        multiset<int> R;
        for(auto &i : a) R.insert(i);
        int ans = a.size()-1;
        multiset<int> L;
        for(int i = 0; i <a.size(); ++i) {
            L.insert(a[i]);
            R.erase(R.find(a[i]));
            
            if(*L.rbegin() <= *R.begin())  {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
