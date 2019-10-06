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
 
#define LIMIT 40000
#define inf INT_MAX
 
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
 
bool visited[LIMIT];
int dis;
int far;
vector<pii>graph[LIMIT];
 
int d[LIMIT];
void init()
{
    for(int i=0;i<LIMIT;i++)
        graph[i].clear(),d[i]=-inf;
    mem(visited,0);
}
void dfs(int u,int di)
{
    visited[u]=true;
    if(di>dis)
    {
        dis=di;
        far=u;
    }
    int x=d[u]=max(d[u],di);
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i].first;
        int c=graph[u][i].second;
        if(visited[v]==false)
        {
            dfs(v,di+c);
 
        }
    }
}
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        SF(n);
        init();
        for(int i=1;i<n;i++)
        {
            int u,v,c;
            SFFF(u,v,c);
            graph[u].pb(pii(v,c));
            graph[v].pb(pii(u,c));
        }
        dis=0;
        dfs(0,0);
        int &a=far,&b=dis;
        dis=0;
        int x=far;
        mem(visited,0);
        dfs(x,0);
        d[x]=dis;
        d[far]=dis;
        mem(visited,0);
        dfs(far,0);
        printf("Case %d:\n",cas);
        for(int i=0;i<n;i++)
        {
            printf("%d\n",d[i]);
        }
    }
}