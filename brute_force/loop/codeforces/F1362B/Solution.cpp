// problem name: Johnny and His Hobbies
// problem link: https://codeforces.com/contest/1362/problem/B
// contest link: https://codeforces.com/contest/1362
// time: (?)
// author: reyad

// other_tags: bitmask
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

#define N 2048

int a[N];
int c[N];
int d[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		memset(c, 0, sizeof(int) * 1032);
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			c[a[i]]++;
		}
		int ans = -1;
		for(int k=1; k<=1024; k++) {
			bool flag = true;
			memset(d, 0, sizeof(int) * 1032);
			for(int i=0; i<n; i++) {
				d[(a[i] ^ k)]++;
			}
			for(int i=0; i<1024; i++) {
				if(c[i] != d[i]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				ans = k;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}