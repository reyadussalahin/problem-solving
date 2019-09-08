// problem name: Count the Multiples of 3
// problem link: http://lightoj.com/volume_showproblem.php?problem=1135
// contest link: (?)
// time: (?)
// author: reyad

#include <bits/stdc++.h>

using namespace std;

#define N 100010

int b[3][4 * N], u[4 * N];
// int a[N];

void build(int p, int l, int r) {
	if(l == r) {
		for(int i=0; i<3; i++) b[i][p] = 0;
		// b[a[l]][p]++;
		b[0][p] = 1;
		u[p] = 0;
		return;
	}
	int m = (l+r)/2;
	build(2*p+1, l, m);
	build(2*p+2, m+1, r);
	for(int i=0; i<3; i++) {
		b[i][p] = b[i][2*p+1] + b[i][2*p+2];
	}
	u[p] = 0;
}

void lazy(int p, int x) {
	for(int i=0; i<x; i++) {
		int t = b[2][p];
		b[2][p] = b[1][p];
		b[1][p] = b[0][p];
		b[0][p] = t;
		u[p] = (u[p] + 1) % 3;
	}
}

void update(int p, int l, int r, int i, int j) {
	if(i == l && j == r) {
		int t = b[2][p];
		b[2][p] = b[1][p];
		b[1][p] = b[0][p];
		b[0][p] = t;
		u[p] = (u[p] + 1) % 3;
		return;
	}
	int m = (l+r)/2;
	if(u[p]) {
		lazy(2*p+1, u[p]);
		lazy(2*p+2, u[p]);
		u[p] = 0;
	}
	if(j <= m) update(2*p+1, l, m, i, j);
	else if(i > m) update(2*p+2, m+1, r, i, j);
	else {
		update(2*p+1, l, m, i, m);
		update(2*p+2, m+1, r, m+1, j);
	}
	for(int i=0; i<3; i++) {
		b[i][p] = b[i][2*p+1] + b[i][2*p+2];
	}
}

int query(int p, int l, int r, int i, int j) {
	if(i == l && j == r) {
		return b[0][p];
	}
	int m = (l+r) / 2;
	if(u[p]) {
		lazy(2*p+1, u[p]);
		lazy(2*p+2, u[p]);
		u[p] = 0;
	}
	if(j <= m) return query(2*p+1, l, m, i, j);
	if(i > m) return query(2*p+2, m+1, r, i, j);
	return query(2*p+1, l, m, i, m) + query(2*p+2, m+1, r, m+1, j);
}


int main() {
	int tc;
	
	scanf("%d", &tc);
	
	for(int cc=0; cc<tc; cc++) {
		int n, q;
	
		scanf("%d %d", &n, &q);
	
		build(0, 0, n-1);
	
		printf("Case %d:\n", cc+1);
	
		for(int i=0; i<q; i++) {
			int c, l, r;
	
			scanf("%d %d %d", &c, &l, &r);
	
			if(c == 0) {
				update(0, 0, n-1, l, r);
			}
			else {
				int ans = query(0, 0, n-1, l, r);
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}