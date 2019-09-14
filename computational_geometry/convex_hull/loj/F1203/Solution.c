// problem name: Guarding Bananas
// problem link: http://lightoj.com/volume_showproblem.php?problem=1203
// contest link: (?)
// time: (?)
// author: reyad

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define N 100000
 
typedef long long int lint;
 
typedef struct {
    lint x, y;
} Point;
 
Point get_point(lint x, lint y) {
    Point p = {x, y};
    return p;
}
 
int compare_point(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    if(p1->x == p2->x) {
        if(p1->y < p2->y) return -1;
        if(p1->y > p2->y) return 1;
        return 0;
    }
    if(p1->x < p2->x) return -1;
    return 1;
}
 
typedef struct {
    lint x, y;
} Vec;
 
Vec get_vec(Point p1, Point p2) {
    Vec v = {p1.x - p2.x, p1.y - p2.y};
    return v;
}
 
lint cross(Vec v1, Vec v2) {
    return v1.x * v2.y - v2.x * v1.y;
}
 
lint dot(Vec v1, Vec v2) {
    return v1.x * v2.x + v1.y * v2.y;
}
 
double length(Vec v) {
    return sqrt(v.x * v.x + v.y * v.y);
}
 
int ccw(Point p0, Point p1, Point p2) {
    Vec v1 = get_vec(p1, p0), v2 = get_vec(p2, p0);
    if(cross(v1, v2) > 0) return 1;
    return 0;
}
 
void solve(int testCase, Point p[], int n) {
    static Point buf[2*N];
    qsort(p, n, sizeof(Point), compare_point);
    int i, top = 0, t;
    for(i=0; i<n; i++) {
        while(top > 1 && ccw(buf[top-2], buf[top-1], p[i]) == 0) top--;
        buf[top++] = p[i];
    }
    for(i=n-2, t = top; i>=0; i--) {
        while(top > t && ccw(buf[top-2], buf[top-1], p[i]) == 0) top--;
        buf[top++] = p[i];
    }
    top--;
    if(top < 3) {
        printf("Case %d: 0\n", testCase);
        return;
    }
    const double PI = acos(-1);
    double ans = 360.0;
    for(i=0; i<top; i++) {
        Vec v1 = get_vec(buf[(top+i-1)%top], buf[i]);
        Vec v2 = get_vec(buf[(i+1)%top], buf[i]);
        double ang = acos(dot(v1, v2) / (length(v1) * length(v2))) * 180 / PI;
        if(ang < ans) ans = ang;
    }
    printf("Case %d: %.9f\n", testCase, ans);
}
 
int main() {
    int i, cc, tc, n;
    Point p[N];
    scanf("%d", &tc);
    for(cc=0; cc<tc; cc++) {
        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
        solve(cc+1, p, n);
    }
   
    return 0;
}
