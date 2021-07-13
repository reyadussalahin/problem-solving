## Solutions
```c++
// problem name: Restorer Distance
// problem link: https://codeforces.com/contest/1355/problem/E
// contest link: https://codeforces.com/contest/1355
// time: (?)
// author: reyad

// other_tags: binary search, greedy, math, sorting
// difficulty_level: medium


// note: this problem can also be solved using binary_search
// to see solution for binary_search see search/binary_search/codeforces/F1355E/Solution.cpp

// solution idea:
// the cost curve would be somewhat like below:
// .                  .
//  .                .
//    .            .
//      .       .
//         . .
// so we just have to find the height of lowest cost point

#include <bits/stdc++.h>

using namespace std;

#define N 100010

const long long inf = (long long)1e18;

int h[N];
int n, a, r, m;

long long calc(long long lev) {
	long long put = 0;
	long long remove = 0;
	for(int i=0; i<n; i++) {
		if(h[i] <= lev) {
			put = put + lev - h[i];
		} else {
			remove = remove + h[i] - lev;
		}
	}
	// now, some elements to put, some to remove and some to move
	// the num of elements can be removed is cnt = min(put, remove) and
	// cnt element should be moved only when move cost(m) < put cost(a) + remove cost(r)
	// and other remaining should be removed or put just normally
	// so,
	long long cnt = min(put, remove);
	put -= cnt;
	remove -= cnt;
	return put * a + remove * r + cnt * min(a + r, m);
}

int main() {
	scanf("%d %d %d %d", &n, &a, &r, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &h[i]);
	}
	long long minCost = inf;
	int s = 0, e = (int)1e9; // height range 0...1e9
	// note: e - s > 1 condition is a must
	// cause if e = s + 1
	// then __m1 = s + s + e = s + s + s + 1 = 3*s + 1
	// and __m2 = s + e + e = s + (s+1) + (s+1) = 3*s + 2
	// so, __m2 = __m1 + 1
	// and it is then possible m1 = (__m1 / 3) = s
	// and m2 = (__m2 / 3) = s
	// i.e. m1 == m2
	// which is something we do not want and it would totally ignore value e
	// and would provide us wrong result
	while(e - s > 1) {
		long long m1 = (0LL + s + s + e) / 3;
		long long m2 = (0LL + s + e + e) / 3;
		if(calc(m1) > calc(m2)) {
			/**
			 * m1 provides much more than
			 * so, we should pull down the m1 until
			 * it equals or provides
			 * less value than m2
			 */
			s = m1 + 1; // we should add 1 to avoid infinite loop
			// and also +1 is totally okay
			// cause calc(m1) > calc(m2) i.e. m1 can never the answer while m2 is present
		} else {
			// its the reverse of situation of previous situation
			e = m2;
		}
	}
	printf("%lld\n", min(calc(s), calc(e)));
	return 0;
}
```
