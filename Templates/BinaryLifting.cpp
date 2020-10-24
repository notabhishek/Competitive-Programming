int n, l;
vector<vector<int>> adj;

int tim;
vector<int> in, out;
vector<vector<int>> up;

void dfs(int v, int p)
{
    in[v] = ++tim;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    out[v] = ++tim;
}

bool isAnc(int u, int v)
{
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
    if (isAnc(u, v))
        return u;
    if (isAnc(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!isAnc(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void init(int root) {
    in.resize(n);
    out.resize(n);
    tim = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}