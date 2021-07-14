## Solutions
#### 1
##### Source Code
```c++
// problem name: Pairs of Paths
// problem link: https://codeforces.com/contest/1486/problem/F
// contest link: https://codeforces.com/contest/1486
// time: (?)
// author: reyad


// other_tags: combinatorics, data structures, dynamic programming, trees, dfs
// difficulty_level: expert


#include <bits/stdc++.h>

using namespace std;

#define DEBUG 1

#define N 300030
#define K 20


/**
 *                   (o) parent of u
 *                    |
 *                   (u) parent of v1, v2, ...
 *             /    /   \    \
 *            /    /     \    \
 *           /    /       \    \
 *          /    /         \    \
 *         /    /           \    \
 *       (v1) (v2)         (v3) (v4)
 */


/**
 * @var
 * g is graph(stores adj list)
 */
vector<int> g[N];
/**
 * @var
 * pt stands for parent table, it is a sparse table
 * helps calculating lca
 * lev keeps track of level i.e. depth
 */
int pt[N][K], lev[N];
/**
 * @var
 * cnt the number of paths(given through query) of which a node 'u' is lca
 */
int lca_cnt[N] = {0};
/**
 * @var
 * ssc[v1] denotes the number of paths(given in query) which's lca is the parent of v1(in this
 * case, 'u')
 * `ssc` stands for `shared single edge count`(in this case edge u->v)
 * note: we don't need to keep track of 'u', cause v1 parent will always be 'u' in a rooted tree
 */
int ssc[N] = {0};
/**
 * @var
 * spc[u][{v1, v2}] denotes the number of paths(given in query) which's lca is the parent of {v1, 
 * v2} where v1, v2 are siblings and in this case their parent is 'u'.
 * `spc` stands for `shared pair edge count(in this case, u->v1 and u->v2)
 * note: we need to keep track of 'u' for computational purposes, otherwise we could just generate
 * all pair combination of `u's` children and find out their shared edge count.
 */
map<pair<int, int>, int> spc[N];
/**
 * @var
 * ptc stands for pass through count
 * it calculates the number of paths are going through a node `v` where 'v' is not a lca of the
 * path. That means the paths will eventually be go through `v's` parent(which is in this case 
 * 'u')
 */
int ptc[N] = {0};
/**
 * @var
 * a global vaiable which hold the answer
 */
long long ans;


/**
 * @function
 * prepares pt i.e sparse table
 */
void dfs(int u, int par, int lv) {
    lev[u] = lv;
    pt[u][0] = par;
    for(int i=1; i<K; i++) {
        if(pt[u][i-1] != -1) {
            pt[u][i] = pt[pt[u][i-1]][i-1];
        }
    }
    for(int v: g[u]) {
        if(v != par) {
            dfs(v, u, lv+1);
        }
    }
}

/**
 * @function
 * returns lca
 */
