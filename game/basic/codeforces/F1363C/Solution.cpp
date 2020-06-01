// problem name: Game On Leaves
// problem link: https://codeforces.com/contest/1363/problem/C
// contest link: https://codeforces.com/contest/1363
// time: (?)
// author: reyad


// other_tags: trees
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

#define N 1024

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, x;
		scanf("%d %d", &n, &x);
		int dx = 0;
		for(int i=1; i<n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			if(u == x || v == x) {
				dx++;
			}
		}
		if(dx <= 1) {
			printf("Ayush\n");
		} else {
			if(n&1) {
				printf("Ashish\n");
			} else {
				printf("Ayush\n");
			}
		}
	}
	return 0;
}