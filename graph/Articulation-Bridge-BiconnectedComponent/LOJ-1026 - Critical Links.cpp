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
 
vector<pii>ap;
int t=0;
map<int,bool>visited;
map<int,int>par,start,low;
 
void find_ap(vector<int>graph[],int u)
{
    visited[u]=true;
    start[u]=low[u]=t++;
 
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(par[u]==v)continue;
        if(visited[v]==false)
        {
            par[v]=u;
            find_ap(graph,v);
        }
            if(start[u]<low[v])
                ap.pb(u<v?pii(u,v):pii(v,u));
        low[u]=min(low[u],low[v]);
    }
}
int main()
{
    int test;
    cin>>test;
    for(int cas=1;cas<=test;cas++)
    {
        int n;
        cin>>n;
        vector<int>graph[n+1];
        for(int i=0;i<=n;i++)
        {
            visited[i]=par[i]=start[i]=low[i]=0;
            graph[i].clear();
        }
 
        int u,k,v;
        for(int j=0;j<n;j++)
        {
            char ch;
            cin>>u>>ch>>k>>ch;
 
            for(int i=0;i<k;i++)
            {
                scanf("%d",&v);
                graph[u].pb(v);
            }
        }
        ap.clear();
 
        t=0;
        printf("Case %d:\n",cas);
 
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                find_ap(graph,i);
            }
        }
        printf("%d critical links\n",ap.size());
        sort(all(ap));
        for(int i=0;i<ap.size();i++)
        {
            pii x=ap[i];
            cout<<x.first<<" - "<<x.second<<endl;
        }
    }
}