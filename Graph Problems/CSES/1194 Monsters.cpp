#include<bits/stdc++.h>
#define VI vector<int>
#define int int64_t
#define ar array
const int mod = 1e9 + 7;
const int INF= INT_MAX;
using namespace std;
 
const int mxN = 1000;
int n , m;
string adj[mxN];
int32_t main()  
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//cout << fixed << setprecision(12);
int T = 1;
for(int tc = 1 ; tc <= T; ++tc )
{	
	cin >> n >> m;
	for(int i = 0 ; i < n;++i ) cin >> adj[i];
	
	queue< ar<int, 2 >  > q;
	vector< VI > dM(n , VI( m , INF));
	for(int i = 0 ; i < n; ++i) 
		for(int j = 0 ; j < m; ++j) 
			if ( adj[i][j] == 'M') {
 				q.push({ i , j});
 				dM[i][j] = 0;
 				}
	while(!q.empty()) {
		int r = q.front()[0];
		int c = q.front()[1];
		q.pop();
		if( r > 0  && adj[r-1][c]!='#') {
			if(dM[r-1][c] == INF) 
				q.push({r-1 , c});
			dM[r-1][c]= min( dM[r-1][c] , dM[r][c] + 1);
		}
		if( c > 0  && adj[r][c-1]!='#') {
			if(dM[r][c-1] == INF) 
				q.push({r , c-1});
			dM[r][c-1]= min( dM[r][c-1] , dM[r][c] + 1);
		}
		if( r < n-1 && adj[r+1][c]!='#') {
			if(dM[r+1][c] == INF ) 
				q.push({r+1 , c});
			dM[r+1][c]= min( dM[r+1][c] , dM[r][c] + 1);
		}
		if( c < m-1  && adj[r][c+1]!='#') {
			if(dM[r][c+1] == INF) 
				q.push({r , c+1});
			dM[r][c+1]= min( dM[r][c+1] , dM[r][c] + 1);
		}
	}
	//cout << dM;
	int sr , sc;
	for(int i = 0 ; i < n ; ++i) 
		for(int j = 0 ; j < m ; ++j) 
			if(adj[i][j] == 'A') {
				sr = i;
				sc = j;
				i = n;
				break;
			}
	
	vector< VI > dA(n , VI( m , INF));
	vector<string> par(n , string( m , '#'));
	dA[sr][sc] = 0;
	q.push({sr , sc});
	par[sr][sc] = 'X';
	
	bool flag = true;
	while(!q.empty()) {
		int r = q.front()[0];
		int c = q.front()[1];
		q.pop();
		if(r == n-1 || c == m-1 || r==0 || c==0) {
			//path found
			flag = false;
			//for(int i = 0 ; i< n;++i )
				//cout << par[i] << endl;
			stack<char> s;
			while(par[r][c] != 'X'){
				s.push(par[r][c]);
				switch(par[r][c]) {
					case 'R' : --c; break;
					case 'L' : ++c; break;
					case 'D' : --r; break;
					case 'U' : ++r; break;
				}
			}
			cout << "YES\n";
			cout << s.size() << endl; 
			while(!s.empty()) {
				cout << s.top(); s.pop();
			}
			break;
		}
		if( r > 0  && adj[r-1][c]!='#' && par[r-1][c] =='#') {
			dA[r-1][c] = min (dA[r-1][c] , 1+dA[r][c] );
			if(dA[r-1][c] < dM[r-1][c]) {
				par[r-1][c] = 'U';
				q.push({r-1 , c});
			}
		}
		if( c > 0  && adj[r][c-1]!='#' && par[r][c-1] =='#') {
			dA[r][c-1] = min (dA[r][c-1] , 1+dA[r][c] );
			if(dA[r][c-1] < dM[r][c-1]) {
				par[r][c-1] = 'L';
				q.push({r , c-1});
			}
		}
		if( r < n-1  && adj[r+1][c]!='#' && par[r+1][c] =='#') {
			dA[r+1][c] = min (dA[r+1][c] , 1+dA[r][c] );
			if(dA[r+1][c] < dM[r+1][c]) {
				par[r+1][c] = 'D';
				q.push({r+1 , c});
			}
		}
		if( c < m-1  && adj[r][c+1]!='#' && par[r][c+1] =='#') {
			dA[r][c+1] = min (dA[r][c+1] , 1+dA[r][c] );
			if(dA[r][c+1] < dM[r][c+1]) {
				par[r][c+1] = 'R';
				q.push({r , c+1});
			}
		}
	}
	if( flag ) 
		cout << "NO";
}
return 0;
}
