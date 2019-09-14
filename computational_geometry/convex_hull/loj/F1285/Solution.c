// problem name: Drawing Simple Polygon
// problem link: http://lightoj.com/volume_showproblem.php?problem=1285
// contest link: (?)
// time: (?)
// author: reyad

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
 
#define N 2000
 
typedef long long int lint;
 
typedef struct {
    lint x, y;
    int id;
} Point;
 
Point get_point(lint x, lint y, int id) {
    Point p = {x, y, id};
    return p;
}
 
int compare_point(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    lint t = p1->y * p2->x - p2->y * p1->x;
    if(t < 0) return -1;
    if(t > 0) return 1;
    t = (p1->x * p1->x + p1->y * p1->y) - (p2->x * p2->x + p2->y * p2->y);
    if(t < 0) return -1;
    if(t > 0) return 1;
    return 0;
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
 
void solve(int testCase, Point p[], int n) {
    int i, j, at = 0;
    for(i=1; i<n; i++) if((p[i].x < p[at].x) || (p[i].x == p[at].x && p[i].y < p[at].y)) at = i;
    if(at != 0) {
        Point t = p[at];
        p[at] = p[0];
        p[0] = t;
    }
    for(i=1; i<n; i++) {
        p[i].x = p[i].x - p[0].x;
        p[i].y = p[i].y - p[0].y;
    }
    qsort(p+1, n-1, sizeof(Point), compare_point);
//  for(i=0; i<n; i++) printf("..%d", p[i].id);
//  puts("");
    int t = 0;
    for(i = n-2; i > 0; i--) {
        if(p[n-1].x * p[i].y != p[i].x * p[n-1].y) {
            t = i;
            break;
        }
    }
//  printf("t: %d\n", t);
    if(t == 0) {
        printf("Case %d:\nImpossible\n", testCase);
        return;
    }
    printf("Case %d:\n", testCase);
    for(i=0; i<=t; i++) {
        if(i != 0) printf(" ");
        printf("%d", p[i].id);
    }
    for(i=n-1; i>t; i--) printf(" %d", p[i].id);
    printf("\n");
}
 
int main() {
    int i, n, cc, tc;
    Point p[N];
    scanf("%d", &tc);
    for(cc=0; cc<tc; cc++) {
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%lld %lld", &p[i].x, &p[i].y);
            p[i].id = i;
        }
        solve(cc+1, p, n);
    }
    return 0;
}