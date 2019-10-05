#include<bits/stdc++.h>
using namespace std;
 
#define limit 2000
#define pb push_back
#define pii pair<int,int>
vector<pii>graph[limit];
int cost[limit][limit];
map<int,int>par;
 
bool bfs(int s,int d)
{
    bool visited[limit]={0};
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].first;
            if(visited[v]==false && cost[u][v]>0)
            {
                visited[v]=true;
                q.push(v);
                par[v]=u;
                if(v==d)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,m,s,d;
        scanf("%d",&n);
        scanf("%d %d %d",&s,&d,&m);
        memset(cost,0,sizeof(cost));
        for(int i=0;i<=n;i++)
            graph[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            graph[u].pb(pii(v,c));
            graph[v].pb(pii(u,c));
            cost[u][v]+=c;
            cost[v][u]+=c;
        }
        int max_flow=0;
        par.clear();
        while(bfs(s,d))
        {
            int min=100000;
            int v=d;
            vector<int>path;
            path.pb(d);
            while(v!=s)
            {
                int u=par[v];
                if(cost[u][v]<min)
                    min=cost[u][v];
                v=u;
                path.pb(v);
            }
            v=d;
            max_flow+=min;
            while(v!=s)
            {
                int u=par[v];
                cost[u][v]-=min;
                cost[v][u]+=min;
                v=u;
            }
            par.clear();
        }
        printf("Case %d: %d\n",cas,max_flow);
    }
}