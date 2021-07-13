## Solutions
```c++
// problem name: Balance the Bits
// problem link: https://codeforces.com/contest/1504/problem/C
// contest link: https://codeforces.com/contest/1504
// time: (?)
// author: reyad


// other_tags: greedy
// difficulty_level: beginner


// solution idea:
// when, 1: either both are open or both are close(so, when 1 both string are the same)
//       0: one is open and another is close
// so, n(0) must be even and the string cannot start or end with 0

#include <bits/stdc++.h>

using namespace std;

char s[200020];
char a[200020];
char b[200020];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int z = 0;
        for(int i=0; s[i]; i++) {
            if(s[i] == '0') {
                z++;
            }
        }
        if(s[0] == '0' || s[n-1] == '0' || (z&1)) {
            printf("NO\n");
            continue;
        }
        int o = n - z;
        int co = 0, cz = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                if((co << 1) < o) {
                    a[i] = b[i] = '(';
                } else {
                    a[i] = b[i] = ')';
                }
                co++;
            } else {
                if(cz&1) {
                    a[i] = '(';
                    b[i] = ')';
                } else {
                    a[i] = ')';
                    b[i] = '(';
                }
                cz++;
            }
        }
        a[n] = b[n] = 0;
        printf("YES\n");
        printf("%s\n", a);
        printf("%s\n", b);
    }
    return 0;
}

```
