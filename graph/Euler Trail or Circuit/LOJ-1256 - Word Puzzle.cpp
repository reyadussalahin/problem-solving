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
#define forcas for(int cas=1;cas<=t;cas++)
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
 
 
#define LIMIT 300
#define inf INT_MAX
 
vector<int>graph[LIMIT],dg[LIMIT],path;
int visited[LIMIT][LIMIT],seen[LIMIT];
queue<int>ss[700];
map<int,string>strings;
int p[200][200]={0},s_col=1;
int in[LIMIT]={0},out[LIMIT]={0};
 
void init()
{
    for(int i=0;i<LIMIT;i++)
        graph[i].clear(),dg[i].clear();
    for(int i=0;i<700;i++)
        ss[i]=queue<int>();
    mem(visited,0);
    mem(seen,0);
    mem(p,0);
    s_col=1;
    mem(in,0);
    mem(out,0);
    path.clear();
    strings.clear();
}
 
void dfs(int u)
{
    seen[u]=true;
    for(int i=0;i<dg[u].size();i++)
    {
        int v=dg[u][i];
        if(seen[v])continue;
        dfs(v);
    }
}
 
void heirholzer(char u)
{
    seen[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        char v=graph[u][i];
        int x=visited[u][v];
        if(visited[u][v]==0)
            continue;
        visited[u][v]--;
        heirholzer(v);
 
    }
    path.pb(u);
}
 
int value(char a,char b)
{
    return (a-'a')+(b-'a')*10;
}
 
int main()
{
    int t;
    cin>>t;
    forcas
    {
        init();
        int col=1;
        int n;
        cin>>n;
        int c=27;
        bool mp[LIMIT]={0};
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            char u=s[0],v=s[s.length()-1];
            graph[u].pb(v);
            dg[u].pb(v);
            dg[v].pb(u);
            in[v]++,out[u]++;
            if(mp[u]==false)
                mp[u]=true,c--;
            if(mp[v]==false)
                mp[v]=true,c--;
            if(p[u][v]==0)
                p[u][v]=col++;
            ss[p[u][v]].push(i);
            strings[i]=s;
            visited[u][v]++;
        }
        int dfs_count=0;
        vector<int>node;
        for(char i='a';i<='z';i++)
        {
            if(seen[i]==false)
                dfs(i),dfs_count++;
            if(in[i]!=out[i])
                node.pb(i);
        }
        printcas;
        if(dfs_count!=c || (node.size()!=0 && node.size()!=2))
        {
            cout<<" No"<<endl;
            continue;
        }
        if(node.size()==0)
        {
            mem(seen,0);
            for(int i='a';i<='z';i++)
            {
                if(graph[i].size() && seen[i]==false)
                    heirholzer(i);
            }
        }
        else
        {
            int count=0;
            for(int i=0;i<2;i++)
            {
                char ch=node[i];
                if(in[node[i]]+1==out[node[i]])
                    heirholzer(ch),count++;
            }
            if(count!=1)
            {
                cout<<" No"<<endl;
                continue;
            }
        }
        reverse(all(path));
        int pos[LIMIT]={0};
        cout<<" Yes"<<endl;
        bool f=false;
        c=0;
        for(int i=0;i<path.size()-1&&c!=n;i++)
        {
            if(f)
                cout<<' ';
            f=true;
            char u=path[i],v=path[i+1];
            int x=p[u][v],y;
            if(ss[x].size()){
                y=ss[x].front();
                ss[x].pop();
            }
            cout<<strings[y];
            pos[x]++;
            c++;
        }
        cout<<endl;
    }
}