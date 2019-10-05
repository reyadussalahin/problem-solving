#includebitsstdc++.h
using namespace std;
 
#define limit 2000
#define pb push_back
#define pii pairint,int
vectorintgraph[limit];
int cost[limit][limit];
mapint,intpar;
 
bool bfs(int s,int d)
{
    bool visited[limit]={0};
    queueintq;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;igraph[u].size();i++)
        {
            int v=graph[u][i];
            if(v==d)
            {
                par[v]=u;
                return true;
            }
            if(visited[v]==false && cost[u][v]0)
            {
                visited[v]=true;
                q.push(v);
                par[v]=u;
                if(v==d)
                    return v;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    scanf(%d,&t);
    for(int cas=1;cas=t;cas++)
    {
        int n,m,s,d;
        scanf(%d,&n);
        memset(cost,0,sizeof(cost));
        for(int i=0;ilimit;i++)
            graph[i].clear();
        for(int i=1;i=n;i++)
        {
            int x;
            scanf(%d,&x);
            graph[i].pb(100+i);
            cost[i][100+i]+=x;
        }
        scanf(%d,&m);
 
        for(int i=0;im;i++)
        {
            int u,v,c;
            scanf(%d %d %d,&u,&v,&c);
            graph[u+100].pb(v);
            graph[v].pb(u+100);
            cost[u+100][v]+=c;
        }
        s=0,d=250;
        scanf(%d %d,&n,&m);
        for(int i=0;in;i++)
        {
            int x;
            scanf(%d,&x);
            graph[s].pb(x);
            cost[s][x]=INT_MAX;
        }
        for(int i=0;im;i++)
        {
            int x;
            scanf(%d,&x);
            graph[x+100].pb(d);
            cost[x+100][d]=INT_MAX;
        }
        int max_flow=0;
        par.clear();
        while(bfs(s,d))
        {
            int mi=INT_MAX;
            int v=d;
            vectorintpath;
            path.pb(d);
            while(v!=s)
            {
                int u=par[v];
                mi=min(cost[u][v],mi);
                v=u;
                path.pb(v);
            }
            v=d;
            max_flow+=mi;
            while(v!=s)
            {
                int u=par[v];
                cost[u][v]-=mi;
                cost[v][u]+=mi;
                v=u;
            }
            par.clear();
        }
        printf(Case %d %dn,cas,max_flow);
    }
}