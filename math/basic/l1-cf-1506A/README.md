## Solutions
```c++
// problem name: Strange Table
// problem link: https://codeforces.com/contest/1506/problem/A
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, m;
        long long x;
        scanf("%d %d %lld", &n, &m, &x);
        long long c = (x + n - 1) / n;
        long long r = x % n;
        if(r == 0) {
            r = n;
        }
        printf("%lld\n", m * (r-1) + c);
    }
    return 0;
}

```
