#include <bits/stdc++.h>

using namespace std;

#define MAXN 200001
#define BSIZE 450

int N,Q,block[MAXN],val[MAXN],divis[MAXN][BSIZE];

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &val[i]);
        block[i] = i / BSIZE;
        for (int j = 1; j <= sqrt(val[i]); j++)
        {
            if (val[i] % j == 0)
            {
                divis[j][block[i]]++;
                if (j*j != val[i])
                    divis[val[i] / j][block[i]]++;
            }
        }
    }

    int com, a, b, c;
    for (int q = 0; q < Q; q++)
    {
        scanf("%d", &com);
        if (com == 1)
        {
            scanf("%d%d%d", &a, &b, &c);
            --a;
            --b;
            int res = 0;
            if (block[a] == block[b])
            {
                for (; a <= b; a++)
                    if (val[a] % c == 0)
                        res++;
            }
            else
            {
                while (a != 0&&block[a] == block[a - 1])
                {
                    if (val[a] % c == 0)
                        res++;
                    a++;
                }
                while (block[b] == block[b + 1])
                {
                    if (val[b] % c == 0)
                        res++;
                    b--;
                }
                for (int i = block[a]; i <= block[b]; i++)
                {
                    res += divis[c][i];
                }
            }
            printf("%d\n", res);
        }
        else
        {
            scanf("%d%d", &a, &b);
            --a;
            for (int i = 1; i <= sqrt(val[a]); i++)
            {
                if (val[a] % i == 0)
                {
                    divis[i][block[a]]--;
                    if (i*i != val[a])
                        divis[val[a] / i][block[a]]--;
                }
            }
            val[a] = b;
            for (int i = 1; i <= sqrt(val[a]); i++)
            {
                if (val[a] % i == 0)
                {
                    divis[i][block[a]]++;
                    if (i*i != val[a])
                        divis[val[a] / i][block[a]]++;
                }
            }
        }
    }
    return 0;
}
