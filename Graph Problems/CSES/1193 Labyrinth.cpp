// Problem : Labyrinth
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1193
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
//Code by : Abhishek Tiwari @devil_within
#include<bits/stdc++.h>
#define VI vector<int>
#define ar array
#define pb push_back
using namespace std;
 
int x[4] = {1, -1, 0 , 0 };
int y[4] = {0, 0, 1, -1  };
char path[4] = {'D' ,'U' ,'R','L'};
const int mxN = 1e3 , mxM = 1e3;
int m , n;
string adj[mxN];
vector<string> par(mxN , string (mxM , '#'));
vector<char> ans;
int sr  , sc; // source
int dr , dc; //dest
bool valid(int r , int c) {
	if( r>=0 && c>=0 && r<n && c<m )
		return adj[r][c]!='#'; //wall
	return false;
}
bool bfs(int r , int c) {
	queue<ar<int , 2 >> q;
	q.push({r , c});
	while(!q.empty()) {
		r = q.front()[0];
		c = q.front()[1];
		q.pop();
		if(r==dr && c==dc) {
			while(par[r][c]!='X') {
				ans.pb(par[r][c]);
				switch(par[r][c]) {
					case 'L' : ++c; break;
					case 'R' : --c; break;
					case 'U' : ++r; break;
					case 'D' : --r; break;
				}
			}
			return true;
		}
		for(int i = 0 ; i < 4; ++i) {
			int tr = r + x[i];
			int tc = c + y[i];
			if(valid(tr,tc) && par[tr][tc] == '#') {
				par[tr][tc] = path[i];
				q.push({ tr , tc} );
			}		
		}	
	}
	return false;
}
int32_t main()  
{
	cin >> n >> m;
	for(int i = 0 ; i < n;++i )  {
		cin >> adj[i];
	}
	for(int i = 0 ; i <n;++i ) {
		for(int j = 0 ; j < m; ++j) {
			if(adj[i][j] == 'A') {
				sr = i;
				sc = j;
				par[sr][sc] = 'X';
			}
			if(adj[i][j] == 'B') {
				dr = i;
				dc = j;
			}	
		}
	}
	if(bfs(sr , sc)) {
		cout << "YES\n";
		cout << ans.size() <<"\n";
		for(int i = ans.size()-1; i >=0; --i) cout << ans[i]; cout <<"\n";
	} else {
		cout << "NO\n";
	}
	
	
 
return 0;
}
