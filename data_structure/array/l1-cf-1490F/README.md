## Solutions
#### 1
##### Source Code
```c++
// problem name: Equalize the Array
// problem link: https://codeforces.com/contest/1490/problem/F
// contest link: https://codeforces.com/contest/1490
// author: reyad
// time: (?)


// other_tags: sortings, math, binary search, greedy
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


#define N 200020

int a[N], c[N], b[N], s[N];


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            c[i] = 0;
        }
        sort(a, a+n);
        int v = a[0];
        int cnt = 1;
        for(int i=1; i<n; i++) {
            if(a[i] == v) {
                cnt++;
            } else {
                c[i-1] = cnt;
                v = a[i];
                cnt = 1;
            }
        }
        c[n-1] = cnt;
        int bc = 0;
        for(int i=0; i<n; i++) {
            if(c[i] > 0) {
                b[bc++] = c[i];
            }
        }
        sort(b, b+bc);
        s[0] = b[0];
        for(int i=1; i<bc; i++) {
            s[i] = s[i-1] + b[i];
        }
        int mn = N;
        for(int i=bc-1; i>=0; i--) {
            int cost = s[bc-1] - (b[i] * (bc - i));
            mn = min(cost, mn);
        }
        printf("%d\n", mn);
    }
    return 0;
}

```
