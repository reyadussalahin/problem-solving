#include<bits/stdc++.h>
using namespace std;
 
int a[100],c[100],n,k;
 
long long dp[55][25][1005];
#define mod 100000007
 
long long func(int i,int t,int cur)
{
    if(cur==k)
        return 1;
    if(i==n)
        return 0;
    if(dp[i][t][cur]!=-1)
        return dp[i][t][cur];
    long long p1=0,p2=0;
    if(a[i]+cur<=k && c[i]>t)
        p1=func(i,t+1,cur+a[i]);
    p2=func(i+1,0,cur);
    return dp[i][t][cur]=(p1%mod+p2%mod)%mod;
}
 
#define sf(n) scanf("%d",&n)
int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    sf(t);
    for(int cas=1;cas<=t;cas++)
    {
        sf(n),sf(k);
        for(int i=0;i<n;i++)
            sf(a[i]);
        for(int i=0;i<n;i++)
            sf(c[i]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",cas,func(0,0,0));
    }
}