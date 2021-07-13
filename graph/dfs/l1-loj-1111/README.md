## Solutions
```c++
// problem name: Best Picnic Ever
// problem link: http://lightoj.com/volume_showproblem.php?problem=1111
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: bfs, brute force
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


#define K 104
#define N 1004
#define M 10004

vector<int> g[N];
int seen[N];
int cnt[N];
int ks[K];


void dfs(int u) {
    seen[u] = true;
    cnt[u]++;
    for(int v: g[u]) {
        if(!seen[v]) {
            dfs(v);
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int k, n, m;
        scanf("%d %d %d", &k, &n, &m);
        for(int i=0; i<n; i++) {
            g[i].clear();
            cnt[i] = 0;
        }
        for(int i=0; i<k; i++) {
            scanf("%d", &ks[i]);
            --ks[i];
        }
        for(int i=0; i<m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u; --v;
            g[u].push_back(v);
        }
        for(int i=0; i<k; i++) {
            memset(seen, 0, sizeof(int) * n);
            dfs(ks[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(cnt[i] == k) {
                ans++;
            }
        }
        printf("Case %d: %d\n", cc+1, ans);
    }
    return 0;
}
```
