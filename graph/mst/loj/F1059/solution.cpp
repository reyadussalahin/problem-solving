#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii>edge;
vector<int>cost;
int pr[MAX],a[MAX],n,m,numSet;
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
        numSet--;
    }
}
int numDisjointSet(){
    return numSet;
}
int kruskal(){
    int i;
    sort(edge.begin(),edge.end(),comp);
    for(i=1;i<=n;i++)a[i]=i;
    int cnt=0,s=0,sz=edge.size();
    for(i=0;i<sz;i++){
        iii frnt=edge[i];
        if(!isSameset(frnt.first.first,frnt.first.second)){
            cnt+=frnt.second;
            cost.push_back(frnt.second);
            unionSet(frnt.first.first,frnt.first.second);
        }
    }
    return cnt;
}
int main(){
    //freopen("in.txt","r",stdin);
    int tc,cases=0,i,p,u,v,w,ans,cou,tmp;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&m,&p);
        numSet=n;
        cou=0,ans=0;
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            edge.push_back(iii(ii(u,v),w));
        }
        tmp=kruskal();
        cou=numDisjointSet();
        //cout<<tmp<<endl;
        ans=tmp;
        for(i=0;i<cost.size();i++){
            if(cost[i]>=p){
                ans-=cost[i];
                cou++;
            }
        }
        ans+=(p*cou);
        printf("Case %d: %d %d\n",++cases,ans,cou);
        cost.clear();
        edge.clear();
    }
    return 0;
}