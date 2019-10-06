    #include<bits/stdc++.h>
    using namespace std;
    #define MAX 110
    typedef pair<int,int> ii;
    typedef pair<int,ii> iii;
    vector<iii>edge;
    int pr[MAX],a[MAX],n,m;
    bool comp(iii a,iii b){
        return (a.first<b.first);
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
    ii node[20];
    int kruskal(){
        int i;
        sort(edge.begin(),edge.end(),comp);
        for(i=1;i<=n;i++)a[i]=i;
        int cnt=0,s=0,sz=edge.size();
        for(i=0;i<sz;i++){
            iii frnt=edge[i];
            if(!isSameset(frnt.second.first,frnt.second.second)){
                cnt+=frnt.first;
                unionSet(frnt.second.first,frnt.second.second);
            }
        }
        return cnt;
    }
    map<string,int>si;
    int main(){
        int tc,cases=0,chk,ans,i;
        bool flag;
        scanf("%d",&tc);
        while(tc--){
            chk=0;
            flag=true;
            string st,en;
            si.clear();
            scanf("%d",&m);
            for(i=0;i<m;i++){
                int w,u,v;
                cin>>st>>en>>w;
                if(!si[st])si[st]=++chk;
                if(!si[en])si[en]=++chk;
                u=si[st],v=si[en];
                edge.push_back(make_pair(w,ii(u,v)));
            }
            n=chk;
            ans=kruskal();
            chk=1;
            for(i=2;i<=n;i++){
                if(!isSameset(chk,i)){
                    flag=false;
                    break;
                }
            }
            if(!flag)printf("Case %d: Impossible\n",++cases);
            else printf("Case %d: %d\n",++cases,ans);
            edge.clear();
        }
        return 0;
    }
     

