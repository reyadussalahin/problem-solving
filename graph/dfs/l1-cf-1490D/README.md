## Solutions
```c++
// problem name: Permutation Transformation
// problem link: https://codeforces.com/contest/1490/problem/D
// contest link: https://codeforces.com/contest/1490
// author: reyad
// time: (?)


// other_tags: divide and conquer, implementation
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


#define N 128

int d[N], a[N];

void calc_depth(int dv, int l, int r) {
    int x = l;
    for(int i=l+1; i<=r; i++) {
        if(a[i] > a[x]) {
            x = i;
        }
    }
    d[x] = dv;
    if(l <= x-1) {
        calc_depth(dv+1, l, x-1);
    }
    if(x+1 <= r) {
        calc_depth(dv+1, x+1, r);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            d[i] = 0;
        }
        calc_depth(0, 0, n-1);
        for(int i=0; i<n; i++) {
            printf("%d ", d[i]);
        }
        printf("\n");
    }
    return 0;
}

```
