#include<bits/stdc++.h>
using namespace std;
#define MAX 6010
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii>edge,tree;
int pr[MAX],a[MAX],n,m,numset;
bool comp(iii a,iii b){
    return (a.second<b.second);
}
int findSet(int r){
    return (a[r]==r)?r:findSet(a[r]);
}
bool isSameset(int i,int j){
    return findSet(i)==findSet(j);
}
void unionSet(int i,int j){
    if(!isSameset(i,j)){
        int x=findSet(i);
        int y=findSet(j);
        if(pr[x]>pr[y]){
            a[y]=x;
        }
        else{
            a[x]=y;
            if(pr[x]==pr[y])pr[y]++;
        }
        numset--;
    }
}
int kruskal(){
    int i;
    sort(edge.begin(),edge.end(),comp);
    for(i=1;i<=n;i++)a[i]=i;
    memset(pr,0,sizeof pr);
    int cnt=0,s=0,sz=edge.size();
    for(i=0;i<sz;i++){
        iii frnt=edge[i];
        if(!isSameset(frnt.first.first,frnt.first.second)){
            cnt+=frnt.second;
            unionSet(frnt.first.first,frnt.first.second);
            tree.push_back(iii(ii(frnt.first.first,frnt.first.second),frnt.second));
        }
    }
    return cnt;
}
int visited[MAX];
vector<int>adjlist[MAX];
map<int,bool>ib;
void dfs(int s){
    visited[s]=1;
    for(int i=0;i<adjlist[s].size();i++){
        int v=adjlist[s][i];
        if(!visited[v])dfs(v);
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,cases=0,u,v,w,i,j,cou,ans;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&n,&m);
        cou=0;
        for(i=1;i<=n;i++)a[i]=i;
        memset(pr,0,sizeof pr);
        printf("Case %d:\n",++cases);
        bool flag=false;
        for(i=0;i<m;i++){
            cou=0;
            scanf("%d %d %d",&u,&v,&w);
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
            edge.push_back(iii(ii(u,v),w));
            for(j=1;j<=n;j++)visited[j]=0;
            for(j=1;j<=n;j++){
                if(!visited[j]){
                    cou++;
                    dfs(j);
                }
            }
            if(cou!=1)printf("-1\n");
            else{
                ans=kruskal();
                edge.clear();
                for(j=0;j<tree.size();j++)edge.push_back(tree[j]);
                //cout<<edge.size()<<endl;
                tree.clear();
                printf("%d\n",ans);
            }
        }
        edge.clear();
        tree.clear();
        for(j=1;j<=n;j++)adjlist[j].clear();
    }
    return 0;
}