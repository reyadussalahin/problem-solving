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
#define rep(i,x,n) for(int i=x;i<n;i++)
#define rrep(i,x,n) for(int i=x;i>n;i--)
 
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
 
 
#define LIMIT 50010
#define inf INT_MAX
vector<int>graph[LIMIT],rgraph[LIMIT],newg[LIMIT];
bool visited[LIMIT];
stack<int>ts;
int color[LIMIT],dp[LIMIT],rcolor[LIMIT],val[LIMIT];
 
void init()
{
    rep(i,0,LIMIT)
    {
        graph[i].clear(),rgraph[i].clear(),newg[i].clear();
        rcolor[i]=LIMIT;
    }
    mem(visited,0);
    mem(color,0);
    mem(dp,0);
    ts=stack<int>();
    mem(val,0);
}
void topsort(int u,vector<int>g[])
{
    visited[u]=true;
    rep(i,0,g[u].size())
    {
        int v=g[u][i];
        if(visited[v])continue;
        topsort(v,g);
    }
    ts.push(u);
}
 
void coloring(int u,int c,int& x)
{
    visited[u]=true;
    color[u]=c;
    if(u<rcolor[c])
        rcolor[c]=u;
    rep(i,0,rgraph[u].size())
    {
        int v=rgraph[u][i];
        if(visited[v])continue;
        x++;
        coloring(v,c,x);
    }
    val[c]=x;
}
 
void create(int u)
{
    visited[u]=true;
    rep(i,0,graph[u].size())
    {
        int v=graph[u][i];
        int x=color[u],y=color[v];
        if(x!=y)
            newg[x].pb(y);
        if(visited[v])continue;
        create(v);
    }
}
 
int find_ans(int u)
{
    visited[u]=true;
    int count=0;
    rep(i,0,newg[u].size())
    {
        int v=newg[u][i];
        if(visited[v])
        {
            count+=val[v];
            continue;
        }
        count+=find_ans(v);
    }
    return val[u]+=count;
}
 
int main()
{
    fast;
    int t;
    cin>>t;
    rep(cs,1,t+1)
    {
        init();
        int n;
        cin>>n;
        rep(i,0,n)
        {
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
            rgraph[v].pb(u);
        }
        rep(i,1,n+1)
        {
            if(visited[i]==false)
                topsort(i,graph);
        }
        int c=1;
        mem(visited,0);
        while(!ts.empty())
        {
            int u=ts.top();
            ts.pop();
            int x=1;
            if(visited[u]==false)
                coloring(u,c,x),c++;
        }
        mem(visited,0);
        rep(i,1,n+1)
        {
            if(visited[i]==false)
                create(i);
        }
        mem(visited,0);
        ts=stack<int>();
        rep(i,1,c)
        {
            if(!visited[i])
                topsort(i,newg);
        }
        mem(visited,0);
        int ans=0,node;
        while(!ts.empty())
        {
            int u=ts.top();
            ts.pop();
            if(visited[u]==false)
            {
                int x=find_ans(u);
                if(x>ans)
                    ans=x,node=rcolor[u];
            }
        }
        cout<<"Case "<<cs<<": "<<node<<endl;
    }
}