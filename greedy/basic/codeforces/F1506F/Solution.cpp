// problem name: Triangular Paths
// problem link: https://codeforces.com/contest/1506/problem/F
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: constructive algorithm, graph, math, sortings, shortest path
// difficulty_level: medium


// one of the worst problem description ever

#include <bits/stdc++.h>

using namespace std;


pair<int, int> p[200020];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &p[i].first);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &p[i].second);
        }
        sort(p, p+n);
        if(p[0] != make_pair(1, 1)) {
            for(int i=n-1; i>=0; i--) {
                p[i+1] = p[i];
            }
            p[0] = {1, 1};
            n++;
        }
        long long ans = 0;
        for(int i=0; i<n-1; i++) {
            auto x = p[i];
            auto y = p[i+1];
            // i guess, we're moving down strictly and keeping the col same or going right
            // otherwise, this solution won't work
            // and the problem description would be proved to be incorrect
            assert(x.first < y.first && x.second <= y.second);
            if(x.first - x.second == y.first - y.second) { // in the same diagonal
                if(!((x.first - x.second)&1)) { // if even diagonal
                    ans = ans + (y.first - x.first);
                }
            } else {
                // just calculate the direct downward cost
                ans = ans + (y.first - y.second) / 2 - (x.first - x.second) / 2;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
