## Solutions
```c++
// problem name: Spy Detected!
// problem link: https://codeforces.com/contest/1512/problem/A
// contest link: https://codeforces.com/contest/1512
// time: (?)
// author: reyad


// other_tags: brute force
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
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            mp[a].push_back(i);
        }
        for(auto it: mp) {
            if((int)it.second.size() == 1) {
                cout << it.second[0] + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}

```
