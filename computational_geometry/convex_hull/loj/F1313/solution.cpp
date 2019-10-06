///*BISMILLAHIR RAHMANI RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
typedef int ll;
struct point{
    int x,y;
    point(){x=y=0;}
    point(ll _x,ll _y):x(_x),y(_y){}
};
inline int crossDet(point o, point a, point b) {
    return ( ( a.x - o.x ) * ( b.y - o.y ) - ( b.x - o.x ) * ( a.y - o.y ) );
}
bool comp(point a,point b){
        return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
ll cross(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
inline bool onSegment(const point &p,const point &q,const point &r){
    return (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) &&r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y));
}
inline int orientation(const point &p,const point &q,const point &r){
    return p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y);
}
inline bool doIntersect(const point &p1,const point &q1,const point &p2,const point &q2,bool &on){
    int o1=orientation(p2,q2,p1);
    int o2=orientation(p2,q2,q1);
    int o3=orientation(p1,q1,p2);
    int o4=orientation(p1,q1,q2);
    on=false;
    if(((o1<0&&o2>0)||(o1>0&&o2<0))&&((o3<0&&o4>0)||(o3>0&&o4<0)))return true;
    if(!o3&&onSegment(p1,q1,p2)){
        on=true;
        return true;
    }
    if(!o4&&onSegment(p1,q1,q2))return true;
    if(!o1&&onSegment(p2,q2,p1))return true;
    if(!o2&&onSegment(p2,q2,q1))return true;
    return false;
}
bool ptInPoly(point pt,vector<point> &poly){
    bool on;
    int sz=poly.size();
    if(sz<3)return false;
    poly.push_back(poly[0]);
    point extreme = point(pt.x+30000,pt.y+30001);
    int count=0,i;
    for(i=0;i<sz;i++){
        if(doIntersect(poly[i],poly[i+1],pt,extreme,on)){
            if(on){
                count=1;
                break;
            }
            count++;
        }
    }
    return count&1;
}
vector<point>CH(vector<point>p){
    int n=p.size(),k=0;
    vector<point>H(2*n);
    sort(p.begin(),p.end(),comp);
    for(int i=0;i<n;i++){
        while(k>=2&&cross(H[k-2],H[k-1],p[i])<=0)k--;
        H[k++]=p[i];
    }
    for(int i=n-2,t=k+1;i>=0;i--){
        while(k>=t&&cross(H[k-2],H[k-1],p[i])<=0)k--;
        H[k++]=p[i];
    }
    H.resize(k-1);
    return H;
}
int mat[110][110];
int solve(vector<point>&hole,vector<point>&mine){
    int i,j,k;
    int n=hole.size(),m=mine.size();
    for( i = 0; i < n; i++ ){
        for( j = 0; j < n; j++ )mat[i][j]=inf;
    }
    for( i = 0; i < n; i++ ){
        for( j = 0; j < n; j++ ){
            if(i!=j){
                bool found=false;
                for(k = 0; k < m; k++ ){
                    if(crossDet(hole[i],hole[j],mine[k])<0){
                        found=true;
                        break;
                    }
                }
                if(!found)mat[i][j]=1;
            }
        }
    }
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            for ( k = 0; k < n; k++ ) {
                mat[j][k] = min ( mat[j][k], mat[j][i] + mat[i][k] );
            }
        }
    }
    int mn=inf;
    for( i = 0; i < n; i++ )mn=min(mn,mat[i][i]);
    return mn;
}
int main(){
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int tc,cases=0,n,m,g,p,i,j,x,y,ans1,ans2,ans;
    scanf("%d",&tc);
    while(tc--){
        vector<point>mine,hole,hole1,inCH;
        scanf("%d %d %d %d",&n,&m,&g,&p);
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            hole1.push_back(point(x,y));
        }
        for(i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            mine.push_back(point(x,y));
        }
        hole=CH(hole1);
        //hole.push_back(hole[0]);
        //cout<<hole.size()<<endl;
        //cout<<hole[0].x<<" " << hole[0].y <<" "<<hole[hole.size() - 1].x <<" "<<hole[hole.size()-1].y<<endl;
        for(i=0;i<mine.size();i++){
            if(ptInPoly(mine[i],hole))inCH.push_back(mine[i]);
        }
        bool flag=false;
        int sz1=inCH.size();
        int sz2=sz1?solve(hole1,inCH):0;
        ans1=(m-sz1)*g;
        ans2=sz2*p;
        ans=ans1+ans2;
        //cout << ans1 << " " << ans2 << endl;
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}