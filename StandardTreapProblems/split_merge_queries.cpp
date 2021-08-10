// Code by : Abhishek Tiwari @devil_within
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define vt vector<int>
#define pii pair<int, int>
#define ar array
using namespace std;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
using ll = long long int;
using ld = long double;

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b)
{
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

/*******************************************************************************************/
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T> ostream &operator<<(ostream &os, const set<T> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v);
template <typename T> inline istream &operator>>(istream &in, vector<T> &a);
/*******************************************************************************************/
// N dimensional Vector, Vec<n , int>
template <int D, typename T> struct Vec : public vector<Vec<D - 1, T>>
{
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template <typename... Args> Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...))
    {
    }
};
template <typename T> struct Vec<1, T> : public vector<T>
{
    Vec(int n = 0, const T &val = T()) : vector<T>(n, val)
    {
    }
};
/*******************************************************************************************/
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}

#define trace(...) cout <<"L:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)

const ll INF = LONG_LONG_MAX;
const int MOD = 1e9 + 7;

ll fpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

struct Treap {
	int data, priority;
	vector<Treap*> child;
	int subtreeSize, sum, toProp;
	
	Treap(int data);
};
int size(Treap *t) {
	return t==nullptr ? 0 : t->subtreeSize;
}
void recalc(Treap *t) {
	if(t == nullptr) return;
	t->subtreeSize = 1;
	t->sum = t->data + t->toProp * size(t); 
	for(Treap *c : t->child) {
		if(c != nullptr) {
			t->subtreeSize += c->subtreeSize;
			t->sum += c->data + c->toProp * size(c);
		}
	}
}
Treap::Treap(int data) {
	this->data = data;
	this->child = {nullptr, nullptr};
	this->priority = randint(0, 1e9);
	this->toProp = 0;
	this->subtreeSize = this->sum = 1;
	recalc(this);
}
void prop(Treap *t) {
	if(t == nullptr) return;
	if(t->toProp == 0) return; 
	for(Treap *c : t->child) {
		if(c != nullptr) {
			c->toProp += t->toProp; // propogate
		}
	}
	t->data += t->toProp * size(t); // calc your answer
	t->toProp = 0;
	recalc(t);
}

// lsz = size of left treap 
vector<Treap*> split(Treap *t, int lsz) {
	if(t == nullptr) return {nullptr, nullptr};
	prop(t);
	if(size(t->child[0]) >= lsz) {
		vector<Treap*> lRes = split(t->child[0], lsz);
		t->child[0] = lRes[1];
		recalc(t);
		return {lRes[0], t}; 
	} else {
		lsz -= size(t->child[0]) + 1;
		vector<Treap*> rRes = split(t->child[1], lsz);
		t->child[1] = rRes[0];
		recalc(t);
		return {t, rRes[1]};
	}
}
Treap* merge(Treap *L, Treap *R) {
	if(L == nullptr) return R;
	if(R == nullptr) return L;
	prop(L); prop(R);
	if(L->priority < R->priority) {
		L->child[1] = merge(L->child[1] , R);
		recalc(L);
		return L;
	} else {
		R->child[0] = merge(L, R->child[0]);
		recalc(R);
		return R;
	}
}
Treap *rangeAdd(Treap *t, int l, int r, int toAdd) {
	vector<Treap*> a = split(t, l) , b = split(a[1], r-l+1);
	b[0]->toProp += toAdd;
	return merge(a[0], merge(b[0], b[1]));
}
int rangeQuery(Treap *t, int l, int r) {
	vector<Treap*> a = split(t, l) , b = split(a[1], r-l+1);
	prop(b[0]);
	int res = b[0]->sum;
	merge(a[0], merge(b[0], b[1]));
	return res;
}
Treap* print(Treap *t) {
	if(!t) return nullptr;
	int n = size(t);
	vector<Treap*> v = split(t, 1);
	cout << v[0]->data << " ";
	return merge(v[0], print(v[1]));
}
void dfs(Treap *t) {
	if(!t) return;
	pii u = {t->data, size(t)};
	cout << u << ", ";
	dfs(t->child[0]);
	dfs(t->child[1]);
}
Treap* shandom_ruffle(Treap *root, int a, int b, int n) {
	if(b <= a) return root; 
	int sz = min(n-b+1, b-a);
	// 0...a-1 | a...a+sz-1 | a+sz..b-1 | b..b+sz-1 | b+sz...n 
	vector<Treap*> halves = split(root, b-1); // 0...b-1 | b...n
	vector<Treap*> h1p1 = split(halves[0], a-1); // 0..a-1 | a...b-1
	vector<Treap*> h1p2 = split(h1p1[1], sz); // a..a+sz-1 | a+sz..b-1
	vector<Treap*> h2p2 = split(halves[1], sz); // b...b+sz-1 | b+sz..n
	return merge(h1p1[0], merge(h2p2[0], merge(h1p2[1], merge(h1p2[0], h2p2[1]))));
}
void solve()
{
	int n;
	cin >> n;
	Treap *root = nullptr;
	root = print(root);
	
	for(int i = 1; i <= n; ++i) {
		Treap *tmp = new Treap(i);
		root = merge(root, tmp);
	}
	for(int i = 0; i < n; ++i) {
		int a , b;
		cin >> a >> b;
		root = shandom_ruffle(root, a, b, n);
	}
	root = print(root);
}

signed main()
{
    // freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        // cout << "Case #"<<tc<<": \n";
        solve();
    }
}

// Functions

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]\n";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v)
{
    os << "{";
    for (auto it : v)
    {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &v)
{
    os << "{";
    for (auto it : v)
    {
        os << "(" << it.first << " : " << it.second << ")";
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << "(";
    os << v.first << ", " << v.second << ")";
    return os;
}
template <typename T> inline istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
}
