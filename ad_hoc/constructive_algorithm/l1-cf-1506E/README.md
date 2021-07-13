## Solutions
```c++
// problem name: Restoring the Permutation
// problem link: https://codeforces.com/contest/1506/problem/E
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: implementation
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;


int mn[200020];
int mx[200020];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        priority_queue<int> mnpq;
        priority_queue<int> mxpq;
        int prev = 0;
        for(int i=0; i<n; i++) {
            int q;
            scanf("%d", &q);
            if(q == prev) {
                mn[i] = -1 * mnpq.top();
                mnpq.pop();
                mx[i] = mxpq.top();
                mxpq.pop();
            } else {
                for(int j=prev+1; j<q; j++) {
                    mnpq.push(-1 * j);
                    mxpq.push(j);
                }
                mn[i] = mx[i] = q;
            }
            prev = q;
        }
        for(int i=0; i<n; i++) {
            printf("%d ", mn[i]);
        }
        printf("\n");
        for(int i=0; i<n; i++) {
            printf("%d ", mx[i]);
        }
        printf("\n");
    }
    return 0;
}

```
