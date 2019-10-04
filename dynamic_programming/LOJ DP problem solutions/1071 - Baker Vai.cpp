#include<bits/stdc++.h>
using namespace std;
 
#define inf INT_MAX;
int dp[105][105][105][4],a[105][105];
int n,m;
 
int func(int i,int j,int k,int nm)
{
    if(i==n-1 && j==m-2 && k==m-1 && nm==0)
        return 0;
    if(dp[i][j][k][nm]!=-1)
        return dp[i][j][k][nm];
    int p=0;
    if(nm==0)
    {
        if(j+1<k)
            p=max(p,func(i,j+1,k,0)+a[i][j+1]);
        p=max(p,func(i,j,k,1));
    }
    else if(nm==1)
    {
        if(k+1<m)
        {
            p=max(p,func(i,j,k+1,1)+a[i][k+1]);
        }
        if(k>j)
            p=max(p,func(i,j,k,2));
    }
    else
    {
        if(k>j&&i+1<n)
            p=max(p,func(i+1,j,k,0)+a[i+1][j]+a[i+1][k]);
    }
    return dp[i][j][k][nm]=p;
}
 
main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cas<<": "<<func(0,0,0,0)+a[0][0]<<endl;
    }
}