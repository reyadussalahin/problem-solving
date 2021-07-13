## Solutions
```c++
// problem name: Trees on My Island
// problem link: http://lightoj.com/volume_showproblem.php?problem=1418
// contest link: (?)
// time: (?)
// author: sumnoon


// other_tags: (?)
// difficulty_level: expert


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point { long long x, y;   // only used if more precision is needed
  	point() { x = y = 0.0; }                      // default constructor
    point(long long _x, long long _y) : x(_x), y(_y) {}        // user-defined
};
long long area(const vector<point> &P) {
long long result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}
int main(){
    int tc,i,n,j;
    long long x,y,inside;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++){
        scanf("%d",&n);
        vector<point>p;
        long long tempx=0,tempy=0,on=0;
        double a;
        for(j=0;j<n;j++){
            scanf("%lld%lld",&x,&y);
            p.push_back(point(x,y));
            tempx=x,tempy=y;
        }
        p.push_back(p[0]);
        for(j=0;j<(int)p.size()-1;j++)on+=__gcd(llabs(p[j].x-p[j+1].x),llabs(p[j].y-p[j+1].y));
        on/=2;
        a=area(p);
        inside=llabs(a)-on+1;
        printf("Case %lld: %lld\n",i,inside);
    }
    return 0;
}


```
