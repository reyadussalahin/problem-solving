    #include<bits/stdc++.h>
    using namespace std;
    typedef pair<int, int> pii;
    typedef vector<pii> vii;
    #define inf 100000000
    #define mx 16010
    int d[mx] ,parent[mx], n , m  ;
    vector < pii > adjlist[mx];
    void dijkstra( int start ){
        int u , v , w , i , c ;
        priority_queue < pii , vector < pii > , greater < pii > > q;
        d[start] = 0 ;
        q.push( pii( 0 , start ) );
        while( !q.empty() ){
            u = q.top().second;
            c  = q.top().first;
            q.pop();
            for(i = 0 ; i < adjlist[u].size() ; i++ ){
                v = adjlist[u][i].first;
                w = adjlist[u][i].second;
                if( max(d[u],w) < d[v] ){
                    d[v] = max(d[u],w);
                    q.push(pii(d[v],v));
                }
            }
        }
    }
    int main(){
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        int tc,cases=0,i,j,k,n,m,u,v,w,t;
        scanf("%d",&tc);
        while(tc--){
            scanf("%d %d",&n,&m);
            for(i=0;i<=n;i++)d[i]=inf;
            for(i=0;i<m;i++){
                scanf("%d %d %d",&u,&v,&w);
                adjlist[u].push_back(pii(v,w));
                adjlist[v].push_back(pii(u,w));
            }
            scanf("%d",&t);
            dijkstra(t);
            printf("Case %d:\n",++cases);
            for(i=0;i<n;i++){
                if(d[i]==inf)printf("Impossible\n");
                else printf("%d\n",d[i]);
            }
            for(i=0;i<=n;i++)adjlist[i].clear();
        }
        return 0;
    }
     

