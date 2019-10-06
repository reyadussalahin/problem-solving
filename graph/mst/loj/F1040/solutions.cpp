#include<bits/stdc++.h>
using namespace std;
#define MAX 110
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii>edge;
int pr[MAX],a[MAX],n,m,cost[MAX][MAX],numSet;
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
            unionSet(frnt.first.first,frnt.first.second);
        }
    }
    return cnt;
}
int main(){
    //freopen("in.txt","r",stdin);
    int tc,cases=0,i,j,w,ans,sum,tmp;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        numSet=n;
        m=n;
        sum=0,ans=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&w);
                sum+=w;
                if(i==j||w==0)continue;
                edge.push_back(iii(ii(i,j),w));
            }
        }
        tmp=kruskal();
        //cout<<tmp<<endl;
        if(numSet!=1)ans=-1;
        else ans=sum-tmp;
        printf("Case %d: %d\n",++cases,ans);
        edge.clear();
    }
    return 0;
}