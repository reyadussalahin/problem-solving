// problem name: Convex Fence
// problem link: http://lightoj.com/volume_showproblem.php?problem=1239
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
 
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
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
    return cross(v1, v2) > 0;
}
 
void solve(int testCase, Point p[], int n, int d) {
    static Point buf[2*N];
    qsort(p, n, sizeof(Point), compare_point);
    int i, top = 0, t;
    for(i=0; i<n; i++) {
        while(top > 1 && !ccw(buf[top-2], buf[top-1], p[i])) top--;
        buf[top++] = p[i];
    }
    for(i=n-2, t = top; i>=0; i--) {
        while(top > t && !ccw(buf[top-2], buf[top-1], p[i])) top--;
        buf[top++] = p[i];
    }
    top--;
    double len = 0;
    for(i=0; i<top; i++) len = len + dist(buf[i], buf[(i+1)%top]);
    len = len + 2 * acos(-1) * d;
    printf("Case %d: %.9f\n", testCase, len);
}
 
int main() {
    int i, cc, tc, n, d;
    Point p[N];
    scanf("%d", &tc);
    for(cc=0; cc<tc; cc++) {
        scanf("%d %d", &n, &d);
        for(i=0; i<n; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
        solve(cc+1, p, n, d);
    }
   
    return 0;
}
