## Solutions
#### 1
##### Source Code
```c++
// problem name: Johnny and Another Rating Drop
// problem link: https://codeforces.com/contest/1362/problem/C
// contest link: https://codeforces.com/contest/1362
// time: (?)
// author: reyad

// other_tags: bitmask, math
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		long long n;
		scanf("%lld", &n);
		long long bit = 62;
		long long unfairness = 0;
		while(bit >= 0) {
			if(n >= (1LL << bit)) {
				n = n - (1LL << bit);
				unfairness = unfairness + (2LL << bit) - 1LL;
			}
			bit--;
		}
		printf("%lld\n", unfairness);
	}
	return 0;
}
```
