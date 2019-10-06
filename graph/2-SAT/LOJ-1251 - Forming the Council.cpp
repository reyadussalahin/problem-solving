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
#define SLL(n,m) scanf("%lld %lld",&n,&m)
#define rep(i,x,n) for(int i=x;i<n;i++)
#define rrep(i,x,n) for(int i=x;i>n;i--)
#define forcas(t) for(int cas=1;cas<=t;cas++)
#define printcas cout<<"Case "<<cas<<':'
 
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
 
 
#define LIMIT 20000
#define inf INT_MAX
 
vector<int>graph[LIMIT],rgraph[LIMIT];
int n,m,col,comp[LIMIT];
stack<int>ts;
 
int value(int x)
{
         if ( x < 0 ){
        x=-x;
        x--;
        return ((x)<<1)+1;
    }
    x--;
    return ((x)<<1);
 
}
 
void init()
{
    for(int i=0;i<LIMIT;i++)
        graph[i].clear(),rgraph[i].clear();
    mem(comp,0);
    col=1;
}
 
void topsort(int u)
{
    comp[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(comp[v]==0)
            topsort(v);
    }
    ts.push(u);
}
 
void scc(int u)
{
    comp[u]=col;
    for(int i=0;i<rgraph[u].size();i++)
    {
        int v=rgraph[u][i];
        if(comp[v]==0)
            scc(v);
    }
}
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        init();
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            int u,v,x,y;
            cin>>u>>v;
            u=value(u),v=value(v);
            x=u,y=v;
            x^=1,y^=1;
            graph[x].pb(v);
            rgraph[v].pb(x);
            graph[y].pb(u);
            rgraph[u].pb(y);
        }
        for(int i=0;i<2*m;i++)
        {
            if(comp[i]==0)
                topsort(i);
        }
        mem(comp,0);
        col=1;
        while(!ts.empty())
        {
            int u=ts.top();
            ts.pop();
            if(comp[u]==0)
                scc(u),col++;
        }
        bool f=false;
        vector<int>ans;
        for(int i=0;i<2*m;i+=2)
        {
            if(comp[i]==comp[i+1])
            {
                f=true;
                break;
            }
            if(comp[i]>comp[i+1])
                ans.pb(i/2);
        }
        if(f)
        {
            cout<<"Case "<<cas<<": No"<<endl;
        }
        else
        {
            cout<<"Case "<<cas<<": Yes"<<endl;
            cout<<ans.size();
            for(int i=0;i<ans.size();i++)
                cout<<' '<<ans[i]+1;
            cout<<endl;
        }
    }
}