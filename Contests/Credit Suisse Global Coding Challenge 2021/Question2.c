#include <stdio.h>
#define gc getchar_unlocked
#define N 51

int cnt[N]; 

int main()
{

    register int val;

    register int ans = 0, cur = 0, z = 0, c;

	c = gc(); 

    for (; c != 10; c = gc())

    {

        z = (z << 1) + (z << 3) + c - 48; 

    } 

    register int i = 1;
	c = gc();
	val = 0;
	while(c != -1) {
		if(c == 32) {
			cnt[val] = cnt[val] + i++;
			val = 0;
		} else {
			val = (val << 1) + (val << 3) + c - 48;
		}
		c = gc();
	}
	cnt[val] = cnt[val] + i++;
    // while (scanf("%d", &val) == 1)
    // {
        // cnt[val] = cnt[val] + i++;
    // }

    i = 1;

    while (i < N && cur <= z)

    {

        cur = cur + i * cnt[i];
        ans = ans + cnt[i++];

    }

    if (cur > z)

    {

        --i;

        ans = ans - cnt[i] + ((z-cur + i * cnt[i])/i);

    }

    printf("%d", ans);

    return 0;

}
