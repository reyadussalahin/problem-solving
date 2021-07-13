## Solutions
```c++
// problem name: Helping Cicada
// problem link: http://lightoj.com/volume_showproblem.php?problem=1117
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: inclusion exclusion, gcd, lcm, divisibility
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

#define N 128

long long d[N];

long long gcd(long long a, long long b) {
    while(b != 0) {
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        long long n;
        scanf("%lld", &n);
        int m;
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%lld", &d[i]);
        }
        long long tot = 0;
        for(int i=0; i<(1<<m); i++) {
            long long div = 1;
            int cnt = 0;
            for(int j=0; j<m; j++) {
                if(i&(1<<j)) {
                    div = lcm(div, d[j]);
                    cnt++;
                }
            }
            if(cnt) {
                if(cnt&1) {
                    tot = tot + (n / div);
                } else {
                    tot = tot - (n / div);
                }
            }
        }
        printf("Case %d: %lld\n", cc+1, n - tot);
    }
    return 0;
}

```
