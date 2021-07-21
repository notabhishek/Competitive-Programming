const int NAX = 3e5 + 100;
int par[NAX];
int siz[NAX];
 
void init(int n) {
	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		siz[i] = 1; 
	}
}

int getp(int u) {
	if(par[u] == u)
		return par[u];
	return par[u] = getp(par[u]);
}

void uni(int x ,int y) {
	int u = getp(x);
	int v = getp(y);
	if(u == v)
		return;
	if(siz[u] > siz[v])
		swap(u , v);
	siz[v] += siz[u];
	par[u] = v;
}

