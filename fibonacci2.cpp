#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int cust[100000],N;
bool l2=false;

void div2(){
}

void multiply(ll F[2][2], ll M[2][2])
{
    ll x = (F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD;
    ll y = (F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD;
    ll z = (F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD;
    ll w = (F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD;

    F[0][0] = x % MOD;
    F[0][1] = y % MOD;
    F[1][0] = z % MOD;
    F[1][1] = w % MOD;
}

void power(ll F[2][2])
{
    if (l2)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (cust[N-1] % 2 != 0)
        multiply(F, M);
}

ll fib(ll n)
{
    if(N==1&&cust[0]<2)
        return 1;
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F);
    return F[0][0];
}

int main()
{
    string s;
    cin>>s;
    N=s.lenght();
    for(int i = 0 ; i<N; i++)
        cust[i]=s[i]-'0';
    int idx=N-1;
    while(cust[idx]==0){
        cust[idx]==9;
        idx--;
    }
    cust[idx]--;
    printf("%lld\n", fib());
    return 0;
}
