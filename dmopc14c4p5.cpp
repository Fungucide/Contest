#incldue <bits/stdc++/.h>

#define MAXN 200001

typedef long long ll

ll N,K, seg[2 * MAXN], lazy[MAXN], segSize[2 * MAXN], h = 0,res=1<<30,l,u;

//NOTE: Current Seg tree is for addition, modifications will need to be made for other operations all parts marked will require editing

template <typename T>
void construct(T *t, T(*combiner)(T, T), bool segS)
{
    for (int i = N - 1; i > 0; --i)
        t[i] = combiner(t[i << 1], t[i << 1 | 1]);
    for (h = 0; N >> h > 0; h++);
    if (segS)
    {
        for (int i = 2 * N - 1; i >= N; i--)
            segSize[i] = 1;
        for (int i = N - 1; i > 0; i--)
            segSize[i] = segSize[i << 1] + segSize[i << 1 | 1];
    }
    else
        for (int i = 0; i < MAXN << 1; i++)
            segSize[i] = 1;
}

template <typename T>
void apply(T *t, T *d, int p, T v)
{
    t[p] += v * segSize[p];
    if (p < N)
        d[p] += v;
}

template <typename T>
void build(T *t, T *d, int p, T(*combiner)(T, T))
{
    while (p > 1)
    {
        p >>= 1;
        t[p] = combiner(t[p << 1], t[p << 1 | 1]) + d[p] * segSize[p];
    }
}

template <typename T>
void push(T *t, T*d, int p)
{
    for (int s = h; s > 0; --s)
    {
        int i = p >> s;
        if (i < N && d[i] != 0)
        {
            apply(t, d, i << 1, d[i]);
            apply(t, d, i << 1 | 1, d[i]);
            d[i] = 0;
        }
    }
}

template <typename T>
void update(T *t, T *d, int l, int r, T value, T(*combiner)(T, T))
{
    l += N, r += N;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            apply(t, d, l, value);
            l++;
        }
        if (r & 1)
        {
            r--;
            apply(t, d, r, value);
        }
    }
    build(t, d, l0, combiner);
    build(t, d, r0 - 1, combiner);
}

template <typename T>
T query(T *t, T*d, int l, int r, T(*combiner)(T, T), T res = 0)
{
    l += N;
    r += N;
    push(t, d, l);
    push(t, d, r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res = combiner(res, t[l]);
            l++;
        }
        if (r & 1)
        {
            --r;
            res = combiner(t[r], res);
        }
    }
    return res;
}

ll sum(ll a, ll b)
{
    return a + b;
}

ll absSum(ll a,ll b)
{
    return abs(a)+abs(b);
}

ll cost(ll val,int n){
    update(seg,lazy,0,n,-val,sum);
}

int main()
{
    scanf("%d%d",&N,&K);
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&seg[N+i]);
    }
    if(!(N&1))
        N--;
    for(int i = 0; i<((N+1)>>1); i++)
    {
        seg[N+i]-=i+1;
        l = min(l,seg[N+i]);
        u = max(u,seg[N+i]);
    }

    int val = ((N+1)>>1)-1;
    for(int i = ((N+1)>>1); i<N; i++,val++)
    {
        seg[N+i]-=val;
        l = min(l,seg[N+i]);
        u = max(u,seg[N+i]);
    }

    for(int i = N;i>=K;i-=2){

    }

    construct(seg,absSum,true);
}
