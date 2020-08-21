// problem name: Omkar and Password
// problem link: https://codeforces.com/contest/1392/problem/A
// contest link: https://codeforces.com/contest/1392
// author: reyad
// time: (?)


// other tags: greedy, math
// difficulty level: beginner


#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, a, b;
		scanf("%d %d", &n, &a);
		bool same = true;
		for(int i=1; i<n; i++) {
			scanf("%d", &b);
			if(b != a) {
				same = false;
			}
		}
		if(same) {
			printf("%d\n", n);
		} else {
			printf("%d\n", 1);
		}
	}
	return 0;
}