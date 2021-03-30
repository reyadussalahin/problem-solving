// problem name: Planar Reflections
// problem link: https://codeforces.com/contest/1498/problem/C
// contest link: https://codeforces.com/contest/1498
// time: (?)
// author: reyad


// other_tags: brute force, data structure
// difficulty_level: easy


// solution idea:
// d(k, n-x) = d(k, n-x-1) + d(k-1, x)
// let, n-x = m
// so, d(k, m) = d(k, m-1) + d(k-1, n-m)

// base cases:
// 1. d(1, m) = 1
// 2. d(x, 0) = 1


#include <bits/stdc++.h>

using namespace std;

#define M 1000000007


long long dp[1024][1024];

long long calc(int k, int m, int n) {
    if((k == 1) || (m == 0)) {
        return 1;
    }
    if(dp[k][m] != -1) {
        return dp[k][m];
    }
    dp[k][m] = (calc(k, m-1, n) + calc(k-1, n-m, n)) % M;
    // printf("k, m, dp: %d %d %lld\n", k, m, dp[k][m]);
    return dp[k][m];
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=0; i<=k; i++) {
            for(int j=0; j<=n; j++) {
                dp[i][j] = -1;
            }
        }
        long long ans = calc(k, n, n);
        printf("%lld\n", ans);
    }
    return 0;
}
