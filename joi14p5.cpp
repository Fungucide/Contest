#include <bits/stdc++.h>
#define ll long long
#define MAXM 100002
#define LL_INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int M,N;
vector<int> col;

struct device {
    int l,r,e,c;//left right end cost
    void cust() {
        l=lower_bound(col.begin(),col.end(),l)-col.begin();
        r=lower_bound(col.begin(),col.end(),r)-col.begin();
        e=lower_bound(col.begin(),col.end(),e)-col.begin();
    }
};
device D[MAXM];

struct segTree {
private:
    int N;
    ll *tree;
public:
    segTree(int size) {
        tree = new ll[2*size];
        for (int i = 0; i < 2 * size; i++) {
            tree[i] = LL_INF;
        }
        N = size;
    }

    void update(int p,ll val) {
        if(tree[p+=N]<val)
            return;
        for(tree[p]=val; p>1; p>>=1)
            tree[p>>1]=min(tree[p],tree[p^1]);
    }

    ll query(int l,int r) {
        ll res=LL_INF;
        for(l+=N,r+=N; l<r; l>>=1,r>>=1) {
            if(l&1) {
                res=min(res,tree[l]);
                l++;
            }
            if(r&1) {
                r--;
                res=min(res,tree[r]);
            }
        }
        return res;
    }
};

int main() {
    scanf("%d%d",&M,&N);
    int a,b,c,d;
    for(int i = 0 ; i<M; i++) {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        D[i]={--a,b,--c,d};
        col.push_back(a);
        col.push_back(b);
        col.push_back(c);
    }
    col.push_back(0);
    col.push_back(N-1);
    sort(col.begin(),col.end());
    col.erase(unique(col.begin(),col.end()),col.end());
    N=col.size();
    for(int i = 0 ; i<M;i++)
        D[i].cust();
    segTree ls(N),rs(N);
    ll res =LL_INF;
    for(int i = 0 ; i<M;i++){
        //printf("Inf:%d [%d,%d] %d\n",i,D[i].l,D[i].r,D[i].e);
        ll la=D[i].l==0?D[i].c:ls.query(D[i].l,D[i].r)+D[i].c;
        ll ra=D[i].r==N-1?D[i].c:rs.query(D[i].l,D[i].r)+D[i].c;
        //printf("\tlq:%lld rq:%lld\n",ls.query(D[i].l,D[i].r),rs.query(D[i].l,D[i].r));
        //printf("\tls:%lld rs:%lld\n",la,ra);
        ls.update(D[i].e,la);
        rs.update(D[i].e,ra);
        res=min(res,la+ra-D[i].c);
    }
    if(res==LL_INF)
        printf("-1\n");
    else
        printf("%lld\n",res);
    return 0;
}
