// problem name: Cells Not Under Attack
// problem link: https://codeforces.com/contest/701/problem/B
// contest link: https://codeforces.com/contest/701
// time: (?)
// author: reyad

// other_tags: data structure
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

#define N 100010

int r[N] = {0};
int c[N] = {0};

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long freeRow = n, freeCol = n;
	for(int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(!r[x]) {
			r[x] = 1;
			freeRow--;
		}
		if(!c[y]) {
			c[y] = 1;
			freeCol--;
		}
		printf("%lld ", freeRow * freeCol);
	}
	printf("\n");
	return 0;
}