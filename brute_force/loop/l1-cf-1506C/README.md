## Solutions
```c++
// problem name: Double-ended Strings
// problem link: https://codeforces.com/contest/1506/problem/C
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: dynamic programming, hashing, string
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

char a[32], b[32];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        scanf("%s %s", a, b);
        int an = strlen(a);
        int bn = strlen(b);
        int ans = an + bn;
        for(int i=0; i<an; i++) {
            for(int j=i; j<an; j++) {
                int w = j-i+1;
                for(int k=0; k<bn; k++) {
                    bool matched = true;
                    for(int h=0; h<w; h++) {
                        if(b[k+h] != a[i+h]) {
                            matched = false;
                            break;
                        }
                    }
                    if(matched) {
                        ans = min(ans, an+bn-(w+w));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

```
