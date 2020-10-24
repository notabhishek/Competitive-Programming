#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int MOD = 1e9 + 7;

struct node
{
    int sum;
    bool operator == (const node &a) {
    	return a.sum == sum;
    }
    void operator = (const node &a) {
    	sum = a.sum;
    }
};

struct segTree
{
	
    vector<node> tree;
    vector<bool> clazy;
    vector<int> lazy;
    int n;
    int MAXN;
    
    node OUT_OF_RANGE = { 0 }; // For Range Query Only
    int LAZY_DEFAULT = 0;
    
    void merge(node &cur, node &l, node &r)
    {
        // complete merge here
        if(l == OUT_OF_RANGE ) {
        	cur = r;
        } 
        else if(r == OUT_OF_RANGE ) {
        	cur = l;
        }
    	else {
    		cur.sum = (l.sum + r.sum);
    	}
    }

    void propogate(int v, int tl, int tr)
    {
    	// complete propogation here
        if (clazy[v] == true)
        {
            if (tl != tr)
            {
                clazy[2 * v] = true;
                clazy[2 * v + 1] = true;
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] +=  lazy[v];
            }
            
            tree[v].sum = (tree[v].sum + lazy[v] * (tr - tl + 1) );

            clazy[v] = false;
            lazy[v] = LAZY_DEFAULT;
        }
    }
    void Build(int v, int tl, int tr, vector<int> &a)
    {
        if (tl == tr)
        {
            // complete here
            tree[v].sum = a[tl];
        }
        else
        {
            int tmid = (tl + tr) / 2;
            Build(2 * v, tl, tmid, a);
            Build(2 * v + 1, tmid + 1, tr, a);
            merge(tree[v], tree[2 * v], tree[2 * v + 1]);
        }
    }
    void build(vector<int> &a)
    {
        MAXN = a.size() + 1;
        n = a.size();
        tree.resize(4 * MAXN);
        clazy.assign(4 * MAXN, false);
        lazy.assign( 4 * MAXN, LAZY_DEFAULT);
        Build(1, 0, n - 1 , a);
    }

    void build(int nn ,int init_val)
    {
        vector< int > a(nn , init_val );
        build(a);
    }

    void Update(int v, int tl, int tr, int l, int r, int val)
    {
    	if(clazy[v])
        	propogate(v, tl, tr);
        if (l > tr || tl > r)
        {
            return;
        }
        if (tl >= l && tr <= r)
        {
            clazy[v] = true;
            lazy[v] = val;
            propogate(v , tl , tr);
        }
        else
        {
            int tmid = (tl + tr) / 2;
            Update(2 * v, tl, tmid, l, r, val);
            Update(2 * v + 1, tmid + 1, tr, l, r, val);
            merge(tree[v], tree[2 * v], tree[2 * v + 1]);
        }
    }

    node Query(int v, int tl, int tr, int l, int r)
    {
    	if(clazy[v])
    		propogate(v, tl, tr);
        if (l > tr || tl > r)
        {
            // return value out of range
            return OUT_OF_RANGE;
        }
        if (tl >= l && tr <= r)
        {
            return tree[v];
        }
        else
        {
            int tmid = (tl + tr) / 2;
            node cur;
            node left = Query(2 * v, tl, tmid, l, r);
            node right = Query(2 * v + 1, tmid + 1, tr, l, r);
            merge(cur , left , right);
            return cur;
        }
    }
    void pUpdate(int v, int tl, int tr, int idx , int val) {
    	if(clazy[v])
    		propogate(v , tl , tr);
    	if(tl == tr) {
    		clazy[v] = true;
    		lazy[v] = val;
    		propogate(v , tl ,  tr);
    		return;
    	}
    	int tmid = (tl + tr)/2;
    	if( idx > tmid )
    		pUpdate(2*v + 1 , tmid + 1 , tr , idx , val);
    	else 
    		pUpdate(2*v ,tl ,tmid ,idx , val);
    	merge(tree[v] , tree[2*v] , tree[2*v + 1]);
    }
    
   	node pQuery(int v, int tl, int tr , int idx) {
    	if(clazy[v])
    		propogate(v , tl , tr);
    	if(tl == tr)
    		return tree[v];
    	int tmid = (tl + tr)/2;
    	if(idx > tmid ) 
    		return pQuery(2*v + 1 , tmid + 1, tr , idx); 
    	else 
    		return pQuery(2*v , tl , tmid , idx);
    }
    
    void update(int l, int r, int v)
    {
        Update(1, 0, n - 1, l, r, v);
    }
    void update(int idx , int val) {
    	pUpdate(1 , 0 , n-1 , idx , val);
    }
    node query(int l, int r)
    {
        return Query(1, 0, n - 1, l, r);
    }
    node query(int idx) {
    	return pQuery(1 , 0 , n-1 , idx);
    }
};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    segTree tree;
    tree.build(n , 0ll);
    while (m--)
    {
        int q , l, r, v;
        cin >> q;
        if(q == 1 ) {
	        cin >> l >> r >> v;
	        --r;
	        tree.update(l, r, v);
        } else {
        	cin >> l >> r;
        	--r;
        	cout << tree.query(l, r).sum << "\n";
        }
    }
}
