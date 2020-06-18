// problem name: Johnny and Ancient Computer
// problem link: https://codeforces.com/contest/1362/problem/A
// contest link: https://codeforces.com/contest/1362
// time: (?)
// author: reyad

// other_tags: (?)
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if(a == b) {
			printf("0\n");
		}
		else if(a < b) {
			int op = 0;
			while((a << 3LL) <= b) {
				a = (a << 3LL);
				op++;
			}
			while((a << 2LL) <= b) {
				a = (a << 2LL);
				op++;
			}
			while((a << 1LL) <= b) {
				a = (a << 1LL);
				op++;
			}
			if(a == b) {
				printf("%d\n", op);
			} else {
				printf("%d\n", -1);
			}
		} else {
			int op = 0;
			while((a&(0x7)) == 0 && (a >> 3LL) >= b) {
				a = (a >> 3LL);
				op++;
			}
			while((a&(0x3)) == 0 && (a >> 2LL) >= b) {
				a = (a >> 2LL);
				op++;
			}
			while((a&(0x1)) == 0 && (a >> 1LL) >= b) {
				a = (a >> 1LL);
				op++;
			}
			if(a == b) {
				printf("%d\n", op);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}