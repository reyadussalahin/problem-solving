## Solutions
```c++
// problem name: Odd Selection
// problem link: https://codeforces.com/contest/1363/problem/A
// contest link: https://codeforces.com/contest/1363
// time: (?)
// author: reyad


// other_tags: brute force, math
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, x;
		scanf("%d %d", &n, &x);
		int odd = 0, even = 0;
		for(int i=0; i<n; i++) {
			int a;
			scanf("%d", &a);
			if(a&1) {
				odd++;
			} else {
				even++;
			}
		}
		if(odd == 0 || ((even == 0) && ((x&1) == 0)) || ((x == n) && ((odd&1) == 0))) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}
```
