#include <stdio.h>

#define gc getchar_unlocked

int main()
{
    register int n = 0, m = 0, c, x, i = 0, j = 0, mS = 0, ans;
    c = gc();
    for (; c > 32; c = gc())
    {
        n = (n << 1) + (n << 3) + c - 48;
    }
    int a[n];
    c = gc();
    for (; c > 32; c = gc())
    {
        m = (m << 1) + (m << 3) + c - 48;
    }

    c = gc();
    for (; c > 32; c = gc())
    {
        mS = (mS << 1) + (mS << 3) + c - 48;
    }

    for (i = 0; i < n; ++i)
    {
        x = 0;
        c = gc();
        for (; c > 32; c = gc())
        {
            x = (x << 1) + (x << 3) + c - 48;
        }
        a[i] = x;
        if (mS >= 0)
        {
            mS = mS - x;
            ++j;
        }
    }
    if (0 > mS)
    {
        --j;
        mS = mS + a[j];
    }
    ans = j;
    i = 0;

    while (i < m)
    {

        x = 0;
        c = gc();
        for (; c > 32; c = gc())
        {
            x = (x << 1) + (x << 3) + c - 48;
        }
        mS = mS - x;
        while (j > 0 && mS < 0)
            mS = mS + a[--j];
        if (0 > mS)
            break;
        ++i;
        if (ans < j + i)
            ans = j + i;
    }
    printf("%d", ans);

    return 0;
}
