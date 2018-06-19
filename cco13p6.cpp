#include <bits/stdc++.h>

using namespace std;

int *dp;

int main() {
    string s;
    int MOD;
    cin>>s>>MOD;
    dp = new int[s.length()+1];
    dp[0]=1;
    for(int i = 1; i<=s.length(); i++) {
        int kust=0;
        for(int j=1; j<i; j++) {
            if(s[i-1]==s[j-1])
                kust=dp[j-1];
            dp[j]=(dp[j]+kust)%MOD;
        }
        dp[i]=(dp[i-1]<<1)%MOD;
    }
    cout<<dp[s.length()]<<"\n";
    return 0;
}
