// problem name: Birthday Paradox
// problem link: http://lightoj.com/volume_showproblem.php?problem=1104
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        long long n;
        scanf("%d", &n);
        double x = 1.0;
        int m = 0;
        for(int i=1; x > 0.5; i++) {
            x = x * (n - i) / n;
            m = i;
        }
        printf("Case %d: %d\n", cc+1, m);
    }
    return 0;
}
