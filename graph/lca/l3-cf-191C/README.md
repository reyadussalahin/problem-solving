## Solutions
```c++
// problem name: Fools and Roads
// problem link: https://codeforces.com/contest/191/problem/C
// contest link: https://codeforces.com/contest/191
// time: (?)
// author: reyad


// other_tags: data structures, trees, dfs, bfs
// difficulty_level: expert


#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define K 18

int lev[N];
int par[N];
int seen[N];
int od[N];
int qu[N];
int qw[N];
int sp[N][K];
int cnt[N];
int res[N];
vector<int> g[N];
map<pair<int, int>, int> mp;


void dfs(int u, int p, int lv) {
    lev[u] = lv;
    par[u] = p;
    seen[u] = true;
    sp[u][0] = p;
    for(int i=1; i<K; i++) {
        if(sp[u][i-1] != -1) {
            sp[u][i] = sp[sp[u][i-1]][i-1];
        }
    }
    for(int v: g[u]) {
        if(!seen[v]) {
            dfs(v, u, lv+1);
            od[u]++;
        }
    }
}

int lca(int u, int v) {
    if(lev[u] < lev[v]) {
        swap(u, v);
    }
    for(int i=K-1; i>=0; i--) {
        if(lev[u] - (1 << i) >= lev[v]) {
            u = sp[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i=K-1; i>=0; i--) {
        if(sp[u][i] != -1 && sp[u][i] != sp[v][i]) {
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    return sp[u][0];
}


int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        mp[make_pair(min(u, v), max(u, v))] = i;
    }
    for(int i=0; i<=n; i++) {
        seen[i] = 0;
        od[i] = 0;
        cnt[i] = 0;
        for(int j=0; j<K; j++) {
            sp[i][j] = -1;
        }
    }
    dfs(1, -1, 0);
    int k;
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int anc = lca(u, v);
        cnt[u]++;
        cnt[v]++;
        cnt[anc]-=2;
    }
    int qs = 0, qe = 0;
    for(int i=1; i<=n; i++) {
        if(!od[i]) {
            qw[qe] = cnt[i];
            qu[qe++] = i;
        }
    }
    while(qs != qe) {
        int w = qw[qs];
        int u = qu[qs++];
        int p = par[u];
        if(p != -1) {
            res[mp[make_pair(min(u, p), max(u, p))]] = w;
            cnt[p] += w;
            od[p]--;
            if(od[p] == 0) {
                qw[qe] = cnt[p];
                qu[qe++] = p;
            }
        }
    }
    for(int i=1; i<n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    return 0;
}
```
