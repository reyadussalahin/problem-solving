// problem name: Tree Shuffling
// problem link: https://codeforces.com/contest/1363/problem/E
// contest link: https://codeforces.com/contest/1363
// time: (?)
// author: reyad


// other_tags: data structures, greedy, sortings, trees
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

#define N 200010
#define INF 1000000007

vector<int> adj[N];
bool seen[N] = {0};
long long a[N];
int b[N];
int c[N];

long long minTotCost =0;

pair<int, int> dfs(int u, long long minCost) {
	seen[u] = true;
	pair<int, int> cnt = make_pair(0, 0);
	for(int v: adj[u]) {
		if(!seen[v]) {
			auto p = dfs(v, min(a[u], minCost));
			cnt.first += p.first;
			cnt.second += p.second;
		}
	}
	if(b[u] != c[u]) {
		if(c[u] == 0) cnt.first++;
		else cnt.second++;
	}
	if(a[u] <= minCost) {
		int k = min(cnt.first, cnt.second);
		minTotCost = minTotCost + 2LL * k * a[u];
		cnt.first -= k;
		cnt.second -= k;
	}
	return cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lld %d %d", &a[i], &b[i], &c[i]);
	}
	for(int i=1; i<n; i++) {
		int u;
		int v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto p = dfs(1, INF);
	if(p.first == 0 && p.first == p.second) {
		printf("%lld\n", minTotCost);
	} else {
		printf("-1\n");
	}

	return 0;
}