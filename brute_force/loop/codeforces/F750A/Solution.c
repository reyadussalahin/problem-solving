// problem name: New Year and Hurry
// problem link: https://codeforces.com/problemset/problem/750/A
// contest link: https://codeforces.com/contest/750
// time: (?)
// author: reyad

#include <stdio.h>

int main() {
	int i, n, t = 0, c = 0, x;
	scanf("%d %d", &n, &x);
	for(i=1; i<=n; i++) {
		if(240 - (t + i * 5) >= x) {
			c++;
			t = t + i * 5;
		} else {
			break;
		}
	}
	printf("%d\n", c);
	return 0;
}