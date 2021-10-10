using ll = long long;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(ll i=0;i<=30;i++){
            ll a = (1LL<<i);
            ll l = left - a,p = l/(a*2);
            int l1 = p*a*2 + a,r1 = l1 + a - 1;
            if(left>=l1 and right<=r1)
                ans+=a;
        }
        return (int)ans;
    }
};
