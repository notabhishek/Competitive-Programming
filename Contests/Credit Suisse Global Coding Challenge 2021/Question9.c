#include <stdio.h>
#define gc getchar_unlocked 
//#define gc getchar

// int time[10][20], dp0[10][1024], dp1[10][1024], mn0[1024], mn1[1024];

int main()
{
    const register int INF = 20005;
    register int b = 0, c = 0, i, j, bi, pbi, bmask, sub, tmp, ch, ans = INF, bit = 0;

    ch = gc();
    for (; ch > 32; ch = gc())
    {
        c = (c << 1) + (c << 3) + ch - 48;
    }
    
    ch = gc();
    for (; ch > 32; ch = gc())
    {
        b = (b << 1) + (b << 3) + ch - 48;
    }
    
    const register int B = 1 << b;
    int time[b][c], dp0[b][B], dp1[b][B], mn0[B], mn1[B];
    
    
    for (i = 0; i < b; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            ch = gc();
            tmp = 0;
            for (; ch > 32; ch = gc())
            {
                tmp = (tmp << 1) + (tmp << 3) + ch - 48;
            }
            time[i][j] = tmp;
        }
    }

    for (i = 0; i < c; ++i)
    {
        if (bit == 0)
        {
            // bit 0  pbit 1
            for (j = B; j--;)
                mn0[j] = INF;
            for (bi = 0, pbi = 1; bi < b; ++bi, pbi <<= 1)
            {
                for (bmask = 0; bmask < B; ++bmask)
                {
                    if ((bmask & pbi) == 0)
                        dp0[bi][bmask] = INF;

                    else if (i == 0)
                    {
                        dp0[bi][bmask] = time[bi][i];

                        if (dp0[bi][bmask] < mn0[bmask])
                            mn0[bmask] = dp0[bi][bmask];
                    }
                    else
                    {
                        dp0[bi][bmask] = dp1[bi][bmask];

                        sub = bmask ^ pbi;

                        if (dp0[bi][bmask] > mn1[sub])
                            dp0[bi][bmask] = mn1[sub];

                        dp0[bi][bmask] = dp0[bi][bmask] + time[bi][i];

                        if (mn0[bmask] > dp0[bi][bmask])
                            mn0[bmask] = dp0[bi][bmask];
                    }
                }
            }
            bit = 1;
        }
        else
        {
            // bit 1 pbit 0
            for (j = B; j--;)
                mn1[j] = INF;
            for (bi = 0, pbi = 1; bi < b; ++bi, pbi <<= 1)
            {
                for (bmask = 0; bmask < B; ++bmask)
                {
                    if ((bmask & pbi) == 0)
                        dp1[bi][bmask] = INF;

                    else if (i == 0)
                    {
                        dp1[bi][bmask] = time[bi][i];

                        if (dp1[bi][bmask] < mn1[bmask])
                            mn1[bmask] = dp1[bi][bmask];
                    }
                    else
                    {
                        dp1[bi][bmask] = dp0[bi][bmask];

                        sub = bmask ^ pbi;

                        if (dp1[bi][bmask] > mn0[sub])
                            dp1[bi][bmask] = mn0[sub];

                        dp1[bi][bmask] = dp1[bi][bmask] + time[bi][i];

                        if (mn1[bmask] > dp1[bi][bmask])
                            mn1[bmask] = dp1[bi][bmask];
                    }
                }
            }
            bit = 0;
        }
    }

    if (bit == 0)
    {
        for (bmask = B; bmask--;)
            if (ans > mn1[bmask])
                ans = mn1[bmask];
    }
    else
    {
        for (bmask = B; bmask--;)
            if (ans > mn0[bmask])
                ans = mn0[bmask];
    }

    printf("%d", ans);
    return 0;
}
