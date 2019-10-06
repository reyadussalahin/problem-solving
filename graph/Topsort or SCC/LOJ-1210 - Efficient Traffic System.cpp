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
 
#define LIMIT 20010
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
 
int color[LIMIT];
 
bool visited[LIMIT],ins[LIMIT],outs[LIMIT];
stack<int>topsort;
 
void dfs(int u,vector<int>graph[],bool f,int cl,bool c)
{
    visited[u]=true;
    if(c)
        color[u]=cl;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(color[u]!=color[v])
            ins[color[v]]=outs[color[u]]=true;
        if(visited[v]==false)
        {
 
            dfs(v,graph,f,cl,c);
        }
    }
    if(f)
        topsort.push(u);
}
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,m;
        SFF(n,m);
        vector<int>graph[n+10],tgraph[n+10];
        for(int i=0;i<m;i++)
        {
            int u,v;
            SFF(u,v);
            graph[u].pb(v);
            tgraph[v].pb(u);
        }
        mem(visited,0);
        topsort=stack<int>();
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
                dfs(i,graph,1,0,0);
        }
        int c=1;
        mem(visited,0);
        while(!topsort.empty())
        {
            int u=topsort.top();
            topsort.pop();
            if(visited[u]==false)
                dfs(u,tgraph,0,c,1),c++;
        }
        mem(visited,0);
        mem(ins,0);
        mem(outs,0);
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
                dfs(i,graph,0,0,0);
        }
        int in=0,out=0;
        for(int i=1;i<c;i++)
        {
            //cout<<ins[i]<<' '<<outs[i]<<endl;
            if(!ins[i])in++;
            if(!outs[i])out++;
        }
        if(c==2)in=out=0;
        printf("Case %d: %d\n",cas,max(in,out));
    }
}