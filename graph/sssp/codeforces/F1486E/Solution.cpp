// problem name: Paired Payment
// problem link: https://codeforces.com/contest/1486/problem/E
// contest link: https://codeforces.com/contest/1486
// time: (?)
// author: reyad


// other_tags: binary search, brute force, constructive algorithms, dp, flows
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

#define N 100010

vector<pair<int, int>> adj[N];
int d[N], mpe[N]; // note: mpe means `minimum of edges visited from parents`
                  //       i.e. the minimum of all edges
                  //       through which this particular node is discovered as an intermediary
                  //       node
int sqr(int n) {
    return n * n;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        adj[u].push_back({w, v}); // note: weight is saved in first and node no in second
        adj[v].push_back({w, u}); //       this is also maintained in priority_queue
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // note: x.first will target weight and x.second will target node no
    d[0] = 0;
    mpe[0] = INT_MAX;
    for(int i=1; i<n; i++) mpe[i] = d[i] = INT_MAX;
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if(d[x.second] < x.first) {
            continue;
        }
        for(auto y: adj[x.second]) {
            if(y.first < mpe[y.second]) {
                for(auto z: adj[y.second]) {
                    // note: `.second` targets node no, both in adj and pq
                    if(d[z.second] > d[x.second] + sqr(y.first + z.first)) {
                        d[z.second] = d[x.second] + sqr(y.first + z.first);
                        pq.push({d[z.second], z.second});
                    }
                }
                mpe[y.second] = y.first;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(d[i] == INT_MAX) {
            d[i] = -1;
        }
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}
