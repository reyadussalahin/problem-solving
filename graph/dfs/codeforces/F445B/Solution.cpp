// problem name: DZY Loves Chemistry
// problem link: https://codeforces.com/contest/445/problem/B
// contest link: https://codeforces.com/contest/445
// author: reyad
// time: (?)


#include<bits/stdc++.h>

using namespace std;

int dfs(int g[][64], int v[], int n, int s) {
	if(v[s]) return 0;
	v[s] = 1;
	int c = 0;
	for(int i=0; i<n; i++) {
		if(g[s][i]) {
			c = c + dfs(g, v, n, i);
		}
	}
	return c + 1;
}

int main() {
	int g[64][64] = {0};
	int v[64] = {0};
	int n, m;

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u -= 1; v -= 1;
		g[u][v] = g[v][u] = 1;
	}

	long long int ans = 1;
	for(int i=0; i<n; i++) {
		int cnt = dfs(g, v, n, i);
		if(cnt > 1) {
			cnt -= 1;
			ans = ans * (1LL<<cnt);
		}
		// printf("%d: %d\n", i+1, cnt);
	}

	// printf("mx: %d\n", mx);

	printf("%lld\n", ans);

	return 0;
}
