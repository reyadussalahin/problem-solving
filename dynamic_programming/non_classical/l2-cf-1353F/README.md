## Solutions
#### 1
##### Source Code
```c++
// problem name: Decreasing Heights
// problem link: https://codeforces.com/contest/1353/problem/F
// contest link: https://codeforces.com/contest/1353
// time: (?)
// author: reyad

// other_tags: brute force
// difficulty_level: medium

// solution idea:
// observation-01: for any value greater than a[0][0], can not be used at a[0][0]
//                 (cause, only decrease operation is allowed)
// observation-02: if we find the minimum cost for x = a[0][0], then we may say that
//                 the path for the solution is as following:
//                 x, x + r_1, x + r_2, ...., x + r_k-1[note: k = n*m, i.e. (0..k-1) has n*m elements]
//                 now, we may say that, x + r_z >= x + z(where, z = 1...k-1)
//                 simply we want to say that, if a[i][j](0-based indexing) is in the solution,
//                 then, a[i][j] >= x + (i+j)[note: x + (i+j) is the value that should be found at
//                 index i, j if we set x as the base]
// observation-03: now, if we want to find a solution for y, where y < x, and the path that
//                 has given mincost for x would be like:
//                 y, y + r_1, y + r_2, ...., y + r_k-1
//                 and the cost would be (x - y) * k i.e. (x - y) * n  *m
//                 so, y should give us a good answer using the path those x used, so we don't need
//                 to see them again,
//                 but
//                 as y < x, y of course open up some new paths, those for x was not opened, cause
//                 a[i][j] >= x + (i+j) has to be satisfied
//                 and now, a[i][j] >= y + (i+j) has to be satisfied, where y < x
//                 now, as those a[i][j] does not satisfied a[i][j] >=  x + (i+j), but
//                 satsfied but satisfied a[i][j] >= y + (i+j) will open up new paths and try to find
//                 new mincost
// observation-04: the previous observation clearly states that we've to open up new paths to find the
//                 new mincost. So, rather than opening up new paths in a decreasing order i.e. at first x
//                 then y then y-p(p > 0)...etc..., we can just bruteforce for each a[i][j], take
//                 a[i][j] - (i+j) as base and find the mincost, cause a[i][j] - (i+j) will sure openup
//                 a[i][j].


#include <bits/stdc++.h>

using namespace std;

#define N 128

const long long inf = (long long)1e18;

long long a[N][N];
long long c[N][N];

int n, m;

long long getCost(long long base) {
	// initialize 0, 0
	c[0][0] = a[0][0] - base;
	// for first column
	for(int i=1; i<n; i++) {
		if(a[i][0] >= base + i) {
			c[i][0] = c[i-1][0] + a[i][0] - (base + i);
		} else {
			c[i][0] = inf;
		}
	}
	// for first row
	for(int i=1; i<m; i++) {
		if(a[0][i] >= base + i) {
			c[0][i] = c[0][i-1] + a[0][i] - (base + i);
		} else {
			c[0][i] = inf;
		}
	}
	// for row = (1...n-1)
	//   for col = (1...m-1)
	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			if(a[i][j] >= base + i + j) {
				c[i][j] = min(c[i-1][j], c[i][j-1]) + a[i][j] - (base + i + j);
			} else {
				c[i][j] = inf;
			}
		}
	}
	return c[n-1][m-1];
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%lld", &a[i][j]);
			}
		}
		long long minCost = inf;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				long long base = a[i][j] - (i + j);
				// check if possible base if greater than a[0][0]
				// in that case, it's not possible to reach the last element of matrix
				// cause, only decrease height operation is
				//        possible(according to problem statement)
				if(a[0][0] < base) continue;
				long long cost = getCost(base);
				minCost = min(minCost, cost);
			}
		}
		assert(minCost != inf);
		printf("%lld\n", minCost);
	}
	return 0;
}

```
