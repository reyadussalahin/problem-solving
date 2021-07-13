## Solutions
```c++
// problem name: An Easy LCS
// problem link: http://lightoj.com/volume_showproblem.php?problem=1110
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

string dp[128][128];
char a[128];
char b[128];

void lcs(int i, int j) {
    if(dp[i][j].length() > 0) {
        return;
    }
    if(a[i] == '\0' || b[j] == '\0') {
        return;
    }
    if(a[i] == b[j]) {
        lcs(i+1, j+1);
        dp[i][j] = a[i] + dp[i+1][j+1];
    } else {
        lcs(i+1, j);
        lcs(i, j+1);
        if(dp[i+1][j].length() == dp[i][j+1].length()) {
            dp[i][j] = (dp[i+1][j].compare(dp[i][j+1]) < 0) ? dp[i+1][j] : dp[i][j+1];
        } else {
            dp[i][j] = (dp[i+1][j].length() > dp[i][j+1].length()) ? dp[i+1][j] : dp[i][j+1];
        }
    }
}


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        for(int i=0; i<104; i++) {
            for(int j=0; j<104; j++) {
                dp[i][j].clear();
            }
        }
        scanf("%s", a);
        scanf("%s", b);
        lcs(0, 0);
        if(dp[0][0].length() == 0) {
            dp[0][0] = ":(";
        }
        printf("Case %d: %s\n", cc+1, dp[0][0].c_str());
    }
    return 0;
}

```
