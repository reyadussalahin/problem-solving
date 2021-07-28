## Solutions
#### 1
##### Source Code
```c++
// problem name: A-B Palindrome
// problem link: https://codeforces.com/contest/1512/problem/C
// contest link: https://codeforces.com/contest/1512
// time: (?)
// author: reyad


// other_tags: constructive algorithm, string
// difficulty_level: beginner


#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        // balance
        int n = a + b;
        for(int i=0; i<n; i++) {
            if(s[i] == '?' && s[n-i-1] != '?') {
                s[i] = s[n-i-1];
            }
        }
        // check if palindrome is maintained in current state
        int flag = 1;
        for(int i=0; i<n; i++) {
            if(s[i] != s[n-i-1]) {
                flag = 0;
                break;
            }
        }
        if(!flag) {
            cout << -1 << "\n";
            // cout << "here is unbalanced s: " << s << "\n";
            continue;
        }
        // reduce count of 0 and 1
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                a--;
            }
            if(s[i] == '1') {
                b--;
            }
        }
        if(a < 0 || b < 0) {
            cout << -1 << "\n";
            // cout << "run out of stock: " << s << "\n";
            continue;
        }
        // get count of '?'
        int cq = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '?') {
                cq++;
            }
        }
        assert((a+b) == cq);
        if(!((a+b)&1) && (a&1)) {
            cout << -1 << "\n";
            // cout << "when even/odd mismatched: " << s << "\n";
            continue;
        }
        for(int i=0; i<n; i++) {
            if(s[i] == '?') {
                if(i == n-i-1) {
                    if(a == 1) {
                        s[i] = s[n-i-1] = '0';
                        a -= 1;
                    } else {
                        s[i] = s[n-i-1] = '1';
                        b -= 1;
                    }
                } else {
                    if(a > 1) {
                        s[i] = s[n-i-1] = '0';
                        a -= 2;
                    } else {
                        s[i] = s[n-i-1] = '1';
                        b -= 2;
                    }
                }
            }
        }
        // assert((a == 0) && (b == 0));
        cout << s << "\n";
    }
    return 0;
}

```
