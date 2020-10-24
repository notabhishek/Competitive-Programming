#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct node
{
    int mn;
};

struct segTree
{
    vector<node> tree;
    vector<bool> clazy;
    vector<int> lazy;
    int n;
    int MAXN;
    void merge(node &cur, node &l, node &r)
    {
        // complete merge here
       	cur.mn = min(l.mn , r.mn);
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
                lazy[2 * v + 1] += lazy[v];
            }
            
            tree[v].mn += lazy[v];

            clazy[v] = false;
            lazy[v] = 0;
        }
    }
    void build(int v, int tl, int tr, vector<int> &a)
    {
        if (tl == tr)
        {
            // complete here
            tree[v].mn = a[tl];
        }
        else
        {
            int tmid = (tl + tr) / 2;
            build(2 * v, tl, tmid, a);
            build(2 * v + 1, tmid + 1, tr, a);
            merge(tree[v], tree[2 * v], tree[2 * v + 1]);
        }
    }
    void build(vector<int> &a)
    {
        MAXN = a.size() + 1;
        n = a.size();
        tree.resize(4 * MAXN);
        clazy.assign(4 * MAXN, false);
        lazy.assign( 4 * MAXN, 0);
        build(1, 0, n - 1 , a);
    }
    void build(int nn)
    {
        MAXN = nn + 1;
        n = nn;
        tree.assign(4 * MAXN , { 0ll } ); // change initial values here
        clazy.assign( 4 * MAXN, false);
        lazy.assign( 4 * MAXN, 0);
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
            lazy[v] += val;
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
            node out;
            out.mn = INT_MAX;
            return out;
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
    		clazy[v] = 1;
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
    tree.build(n);
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
        	cout << tree.query(l, r).mn << "\n";
        }
    }
}


