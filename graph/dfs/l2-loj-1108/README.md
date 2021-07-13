## Solutions
```c++
// problem name: Instant View of Big Bang
// problem link: http://lightoj.com/volume_showproblem.php?problem=1108
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: data structure
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int>> g[1024];
vector<int> rg[1024];
map<int, int> instack;
int seen[1024];
int stck[1024];
int top;
int marked[1024];


void dfs(int u, int cost) {
    if(seen[u]) {
        if(instack.count(u)) {
            if(cost - instack[u] < 0) {
                stck[top++] = u;
            }
        }
        return;
    }
    seen[u] = true;
    instack[u] = cost;
    for(auto e: g[u]) {
        dfs(e.first, cost + e.second);
    }
    instack.erase(u);
}


void mark(int u) {
    marked[u] = true;
    for(int v: rg[u]) {
        if(!marked[v]) {
            mark(v);
        }
    }
}


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            g[i].clear();
            rg[i].clear();
            marked[i] = 0;
        }
        for(int i=0; i<m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back(make_pair(v, w));
            rg[v].push_back(u);
        }
        for(int i=0; i<n; i++) {
            if(!marked[i]) {
                top = 0;
                memset(seen, 0, sizeof(seen));
                dfs(i, 0);
                for(int j=0; j<top; j++) {
                    if(!marked[stck[j]]) {
                        mark(stck[j]);
                    }
                }
            }
        }
        printf("Case %d:", cc+1);
        int c = 0;
        for(int i=0; i<n; i++) {
            if(marked[i]) {
                printf(" %d", i);
                c++;
            }
        }
        if(c == 0) {
            printf(" impossible");
        }
        printf("\n");
    }
    return 0;
}
```
