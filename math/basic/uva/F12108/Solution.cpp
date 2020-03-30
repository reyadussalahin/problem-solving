// problem name: Extraordinarily Tired Students
// problem link: http://uva.onlinejudge.org/external/121/12108.pdf
// contest link: (?)
// time: (?)
// author: reyad

// other tags: number theory

// difficulty level: beginner


#include <bits/stdc++.h>

using namespace std;

#define N 12

int mode[N], a[N], b[N], c[N];

int main() {
	int n, cc=1;

	for(scanf("%d", &n); n; scanf("%d", &n), cc++) {
		for(int i=0; i<n; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			if(c[i] > a[i]) {
				mode[i] = 1;
				c[i] -= a[i];
			} else mode[i] = 0;
		}

		int ans = -1;
		for(int k=1; k<=1000000; k++) {
			int sleep = 0, awake = 0;
			for(int i=0; i<n; i++) {
				if(mode[i]) sleep++;
				else awake++;
			}
			if(!sleep) {
				ans = k;
				break;
			}
			for(int i=0; i<n; i++) {
				c[i]++;
				if(mode[i]) {
					if(c[i] > b[i]) {
						c[i] = 1;
						mode[i] = 0;
					}
				} else {
					if(c[i] > a[i]) {
						if(sleep > awake) mode[i] = 1;
						c[i] = 1;
					}
				}
			}
		}
		printf("Case %d: %d\n", cc, ans);
	}

	return 0;
}