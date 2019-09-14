// problem name: I_love_%username%
// problem link: https://codeforces.com/problemset/problem/155/A
// contest link: https://codeforces.com/contest/155
// time: (?)
// author: reyad

#include <stdio.h>

int main() {
	int i, min, max, ans = 0, n;
	int a[1024];

	scanf("%d", &n);
	scanf("%d", &a[0]);
	min = max = a[0];
	for(i=1; i<n; i++) {
		scanf("%d", &a[i]);
		if(a[i] < min) {
			ans++;
			min = a[i];
		}
		if(a[i] > max) {
			ans++;
			max = a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
