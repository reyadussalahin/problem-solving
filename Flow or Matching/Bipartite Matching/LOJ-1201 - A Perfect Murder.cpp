#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define fast ios_base::sync_with_stdio(false)
#define endl '\n'
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
#define SF(n) scanf("%d",&n);
#define SFF(n,m) scanf("%d %d",&n,&m)
#define SFFF(n,m,l) scanf("%d %d %d",&n,&m,&l)
#define SL(n) scanf("%lld",&n)
#define SLL(n,m) scanf("%lld %lld,&n,&m)
 
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
 
//Direction Array
//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};
 
 
#define LIMIT 1500
#define inf INT_MAX
 
vector<int>graph[LIMIT];
int dp[LIMIT][3];
int par[LIMIT];
void init()
{
    for(int i=0;i<=LIMIT;i++)
        graph[i].clear(),par[i]=0;
    mem(dp,-1);
}
 
int func(int u,bool k)
{
    if(dp[u][k]!=-1)return dp[u][k];
    int p1=0,p2=0;
    if(k)
        p2=1;
    bool f=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(v==par[u])continue;
        par[v]=u;
        f=false;
        if(k==false)
        {
            p1+=func(v,true);
        }
        else
        {
            p1+=func(v,true);
            p2+=func(v,false);
        }
    }
    if(f && k)
        p2=1;
    return dp[u][k]=max(p1,p2);
}
 
int main()
{
    fast;
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int n,m;
        cin>>n>>m;
        init();
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(par[i]==0)
                ans+=func(i,true);
        }
        cout<<"Case "<<cas<<": ";
        cout<<ans<<endl;
    }
}