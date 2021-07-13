## Solutions
```c++
// problem name: Fi Binary Number 
// problem link: http://lightoj.com/volume_showproblem.php?problem=1105
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: fibonacci
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


#define N 1000010
#define M 1000000000
 
int stck[128];
char str[128];
 
int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n;
        scanf("%d", &n);
        int top = 0;
        while(n > 0) {
            int a = 1, b = 2;
            int i = 1;
            while(b <= n) {
                int c = a + b;
                a = b;
                b = c;
                i++;
            }
            stck[top++] = i - 1;
            n = n - a;
        }
        int l = stck[0];
        for(int i=0; top > 0; i++) {
            if(i == stck[top-1]) {
                str[i] = '1';
                top--;
            } else {
                str[i] = '0';
            }
        }
        printf("Case %d: ", cc+1);
        for(int i=l; i>=0; i--) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}

```
