## Solutions
#### 1
##### Source Code
```c++
// problem name: New Year's Number
// problem link: https://codeforces.com/contest/1475/problem/B
// contest link: https://codeforces.com/contest/1475/
// time: (?)
// author: reyad


// other_tags: dynamic programming, brute force
// difficulty_level: beginner


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int n;
        cin >> n;
        if(n < 2020) {
            cout << "NO\n";
            continue;
        }
        int q = n / 2020;
        int r = n - (2020 * q);
        if(r <= q) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

```
