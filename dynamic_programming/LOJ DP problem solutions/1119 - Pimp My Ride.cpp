#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define fast ios_base::sync_with_stdio(false)
#define loop(a,b) for(int i=a;i<b;i++)
#define mem(a,x) memset(a,x,sizeof(a))
#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define fast ios_base::sync_with_stdio(false)
#define loop(a,b) for(int i=a;i<b;i++)
#define mem(a,x) memset(a,x,sizeof(a))
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<long long,long long>
#define pls pair<long long,string>
#define pis pair<int,string>
#define pcc pair<char,char>
#define pb push_back
#define all(v) v.begin(),v.end()
 
typedef long long lli;
typedef long li;
typedef unsigned long long ulli;
typedef unsigned long int uli;
typedef unsigned int ui;
typedef long double ld;
 
inline int iseven(int x){return x&1?0:1;}
 
inline bool is_double(double x)
{
    double y=x-(int)x;
    return (y==x?true:false);
}
 
li bigmod(li b,li p,lli m)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        return (li)pow(bigmod(b,p/2,m)%m,2)%m;
    }
    return (b%m*bigmod(b,p-1,m)%m)%m;
}
 
template<class T>
ostream& operator<<(ostream &out,vector<T>v)
{
    for(lli i=0;i<v.size();i++)
        out<<v[i]<<' ';
    return out;
}
 
inline double distance(int x,int y,int a,int b)
{
    return sqrt(pow(x-a,2)+pow(y-b,2));
}
 
int n;
long long a[20][20];
long long dp[(1<<15)+10];
int Set(int n,int i)
{
    return (n|(1<<i));
}
 
int reset(int n,int i)
{
    return (n&(~(0<<i)));
}
 
bool check(int n,int i)
{
    return (bool)(n&(1<<i));
}
 
long long func(int mask)
{
    if(mask==((1<<(n+1))-2))
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    long long ans=1<<28;
    for(int i=1;i<=n;i++)
    {
        if(!check(mask,i))
        {
            long long p=a[i][i];
            for(int j=1;j<=n;j++)
            {
                if(check(mask,j) && i!=j)
                    p+=a[i][j];
            }
            long long ret=p+func(Set(mask,i));
            ans=min(ans,ret);
        }
    }
    return dp[mask]=ans;
}
 
#define sf(n) scanf("%d",&n)
int main()
{
    int t;
    sf(t);
    for(int cas=1;cas<=t;cas++)
    {
        sf(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                sf(a[i][j]);
        }
        mem(dp,-1);
        printf("Case %d: %lld\n",cas,func(0));
    }
}