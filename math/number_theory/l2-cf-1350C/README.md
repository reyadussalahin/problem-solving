## Solutions
```c++
// problem name: Orac and LCM
// problem link: https://codeforces.com/contest/1350/problem/C
// contest link: https://codeforces.com/contest/1350
// time: (?)
// author: reyad

// other_tags: (?)
// difficulty_level: medium


// solution hint:  gcd(lcm(u, v_1), lcm(u, v_2), ..., lcm(u, v_n)) = lcm(u, gcd(v_1, v_2, ..., v_n))


#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	while(b != 0) {
		long long c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return (long long)a * b / gcd(a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	long long v = 0;
	long long gp = 0;
	for(int i=0; i<n; i++) {
		int u;
		scanf("%d", &u);
		gp = gcd(gp, lcm(u, v));
		v = gcd(u, v);
	}
	printf("%lld\n", gp);
	return 0;
}

```
