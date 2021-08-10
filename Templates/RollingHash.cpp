// Problem: A Needle in the Haystack
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/NHAY/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long int;

const int MOD = 1e9 + 7;
ll fpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


struct Hash{
	ll v1, v2;
	ll len;
	const int m1 = 8675309, p1=257;
    const int m2 = 1000000009, p2=619;
    
    const int lenMax = 1e6;
    bool prec;
    vector<int> powp1, powp2;
	
	Hash(): v1(0), v2(0), len(0), prec(false) {};
	
	void precomp() {
		if(prec) return;
		prec = 1;
		powp1.resize(lenMax+1);
		powp2.resize(lenMax+1);
		powp1[0] = powp2[0] = 1;
		for(int i = 1; i <= lenMax; ++i) {
			powp1[i] = powp1[i-1]*p1%m1;
			powp2[i] = powp2[i-1]*p2%m2;
		}
	}

	void add(char c) {
		v1=(v1*p1 + c)%m1;
		v2=(v2*p2 + c)%m2;
		len++;
	}
	
	Hash(string const &s) {
		v1 = v2 = len = prec = 0;
		for(auto c : s) 
			add(c);	
    } 
    Hash(Hash const &h) {
    	v1 = h.v1; v2=h.v2; len=h.len;
    }
    void append(Hash h){
    	v1 = (v1*fpow(p1, h.len, m1) + h.v1)%m1;
    	v2 = (v2*fpow(p2, h.len, m2) + h.v2)%m2;
    	len += h.len;
    	// precomp();
    	// v1 = (v1*powp1[len] + h.v1)%m1;
    	// v2 = (v2*powp2[len] + h.v2)%m2;
    	// len += h.len;
    }
    pair<int,int> get() { return {v1, v2}; }
    vector<pair<int,int>> getPreHash(string &s) {
    	v1 = v2 = len = prec = 0;
    	vector<pair<int,int>> res;
    	for(auto c : s) {
			add(c);
			res.push_back(get());	
		}
		return res;
    }
    bool operator == (Hash h) {
    	return v1 == h.v1 && v2 == h.v2 && len == h.len;
    	return get() == h.get();
    }
    bool operator == (pair<int,int> p) {
    	return get() == p;
    }
    void operator = (Hash h) {
    	v1 = h.v1; v2 = h.v2; len = h.len;
    }
};

void solve()
{
	int n;
	while(cin>>n){
		string txt, pat;
		cin >> pat >> txt;
		int m = txt.length();
		Hash phash(pat);
		Hash thash1, thash2;
		for(int i = 0; i < m; ++i) {
			thash2.add(txt[i]);
			if(i >= n) {
				thash1.add(txt[i-n]);
			}
			Hash tmp(thash1);
			tmp.append(phash);
			if(tmp == thash2) {
				cout << i-n+1 << "\n";
			}
		}
		cout << endl;
	}
}

signed main()
{
    solve();
}
