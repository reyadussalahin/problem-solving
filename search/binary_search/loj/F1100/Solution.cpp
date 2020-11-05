// problem name: Again Array Queries
// problem link: http://lightoj.com/volume_showproblem.php?problem=1100
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: sorting, range query
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;


vector<int> b[1024];


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        for(int i=1; i<=1000; i++){
            b[i].clear();
        }
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=0; i<n; i++) {
            int a;
            scanf("%d", &a);
            b[a].push_back(i);
        }
        printf("Case %d:\n", cc+1);
        for(int i=0; i<q; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            int prev = -2048;
            int ans = 2048;
            for(int j=1; j<=1000; j++) {
                int s = 0, e = b[j].size() - 1, x = -1;
                while(s <= e) {
                    int m = (s + e) / 2;
                    if(b[j][m] < l) {
                        s = m + 1;
                    } else {
                        x = m;
                        e = m - 1;
                    }
                }
                if(x != -1 && b[j][x] <= r) {
                    if(x < b[j].size()-1 && b[j][x+1] <= r) {
                        ans = 0;
                        break;
                    }
                    ans = min(ans, j - prev);
                    prev = j;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}