## Solutions
#### 1
##### Source Code
```c++
// problem name: Most Unstable Array
// problem link: https://codeforces.com/contest/1353/problem/A
// contest link: https://codeforces.com/contest/1353
// time: (?)
// author: reyad

// other_tags: greedy, math
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long ans = 0;
		if(n == 1) {
			ans = 0LL;
		} else if(n == 2) {
			ans = m;
		} else {
			ans = 2LL * m;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```
