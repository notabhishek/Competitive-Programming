using ll = long long;
class Solution {
public:
    ll ncr(ll n, ll r) {
        if(n < r) return 0;
        ll res = 1;
        for(int i = 0; i < r; ++i) {
            res = res * (n-i) / (i+1);
        }
        return res;
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        string res = "";
        int ver = destination[0];
        int hor = destination[1];
        int n = hor + ver;
        for(int i = 1; i <= n; ++i) {
            // put H here 
            ll left = ncr(hor + ver - 1, hor-1);
            if(hor > 0 && left >= k) {
                res += "H";
                hor-=1;
            } else {
                k-=left;
                res += "V";
                ver-=1;
            }
        }
        return res;
    }
};
