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
#define si(n) scanf("%d",&n);
#define si(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
 
#define MAX 150010
 
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
 
vector<int>graph[20000];
int start[20000],low[20000],par[20000];
bool visited[20000];
vector<int>dag[20000];
map<pii,bool>bridge;
vector<int>ap;
int t,bcc,ans,col=1,color[20000];
void init(int n)
{
    for(int i=0;i<=n;i++)
        graph[i].clear(),dag[i].clear();
    mem(start,0),mem(low,0),mem(par,0);
    mem(visited,0);
    bridge.clear();
    ap.clear();
    t=bcc=ans=0;
    mem(color,0);
    col=1;
}
void find_ap(int u)
{
    visited[u]=true;
    start[u]=low[u]=t++;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(par[u]==v)
            continue;
        if(visited[v])
            low[u]=min(low[u],low[v]);
        if(!visited[v])
        {
            par[v]=u;
            find_ap(v);
            low[u]=min(low[u],low[v]);
            if(start[u]<low[v])
            {
                bridge[pii(min(u,v),max(u,v))]=true;
                ap.pb(u),ap.pb(v);
            }
        }
    }
}
 
int dfs(int u)
{
    visited[u]=true;
    color[u]=col;
    int cc=0;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visited[v] && bridge[pii(min(u,v),max(u,v))]==false)
        {
            cc++;
            dfs(v);
        }
 
        else if(bridge[pii(min(u,v),max(u,v))])
        {
            int x=color[u],y=color[v];
            if(color[u]!=0 && color[v]!=0)
                dag[x].pb(y),dag[y].pb(x);
        }
    }
    if(cc==0 && graph[u].size()==1)
        return 1;
    else
        return cc;
}
 
void find_ans(int u)
{
    visited[u]=true;
    if(dag[u].size()==1)
        ans++;
    for(int i=0;i<dag[u].size();i++)
    {
        int v=dag[u][i];
        if(visited[v]==false)
        {
            find_ans(v);
        }
    }
}
int main()
{
    int c;
    cin>>c;
    for(int cas=1;cas<=c;cas++)
    {
 
        int n,m;
        si(n,m);
        init(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            si(u,v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        find_ap(0);
        mem(visited,0);
        int& x=bcc;
        for(int i=0;i<ap.size();i++)
        {
            int u=ap[i];
            if(visited[u]==false)
            {
                bcc+=dfs(u);
                col++;
            }
        }
        mem(visited,0);
        find_ans(1);
        printf("Case %d: %d\n",cas,(ans+1)/2);
    }
}