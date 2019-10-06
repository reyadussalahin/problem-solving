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
#define sc1(n) scanf("%d",&n);
#define sc2(n,m) scanf("%d %d",&n,&m)
#define sc3(n,m,l) scanf("%d %d %d",&n,&m,&l)
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
 
vector<pii>graph[50000];
int far,dis;
bool visited[50000];
 
void init()
{
    for(int i=0;i<40000;i++)
        graph[i].clear();
    far=dis=0;
    mem(visited,0);
}
 
void dfs(int u,int d)
{
    visited[u]=true;
    if(dis<d)
    {
        dis=d;
        far=u;
    }
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i].first;
        if(visited[v]==false)
            dfs(v,graph[u][i].second+d);
    }
}
int main()
{
    int t;
    sc1(t);
    for(int cas=1;cas<=t;cas++)
    {
        init();
        int n;
        sc1(n);
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            sc3(u,v,w);
            graph[u].pb(pii(v,w));
            graph[v].pb(pii(u,w));
        }
        dfs(0,0);
        dis=0;
        mem(visited,0);
        dfs(far,0);
        printf("Case %d: %d\n",cas,dis);
    }
}