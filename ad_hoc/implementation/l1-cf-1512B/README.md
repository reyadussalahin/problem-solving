## Solutions
```c++
// problem name: Almost Rectangle
// problem link: https://codeforces.com/contest/1512/problem/B
// contest link: https://codeforces.com/contest/1512
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: beginner


#include <bits/stdc++.h>
using namespace std;

string s[412];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int n;
        cin >> n;
        vector<pair<int, int>> p;
        for(int i=0; i<n; i++) {
            cin >> s[i];
            for(int j=0; j<n; j++) {
                if(s[i][j] == '*') {
                    p.push_back({i, j});
                }
            }
        }
        assert(p.size() == 2);
        assert(p[0] != p[1]);
        if(p[0].first == p[1].first) { // same row
            for(int i=0; i<n; i++) {
                if(i != p[0].first) {
                    s[i][p[0].second] = '*';
                    s[i][p[1].second] = '*';
                    break;
                }
            }
        } else if(p[0].second == p[1].second) { // same col
            for(int i=0; i<n; i++) {
                if(i != p[0].second) {
                    s[p[0].first][i] = '*';
                    s[p[1].first][i] = '*';
                    break;
                }
            }
        } else { // different row-col
            s[p[0].first][p[1].second] = '*';
            s[p[1].first][p[0].second] = '*';
        }
        for(int i=0; i<n; i++) {
            cout << s[i] << "\n";
        }
    }
    return 0;
}

```
