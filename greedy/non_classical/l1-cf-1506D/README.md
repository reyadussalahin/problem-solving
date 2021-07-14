## Solutions
#### 1
##### Source Code
```c++
// problem name: Epic Transformation
// problem link: https://codeforces.com/contest/1506/problem/D
// contest link: https://codeforces.com/contest/1506
// time: (?)
// author: reyad


// other_tags: constructive algorithm, data structure
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        map<int, int> mp;
        priority_queue<int> pq;
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int a;
            scanf("%d", &a);
            mp[a]++;
        }
        for(auto it: mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) {
                pq.push(x);
                break;
            }
            int y = pq.top();
            pq.pop();
            // printf("x, y: %d\n", x, y);
            --x; --y;
            if(x) {
                pq.push(x);
            }
            if(y) {
                pq.push(y);
            }
        }
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}

```
