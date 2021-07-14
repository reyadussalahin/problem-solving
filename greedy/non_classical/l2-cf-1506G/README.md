## Solutions
#### 1
##### Source Code
```c++
// problem name: Maximize the Remaining String
// problem link: https://codeforces.com/contest/1506/problem/G
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: brute force, data structures, dynamic programming, strings
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

char s[200020];
int stck[200020];


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        scanf("%s", s);
        int c[26] = {0};
        int unq = 0;
        for(int i=0; s[i]; i++) {
            int ch = s[i] - 'a';
            if(c[ch] == 0) {
                unq++;
            }
            c[ch]++;
        }
        char ans[32] = {0};
        int ansLen = 0;
        int start = 0;
        // printf("cc: %d\n", cc+1);
        while(unq > 0) {
            int mx = -1;
            int top = 0;
            for(int i=start; s[i]; i++) {
                int ch = s[i] - 'a';
                if(c[ch] == 0) {
                    continue;
                }
                if(ch > mx) {
                    mx = ch;
                    start = i + 1;
                }
                c[ch]--;
                stck[top++] = i;
                if(c[ch] == 0) {
                    break;
                }
            }
            // printf("%c ", (char)(mx + 'a'));
            assert(mx != -1);
            ans[ansLen++] = (char)(mx + 'a');
            // adjusting char counts and unq counts
            while(stck[--top] >= start) {
                c[s[stck[top]] - 'a']++;
            }
            c[mx] = 0;
            unq--;
        }
        printf("%s\n", ans);
    }
    return 0;
}

```
