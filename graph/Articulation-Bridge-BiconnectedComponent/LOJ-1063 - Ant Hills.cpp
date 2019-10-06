#include<bits/stdc++.h>
using namespace std;
 
 
#define pb push_back
map<int,bool>visited,in_ap;
map<int,int>start,low,par;
int t,ap;
 
vector<int>temp;
void find_ap(vector<int>graph[],int u)
{
    visited[u]=true;
    int x;
    x=start[u]=low[u]=t++;
    int cc=0,mi=INT_MAX;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(par[u]==v)continue;
        if(visited[v])
            x=mi=min(mi,low[v]);
        else
        {
            par[v]=u;
            find_ap(graph,v);
            x=mi=min(mi,low[v]);
            if(start[u]<=low[v] && in_ap[u]==false && par[u]!=0)
                in_ap[u]=true,ap++;
            cc++;
        }
        if(par[u]==0 && cc>1 && in_ap[u]==false)
            in_ap[u]=true,ap++;
    }
    low[u]=mi;
}
#define pb push_back
int main()
{
    int te;
    scanf("%d",&te);
    for(int cas=1;cas<=te;cas++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int>graph[n+1];
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        start.clear(),low.clear(),par.clear(),visited.clear(),in_ap.clear();
        ap=t=0;
        find_ap(graph,1);
 
        printf("Case %d: %d\n",cas,ap);
    }
}