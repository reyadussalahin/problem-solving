// problem name: Bananas in a Microwave
// problem link: https://codeforces.com/contest/1498/problem/D
// contest link: https://codeforces.com/contest/1498
// time: (?)
// author: reyad


// other_tags: graph, dfs and similiar, implementation
// difficulty_level: intermediate


// solution idea:
// let,
// function calc(t, k, x):
//     return ceil(k + x) if t == 1 else return ceil(k * x)

// if d(i, k) is possible, then the followings are possible,
// let, kx = calc(t[i], k, x[i])
// - d(i, kx) if d(i, k)'s step is < y[i]
// - d(i+1, k)

#include <bits/stdc++.h>

using namespace std;

#define inf 1000000009
#define M 100010

long long x[M];
int t[M], y[M];
int dp[M], ans[M];

long long calc(int t, long long k, long long x) {
    if(t == 1) {
        return (k * 100000 + x + 99999) / 100000;
    }
    return (k * x + 99999) / 100000;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d %lld %d", &t[i], &x[i], &y[i]);
    }
    for(int i=0; i<=m; i++) {
        dp[i] = inf;
        ans[i] = -1;
    }
    dp[0] = ans[0] = 0;
    for(int i=0; i<=n; i++) {
        for(int k=0; k<=m; k++) {
            dp[k] = (ans[k] != -1) ? 0 : inf;
        }
        for(int k=0; k<=m; k++) {
            long long kx = calc(t[i], k, x[i]);
            if(kx <= m) {
                dp[kx] = min(dp[k]+1, dp[kx]);
            }
        }
        for(int k=0; k<=m; k++) {
            if(dp[k] <= y[i]) {
                if(ans[k] == -1) {
                    ans[k] = i;
                }
                // printf("%d ", k);
            }
        }
        // printf("\n");
    }
    for(int k=1; k<=m; k++) {
        printf("%d ", ans[k]);
    }
    printf("\n");
    return 0;
}
