// SPF
const int MAXA = 1e5 + 10;
int minPrime[MAXA];
int init(int n = MAXA) {
	for (int i = 2; i * i <= n; ++i) {
	    if (minPrime[i] == 0) {         //If i is prime
	        for (int j = i * i; j <= n; j += i) {
	            if (minPrime[j] == 0) {
	                minPrime[j] = i;
	            }
	        }
	    }
	}
	for (int i = 2; i <= n; ++i) {
	    if (minPrime[i] == 0) {
	        minPrime[i] = i;
	    }
	}
}


const int MOD = 998244353;

// fpow
ll fpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

// NCR 
vector<int> fact;
vector<int> ifact;
void init(int NAX = 3e5) {
	fact.resize(NAX + 1);
	ifact.resize(NAX + 1);
	fact[0] = 1;
	for(int i = 1; i <= NAX; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
	ifact[NAX] = fpow(fact[NAX], MOD-2, MOD);
	for(int i = NAX-1; i >= 0; --i) {
		ifact[i] = ( (i+1) * ifact[i+1] )%MOD;
	}
}
int ncr(int n, int r){
	if(n < r || n < 0 || r < 0) 
		return 0;
	int res = (fact[n] * ifact[r]) % MOD;
	res = (res * ifact[n-r]) % MOD;
	return res;
}


// Extended Euclidean Algorithm
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
