## Solutions
```c++
// problem name: A Secret Mission
// problem link: http://lightoj.com/volume_showproblem.php?problem=1101
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: tree path queries, minimum spanning tree, dfs, data structures
// difficulty_level: expert


#include <bits/stdc++.h>

using namespace std;


#define N 50010
#define M 100010
#define K 20


struct E {
    int x, y, w;
    E(){}
};

bool cmp(const E &e1, const E &e2) {
    return e1.w < e2.w;
}


E e[M];
int p[2 * N];
vector<int> mst[2 * N];
map<int, int> wc;
int spt[2 * N][K];
int lev[2 * N];


int find(int i) {
    return (i == p[i]) ? i : (p[i] = find(p[i]));
}


void dfs(int u, int par, int lv) {
    lev[u] = lv;
    spt[u][0] = par;
    for(int i=1; i<K; i++) {
        if(spt[u][i-1] != -1) {
            spt[u][i] = spt[spt[u][i-1]][i-1];
        }
    }
    for(int v: mst[u]) {
        dfs(v, u, lv+1);
    }
}

int lca(int u, int v) {
    if(lev[u] < lev[v]) {
        swap(u, v);
    }
    for(int i=K-1; i>=0; i--) {
        if((lev[u] - (1 << i)) >= lev[v]) {
            u = spt[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i=K-1; i>=0; i--) {
        if(spt[u][i] != -1 && spt[u][i] != spt[v][i]) {
            u = spt[u][i];
            v = spt[v][i];
        }
    }
    return spt[u][0];
}


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for(int i=0; i<=2*n; i++) {
            mst[i].clear();
        }
        wc.clear();

        for(int i=0; i<m; i++) {
            scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].w);
        }
        
        sort(e, e+m, cmp);
        for(int i=1; i<=2*n; i++) {
            p[i] = i;
        }

        int z = n;
        for(int i=0; i<m; i++) {
            int u = e[i].x;
            int v = e[i].y;
            if(find(u) != find(v)) {
                z += 1;
                int pu = find(u), pv = find(v), pz = find(z);
                p[pu] = p[pv] = pz;
                wc[z] = e[i].w;
                mst[pz].push_back(pu);
                mst[pz].push_back(pv);
            }
        }

        for(int i=0; i<=z; i++) {
            for(int j=0; j<K; j++) {
                spt[i][j] = -1;
            }
        }

        assert(z <= 2*n);
        assert(find(1) == find(z));
        
        dfs(z, -1, 0);

        int q;
        scanf("%d", &q);
        printf("Case %d:\n", cc+1);
        for(int i=0; i<q; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int t = lca(u, v);
            assert(wc.count(t) != 0);
            printf("%d\n", wc[t]);
        }
    }

    return 0;
}
```
