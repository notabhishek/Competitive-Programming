// Problem : Tree Diameter
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1131
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
//Code by : Abhishek Tiwari @devil_within
#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 10;
int n  , m;
vector<int> adj[MAXN];
 
int far , dist;
 
void findFar(int src, int p , int lvl ){
	if(lvl > dist ) {
		far = src;
		dist = lvl;
	}
	for(auto &node : adj[src] ) {
		if( node != p )
			findFar(node , src , lvl + 1);
	}
}
int diameter() {
	
	far = -1; dist = 0;
	
	findFar(1 , -1 , 0);
	int end1 = far;
	
	far = -1; dist = 0;
	
	findFar(end1 , -1 , 0 );
	int end2 = far;
	
	// cout << "Ends of diameter : " << end1 << " " << end2 << "\n";
	// cout << "Diameter : " << dist << endl;
	return dist; 
}
 
int32_t main(){
	cin >> n;
	for(int i = 1 ; i < n ; ++i ) {
		int u , v;
		cin >> u  >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << diameter() << endl;
	
}