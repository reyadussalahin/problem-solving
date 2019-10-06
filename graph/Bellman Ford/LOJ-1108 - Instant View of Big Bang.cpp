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
#define sl(n) scanf("%lld",&n)
 
#define LIMIT 2000
#define inf 100000
 
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
stack<int>topsort;
vector<int>graph[LIMIT];
int cost[LIMIT][LIMIT];
void dfs(int u,vector<int>graph[],bool t)
{
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(visited[v]==false)
        {
            dfs(v,graph,t);
        }
    }
    if(t)
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
        for(int i=0;i<n+10;i++)
            graph[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            SFFF(u,v,c);
            graph[v].pb(u);
            cost[v][u]=c;
        }
        mem(visited,0);
        int d[n+1];
        topsort=stack<int>();
        for(int i=0;i<n;i++)
        {
            d[i]=inf;
            if(visited[i]==false)
                dfs(i,graph,1);
        }
        mem(visited,0);
        while(!topsort.empty())
        {
            int u=topsort.top();
            topsort.pop();
            if(visited[u]==false)
                dfs(u,graph,0),d[u]=0;
        }
 
        for(int i=0;i<n-1;i++)
        {
            for(int u=0;u<n;u++)
            {
                for(int j=0;j<graph[u].size();j++)
                {
                    int v=graph[u][j];
                    int c=d[u]+cost[u][v];
                    int du=d[u],dv=d[v];
                    if(d[v]>d[u]+cost[u][v])
                        d[v]=d[u]+cost[u][v];
                }
            }
        }
        set<int>ans;
        mem(visited,0);
        for(int i=0;i<500;i++)
        for(int u=0;u<n;u++)
        {
            for(int j=0;j<graph[u].size();j++)
            {
                int v=graph[u][j];
                int c=d[u]+cost[u][v];
                int du=d[u],dv=d[v];
                if(d[v]>d[u]+cost[u][v])
                    d[v]=d[u]+cost[u][v],dfs(v,graph,0);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                ans.insert(i);
        }
        printf("Case %d: ",cas);
        bool f=false;
        if(ans.size()==0)
            cout<<"impossible";
        else
            for(set<int>::iterator i=ans.begin();i!=ans.end();i++)
            {
                if(f)
                    cout<<' ';
                f=true;
                printf("%d",*i);
            }
 
        cout<<endl;
    }
}