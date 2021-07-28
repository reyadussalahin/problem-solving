## Solutions
#### 1
##### Source Code
```c++
// problem name: Déjà Vu
// problem link: https://codeforces.com/contest/1504/problem/A
// contest link: https://codeforces.com/contest/1504
// time: (?)
// author: reyad


// other_tags: string
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

char s[300030];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        scanf("%s", s);
        int l = strlen(s);
        int ac = 0;
        for(int i=0; i<l; i++) {
            if(s[i] == 'a') {
                ac++;
            }
        }
        if(ac == l) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=0; i<l; i++) {
            if(s[i] == s[l-i-1]) {
                if(s[i] != 'a') {
                    printf("%c", 'a');
                    printf("%s\n", s+i);
                    break;
                }
            } else {
                printf("%c", s[i]);
                s[i] = 'a';
                printf("%s\n", s+i);
                break;
            }
            printf("%c", s[i]);
        }
    }
    return 0;
}

```
