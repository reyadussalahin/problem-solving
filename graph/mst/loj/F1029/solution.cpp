#include<bits/stdc++.h>
using namespace std;
#define MAX 110
typedef pair<int,int> ii;
typedef pair<ii,ii> iii;
vector<iii>edge;
int pr[MAX],a[MAX];
bool comp(iii a,iii b){
    return (a.first.second<b.first.second);
}
bool comp1(iii a,iii b){
    return (a.first.second>b.first.second);
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
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    int tc,cases=0,n,m,i,w,u,v,ans;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        while(scanf("%d %d %d",&u,&v,&w)==3&&w+u+v!=0)edge.push_back(make_pair(ii(i,w),ii(u,v)));
        sort(edge.begin(),edge.end(),comp);
        for(i=0;i<=n;i++)a[i]=i,pr[i]=0;
        int cnt=0,sz=(int)edge.size();
        for(i=0;i<sz;i++){
            iii frnt=edge[i];
            if(!isSameset(frnt.second.first,frnt.second.second)){
                //cout<<frnt.first.second<<" "<<frnt.second.first<<" "<<frnt.second.second<<endl;
                cnt+=frnt.first.second;
                unionSet(frnt.second.first,frnt.second.second);
            }
        }
        ans=cnt;
        cnt=0;
        sort(edge.begin(),edge.end(),comp1);
        for(i=0;i<=n;i++)a[i]=i;
        for(i=0;i<sz;i++){
            iii frnt=edge[i];
            if(!isSameset(frnt.second.first,frnt.second.second)){
                //cout<<frnt.first.second<<" "<<frnt.second.first<<" "<<frnt.second.second<<endl;
                cnt+=frnt.first.second;
                unionSet(frnt.second.first,frnt.second.second);
            }
        }
        ans+=cnt;
        printf("Case %d: ",++cases);
        if(ans&1)printf("%d/2\n",ans);
        else printf("%d\n",ans>>1);
        edge.clear();
    }
    return 0;
}