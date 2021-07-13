## Solutions
```c++
// problem name: Cleaning the Phone
// problem link: https://codeforces.com/contest/1475/problem/D
// contest link: https://codeforces.com/contest/1475/
// time: (?)
// author: reyad


// other_tags: binary search, sorting, two pointers
// difficulty_level: intermediate


#include <bits/stdc++.h>
using namespace std;

#define N 200020

int mem[N];
int cost[N];
int mem1[N];
int mem2[N];
int p1[4 * N];
int p2[4 * N];
long long dp[4 * N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> mem[i];
        }
        for(int i=0; i<n; i++) {
            cin >> cost[i];
        }
        int c1 = 0, c2 = 0;
        int mxc = 0;
        for(int i=0; i<n; i++) {
            if(cost[i] == 1) {
                mem1[c1++] = mem[i];
            } else {
                mem2[c2++] = mem[i];
            }
            mxc += cost[i];
        }
        sort(mem1, mem1 + c1);
        sort(mem2, mem2 + c2);
        p1[0] = c1 - 1, p2[0] = c2 - 1;
        dp[0] = 0;
        dp[1] = mem1[p1[0]];
        p1[1] = p1[0]-1;
        p2[1] = p2[0];
        int ans = (dp[1] >= m) ? 1 : -1;
        if(ans != -1) {
            cout << ans << "\n";
            continue;
        }
        for(int i=2; i<=mxc; i++) {
            dp[i] = -1;
            // int sel = -1;
            if(p1[i-1] >= 0 && dp[i-1] + mem1[p1[i-1]] > dp[i]) {
                dp[i] = dp[i-1] + mem1[p1[i-1]];
                p1[i] = p1[i-1]-1;
                p2[i] = p2[i-1];
                // sel = mem1[p1[i-1]];
            }
            if(p2[i-2] >= 0 && dp[i-2] + mem2[p2[i-2]] > dp[i]) {
                dp[i] = dp[i-2] + mem2[p2[i-2]];
                p1[i] = p1[i-2];
                p2[i] = p2[i-2]-1;
                // sel = mem2[p2[i-2]];
            }
            // cout << i << ": " << mem1[p1[i-1]] << " || " << mem2[p2[i-2]] << " || " << dp[i] << "\n";
            // cout << i << ": " << sel << "\n";
            if(dp[i] >= m) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

```
