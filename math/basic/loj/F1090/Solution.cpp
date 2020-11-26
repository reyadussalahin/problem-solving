// problem name: Trailing Zeroes (II) 
// pronlem link: http://lightoj.com/volume_showproblem.php?problem=1090
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: dynamic programming
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;


#define N 1000010


int calc(int num, int div) {
    int cnt = 0;
    while((num % div) == 0) {
        num = num / div;
        cnt++;
    }
    return cnt;
}

int two[N];
int five[N];

int main() {
    two[0] = five[0] = 0;
    for(int i=1; i<N; i++) {
        two[i] = two[i-1] + calc(i, 2);
        five[i] = five[i-1] + calc(i, 5);
    }

    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, r, p, q;
        scanf("%d %d %d %d", &n, &r, &p, &q);
        int ts = two[n] - two[r] - two[n-r] + calc(p, 2) * q;
        int fs = five[n] - five[r] - five[n-r] + calc(p, 5) * q;
        printf("Case %d: %d\n", cc+1, min(ts, fs));
    }
    return 0;
}
