## Solutions
```c++
// problem name: Accidental Victory
// problem link: https://codeforces.com/contest/1490/problem/E
// contest link: https://codeforces.com/contest/1490
// author: reyad
// time: (?)


// other_tags: greedy, implementation
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

#define N 200020

int a[N], x[N], b[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

bool does_satisfy(int s, int n) {
    long long int sum = 0;
    for(int i=0; i<=s; i++) {
        sum = sum + a[x[i]];
    }
    for(int i=s+1; i<n; i++) {
        if(sum < a[x[i]]) {
            return false;
        }
        sum = sum + a[x[i]];
    }
    return true;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            x[i] = i;
        }
        sort(x, x+n, cmp);
        int s = 0, e = n-1, p = -1;
        while(s <= e) {
            int m = (s + e) / 2;
            if(does_satisfy(m, n)) {
                p = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        assert(p != -1);
        int bc = 0;
        for(int i=p; i<n; i++) {
            b[bc++] = x[i];
        }
        sort(b, b+bc);
        printf("%d\n", bc);
        for(int i=0; i<bc; i++) {
            printf("%d ", b[i] + 1); // cause, 1 based indexing of codeforces
        }
        printf("\n");
    }
    return 0;
}

```
