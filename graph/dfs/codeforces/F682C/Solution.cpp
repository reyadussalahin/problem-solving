// problem name: Alyona and the Tree
// problem link: https://codeforces.com/contest/682/problem/C
// contest link: https://codeforces.com/contest/682
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;

vector<int> g[100010], w[100010];
int a[100010], ok = 0;

void dfs(int u, int p, int mx) {
	if(mx > a[u]) return;
	ok++;
	for(int i=0; i<(int)g[u].size(); i++) {
		if(g[u][i] == p) continue;
		dfs(g[u][i], u, ((mx + w[u][i]) > 0 ? mx + w[u][i] : 0));
	}
}

int main() {
	int n;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);

	for(int i=1; i<n; i++) {
		int p, c;
		scanf("%d %d", &p, &c);
		g[i].push_back(p-1);  w[i].push_back(c);
		g[p-1].push_back(i);  w[p-1].push_back(c);
	}

	dfs(0, -1, 0);
	printf("%d\n", n - ok);
	return 0;
}