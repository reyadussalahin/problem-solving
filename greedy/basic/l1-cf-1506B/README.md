## Solutions
```c++
// problem name: Partial Replacement
// problem link: https://codeforces.com/contest/1506/problem/B
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: implementation
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

char s[64];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, k;
        scanf("%d %d %s", &n, &k, s);
        int f = -1, l = -1;
        for(int i=0; i<n; i++) {
            if(s[i] == '*' && f == -1) {
                f = i;
            }
            if(s[n-i-1] == '*' && l == -1) {
                l = n-i-1;
            }
        }
        int cnt = 1;
        if(f != l) {
            cnt++;
        }
        int i = f;
        while(i < l) {
            bool stop = false;
            for(int j=k; j>0; j--) {
                if(i+j < l) {
                    if(s[i+j] == '*') {
                        cnt++;
                        i = i+j;
                        break;
                    }
                } else {
                    stop = true;
                    break;
                }
            }
            if(stop) {
                break;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
```
