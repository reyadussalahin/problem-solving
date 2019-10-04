#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int dp[50][50];
ll dp2[50][50][100],len;
char a[50],b[50];
 
 
int findlcs(int i,int j)
{
    if(i==strlen(a)||j==strlen(b))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    if(a[i]==b[j])
        ans=1+findlcs(i+1,j+1);
    else
        ans=max(findlcs(i+1,j),findlcs(i,j+1));
    return dp[i][j]=ans;
}
 
ll findans(int i,int j,int l)
{
    if(i==strlen(a))
    {
        if((strlen(b)-j+l)==len)
            return 1;
        return 0;
    }
    if(j==strlen(b))
    {
        if((strlen(a)-i+l)==len)
            return 1;
        return 0;
    }
    if(dp2[i][j][l]!=-1)
        return dp2[i][j][l];
    ll ans=0;
    if(a[i]==b[j])
        ans=findans(i+1,j+1,l+1);
    else
    {
        ans=findans(i+1,j,l+1)+findans(i,j+1,l+1);
    }
    return dp2[i][j][l]=ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(dp,-1,sizeof(dp));
        int ch[300]={0};
        scanf("%s",a);
        scanf("%s",b);
        len=strlen(a)+strlen(b)-findlcs(0,0);
        memset(dp2,-1,sizeof(dp2));
        printf("Case %d: %d ",i,len);
        printf("%lld\n",findans(0,0,0));
    }
}