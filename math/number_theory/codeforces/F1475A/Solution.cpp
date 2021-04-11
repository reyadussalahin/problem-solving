// problem name: Odd Divisor
// problem link: https://codeforces.com/contest/1475/problem/A
// contest link: https://codeforces.com/contest/1475/
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: beginner



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int cc=0; cc<tc; cc++) {
        long long n;
        cin >> n;
        while(n>1 && !(n&1)) {
            n /= 2;
        }
        if(n == 1) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
