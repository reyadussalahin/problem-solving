// problem name: 3-Coloring
// problem link: https://codeforces.com/contest/1504/problem/D
// contest link: https://codeforces.com/contest/1504
// time: (?)
// author: reyad


// other_tags: game, interactive, graph
// difficulty_level: beginner


// solution idea:
// with two colors we can create a pattern as
// follows so that no neighboring cell share
// same colors
// x y x y x
// y x y x y
// x y x y x
// y x y x y
// x y x y x
// so, as we're given the choice to select from
// one of two colors(as alice blocks the other color)
// we can always between either x or y
// so, what we'll do first is
// either complete all the cells of x
// or, complete all the cells of y
// one of the x or y must complete prior to other
// let's assume x is completed first
// and for the one which is not complete, we can select
// between one of (y and z), cause alice can't force us
// to select a single color x in anyway.
// so, the solved graph may look(considering x is completed first)
// x y x y x
// y x y x y
// x z x y x
// y x z x z
// x z x y x


#include <bits/stdc++.h>

using namespace std;


pair<int, int> x[10010];
pair<int, int> y[10010];

int main() {
    int n;
    scanf("%d", &n);
    int xc = 0, yc = 0;
    for(int i=0; i<n; i++) {
        if(!(i&1)) {
            for(int j=0; j<n; j++) {
                if(!(j&1)) {
                    x[xc++]= {i+1, j+1};
                } else {
                    y[yc++] = {i+1, j+1};
                }
            }
        } else {
            for(int j=0; j<n; j++) {
                if(!(j&1)) {
                    y[yc++] = {i+1, j+1};
                } else {
                    x[xc++]= {i+1, j+1};
                }
            }
        }
    }
    int m = n * n;
    int _xc = 0, _yc = 0;
    for(int i=0; i<m; i++) {
        int a;
        scanf("%d", &a);
        if(_xc < xc && _yc < yc) {
            if(a == 1) {
                printf("%d %d %d\n", 2, y[_yc].first, y[_yc].second);
                ++_yc;
                fflush(stdout);
            } else {
                printf("%d %d %d\n", 1, x[_xc].first, x[_xc].second);
                ++_xc;
                fflush(stdout);
            }
        } else {
            if(_xc < xc) {
                int choose = (a == 1) ? 3 : 1;
                printf("%d %d %d\n", choose, x[_xc].first, x[_xc].second);
                ++_xc;
                fflush(stdout);
            }
            if(_yc < yc) {
                int choose = (a == 2) ? 3 : 2;
                printf("%d %d %d\n", choose, y[_yc].first, y[_yc].second);
                ++_yc;
                fflush(stdout);
            }
        }
    }
    return 0;
}
