## Solutions
#### 1
##### Source Code
```c++
// problem name: Pimp My Ride 
// problem link: http://lightoj.com/volume_showproblem.php?problem=1119
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;


#define N 16

const long long INF = 12345678911LL;

long long dist[N][N];
long long dp[N][(1<<N)];

long long run(int u, int mask, int n) {
    if(dp[u][mask] != -1) {
        return dp[u][mask];
    }
    dp[u][mask] = INF;
    long long tcost = 0;
    for(int v=0; v<n; v++) {
        if(!(mask & (1<<v))) {
            dp[u][mask] = min(dp[u][mask], run(v, mask | (1<<v), n));
        } else {
            tcost = tcost + dist[u][v];
        }
    }
    if(dp[u][mask] == INF) {
        dp[u][mask] = 0;
    }
    dp[u][mask] = dp[u][mask] + tcost;
    return dp[u][mask];
}


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%lld", &dist[i][j]);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<(1<<n); j++) {
                dp[i][j] = -1;
            }
        }
        long long cost = INF;
        for(int i=0; i<n; i++) {
            long long t = run(i, 0, n);
            cost = min(cost, t);
        }
        printf("Case %d: %lld\n", cc+1, cost);
    }
    return 0;
}

```
