#include<bits/stdc++.h>
using namespace std;
#define VVI vector<vector<int>> 
void addEdge(int u , int v , VVI &adj , bool bidir = true){
    adj[u].push_back(v);
    if ( bidir ) 
        adj[ v ].push_back( u );
}
 
void printAdj(VVI &adj){
    for( auto i : adj){
        cout<<"[ ";
        for(auto j : i){
            cout << j << ", "; 
        }
        cout<<"]\n";
    }
    cout<<"\n";
}
 
void findCmpUtil(int src ,int &mark,vector<int> &component,  vector<bool> &vis , VVI &adj)
{
    vis[src] = 1;
    component[ src ] = mark;
    //cout << src << " ";
    for(auto i : adj[ src ]){
        if ( !vis[i] )
            findCmpUtil(i, mark, component, vis, adj);
    }
}
 
void findComponents(int N ,VVI &adj)
{
    vector<int> component(N+1);
    vector<bool> vis(N+1 , 0);
    int cnt = 1;
    for ( int i = 1 ; i <= N ; ++i) {
        if ( !vis[i] ) {
            findCmpUtil(i , cnt , component, vis, adj);
            ++cnt;
        }
    }
	cout << cnt-2 << endl;
	vector<int> cmp(cnt);
	for(int i = 1;  i <= N; ++i) cmp[ component[i] ] = i;
	for(int i = 2; i < cnt; ++i) 
		cout << cmp[1] << " " << cmp[i] << endl;
    //for(auto i : component ) cout<< i <<" "; cout<<"\n";
}
int main()
{
    int N;
    cin >> N;
    VVI adj( N+1 );
    int E; 
    cin >> E;
    for( int i = 0 ; i < E ; ++i)
    {
        int u , v;
        cin >> u >> v;
        addEdge( u , v , adj , true );
    }
    //printAdj(adj);
    findComponents(N , adj);
}