int lca(int u, int v) {
    if(lev[u] < lev[v]) {
        swap(u, v);
    }
    for(int i=K-1; i>=0; i--) {
        if((lev[u] - (1 << i)) >= lev[v]) {
            u = pt[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i=K-1; i>=0; i--) {
        if(pt[u][i] != -1 && pt[u][i] != pt[v][i]) {
            u = pt[u][i];
            v = pt[v][i];
        }
    }
    return pt[u][0];
}

/**
 * @function
 * returns nth_ancestor of a given node
 */
int nth_ancestor(int u, int nth) {
    for(int i = K-1; i >= 0; i--) {
        if((nth >> i) & 1) {
            u = pt[u][i];
        }
    }
    return u;
}

/**
 * @function
 * calculates no of pairs for a set of given n elements
 */
long long count_pair(int n) {
    return (long long)n * (n - 1) / 2;
}

/**
 * @function
 * processes pass through
 */
void process_pass_through(int u, int par) {
    for(auto v: g[u]) {
        if(v != par) {
            process_pass_through(v, u);
            ptc[u] += ptc[v];
        }
    }
}

/**
 * @function
 * calculates final answer
 */
void calc_ans(int u, int par) {
    // calculate ans for children
    for(auto v: g[u]) {
        if(v != par) {
            calc_ans(v, u);
        }
    }
    // calc ans for type 1 i.e. same lca
    // first add all possible pairs for which 'u' is lca
    ans += count_pair(lca_cnt[u]);
    // now subtract all pairs which has shared edge u->v1, u->v2, ...
    for(auto v: g[u]) {
        if(v != par) {
            ans -= count_pair(ssc[v]);
        }
    }
    // now, if there are some paths which goes through both two edges such as {v1, v2}
    // those path's pair have been subtracted twice, one for v1 and another fot v2
    // so, we must add those pairs
    for(auto sp: spc[u]) {
        ans += count_pair(sp.second);
    }

    // calc ans for type 2 i.e. different lca
    // first calculate total possible intersection
    // i.e. the number of pairs where one of the path has lca 'u'
    // and the other path pass through 'u' to its parent
    ans += (long long)ptc[u] * lca_cnt[u];
    // now, some path those pass through 'u'(i.e. goes to u's parent o)
    //      has shared edge with v1 with those paths which has lca at
    //      'u' and also goes through v1
    //      this is also tru for v2, v3, ...
    //      so, we must get rid of them
    // for that, first we need to determine the no of paths those goes through 'v1->u', 
    // 'v2->u', ... but does not have lca at 'u', i.e. goes to `u's` parent `o`
    // we may count it by subtracting ssc[v1] from ptc[v1]
    // i.e. ptc[v1] - ssc[v1]
    // ptc[v1] contains the number of paths that passes through v1 to u
    // ssc[v1] contains the number of paths that has lca at 'u'
    for(auto v: g[u]) {
        if(v != par) {
            int ptc_vuo = ptc[v] - ssc[v];
            // now, count the pairs those shared v->u edge
            ans -= (long long)ssc[v] * ptc_vuo;
        }
    }
}

/**
 * @function
 * driver function @main
 */
int main() {
    #undef DEBUG
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // here, 'u' is the lca
        int u = lca(x, y);
        lca_cnt[u]++;
        // determining the children through which the path (x, y)
        // meets at 'u'
        int v1 = -1, v2 = -1;
        if(x != u) {
            v1 = nth_ancestor(x, lev[x] - lev[u] - 1);
        }
        if(y != u) {
            v2 = nth_ancestor(y, lev[y] - lev[u] - 1);
        }

        #ifdef DEBUG
        printf("lca of %d, %d: %d\n", x, y, u);
        printf("v1, v2: %d, %d\n", v1, v2);
        #endif
        
        // increase shared single edge count for v1
        if(v1 != -1) {
            ssc[v1]++;
        }
        // increase shared single edge count for v1
        if(v2 != -1) {
            ssc[v2]++;
        }
        // if v1, v2 both are used for path, then
        // increase count for shared pair edge count for {v1, v2}
        if(v1 != -1 && v2 != -1) {
            if(v2 < v1) {
                swap(v1, v2);
            }
            spc[u][{v1, v2}]++;
        }
        // now, update pass through count
        // ptc at x and y should be increased by 1
        // which will flow upward, you'll see in process_pass_through function
        ptc[x]++;
        ptc[y]++;
        // and therefore, ptc at 'u' i.e. lca must be reduced to 0
        ptc[u] -= 2;
        // in this way, ptc only contains the no of paths
        // that must go through a node to it's parent
    }
    
    process_pass_through(1, 0);

    #ifdef DEBUG
    printf("lca debug\n");
    for(int i=1; i<=n; i++) {
        printf("lca of %d: %d\n", i, lca_cnt[i]);
    }
    printf("\n");
    printf("shared single edge count debug\n");
    for(int i=1; i<=n; i++) {
        printf("ssc of %d: %d\n", i, ssc[i]);
    }
    printf("\n");
    printf("pass through count debug\n");
    for(int i=1; i<=n; i++) {
        printf("ptc of %d: %d\n", i, ptc[i]);
    }
    printf("\n");
    #endif

    ans = 0;
    calc_ans(1, 0);
    printf("%lld\n", ans);
}

```
