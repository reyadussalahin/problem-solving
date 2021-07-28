## Solutions
#### 1
##### Source Code
```c++
// problem name: Ball in Berland
// problem link: https://codeforces.com/contest/1475/problem/C
// contest link: https://codeforces.com/contest/1475/
// time: (?)
// author: reyad


// other_tags: graph, inclusion exclusion principle
// difficulty_level: beginner


#include <bits/stdc++.h>
using namespace std;

#define N 200020

int aa[N], bb[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int a, b, k;
        map<int, int> boy;
        map<int, int> girl;
        cin >> a >> b >> k;
        for(int i=0; i<k; i++) {
            cin >> aa[i];
            boy[aa[i]]++;
        }
        for(int i=0; i<k; i++) {
            cin >> bb[i];
            girl[bb[i]]++;
        }
        long long ans = 0;
        for(int i=0; i<k; i++) {
            long long t = k - (boy[aa[i]] + girl[bb[i]] - 1);
            ans += t;
        }
        cout << (ans / 2) << "\n";
    }
    return 0;
}

```
