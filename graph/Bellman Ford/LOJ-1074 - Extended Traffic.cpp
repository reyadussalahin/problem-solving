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
 
 
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        SF(n);
        int a[n+1],d[n+1];
        for(int i=1;i<=n;i++){
            SF(a[i]);
            d[i]=inf;
        }
        vector<pii>edges;
        int m;
        SF(m);
        long long cost[300][300];
        for(int i=0;i<m;i++)
        {
            int u,v;
            SFF(u,v);
            edges.pb(pii(u,v));
            long long x=a[v]-a[u];
            x=x*x*x;
            cost[u][v]=x;
        }
        d[1]=0;
        for(int i=1;i<=n+10;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                int u=edges[j].first,v=edges[j].second;
                if(d[v]>cost[u][v]+d[u])
                    d[v]=cost[u][v]+d[u];
            }
        }
        printf("Case %d:\n",cas);
        int q;
        SF(q);
        while(q--)
        {
            int u;
            SF(u);
            printf(d[u]<3 || d[u]>inf-100000?"?\n":"%d\n",d[u]);
        }
    }
}