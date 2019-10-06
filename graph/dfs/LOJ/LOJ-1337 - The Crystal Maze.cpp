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
int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};
 
 
#define LIMIT 600
#define inf INT_MAX
 
char grid[LIMIT][LIMIT];
int val[LIMIT][LIMIT];
bool visited[LIMIT][LIMIT],svisited[LIMIT][LIMIT];
int n,m,cnt;
void init()
{
    mem(val,0);
    mem(visited,0);
    mem(svisited,0);
    cnt=0;
}
 
void dfs(int u,int v)
{
    int &p=cnt;
    visited[u][v]=true;
    if(grid[u][v]=='C')
        cnt++;
    for(int i=0;i<4;i++)
    {
        int x=u+fx[i],y=v+fy[i];
        if(grid[x][y]!='#' && visited[x][y]==false && x<=n && x>0 && y<=m && y>0)
        {
            dfs(x,y);
        }
    }
    val[u][v]=max(val[u][v],cnt);
}
 
void sdfs(int u,int v)
{
    int &p=cnt;
    svisited[u][v]=true;
    for(int i=0;i<4;i++)
    {
        int x=u+fx[i],y=v+fy[i];
        if(grid[x][y]!='#' && svisited[x][y]==false && x<=n && x>0 && y<=m && y>0)
        {
            sdfs(x,y);
        }
    }
    val[u][v]=max(val[u][v],cnt);
}
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        init();
        int q;
        SFFF(n,m,q);
        char ch;
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%c",&grid[i][j]),ch=grid[i][j];
            getchar();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(visited[i][j]==false && grid[i][j]!='#')
                {
                    cnt=0;
                    dfs(i,j);
                    int x=cnt;
                    sdfs(i,j);
                }
            }
        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//                cout<<val[i][j]<<' ';
//            cout<<endl;
//        }
        printf("Case %d:\n",cas);
        while(q--)
        {
            int x,y;
            SFF(x,y);
            printf("%d\n",val[x][y]);
        }
    }
}