// problem name: Three Paths on a Tree
// problem link: https://codeforces.com/contest/1294/problem/F
// contest link: https://codeforces.com/contest/1294
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;


struct Chain {
	int origin, length;
	Chain() {}
	Chain(int origin, int length) {
		this->origin = origin;
		this->length = length;
	}
};

struct Packet {
	Chain f, w;
	Packet(Chain f, Chain w) {
		this->f = f;
		this->w = w;
	}
};

vector<int> adj[200020];
bool visited[200020];
int rr = 0, aa = -1, bb = -1, cc = -1;

void update(Chain c[], Chain nc) {
	if(nc.length >= c[0].length) {
		c[2] = c[1];
		c[1] = c[0];
		c[0] = nc;
	}
	else if(nc.length >= c[1].length) {
		c[2] = c[1];
		c[1] = nc;
	}
	else if(nc.length > c[2].length) {
		c[2] = nc;
	}
}

Packet dfs(int u) {
	visited[u] = true;
	Chain c[3] = { Chain(u, 0), Chain(u, 0), Chain(u, 0) };

	for(int v: adj[u]) {
		if(visited[v]) continue;
		Packet p = dfs(v);
		p.f.length += 1;
		update(c, p.f);
		if(p.w.origin != p.f.origin) update(c, p.w);
	}
	
	if(c[0].length + c[1].length + c[2].length > rr) {
		rr = c[0].length + c[1].length + c[2].length;
		aa = c[0].origin;
		bb = c[1].origin;
		cc = c[2].origin;
	}

	return Packet(c[0], c[1]);
}

int main() {
	int n, u, v;

	scanf("%d", &n);
	for(int i=1; i<n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);
	
	printf("%d\n%d %d %d\n", rr, aa, bb, cc);
	
	return 0;
}