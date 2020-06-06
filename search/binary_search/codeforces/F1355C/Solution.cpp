// problem name: Count Triangles
// problem link: https://codeforces.com/contest/1355/problem/C
// contest link: https://codeforces.com/contest/1355
// time: (?)
// author: reyad

// other_tags: implementation, math, two pointers
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	long long tot = 0;
	for(int i=a; i<=b; i++) {
		int s = b, e = c, yp = -1;
		while(s <= e) {
			int m = (s + e) / 2;
			if(i + m > c) {
				yp = m;
				e = m - 1;
			} else {
				s = m + 1;
			}
		}
		if(yp != -1) {
			/* trying to measure the range of x(i) + y, where x(i) + y is always greater than z */
			/* then, we are trying to count for possible no. of z's for each x(i) + y */
			// for low      possible z's are c....low-1
			// for low + 1  possible z's are c....low
			// ....
			// ....
			// for d        possible z's are c....d-1
			// for d + 1    possible z's are c....d
			// for d + 2    possible z's are c....d
			// ....
			// ....
			// for high     possible z's are c....d
			// i.e. if low <= d, then for x + y = (low...d) the no of z's will be an arithmetic series
			int low = i + yp; // note: low > z(c), see the binary search above
			int high = i + c;
			if(low > d) {
				tot = tot + 1LL * (d - c + 1) * (c - yp + 1); // all (c...d) is eligible as z for y = (yp...c)
			} else {
				// so, z = (low-1) + low + (low+1) + ... + (h-1) for x+y = (low...min(d, high))
				int h = min(high, d);
				int u = (h - 1) - c + 1;   // z's range for (x+y = h): c...h-1
				int v = (low - 2) - c + 1; // z's range for (x+y = low-1): c...low-2
				tot = tot + (1LL * u * (u + 1) - 1LL * v * (v + 1)) / 2;
				// for x+y = d+1...high if high > d
				if(high > d) {
					tot = tot + 1LL * (high - d) * (d - c + 1);
				}
			}
		}
	}
	printf("%lld\n", tot);
	return 0;
}