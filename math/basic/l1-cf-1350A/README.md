## Solutions
#### 1
##### Source Code
```c++
// problem name: Orac and Factors
// problem link: https://codeforces.com/contest/1350/problem/A
// contest link: https://codeforces.com/contest/1350
// time: (?)
// author: reyad

// other_tags: number theory
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

int getFirstDiv(int n) {
	// note: n is always greater than or equal 2
	if((n&1) == 0) return 2;
	for(int i=3; (long long)i*i <= n; i+=2) {
		if((n % i) == 0) return i;
	}
	return n;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		int d = getFirstDiv(n);
		if(d == n) { // if prime
			printf("%lld\n", n + n + (long long)(k-1) * 2);
		} else if(d == 2) { // if even
			printf("%lld\n", n + (long long)k * 2);
		} else { // if odd
			printf("%lld\n", n + d + (long long)(k-1) * 2);
		}
	}
	return 0;
}
```
