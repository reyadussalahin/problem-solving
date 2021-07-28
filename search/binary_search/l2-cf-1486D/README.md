## Solutions
#### 1
##### Source Code
```c++
// problem name: Max Median
// problem link: https://codeforces.com/contest/1486/problem/D
// contest link: https://codeforces.com/contest/1486
// time: (?)
// author: reyad


// other_tags: data structure, dynamic programming
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

#define N 200020

int a[N], t[N], mn[N];


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    mn[0] = t[0] = 0;
    int s = 0, e = n, p = -1;
    while(s <= e) {
        int m = (s + e) / 2;
        for(int i=1; i<=n; i++) {
            if(a[i] >= m) {
                t[i] = t[i-1] + 1;
            } else {
                t[i] = t[i-1] - 1;
            }
            mn[i] = min(mn[i-1], t[i]);
        }
        bool flag = false;
        for(int i=k; i<=n; i++) {
            if(t[i] - mn[i-k] > 0) {
                flag = true;
                break;
            }
        }
        if(flag) {
            p = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    assert(p != -1);
    printf("%d\n", p);
    return 0;
}
```
