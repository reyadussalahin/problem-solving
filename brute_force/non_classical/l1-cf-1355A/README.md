## Solutions
```c++
// problem name: Sequence with Digits
// problem link: https://codeforces.com/contest/1355/problem/A
// contest link: https://codeforces.com/contest/1355
// time: (?)
// author: reyad

// other_tags: implementation, math
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		long long a, k;
		scanf("%lld %lld", &a, &k);
		for(int i=2; i<=k; i++) {
			int mn = 10, mx = -1;
			long long b = a;
			while(b > 0) {
				int d = b % 10;
				b = b / 10;
				mn = min(mn, d);
				mx = max(mx, d);
			}
			if(mn == 0) {
				break;
			}
			a = a + mn * mx;
		}
		printf("%lld\n", a);
	}
	return 0;
}
```
