## Solutions
```c++
// problem name: Blood Cousins
// problem link: https://codeforces.com/contest/208/problem/E
// contest link: https://codeforces.com/contest/208
// time: (?)
// author: reyad


// other_tags: dfs and similar, trees, binary search, data structures
// difficulty_level: expert


#include <bits/stdc++.h>

using namespace std;


#define N 100010
#define K 19

vector<int> adj[N];
int p[N];
int lev[N];
int stp[N][K];
int stm[N], etm[N];
int dtm = 0;
vector<int> b[N];


void dfs(int u, int par, int lv) {
    stm[u] = dtm++;
    b[lv].push_back(stm[u]);
    lev[u] = lv;
    stp[u][0] = par;
    for(int i=1; i<K; i++) {
        if(stp[u][i-1] != -1) {
            stp[u][i] = stp[stp[u][i-1]][i-1];
        }
    }
    for(int v: adj[u]) {
        dfs(v, u, lv+1);
    }
    etm[u] = dtm++;
}

int getAncestor(int u, int x) {
    for(int i=K-1; i>=0; i--) {
        if((1 << i) <= x) {
            u = stp[u][i];
            if(u == -1) {
                return u;
            }
            x = x - (1 << i);
        }
    }
    return u;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
        if(p[i] != 0) {
            adj[p[i]].push_back(i);
        }
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<K; j++) {
            stp[i][j] = -1;
        }
    }
    for(int i=1; i<=n; i++) {
        if(p[i] == 0) {
            dfs(i, -1, 0);
        }
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int u, r;
        scanf("%d %d", &u, &r);
        int t = getAncestor(u, r);
        if(t == -1) {
            printf("0 ");
            continue;
        }
        int lv = lev[u];
        int s = 0, e = (int)b[lv].size() - 1, x = -1;
        while(s <= e) {
            int m = (s + e) / 2;
            if(b[lv][m] > stm[t]) {
                x = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        if(x == -1) {
            printf("0 ");
            continue;
        }
        s = 0; e = (int)b[lv].size() - 1; int y = -1;
        while(s <= e) {
            int m = (s + e) / 2;
            if(b[lv][m] < etm[t]) {
                y = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        if(y == -1) {
            printf("0 ");
            continue;
        }
        printf("%d ", max(0, y - x));
    }
    printf("\n");

    return 0;
}
```
