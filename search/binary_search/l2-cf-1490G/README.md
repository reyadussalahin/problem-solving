## Solutions
```c++
// problem name: Old Floppy Drive
// problem link: https://codeforces.com/contest/1490/problem/G
// contest link: https://codeforces.com/contest/1490
// author: reyad
// time: (?)


// other_tags: math, binary search, data structures, sortings
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

#define N 200020

int a[N], x[N], y[N];
long long int s[N];


bool cmp(int i, int j) {
    return s[i] < s[j];
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            x[i] = i;
        }
        s[0] = a[0];
        for(int i=1; i<n; i++) {
            s[i] = s[i-1] + a[i];
        }
        sort(x, x+n, cmp);
        y[n-1] = x[n-1];
        for(int i=n-2; i>=0; i--) {
            y[i] = min(y[i+1], x[i]);
        }
        for(int i=0; i<m; i++) {
            int sum;
            scanf("%d", &sum);
            if(s[n-1] <= 0 && s[x[n-1]] < sum) {
                printf("-1 ");
                continue;
            }
            long long int step = 0;
            if(s[n-1] > 0) {
                int start = 0;
                int end = (sum + s[n-1]) / s[n-1];
                int p = -1;
                while(start <= end) {
                    int mid = (start + end) / 2;
                    if(mid * s[n-1] + s[x[n-1]] >= sum) {
                        p = mid;
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
                assert(p != -1);
                sum = sum - (p * s[n-1]);
                step = step + (long long int)p * n;
            }
            int start = 0, end = n-1, p = -1;
            while(start <= end) {
                int mid = (start + end) / 2;
                if(sum <= s[x[mid]]) {
                    p = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            assert(p != -1);
            step += y[p];
            printf("%lld ", step);
        }
        printf("\n");
    }
    return 0;
}

```
