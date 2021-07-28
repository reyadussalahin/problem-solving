## Solutions
#### 1
##### Source Code
```c++
// problem name: Permutation by Sum
// problem link: https://codeforces.com/contest/1512/problem/E
// contest link: https://codeforces.com/contest/1512
// time: (?)
// author: reyad


// other_tags: brute force, math
// difficulty_level: beginner


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int o = r - l + 1;
        int min_sum = o * (o + 1) / 2;
        int _o = n - o;
        int max_sum = (n * (n + 1) / 2) - (_o * (_o + 1) / 2);
        if(s < min_sum || s > max_sum) {
            cout << -1 << "\n";
            continue;
        }
        set<int> st;
        for(int i=n; i>=1; i--) {
            if((s - i) >= (o * (o - 1) / 2)) {
                s -= i;
                o--;
                st.insert(i);
            }
        }
        assert(s == 0);
        int c = 1;
        for(int i=1; i<=n; i++) {
            if(c == l) {
                for(auto it: st) {
                    cout << it << " ";
                }
                c++;
            }
            if(st.find(i) == st.end()) {
                cout << i << " ";
                c++;
            }
        }
        if(c == l) {
            for(auto it: st) {
                cout << it << " ";
            }
            c++;
        }
        cout << "\n";
    }
    return 0;
}

```
