## Solutions
#### 1
##### Source Code
```c++
// problem name: Board Moves
// problem link: https://codeforces.com/contest/1353/problem/C
// contest link: https://codeforces.com/contest/1353
// time: (?)
// author: reyad

// other_tags: (?)
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

#define N 500000

long long a[N+10];

int main() {
	a[1] = 0LL;
	long long sq = 1LL;
	for(int i=3, j=1; i<=N; j++, i+=2) {
		a[i] = a[i-2] + (j * ((1LL * i * i) - sq));
		sq = 1LL * i * i;
	}
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
	return 0;
}
```
