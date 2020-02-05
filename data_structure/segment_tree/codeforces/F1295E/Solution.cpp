// problem: https://codeforces.com/contest/1295/problem/E
// contest: https://codeforces.com/contest/1295
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;

long long int a[200020], b[4 * 200020], u[4 * 200020];
int c[200020], id[200020];

void build(int p, int l, int r) {
	if(l == r) {
		b[p] = a[l];
		u[p] = 0;
		return;
	}
	int m = (l+r) / 2;
	build(2*p+1, l, m);
	build(2*p+2, m+1, r);
	b[p] = min(b[2*p+1], b[2*p+2]);
	u[p] = 0;
}

void lazy(int p, long long int x) {
	b[p] = b[p] + x;
	u[p] = u[p] + x;
}

void update(int p, int l, int r, int i, int j, int x) {
	if(i == l && r == j) {
		b[p] = b[p] + x;
		u[p] = u[p] + x;
		return;
	}
	if(u[p]) {
		lazy(2*p+1, u[p]);
		lazy(2*p+2, u[p]);
		u[p] = 0;
	}
	int m = (l+r) / 2;
	if(j <= m) update(2*p+1, l, m, i, j, x);
	else if(i > m) update(2*p+2, m+1, r, i, j, x);
	else {
		update(2*p+1, l, m, i, m, x);
		update(2*p+2, m+1, r, m+1, j, x);
	}
	b[p] = min(b[2*p+1], b[2*p+2]);
}

long long int query(int p, int l, int r, int i, int j) {
	if(i == l && r == j) {
		return b[p];
	}
	if(u[p]) {
		lazy(2*p+1, u[p]);
		lazy(2*p+2, u[p]);
		u[p] = 0;
	}
	int m = (l+r) / 2;
	if(j <= m) return query(2*p+1, l, m, i, j);
	if(i > m) return query(2*p+2, m+1, r, i, j);
	return min(query(2*p+1, l, m, i, m), query(2*p+2, m+1, r, m+1, j));
}

int main() {
	int n, v;

	scanf("%d", &n);
	for(int i=1; i<=n; i++) id[i] = -1;
	for(int i=0; i<n; i++) {
		scanf("%d", &v);
		id[v] = i;
	}
	for(int i=0; i<n; i++) scanf("%d", &c[i]);

	a[0] = c[0];
	for(int i=1; i<n; i++) a[i] = a[i-1] + c[i];

	build(0, 0, n-1);
	
	long long int ans = query(0, 0, n-1, 0, n-2);
	for(int i=1; i<=n; i++) {
		if(id[i] == -1) continue;
		update(0, 0, n-1, id[i], n-1, -c[id[i]]);
		if(id[i] > 0) update(0, 0, n-1, 0, id[i]-1, c[id[i]]);
		ans = min(ans, query(0, 0, n-1, 0, n-2));
	}

	printf("%lld\n", ans);

	return 0;
}
