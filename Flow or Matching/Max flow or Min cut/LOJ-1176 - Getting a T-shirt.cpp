#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n)            for(int i=0;i<n;i++)cin>>a[i]
#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))
#define forcas          for(int cas=1;cas<=t;cas++)
#define printcas        cout<<"Case "<<cas<<':'
 
 
typedef long long ll;
typedef long li;
typedef unsigned long long ull;
typedef unsigned long int ul;
typedef unsigned int ui;
typedef long double ld;
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < vlong, vlong > pll;
typedef vector<pll> vll;
typedef vector<vlong> vl;
 
#define NODE 1000
 
struct KUHN{
    int left[NODE]; // Contains who is matched with ith vertex on left side
    int right[NODE]; // Contains who is matched with ith vertex on right side
    int vis[2*NODE]; ///Node double in vis for vertex print
    int cc;
    vector<int> adj[NODE]; // For each node on left side, push its neighbor here
 
    KUHN() : cc(1) {}
 
    void clear( int n ) {
        FOR(i,0,n) adj[i].clear();
    }
 
    bool tryK ( int v ) {
        if ( vis[v] == cc ) return false;
        vis[v] = cc;
        for ( int i = 0; i < SZ(adj[v]); i++ ) {
            int t = adj[v][i];
            if ( right[t] == -1 ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        for ( int i = 0; i < SZ(adj[v]); i++ ) {
            int t = adj[v][i];
            if ( tryK ( right[t] ) ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        return false;
    }
 
    int match(int n) {
        int res = 0;
        bool done;
        CLR(left,-1); CLR(right,-1);
        do {
            done = true; cc++;
            FOR(i,0,n) {
                if(left[i]==-1 && tryK(i)) {
                    done = false;
                }
            }
        } while(!done);
        FOR(i,0,n) res += (left[i]!=-1);
        return res;
    }
 
    ///Careful. Loop runs from 0 to n-1
    ///Make sure match() has been run
    int lcover[NODE]; // If lcover[i] is 1, then ith node of left side is a member of vertex cover
    int rcover[NODE]; // If rcover[i] is 1, then ith node of right side is a member of vertex cover
    void findVertexCover ( int n ) {
        queue<int> q;
        cc++;
        FOR(i,0,n-1){
            if ( left[i] == -1 ) {
                q.push ( i );
                vis[i] = cc;
            }
        };
 
        while ( !q.empty() ) {
            int s = q.front(); q.pop();
            FOR(i,0,SZ(adj[s])-1){
                int t = adj[s][i];
                if ( t == left[s] ) continue;
 
                int xt = t + n;
                if ( vis[xt] == cc ) continue;
 
                vis[xt] = cc;
                xt = right[t];
 
                if ( xt != -1 && vis[xt] != cc ) {
                    vis[xt] = cc;
                    q.push ( xt );
                }
 
            };
        }
 
        FOR(i,0,n-1){
            if ( vis[i] != cc ) lcover[i] = 1;
            else lcover[i] = 0;
        };
        FOR(i,0,n-1){
            if ( vis[i+n] == cc ) rcover[i] = 1;
            else rcover[i] = 0;
        };
 
    }
}kuhn;
 
 
 
 
vector<int>graph[1000];
int cost[1000][1000];
int source,sink;
map<string,int>mp;
int n,m;
 
void setedge(int u,int v)
{
    for(int i=0;i<n;i++)
    {
        kuhn.adj[u].pb(v);
        graph[u].pb(v),cost[u][v]=1;
        graph[v].pb(sink),cost[v][sink]=1;
        v++;
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    mp["XXL"]=0,mp["XL"]=1,mp["L"]=2,mp["M"]=3,mp["S"]=4,mp["XS"]=5;
 
    cin>>t;
    forcas
    {
        kuhn.clear(999);
        cin>>n>>m;
        int node=n*6;
        source=n*6+m;
        sink=source+1;
        for(int i=0;i<m;i++)
        {
            string a,b;
            cin>>a>>b;
            int ts=mp[a]*n;
            setedge(node,ts);
            ts=mp[b]*n;
            setedge(node,ts);
            graph[source].pb(node);
            cost[source][node]=1;
            node++;
        }
        int bpm=kuhn.match(888);
        printcas;
        cout<<(bpm==m?" YES":" NO")<<endl;
 
    }
}