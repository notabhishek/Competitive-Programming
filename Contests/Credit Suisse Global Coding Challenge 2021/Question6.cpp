// using printf + hash + gp_hash_table

// #include <algorithm>
// #include <iostream>
#include <stdio.h>
#include <string.h>
// #include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std; 

#define gc getchar_unlocked
#define pc putchar_unlocked
//#define gc getchar
// #define pc putchar

// struct custom_hash{
	// size_t operator()(unsigned int key) const {
	    // return key;
    // }
// };

int main()
{ 


    register int n = 0, m = 0, a = 0, b = 0, f = 0, s = 0, t = 0, c;

    c = gc();

    for (; c != 32; c = gc())

    {

        n = (n << 1) + (n << 3) + c - 48;
    }

    // m

    c = gc();

    for (; c != 32; c = gc())

    {

        m = (m << 1) + (m << 3) + c - 48;
    }

    // a

    c = gc();

    for (; c != 32; c = gc())

    {

        a = (a << 1) + (a << 3) + c - 48;
    }

    // b

    c = gc();

    for (; c != 32; c = gc())

    {

        b = (b << 1) + (b << 3) + c - 48;
    }

    // f

    c = gc();

    for (; c != 32; c = gc())

    {

        f = (f << 1) + (f << 3) + c - 48;
    }

    // s

    c = gc();

    for (; c != 32; c = gc())

    {

        s = (s << 1) + (s << 3) + c - 48;
    }

    // t

    c = gc();

    for (; c != 10; c = gc())
    {

        t = (t << 1) + (t << 3) + c - 48;
    }

    register int par[n], siz[n], cnt1[n], cnt2[n], cnt3[n];

    // unordered_map<string, int> idx;
    // idx.reserve(n);
    // unordered_map<unsigned int, unsigned int, custom_hash> idx;
    // idx.reserve(n);
    gp_hash_table<unsigned int, int> idx;

    char emp[n][12];

    register int i;
    register unsigned int hash;

    // string ts;
    char *ts;

    for (i = 0; i < n; ++i)

    {

        ts = emp[i];

        c = gc();
        hash = 0;
        for (; c != 32; c = gc())

        {
            hash += c;
            hash += (hash << 10);
            hash ^= (hash >> 6);
            *ts = c;
            ts++;
        }
        *ts = '\0';
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);

        idx[hash] = i;
        // printf("%d_%s_\n", i, emp[i]);
        // emp[i] = ts;

        c = gc();

        siz[i] = 1;

        par[i] = i;

        if (c == '1')
        {

            cnt1[i] = 1;
            cnt2[i] = cnt3[i] = 0;
        }
        else if (c == '2')
        {

            cnt2[i] = 1;
            cnt1[i] = cnt3[i] = 0;
        }
        else
        {

            cnt3[i] = 1;
            cnt1[i] = cnt2[i] = 0;
        }

        c = gc();
    }

    // process requests

    register int u, v;
    register int mxsz = 0, cnt = 0;
    
    while (m-- > 0)

    {
        c = gc();
        hash = 0;
        for (; c != 32; c = gc())

        {
            hash += c;
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
        u = idx[hash];
        while (par[u] != u)

        {

            par[u] = par[par[u]];

            u = par[u];
        }

        hash = 0;
        c = gc();
        for (; c != 10 && c != -1; c = gc())

        {
            hash += c;
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
        v = idx[hash];

        while (par[v] != v)

        {

            par[v] = par[par[v]];

            v = par[v];
        }

        if ((u != v) && (siz[u] + siz[v] <= b) && (cnt1[u] + cnt1[v] <= f) && (cnt2[u] + cnt2[v] <= s) &&

            (cnt3[u] + cnt3[v] <= t))

        {

            if (siz[u] > siz[v])

                swap(u, v);

            siz[v] = siz[v] + siz[u];

            par[u] = v;

            cnt1[v] = cnt1[v] + cnt1[u];

            cnt2[v] = cnt2[v] + cnt2[u];

            cnt3[v] = cnt3[v] + cnt3[u];
            if(siz[v] >= mxsz) {
            	if(siz[v] == mxsz) cnt = cnt + mxsz;
            	else mxsz = cnt = siz[v];
            }
        }
    }


    // for (i = 0; i < n; ++i)
    // {
        // if (siz[i] >= mxsz)
        // {
            // if (siz[i] == mxsz)
                // cnt = cnt + mxsz;
            // else
            // {
                // mxsz = siz[i];
                // cnt = mxsz;
            // }
        // }
    // }

    if (mxsz < a)
    {
        puts("no groups\n");
        return 0;
    }

    register int ridx = 0;

    for (i = 0; i < n && ridx < cnt; ++i)
    {

        register int u = i;

        while (par[u] != u)
        {

            par[u] = par[par[u]];

            u = par[u];
        }

        if (siz[u] == mxsz)
        {
            strcpy(emp[ridx++], emp[i]);
        }
    }
    
    qsort(emp, cnt, sizeof(*emp), (int (*)(const void*, const void*))strcmp);
    
    for(i = 0; i < cnt; ++i) printf("%s\n", emp[i]);   
    
    /*
    char *tmp; 
    for(i = 0; i < cnt; ++i) {
    	tmp = emp[i];
    	while(*tmp) {
    		pc(*tmp); tmp++;
    	}
    	pc('\n');
    }     
    */

    return 0;
}
