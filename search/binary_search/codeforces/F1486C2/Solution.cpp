// problem name: Guessing the Greatest (hard version)
// problem link: https://codeforces.com/contest/1486/problem/C2
// contest link: https://codeforces.com/contest/1486
// time: (?)
// author: reyad


// other_tags: interactive
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


int query(int l, int r) {
    if(l < r) {
        printf("? %d %d\n", l, r);
        fflush(stdout);
        int y;
        scanf("%d", &y);
        return y;
    }
    return -1;
}


int main() {
    int n;
    scanf("%d", &n);
    int x = query(1, n);
    bool left = true;
    if(query(1, x) != x) {
        left = false;
    }
    int len = left ? x : (n - x + 1);
    int k = 1;
    while(len > 0) {
        k += k;
        len /= 2;
    }
    if(left) {
        int u = 1;
        while(k > 0) {
            int m = u + (k / 2);
            if(query(m, x) == x) {
                u += k / 2;
            }
            k = k / 2;
        }
        printf("! %d\n", u+k);
    } else {
        int u = n;
        while(k > 0) {
            int m = u - (k / 2);
            if(query(x, m) == x) {
                u -= k / 2;
            }
            k = k / 2;
        }
        printf("! %d\n", u-k);
    }
    return 0;
}
