## Solutions
#### 1
##### Source Code
```c++
// problem name: Flip the Bits
// problem link: https://codeforces.com/contest/1504/problem/B
// contest link: https://codeforces.com/contest/1504
// time: (?)
// author: reyad


// other_tags: greedy, implementation, math
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;


char s[300030];
char b[300030];
int c[300030];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        scanf("%s", b);
        for(int i=0; i<n; i++) {
            s[i] = s[i] - '0';
            b[i] = b[i] - '0';
            if(s[i] == 0) {
                c[i] = ((i > 0) ? c[i-1] : 0) + 1;
            } else {
                c[i] = ((i > 0) ? c[i-1] : 0);
            }
        }
        int shift = 0;
        int flag = 1;
        for(int i=n-1; i>=0; i--) {
            if((s[i] ^ shift) == b[i]) {
                continue;
            }
            if((c[i] * 2) != (i + 1)) {
                flag = 0;
                break;
            }
            shift ^= 1;
        }
        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

```
