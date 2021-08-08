/*
Given an array (N <= 1e5, 1 <= a[i] <= 1e9), 2 types of queries
1 idx val,  set a[idx] = val
2 val, find max ( a[i] ^ x ) from the array

Solution using trie
*/
#include <bits/stdc++.h>
using namespace std;

class node {
public: 
	int cnt[2];
	node *child[2];
	node(){
		cnt[0] = cnt[1] = 0;
		child[0] = child[1] = nullptr;
	}
};
class Trie {
public :
	int BIT; 
	node *root;
	Trie() {
		root = new node();
		BIT = 31;
	}
	void ins(int v) {
		node *cur = root;
		for(int i = BIT; i >= 0; --i) {
			int u = (v&(1ll<<i)) > 0;
			if(!cur->child[u]) 
				cur->child[u] = new node();
			cur->cnt[u]++;
			cur = cur->child[u]; 
		}
	}
	int get(int v) {
		node *cur = root;
		int ans = 0;
		for(int i = BIT; i >= 0; --i) {
			int u = (v&(1ll<<i)) > 0;
			if(cur->child[1-u]) {
				ans += (1ll<<i);
				cur = cur->child[1-u];
			} else if(cur->child[u]) {
				cur = cur->child[u];
			} else break; 
		}
		return ans;
	}
	void delHelper(int b, node *cur, int v) {
		if(!cur || b < 0) 
			return;
		int u = (v&(1ll<<b)) > 0;
		if(cur->child[u]) {
			cur->cnt[u]--;
			delHelper(b-1, cur->child[u], v);
		}
		if(cur->child[0] && cur->cnt[0] == 0) {
			free(cur->child[0]);
			cur->child[0] = nullptr;
		}
		if(cur->child[1] && cur->cnt[1] == 0) {
			free(cur->child[1]);
			cur->child[1] = nullptr;
		}
	}
	void del(int v) {
		delHelper(BIT, root, v);
	}
	void del2(int v) {
		node *cur = root;
		vector<node*> path;
		for(int i = BIT; i >= 0; --i) {
			int u = (v&(1ll<<i)) > 0;
			cur->cnt[u]--;
			if(cur->cnt[u] == 0) path.push_back(cur);
			cur = cur->child[u]; 
		}
		for(int i = path.size()-1; i>=0; --i) {
			if(path[i]->child[0] && path[i]->cnt[0] == 0) {
				free(path[i]->child[0]);
				path[i]->child[0] = nullptr;
			}
			if(path[i]->child[1] && path[i]->cnt[1] == 0) {
				free(path[i]->child[1]);
				path[i]->child[1] = nullptr;
			}
		}
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	Trie t;
	for(auto &i : a) {
		cin >> i;
		t.ins(i);
	}
	
	int q;
	cin >> q;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int idx , val;
			cin >> idx >> val;
			t.del(a[idx-1]);
			a[idx-1] = val;
			t.ins(val);
		} else {
			int x;
			cin >> x;
			cout << t.get(x) << "\n";
		}
	}
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
/*
input:
5
1 2 3 4 5 
3
2 7 
1 5 8 
2 7 

output:
6
15

input:
3
1 2 3 
7
2 4
1 3 1
2 4
1 2 1 
2 4 
2 0 
2 1

output:
7
6
5
1
0
*/
