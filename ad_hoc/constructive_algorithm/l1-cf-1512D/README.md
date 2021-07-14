## Solutions
#### 1
##### Source Code
```c++
// problem name: Corrupted Array
// problem link: https://codeforces.com/contest/1512/problem/D
// contest link: https://codeforces.com/contest/1512
// time: (?)
// author: reyad


// other_tags: data structure, greedy
// difficulty_level: beginner


#include <bits/stdc++.h>
using namespace std;

#define N 200020


int lx[N], rx[N];
int b[N];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int n;
        cin >> n;
        int m = n + 2;
        for(int i=0; i<m; i++) {
            cin >> b[i];
        }
        lx[0] = 0; rx[m-1] = m-1;
        long long sum = b[0];
        for(int i=1; i<m; i++) {
            lx[i] = lx[i-1];
            if(b[i] > b[lx[i]]) {
                lx[i] = i;
            }
            int j = m-i-1;
            rx[j] = rx[j+1];
            if(b[j] > b[rx[j]]) {
                rx[j] = j;
            }
            sum = sum + b[i];
        }
        int hasAns = 0;
        int n1 = -1, n2 = -1;
        for(int i=0; i<m; i++) {
            int mxi = ((i > 0) ? lx[i-1] : -1);
            if((mxi == -1) || ((i < m-1) && (b[rx[i+1]] > b[mxi]))) {
                mxi = rx[i+1];
            }
            assert(mxi != -1);
            if((long long)b[mxi] + b[mxi] == (sum - b[i])) {
                hasAns = 1;
                n1 = i; n2 = mxi;
                break;
            }
        }
        if(hasAns) {
            for(int i=0; i<m; i++) {
                if(i != n1 && i != n2) {
                    printf("%d ", b[i]);
                }
            }
        } else {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}

```
