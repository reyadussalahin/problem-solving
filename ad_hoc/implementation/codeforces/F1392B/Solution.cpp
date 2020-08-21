// problem name: Omkar and Infinity Clock
// problem link: https://codeforces.com/contest/1392/problem/B
// contest link: https://codeforces.com/contest/1392
// author: reyad
// time: (?)


// other tags: math
// difficulty level: beginner


#include <bits/stdc++.h>

using namespace std;


int a[200020];

int main() {

	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		long long n, k;
		scanf("%lld %lld", &n, &k);
		bool hasZero = false;
		int mx = -1000000007;
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			if(a[i] == 0) {
				hasZero = true;
			}
			mx = max(mx, a[i]);
		}
		int nmx = -1000000007;
		for(int i=0; i<n; i++) {
			a[i] = mx - a[i];
			nmx = max(nmx, a[i]);
		}
		k--;
		mx = nmx;
		if(k&1) {
			for(int i=0; i<n; i++) {
				a[i] = mx - a[i];
			}
		}
		for(int i=0; i<n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}