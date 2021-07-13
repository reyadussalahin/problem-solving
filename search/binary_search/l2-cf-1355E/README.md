## Solutions
```c++
// problem name: Restorer Distance
// problem link: https://codeforces.com/contest/1355/problem/E
// contest link: https://codeforces.com/contest/1355
// time: (?)
// author: reyad

// other_tags: ternary search, greedy, math, sorting
// difficulty_level: medium


// note: this problem can also be solved using ternary_search
// to see solution for ternary_search see search/ternary_search/codeforces/F1355E/Solution.cpp

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

long long calc(int lev) {
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
	while(s <= e) {
		int m = (s + e) / 2;
		long long costAtMid = calc(m);
		long long costJustAfterMid = calc(m + 1);
		if(costAtMid < costJustAfterMid) {
			minCost = min(costAtMid, minCost);
			// we've to go left to find the lowest point
			e = m - 1;
		} else {
			minCost = min(costJustAfterMid, minCost);
			// we've to go right to find the lowest point
			s = m + 1;
		}
	}
	printf("%lld\n", minCost);
	return 0;
}
```
